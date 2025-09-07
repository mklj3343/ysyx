#include <device/map.h>
#include <utils.h>
#include<time.h> 
static uint32_t *rtc_port_base = NULL;

uint64_t get_sys_time();

static void rtc_io_handler(uint32_t offset, int len, bool is_write)
{

  // assert(offset == 0 || offset == 4);&& offset == 4
  if (!is_write ) {
    uint64_t us = get_time();
    rtc_port_base[0] = (uint32_t)us;
    rtc_port_base[1] = us >> 32;

    time_t seconds = get_sys_time() / 1000000;

    struct tm *tm = localtime(&seconds);
    rtc_port_base[2] = tm->tm_year + 1900;
    rtc_port_base[3] = tm->tm_mon + 1;
    rtc_port_base[4] = tm->tm_mday;
    rtc_port_base[5] = tm->tm_hour;
    rtc_port_base[6] = tm->tm_min;
    rtc_port_base[7] = tm->tm_sec;
  }
}

void init_timer() {
 
  rtc_port_base = (uint32_t *)new_space(32);

#ifdef CONFIG_HAS_PORT_IO
  add_pio_map("rtc", CONFIG_RTC_PORT, rtc_port_base, 32, rtc_io_handler);
#else
  add_mmio_map("rtc", CONFIG_RTC_MMIO, rtc_port_base, 32, rtc_io_handler);
#endif

}
