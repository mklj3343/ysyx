
#ifndef __DEVICE_MAP_H__
#define __DEVICE_MAP_H__

#include <cpu/difftest.h>


typedef void (*io_callback_t)(uint32_t, int, bool);


typedef struct {
  const char *name;
  paddr_t low;
  paddr_t high;
  void *space;
  io_callback_t callback;
} IOMap;

// 检查地址是否在映射范围内
static inline bool map_inside(IOMap *map, paddr_t addr) {
  return (addr >= map->low && addr <= map->high);
}


static inline int find_mapid_by_addr(IOMap *maps, int size, paddr_t addr) {
  int i;
  for (i = 0; i < size; i++) {
    if (map_inside(maps + i, addr)) {
      difftest_skip_ref(); 
      return i;
    }
  }
  return -1;
}


uint8_t *new_space(int size);

void add_pio_map(const char *name, ioaddr_t addr, void *space, uint32_t len,
                 io_callback_t callback);



word_t map_read(paddr_t addr, int len, IOMap *map);
void map_write(paddr_t addr, int len, word_t data, IOMap *map);

#ifdef __cplusplus
extern "C" {
#endif

// 声明 C 函数
void add_mmio_map(const char *name, paddr_t addr, void *space, uint32_t len,
                  io_callback_t callback);

#ifdef __cplusplus
}
#endif

#endif
