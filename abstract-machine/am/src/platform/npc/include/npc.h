#ifndef __NPC_H__
#define __NPC_H__

#include <klib-macros.h>

#include ISA_H

#define npc_trap(code) asm volatile("mv a0, %0; ebreak" : : "r"(code))

#define APB_BASE 0x10000000
#define VGA_BASE 0x1F000000

#define SERIAL_PORT APB_BASE
#define RTC_ADDR (APB_BASE + 0x00001000)
#define KBD_ADDR (APB_BASE + 0x00011000)

#define VGACTL_ADDR (VGA_BASE + 0x00000000)
#define SYNC_ADDR (VGA_BASE + 0x00000004)
#define FB_ADDR 0x1F010000

typedef uintptr_t PTE;

#define PGSIZE 4096

#endif