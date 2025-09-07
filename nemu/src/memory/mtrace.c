#include <stdio.h>
#include "mtrace.h"

#ifdef CONFIG_MTRACE
static paddr_t mtrace_start = 0x80000000;
static paddr_t mtrace_end = 0xffffffff;


void mtrace_record(char type, paddr_t addr, int len, word_t data)
{
    if(addr>=mtrace_start && addr <= mtrace_end)
    {
        printf("mtrace: %c addr=0x%08x len=%d data=0x%08x\n", type, addr, len, data);
    }
}

void mtrace_set_range(vaddr_t start,vaddr_t end)
{
    mtrace_start = start;
    mtrace_end = end;
    printf("mtrace: Set range [0x%08x, 0x%08x)\n", start, end);
}

#endif