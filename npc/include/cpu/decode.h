
#ifndef __CPU_DECODE_H__
#define __CPU_DECODE_H__

#include <isa.h>


typedef struct Decode {

    vaddr_t pc;
    vaddr_t snpc;
    vaddr_t dnpc;
    ISADecodeInfo isa;
    IFDEF(CONFIG_ITRACE, char logbuf[128]);
} Decode;



#endif