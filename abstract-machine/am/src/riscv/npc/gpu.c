#include <am.h>
#include <klib.h>
#include <npc.h>



void __am_gpu_init() {
  /*
   int i;
   uint32_t screen_info = inl(VGACTL_ADDR);
   int w = screen_info >> 16;
   int h = screen_info & 0xFFFF;
   uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
   for (i = 0; i < w * h; i ++) fb[i] = i;
   outl(SYNC_ADDR, 1);*/
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {

  uint32_t screen_info = inl(VGACTL_ADDR);
  uint32_t width = screen_info >> 16;
  uint32_t height = screen_info & 0xFFFF;
  *cfg = (AM_GPU_CONFIG_T){.present = false,
                           .has_accel = false,
                           .width = width,
                           .height = height,
                           .vmemsz = width * height * sizeof(uint32_t)};
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {

  static AM_GPU_FBDRAW_T static_ctl;

  static_ctl = *ctl;


  outl(VGACTL_ADDR + 8, (uintptr_t)&static_ctl);
}

void __am_gpu_tileblit(AM_GPU_TILEBLIT_T *ctl) {

  static AM_GPU_TILEBLIT_T static_ctl;
  static_ctl = *ctl;
  outl(VGACTL_ADDR + 12, (uintptr_t)&static_ctl);
}

void __am_gpu_status(AM_GPU_STATUS_T *status) { status->ready = true; }
