
#include <device/map.h>
#include <isa.h>
#include <memory/host.h>
#include <memory/vaddr.h>

#define IO_SPACE_MAX (32 * 1024 * 1024)

static void dtrace(IOMap *map, char type, word_t data);
static uint8_t *io_space = NULL;
static uint8_t *p_space = NULL;

uint8_t *new_space(int size) {
  uint8_t *p = p_space;
  // page aligned;
  size = (size + (PAGE_SIZE - 1)) &
         ~PAGE_MASK;
  p_space += size; 
  assert(p_space - io_space < IO_SPACE_MAX);
  return p; 
}


static void check_bound(IOMap *map, paddr_t addr) {
  if (map == NULL) {
    Assert(map != NULL,
           "address (" FMT_PADDR ") is out of bound at pc = " FMT_WORD, addr,
           cpu.pc);
  } else {
    Assert(addr <= map->high && addr >= map->low,
           "address (" FMT_PADDR ") is out of bound {%s} [" FMT_PADDR
           ", " FMT_PADDR "] at pc = " FMT_WORD,
           addr, map->name, map->low, map->high, cpu.pc);
  }
}

// 调用设备映射的回调函数，- c: 回调函数（io_callback_t 类型）
static void invoke_callback(io_callback_t c, paddr_t offset, int len,bool is_write) {
  if (c != NULL) {
    c(offset, len, is_write);
  }
}

void init_map() {
  io_space = (uint8_t *)malloc(IO_SPACE_MAX);
  assert(io_space);
  p_space = io_space;
}


word_t map_read(paddr_t addr, int len, IOMap *map) {
  assert(len >= 1 && len <= 8);
  check_bound(map, addr);
  paddr_t offset = addr - map->low;                  
  invoke_callback(map->callback, offset, len, false);
  word_t ret = host_read((uint8_t *)map->space + offset, len);
  dtrace(map, 'R', ret);
  return ret;
}

void map_write(paddr_t addr, int len, word_t data, IOMap *map) {
  assert(len >= 1 && len <= 8);
  check_bound(map, addr);
  paddr_t offset = addr - map->low;
  host_write((uint8_t *)map->space + offset, len, data);
  invoke_callback(map->callback, offset, len, true);
  dtrace(map, 'W', data);
}

static void dtrace(IOMap *map, char type, word_t data) {
#ifdef CONFIG_DTRACE
  printf("Device: %-10s | PC: 0x%08x | Operation: '%c' | Data: 0x%08x (%u)\n",
         map->name, cpu.pc, type, data, data);
#endif
}
