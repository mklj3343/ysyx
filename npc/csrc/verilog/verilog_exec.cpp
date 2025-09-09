#include<verilog_init.h>
#include<verilog.h>
#include<cpu/cpu.h>
#include<cpu/decode.h>
#include<cpu/difftest.h>
#include<reg.h>


void device_update();

CPU_state cpu = {};
Decode lastest_decode = {
    .pc   = cpu.pc,
    .snpc = cpu.pc + 4,
    .logbuf = {},
};



#define MAX_INST_TO_PRINT 100

static void trace_and_difftest(Decode *_this,vaddr_t dnpc)
{

 //  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));

#ifdef CONFIG_WATCHPOINT
    extern int monitor_point(uint32_t cpu_pc);

    if (monitor_point(cpu.pc))
    {
        npc_state.state = NPC_STOP;
    }

#endif
}

uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0;
static bool g_print_step = false;
 
static void exec_once(){


    
    top->clk = 0;
    top->eval();
    tfp->dump(sim_time++);
    top->clk = 1;
    top->eval();
    tfp->dump(sim_time++);
 /*   top->clk = 0;
    top->eval();
    tfp->dump(sim_time++);
    top->clk = 1;
    top->eval();
    tfp->dump(sim_time++);*/

}

static void execute(uint64_t n)
{
    for (; n > 0;n--){
       

     //   clint_update_mtime();
     exec_once();
        g_nr_guest_inst++;
        trace_and_difftest(&lastest_decode ,cpu.pc);

        if(npc_state.state != NPC_RUNNING)
        break;

         IFDEF(CONFIG_DEVICE, device_update());
    }
}

void cpu_exec(uint64_t n){
    
    g_print_step = (n < MAX_INST_TO_PRINT);
    switch (npc_state.state){
    case NPC_END:
    case NPC_ABORT:
    case NPC_QUIT:
        std::cout << " Program execution has ended.To restart the program, exit NEMU and run again."<<std::endl;
        return;
    default:
        npc_state.state = NPC_RUNNING;
    }

    top->p_count_number = n > 1000000 ? MAX_INST_TO_PRINT + 1 : n;
    execute(n);


}
 
