#ifndef __VERILOG_INIT_H__
#define __VERILOG_INIT_H__


#include <Vysyx_25040109_top.h>
#include <verilated_fst_c.h>
#include <verilated.h>
#include <Vysyx_25040109_top___024root.h>

extern Vysyx_25040109_top *top;
extern VerilatedFstC *tfp;
extern vluint64_t sim_time ;

extern "C" void init_verilog(int argc, char **argv);
extern "C" void clear_verilog();

#endif
