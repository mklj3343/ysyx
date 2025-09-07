/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#ifndef __DEVICE_MAP_H__
#define __DEVICE_MAP_H__

#include <cpu/difftest.h>

// 定义 I/O 回调函数指针类型，用于设备读写时的回调处理
// - uint32_t offset: 相对于映射起始地址的偏移量
typedef void(*io_callback_t)(uint32_t, int, bool);
uint8_t* new_space(int size);


typedef struct {
  const char *name;
  // we treat ioaddr_t as paddr_t here
  // 将ioaddr_t 被视为 paddr_t（物理地址类型）
  paddr_t low;    
  paddr_t high;   
  void *space;
  io_callback_t callback;
} IOMap;

// 检查地址是否在映射范围内
static inline bool map_inside(IOMap *map, paddr_t addr) {
  return (addr >= map->low && addr <= map->high);
}

// 内联函数 find_mapid_by_addr，在映射数组中查找包含指定地址的映射
// - maps: 指向 IOMap 结构体数组的指针，表示所有设备映射
// 作用：通过地址定位对应的设备映射，并在差分测试中跳过设备检查
static inline int find_mapid_by_addr(IOMap *maps, int size, paddr_t addr) {
  int i;
  for (i = 0; i < size; i ++) {
    if (map_inside(maps + i, addr)) {
      difftest_skip_ref();// 调用 difftest_skip_ref，跳过差分测试的参考模型检查， 原因：设备 I/O 通常不需与参考模型比较（如 QEMU）
      return i;
    }
  }
  return -1;
}

// 作用：在系统中注册一个端口映射，配置设备的端口地址和处理逻辑
void add_pio_map(const char *name, ioaddr_t addr,
        void *space, uint32_t len, io_callback_t callback);

// 作用：在系统中注册一个内存映射，配置设备的内存地址范围和处理逻辑
void add_mmio_map(const char *name, paddr_t addr,
        void *space, uint32_t len, io_callback_t callback);
// 作用：从指定设备的映射地址读取数据
word_t map_read(paddr_t addr, int len, IOMap *map);
// 作用：向指定设备的映射地址写入数据
void map_write(paddr_t addr, int len, word_t data, IOMap *map);

#endif
