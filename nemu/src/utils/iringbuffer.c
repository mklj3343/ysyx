#include <common.h>


#ifdef CONFIG_ITRACE

#define IRINGBUF_SIZE 16

extern void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);

typedef struct 
{
    vaddr_t pc;
    uint32_t inst;
    char disasm[64];
} IRingBufEntry;

static IRingBufEntry iringbuf[IRINGBUF_SIZE];
static int iringbuf_index = 0;
static bool iringbuf_full = false;

void iringbuf_init()
{
    iringbuf_index = 0;
    iringbuf_full = false;
    for (int i = 0;i < IRINGBUF_SIZE ; i++)
    {
        iringbuf[i].pc = 0;
        iringbuf[i].inst = 0;
        iringbuf[i].disasm[0] = '\0';
    }
}

void write_iringbuf(vaddr_t pc, uint32_t inst)
{
    IRingBufEntry *entry = &iringbuf[iringbuf_index];
    entry->pc = pc;
    entry->inst = inst;

    disassemble(entry->disasm, sizeof(entry->disasm), pc, (uint8_t *)&inst, 4);

    iringbuf_index = (iringbuf_index + 1) % IRINGBUF_SIZE;
    if(iringbuf_index==0)
    {
        iringbuf_full = true;
    }
}

void iringbuf_dump()
{
    if(iringbuf_index || iringbuf_full)
    {
    printf("\n===hit error inst===\n");
    int start = iringbuf_full ? iringbuf_index : 0;
    int count = iringbuf_full ? IRINGBUF_SIZE : iringbuf_index ;

    for (int i = 0; i < count;i++)
    {
        int idx = (start + i) % IRINGBUF_SIZE;

        IRingBufEntry *entry = &iringbuf[idx];

        char *marker = (i == (iringbuf_index - 1)) ? "-->" : "   ";

        printf("%s  0x%08x:  %08x  %-30s\n ", marker, entry->pc, entry->inst, entry->disasm);
    }

    printf("=====================================\n");
}
}
#endif