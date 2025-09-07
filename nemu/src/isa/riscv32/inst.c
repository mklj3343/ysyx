/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include "local-include/reg.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>
#include<ftrace.h>
#include<mtrace.h>
#include<csr.h>
//#include<stdlib.h>

#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write


typedef struct {
  uint32_t pc;
  uint32_t target;
  uint64_t count;
  uint64_t taken_count;
  char type[8];

} BranchStat;


static BranchStat *branch_stats = NULL;
static int branch_count = 0;


enum {
  TYPE_I,
  TYPE_U,
  TYPE_S,
  TYPE_J,
  TYPE_B,
  TYPE_R,
  TYPE_N, // none
};

#define src1R() do { *src1 = R(rs1); } while (0)
#define src2R() do { *src2 = R(rs2); } while (0)
#define immI() do  { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immU() do  { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immS() do  { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)
#define immJ() do  { *imm = SEXT((BITS(i, 31, 31) << 20) | (BITS(i, 30, 21) << 1) | (BITS(i,20,20) << 11) | (BITS(i, 19, 12) << 12) , 21);  } while (0) 
#define immB() do  { *imm = SEXT((BITS(i, 31, 31) << 12) | (BITS(i, 7, 7) << 11) | (BITS(i, 30, 25) << 5) | (BITS(i, 11, 8) << 1), 13);}while(0)


static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst;
  int rs1 = BITS(i, 19, 15); 
  int rs2 = BITS(i, 24, 20);
  *rd     = BITS(i, 11, 7);
  switch (type) {
    case TYPE_I: src1R();          immI(); break;
    case TYPE_U:                   immU(); break;
    case TYPE_S: src1R(); src2R(); immS(); break;
    case TYPE_J:                   immJ();break;
    case TYPE_B: src1R();src2R();  immB();break;
    case TYPE_R: src1R();src2R();         break; 
    case TYPE_N:
      break;
    default: panic("unsupported type = %d", type);
  }
}

void track_branch(Decode *s, bool taken, uint32_t target, const char *inst_type)
{
  #ifdef CONFIG_FTRACE
  for (int i = 0; i < branch_count; i++)
  {
    if (branch_stats[i].pc == s->pc)
    {
      branch_stats[i].count++;
      if (taken)
        branch_stats[i].taken_count++;
      return;
    }
  }
  BranchStat *new_stats = realloc(branch_stats, (branch_count + 1) * sizeof(BranchStat));//记录新的跳转指令，新增一个内存，
  if (!new_stats)
  {
    fprintf(stderr, "内存分配失败\n");
    exit(1);
  }
  branch_stats = new_stats;
  branch_stats[branch_count] = (BranchStat){s->pc, target, 1, taken ? 1 : 0, {0}};

  strncpy(branch_stats[branch_count].type, inst_type, sizeof(branch_stats[branch_count].type) - 1); // 最大复制范围，不足最大就连'\0也复制
  branch_stats[branch_count].type[sizeof(branch_stats[branch_count].type) - 1] = '\0';
  branch_count++;
  #endif
}

//操作数解码
static int decode_exec(Decode *s) {
  s->dnpc = s->snpc;

#define INSTPAT_INST(s) ((s)->isa.inst)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
  int rd = 0; \
  word_t src1 = 0, src2 = 0, imm = 0; \
  decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}


  INSTPAT_START();
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc, U, R(rd) = s->pc + imm);
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui,   U, R(rd) = imm);
  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi,  I, R(rd) = src1 + imm);
  INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti,  I, R(rd) = ( (int32_t)src1  < (int32_t)imm ) ? 1 : 0);
  INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu, I, R(rd) = ( (uint32_t)src1 < (uint32_t)imm) ? 1 : 0);
  INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori,  I, R(rd) = src1 ^ imm); 
  INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori,   I, R(rd) = src1 | imm);
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi,  I, R(rd) = src1 & imm);
  INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli,  I, R(rd) = src1 << (imm & 0x1f));
  INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli,  I, R(rd) = (uint32_t)src1 >> (imm & 0x1f));
  INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai,  I, R(rd) = (int32_t)src1 >> (imm & 0x1f)); // 0x1f 是一个 5 位的掩码（二进制为 11111）,作用是 提取 imm 的低 5 位
  INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb,    I, R(rd) = (int32_t)(int8_t)Mr(src1 + imm, 1), mtrace_record('R', src1 + imm, 1, R(rd)));
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh,    I, R(rd) = (int32_t)(int16_t)Mr(src1 + imm, 2), mtrace_record('R', src1 + imm, 2, R(rd)));
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw,    I, R(rd) = Mr(src1 + imm, 4),mtrace_record('R', src1 + imm, 4, R(rd)));
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu,   I, R(rd) = (uint32_t)(uint8_t)Mr(src1 + imm, 1), mtrace_record('R', src1 + imm, 1, R(rd)));
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu,   I, R(rd) = (uint32_t)(uint16_t)Mr(src1 + imm, 2), mtrace_record('R', src1 + imm, 2, R(rd)));

  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add,   R, R(rd) = src1 + src2);
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub,   R, R(rd) = src1 - src2);
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll,   R, R(rd) = src1 << (src2 & 0x1f));
  INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt,   R, R(rd) = ((int32_t)src1 < (int32_t)src2) ? 1 : 0);
  INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu,  R, R(rd) = ((uint32_t)src1 < (uint32_t)src2) ? 1 : 0);
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor,   R, R(rd) = src1 ^ src2);
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl,   R, R(rd) = (uint32_t)src1 >> (src2 & 0x1f));
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra,   R, R(rd) = (int32_t)src1 >> (src2 & 0x1f));
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or,    R, R(rd) = src1 | src2); 
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and,   R, R(rd) = src1 & src2);

  INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul,   R, R(rd) = (int64_t)(int32_t)src1 * (int32_t)src2); 
  INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh,  R, R(rd) = ((int64_t)(int32_t)src1 * (int64_t)(int32_t)src2) >> 32);
  INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu, R, R(rd) = ((uint64_t)src1 * (uint64_t)src2) >> 32);
  INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div,   R, R(rd) = (src2 == 0) ? -1 : ((src1 == INT32_MIN && src2 == -1) ? INT32_MIN : (int32_t)src1 / (int32_t)src2)); // 除0等于-1
  INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu,  R, R(rd) = (src2 == 0) ? 0xFFFFFFFF : (uint32_t)src1 / (uint32_t)src2);
  INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem,   R, R(rd) = (src2 == 0) ? src1 : ((src1 == INT32_MIN && src2 == -1) ? 0 : (int32_t)src1 % (int32_t)src2));
  INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu,  R, R(rd) = (src2 == 0) ? src1 : (uint32_t)src1 % (uint32_t)src2);
    
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb,    S, Mw(src1 + imm, 1, src2), mtrace_record('W', src1 + imm, 1, src2));
  INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh,    S, Mw(src1 + imm, 2, src2), mtrace_record('W', src1 + imm, 2, src2));
  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw,    S, Mw(src1 + imm, 4, src2), mtrace_record('W', src1 + imm, 4, src2));

  INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr, I, R(rd) = s->pc + 4;
      s->dnpc = (src1 + imm) & ~1UL; // JALR 的目标地址必须将最低位（bit
                                     // 0）清零，1UL 表示值为1，的32位无符号数
#ifdef CONFIG_FTRACE
      if (rd == 1) {
        ftrace_call(s->pc, s->dnpc);
      } else if (rd == 0 && BITS(s->isa.inst, 19, 15) == 1 && imm == 0) {
        ftrace_ret(s->pc);
      }
#endif
  );

  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal,   J, R(rd) = s->pc + 4; s->dnpc = s->pc + imm;
  #ifdef CONFIG_FTRACE
            if (rd == 1) { ftrace_call(s->pc, s->dnpc); }

  #endif
    );
    


  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq, B, {
  bool taken = (src1 == src2);
  if (taken)
    s->dnpc = s->pc + imm;
  track_branch(s, taken, s->pc + imm, "beq");
});
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne, B, {
  bool taken = (src1 != src2);
  if (taken)
    s->dnpc = s->pc + imm;
  track_branch(s, taken, s->pc + imm, "bne");
});
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt, B, {
  bool taken = ((int32_t)src1 < (int32_t)src2);
  if (taken)
    s->dnpc = s->pc + imm;
  track_branch(s, taken, s->pc + imm, "blt");
});
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge, B, {
  bool taken = ((int32_t)src1 >= (int32_t)src2);
  if (taken)
    s->dnpc = s->pc + imm;
  track_branch(s, taken, s->pc + imm, "bge");
});
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu, B, {
  bool taken = ((uint32_t)src1 < (uint32_t)src2);
  if (taken)
    s->dnpc = s->pc + imm;
  track_branch(s, taken, s->pc + imm, "bltu");
});

  INSTPAT("??????? 00000 ????? 001 ????? 11000 11", bnez, B, {
  bool taken = ((src1 != 0));
  if (taken)
    s->dnpc = s->pc + imm;
  track_branch(s, taken, s->pc + imm, "bnez");
});
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu, B, {
  bool taken = ((uint32_t)src1 >= (uint32_t)src2);
  if (taken)
    s->dnpc = s->pc + imm;
  track_branch(s, taken, s->pc + imm, "bgeu");
});

  INSTPAT("0011000 00010 00000 000 00000 11100 11", mret, N, {

    
    //验证 靠谁恢复
#ifdef CONFIG_ETRACE
    printf("\033[1;33m cpu reg interrupte after:\033[0m\n");
     for (int i = 0; i < 32; i++) {
       printf(" %-3s: 0x%08x\n", reg_name(i), cpu.gpr[i]);}

       printf(" mepc   : 0x%08x\n", cpu.csr[CSR_MEPC]);
       printf(" mcause : 0x%08x\n", cpu.csr[CSR_MCAUSE]);
       printf(" mstatus: 0x%08x\n", cpu.csr[CSR_MSTATUS]);

#endif

       s->dnpc = cpu.csr[CSR_MEPC];

    
    /* word_t mstatus = cpu.csr[CSR_MSTATUS];

     bool mpie = (mstatus >> 7) & 1;
     if (mpie) {
       mstatus |= (1 << 3);

     } else {
       mstatus &= ~(1 << 3);
     }

  mstatus |= (1 << 7);

  mstatus &= ~((1U << 12) | (1U << 11));

  cpu.csr[CSR_MSTATUS] = mstatus;*/

    //查看这三个寄存器的变化
#ifdef CONFIG_ETRACE
    printf("\033[1;33m cpu system  reg interrupte after:\033[0m\n");
    // for (int i = 0; i < 32; i++) {
    // printf(" %2s: 0x%08x\n", reg_name(i), cpu.gpr[i]);

    printf(" mepc   : 0x%08x\n", cpu.csr[CSR_MEPC]);
    printf(" mcause : 0x%08x\n", cpu.csr[CSR_MCAUSE]);
    printf(" mstatus: 0x%08x\n", cpu.csr[CSR_MSTATUS]);

#endif
  });

  INSTPAT("???????????? ????? 010 ????? 1110011", csrr, I,
          R(rd) = cpu.csr[imm]);

  //csrr,csrw是伪指令        
  INSTPAT("??????? ????? ????? 001 ????? 1110011", csrrw, I,
          word_t old_val = cpu.csr[imm];
          cpu.csr[imm] = src1;
          R(rd) = old_val;
        );



  INSTPAT("0000000 00000 00000 000 00000 1110011", ecall, N, {

    //检查复制的对不对
#ifdef CONFIG_ETRACE
    printf("\033[1;33, cpu reg interrupte before:\033[0m\n");
    for (int i = 0; i < 32; i++) {
      printf(" %-3s: 0x%08x\n", reg_name(i), cpu.gpr[i]);
    }

    printf(" mepc   : 0x%08x\n", cpu.csr[CSR_MEPC]);
    printf(" mcause : 0x%08x\n", cpu.csr[CSR_MCAUSE]);
    printf(" mstatus: 0x%08x\n", cpu.csr[CSR_MSTATUS]);

#endif

    vaddr_t handler_addr = isa_raise_intr(11, s->pc);
    s->dnpc = handler_addr;
  

#ifdef CONFIG_ETRACE
    printf("\033[1;33m cpu system reg interrupte before:\033[0m\n");
    // for (int i = 0; i < 32; i++) {
    // printf(" %2s: 0x%08x\n", reg_name(i), cpu.gpr[i]);

    printf(" mepc   : 0x%08x\n", cpu.csr[CSR_MEPC]);
    printf(" mcause : 0x%08x\n", cpu.csr[CSR_MCAUSE]);
    printf(" mstatus: 0x%08x\n", cpu.csr[CSR_MSTATUS]);

#endif

  });
  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak, N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv, N, INV(s->pc));

  INSTPAT_END();

  R(0) = 0; // reset $zero to 0

  return 0;
}
void printf_branchstat()
{
  printf("分支指令跟踪 (itrace):\n");
  printf("PC\t\t目标地址\t计数\t跳转次数\t跳转率\t类型\n");
  for (int i = 0; i < branch_count; i++)
  {
    double taken_rate = (branch_stats[i].count > 0) ? (double)branch_stats[i].taken_count / branch_stats[i].count * 100 : 0;
    printf("0x%08x\t0x%08x\t%lu\t%lu\t        %.2f%%\t%s\n",
           branch_stats[i].pc, branch_stats[i].target,
           branch_stats[i].count, branch_stats[i].taken_count,
           taken_rate, branch_stats[i].type);
  }
}

int isa_exec_once(Decode *s) {
  s->isa.inst = inst_fetch(&s->snpc, 4);
  
  return decode_exec(s);
}
