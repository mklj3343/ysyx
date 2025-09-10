
#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>



#if defined(CONFIG_PMEM_MALLOC)
    static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
    static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

uint8_t *guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len)
{
    word_t ret = host_read(guest_to_host(addr), len);
    return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data)
{
    host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr)
{
    panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
          addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem()
{

#if defined(CONFIG_PMEM_MALLOC)
    pmem = malloc(CONFIG_MSIZE);
    assert(pmem);
#endif
    IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
    Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

word_t paddr_read(paddr_t addr, int len)
{


    word_t ret = 0;

    if (likely(in_pmem(addr)))
    {
        ret = pmem_read(addr, len);
        return ret;
    }

    printf("addr:0x%08x,pc:0x%08x\n", addr, cpu.pc);
    printf("111111111\n");
    IFDEF(CONFIG_DEVICE, ret = mmio_read(addr, len); return ret);

    printf("22222222\n");
    out_of_bound(addr);
    return 0;
}

void paddr_write(paddr_t addr, int len, word_t data)
{

  
  if (likely(in_pmem(addr))) {
    pmem_write(addr, len, data);
    return;
  }

  printf("333333333333\n");
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  printf("44444444\n");
  out_of_bound(addr);
}
