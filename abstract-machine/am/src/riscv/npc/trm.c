#include <am.h>
#include <npc.h>
#include<klib.h>

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] =TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) { 
  outb(SERIAL_PORT, ch); 
}

void halt(int code) {
  
  npc_trap(code);

  while (1);
}

void _trm_init() {

  /*
  unsigned int vendor_id;
  unsigned int arch_id;
  unsigned int mcycle;
  unsigned int mcycleh;

  asm volatile("csrr %0, mcycle" : "=r"(mcycle));
  asm volatile("csrr %0, mcycleh" : "=r"(mcycleh));

  printf("CSR mycle  : %u  , %u\n", mcycle,mcycleh);

  asm volatile("csrr %0, mvendorid" : "=r"(vendor_id));
  asm volatile("csrr %0, marchid" : "=r"(arch_id));

  asm volatile("csrr %0, mcycle" : "=r"(mcycle));
  asm volatile("csrr %0, mcycleh" : "=r"(mcycleh));

  printf("CSR mycle  : %u  , %u\n", mcycle, mcycleh);

  printf("CSR mvendorid: 0x%08x -> Vendor: %c%c%c%c\n", vendor_id,
         (vendor_id >> 24) & 0xff, (vendor_id >> 16) & 0xff,
         (vendor_id >> 8) & 0xff, (vendor_id >> 0) & 0xff);

  asm volatile("csrr %0, mcycle" : "=r"(mcycle));
  asm volatile("csrr %0, mcycleh" : "=r"(mcycleh));

  printf("CSR mycle  : %u  , %u\n", mcycle, mcycleh);

  printf("CSR marchid  : %u (0x%x)\n", arch_id, arch_id);

  asm volatile("csrr %0, mcycle" : "=r"(mcycle));
  asm volatile("csrr %0, mcycleh" : "=r"(mcycleh));

  printf("CSR mycle  : %u  , %u\n", mcycle, mcycleh);
*/
  int ret = main(mainargs);
  halt(ret);
}
