#include <isa.h>
#include<paddr.h>
#include<verilog.h>
#include<verilog_init.h>
#include <cpu/decode.h>

extern Decode lastest_decode;


extern "C" int  verilog_pmem_read(paddr_t addr,int len)
{
     
   // mtrace_record('R', addr, 4, *data);
   return paddr_read(addr, len);
}

extern "C" void verilog_pmem_write(paddr_t addr, uint32_t data,uint32_t len){
    paddr_write(addr, len, data);
   // mtrace_record('W', addr, len, data);
}

/*
extern "C" int printf_finish(uint32_t inst)
{
    if (inst == 0x00100073 || inst == 0x00000073)
    {
        uint32_t a0 = top->a0_out;
        std::cout << "Finish program (" << (inst == 0x00100073 ? "EBREAK" : "ECALL")
                  << "), Hit a \033[1;" << (a0 == 0 ? 32 : 31) << "m"
                  << (a0 == 0 ? "GOOD" : "BAD") << "\033[0m TRAP\n";

        npc_state.state = (inst == 0x00000073 && a0 != 0) ? NPC_STOP : NPC_END;
        return (inst == 0x00000073 && a0 != 0) ? 1 : 0;
    }

    return 1;
}*/


extern "C" void printf_finish()
{
  uint32_t a0 = cpu.gpr[10];
  
  printf("a0:%d\n",a0);
  if(a0 == 0){
        std::cout << "Finish program (" << "EBREAK" 
                  << "), Hit a \033[1;" << (a0 == 0 ? 32 : 31) << "m"
                  << (a0 == 0 ? "GOOD" : "BAD") << "\033[0m TRAP\n";

        npc_state.state = ( a0 != 0) ? NPC_STOP : NPC_END;
        }

}




extern "C" void update_cpu_state(uint32_t pc,const uint32_t regs[16] )
{
  cpu.pc = pc;
  for (int i = 0; i < 16;i++)
  {
      cpu.gpr[i] = regs[i];
  }
  
  /*
  cpu.pc = pc;
    for (int i = 0; i < 16; i++) {
        cpu.gpr[i] = regs[i];  // 只用传入的参数，不要直接访问top->rootp
    }*/
        
}




extern "C" void update_cpu_state16(int pc, int r0,int r1,int r2,int r3,int r4,int r5,int r6,int r7, int r8,int r9,int r10,int r11,int r12,int r13,int r14,int r15) { uint32_t a[16] = { (uint32_t)r0,(uint32_t)r1,(uint32_t)r2,(uint32_t)r3, (uint32_t)r4,(uint32_t)r5,(uint32_t)r6,(uint32_t)r7, (uint32_t)r8,(uint32_t)r9,(uint32_t)r10,(uint32_t)r11, (uint32_t)r12,(uint32_t)r13,(uint32_t)r14,(uint32_t)r15 }; update_cpu_state((uint32_t)pc, a); }



extern "C" void update_decode_state(vaddr_t pc,vaddr_t snpc ,vaddr_t dnpc,uint32_t inst){
    lastest_decode.pc = pc;
    lastest_decode.snpc = pc + 4;
    lastest_decode.dnpc = dnpc;
    lastest_decode.isa.inst = inst;

}
extern "C" void trap_record(int pc,int cause){
    std::cout << "pc: " << pc << ", cause:  " << cause << std::endl;

}
