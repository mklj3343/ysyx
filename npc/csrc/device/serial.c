#include <device/map.h>
#include <utils.h>


#define THR_OFFSET 0 
#define RBR_OFFSET 0 
#define LSR_OFFSET 5 


#define LSR_THRE_MASK 0x20

static uint8_t *serial_port_base = NULL;


static void serial_io_handler(uint32_t offset, int len, bool is_write) {

  assert(len == 1);

  if (is_write) {
    switch (offset) {
    case THR_OFFSET:
      putc(serial_port_base[THR_OFFSET], stderr);
      break;
    default:
      break;
    }
  } else {
    switch (offset) {
    case LSR_OFFSET:
      serial_port_base[LSR_OFFSET] = LSR_THRE_MASK;
      break;
    default:
      break;
    }
  }
}

void init_serial() {
  serial_port_base = new_space(8);
  add_mmio_map("serial", CONFIG_SERIAL_MMIO, serial_port_base, 8,
               serial_io_handler);
}