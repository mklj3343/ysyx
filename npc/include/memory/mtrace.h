#ifndef __MTRACE_H__
#define __MTRACE_H__

#include <common.h>

void mtrace_record(char type, paddr_t addr, int len, word_t data);

void mtrace_set_range(vaddr_t start, vaddr_t end);

#endif