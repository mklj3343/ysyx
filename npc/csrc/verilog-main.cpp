#include<verilog_init.h>
#include<iostream>


Vysyx_25040109_top *top = new Vysyx_25040109_top;
VerilatedFstC *tfp = new VerilatedFstC;
vluint64_t sim_time = 0;

extern "C" void init_verilog(int argc, char **argv)
{

    Verilated::commandArgs(argc, argv);

    Verilated::traceEverOn(true);

        top->trace(tfp, 99);
        tfp->open("sim.fst");

        

        top->clk = 0;
        top->eval();
        top->rst = 1;
        top->clk = 1;
        top->eval();
        tfp->dump(sim_time++);
        top->rst = 0;

        std::cout << "After reset: PC = 0x" << std::hex << top->pc << std::dec << std::endl;
}

extern "C" void clear_verilog(){
    tfp->close();
    top->final();
    delete top;
    delete tfp;
    return;
}

