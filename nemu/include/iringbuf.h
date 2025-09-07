#ifndef __IRINGBUF_H__
#define __IRINGBUF_H__



void iringbuf_init();
void iringbuf_write(vaddr_t pc, uint32_t inst);
void iringbuf_dump();

#endif