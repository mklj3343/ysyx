#ifndef __WATCHPOINT_H__
#define __WATCHPOINT_H__

#include"common.h"

int monitor_point(uint32_t cpu_pc);
void new_wp(char *expr_str);
void free_wp(int NO);
void printf_point();
void init_wp_pool();

#endif