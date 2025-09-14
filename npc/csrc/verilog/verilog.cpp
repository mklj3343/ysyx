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
      cpu.gpr[i]=top->rootp->ysyx_25040109_top__DOT__cpu__DOT__u_regfile__DOT__registers[i];


  }
  /*
  cpu.pc = pc;
    for (int i = 0; i < 16; i++) {
        cpu.gpr[i] = regs[i];  // 只用传入的参数，不要直接访问top->rootp
    }*/
        
}

extern "C" void update_decode_state(vaddr_t pc,vaddr_t snpc ,vaddr_t dnpc,uint32_t inst){
    lastest_decode.pc = pc;
    lastest_decode.snpc = pc + 4;
    lastest_decode.dnpc = dnpc;
    lastest_decode.isa.inst = inst;

}
extern "C" void trap_record(int pc,int cause){
    std::cout << "pc: " << pc << ", cause:  " << cause << std::endl;

}
