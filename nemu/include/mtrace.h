#ifndef _MARACE_H_
#define _MTRACE_H_


#include<common.h>

#ifdef CONFIG_MTRACE
void mtrace_record(char type, paddr_t addr, int len, word_t data);
void mtrace_set_range(vaddr_t start, vaddr_t end);

#else
#define mtrace_record(type, addr, len, date) ((void)0)
#define mtrace_set_range(start, end) ((void)0)
//定义为空
#endif

#endif
