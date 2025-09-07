#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>




static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {

  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
    case 11:
      ev.event = EVENT_YIELD;
      ev.cause = c->mcause;
      ev.ref = c->mepc;
      c->mepc += 4;
      ev.msg = "Machine External Interrupt";
      break;

    default:
      ev.event = EVENT_ERROR;
      ev.cause = c->mcause;
      ev.ref = c->mepc;
      break;
    }

    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;

  return true;
}

extern void __am_kcontext_start(void);

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {

  Context *c = (Context *)(((uintptr_t)kstack.end - sizeof(Context)) & ~0xF);


  memset(c, 0, sizeof(Context));


  c->mepc = (uintptr_t)__am_kcontext_start;

 
  c->gpr[2] = (uintptr_t)kstack.end; 


  c->gpr[10] = (uintptr_t)arg;   
  c->gpr[11] = (uintptr_t)entry; 


  c->mstatus = 0x1800; 

  return c;
}

void yield() {
#ifdef __riscv_e
  asm volatile("li a5, -1; ecall");
#else
  asm volatile("li a7, -1; ecall");
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
