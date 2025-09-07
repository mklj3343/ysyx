#include <am.h>
#include <klib.h>
#include <nemu.h>

static uint32_t SBUF_SIZE = 0;
#define AUDIO_FREQ_ADDR (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR (AUDIO_ADDR + 0x14)

void __am_audio_init() {}

void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
  SBUF_SIZE = inl(AUDIO_SBUF_SIZE_ADDR);
  cfg->bufsize = SBUF_SIZE;
  cfg->present = false;
}

void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
  outl(AUDIO_FREQ_ADDR, ctrl->freq);
  outl(AUDIO_CHANNELS_ADDR, ctrl->channels);
  outl(AUDIO_SAMPLES_ADDR, ctrl->samples);
  outl(AUDIO_INIT_ADDR, 1);
}

void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  stat->count = inl(AUDIO_COUNT_ADDR);
}

void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
  uint32_t len = (uintptr_t)ctl->buf.end - (uintptr_t)ctl->buf.start;

  if (len == 0){
    printf("AM Audio: No data to play (len == 0)\n");
    return;
  }
  // 检查缓冲区状态 - 如果满了就直接返回，不等待
  uint32_t current_count = inl(AUDIO_COUNT_ADDR);
  uint32_t free_space = SBUF_SIZE - current_count;

//  printf("AM Audio: Request %u bytes, current_count=%u, free_space=%u, ""SBUF_SIZE=%u\n",len, current_count, free_space, SBUF_SIZE);

  if (free_space == 0) {
   // printf("AM Audio: Buffer full, dropping data\n");
    return; // 缓冲区满，直接丢弃数据
  }

  // 如果空间不够，只写入能写的部分
  if (len > free_space) {
   // printf("AM Audio: Truncating from %u to %u bytes\n", len, free_space);
    len = free_space;
  }

  // 额外的安全检查
  if (len > SBUF_SIZE) {
    //printf("AM Audio: len > SBUF_SIZE, setting len = SBUF_SIZE/4\n");
    len = SBUF_SIZE / 4;
  }

  static uint32_t write_offset = 0;
  uint8_t *src = (uint8_t *)ctl->buf.start;

  // 确保write_offset在有效范围内
  write_offset = write_offset % SBUF_SIZE;

  // 写入数据到循环缓冲区
  for (uint32_t i = 0; i < len; i++) {
    uint32_t offset = (write_offset + i) % SBUF_SIZE;
    outb(AUDIO_SBUF_ADDR + offset, src[i]);
  }

  write_offset = (write_offset + len) % SBUF_SIZE;

  // 一次性通知硬件写入的数据量
  outl(AUDIO_COUNT_ADDR, len);

  //printf("AM Audio: Successfully wrote %u bytes, write_offset=%u\n", len,write_offset);
}