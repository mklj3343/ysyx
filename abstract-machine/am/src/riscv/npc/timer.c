#include <am.h>
#include<npc.h>
#include<klib.h>

void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {

  uint32_t hi, lo;
  do {
    lo = inl(RTC_ADDR);
    hi = inl(RTC_ADDR + 4);

  } while (inl(RTC_ADDR + 4) != hi);

  uptime->us = ((uint64_t)hi << 32) | lo;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->year = inl(RTC_ADDR + 8);
  rtc->month = inl(RTC_ADDR + 12);
  rtc->day = inl(RTC_ADDR + 16);
  rtc->hour = inl(RTC_ADDR + 20);
  rtc->minute = inl(RTC_ADDR + 24);
  rtc->second = inl(RTC_ADDR + 28);
}
