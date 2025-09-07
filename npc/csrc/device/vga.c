
#include <common.h>
#include <device/map.h>

#define SCREEN_W (MUXDEF(CONFIG_VGA_SIZE_800x600, 800, 400))
#define SCREEN_H (MUXDEF(CONFIG_VGA_SIZE_800x600, 600, 300))

static uint32_t screen_width() {
  return MUXDEF(CONFIG_TARGET_AM, io_read(AM_GPU_CONFIG).width, SCREEN_W);
}

static uint32_t screen_height() {
  return MUXDEF(CONFIG_TARGET_AM, io_read(AM_GPU_CONFIG).height, SCREEN_H);
}

static uint32_t screen_size() {
  return screen_width() * screen_height() * sizeof(uint32_t);
}

static void *vmem = NULL;
static uint32_t *vgactl_port_base = NULL;

#ifdef CONFIG_VGA_SHOW_SCREEN
#ifndef CONFIG_TARGET_AM
#include <SDL2/SDL.h>

static SDL_Renderer *renderer = NULL;
static SDL_Texture *texture = NULL;

static void init_screen() {
  SDL_Window *window = NULL;
  char title[128];
  sprintf(title, "%s-NEMU", str(__GUEST_ISA__));
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(
      SCREEN_W * (MUXDEF(CONFIG_VGA_SIZE_400x300, 2, 1)),
      SCREEN_H * (MUXDEF(CONFIG_VGA_SIZE_400x300, 2, 1)), 0, &window,
      &renderer);
  SDL_SetWindowTitle(window, title);
  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                              SDL_TEXTUREACCESS_STATIC, SCREEN_W, SCREEN_H);
  SDL_RenderPresent(renderer);
}

static inline void update_screen() {
  SDL_UpdateTexture(texture, NULL, vmem, SCREEN_W * sizeof(uint32_t));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
}
#else
static void init_screen() {}

static inline void update_screen() {
  io_write(AM_GPU_FBDRAW, 0, 0, vmem, screen_width(), screen_height(), true);
}
#endif
#endif

void vga_update_screen() {
  // TODO: call `update_screen()` when the sync register is non-zero,
  // then zero out the sync register

  if (vgactl_port_base[1]) {
    update_screen();
    vgactl_port_base[1] = 0;
  }
}

typedef struct {
  int x, y;
  void *pixels;
  int w, h;
  bool sync;
} vga_blit_req_t;

word_t paddr_read(paddr_t addr, int len);
uint8_t *guest_to_host(paddr_t paddr);
static uint32_t *fbdraw_paddr_ptr = NULL;
static uint32_t *tileblit_paddr_ptr = NULL;

// FBDRAW 的处理函数：主要用于处理同步信号，或传统的 memcpy 绘图
static void vga_blit_handler(uint32_t offset, int len, bool is_write) {
  if (!is_write)
    return;
  uint32_t ctl_paddr = *fbdraw_paddr_ptr;

  // 手动解析 AM_GPU_FBDRAW_T 结构体
  int x = paddr_read(ctl_paddr + 0, 4);
  int y = paddr_read(ctl_paddr + 4, 4);
  uint32_t pixels = paddr_read(ctl_paddr + 8, 4);
  int w = paddr_read(ctl_paddr + 12, 4);
  int h = paddr_read(ctl_paddr + 16, 4);
  bool sync = paddr_read(ctl_paddr + 20, 1);

  // 如果有像素数据，则执行 memcpy
  if (pixels != 0 && w != 0 && h != 0) {
    uint32_t screen_w = screen_width();
    uint32_t *fb = (uint32_t *)vmem;
    uint32_t *pixels_haddr = (uint32_t *)guest_to_host(pixels);
    for (int j = 0; j < h; j++) {
      uint32_t *dest = &fb[(y + j) * screen_w + x];
      uint32_t *src = &pixels_haddr[j * w];
      memcpy(dest, src, w * sizeof(uint32_t));
    }
  }

  // 如果有同步标志，则设置同步位
  if (sync) {
    vgactl_port_base[1] = 1;
  }
}

// TILEBLIT 的处理函数：高性能的硬件加速器
static void vga_tileblit_handler(uint32_t offset, int len, bool is_write) {
  if (!is_write)
    return;
  uint32_t ctl_paddr = *tileblit_paddr_ptr;

  // 手动解析 AM_GPU_TILEBLIT_T 结构体
  int x0 = paddr_read(ctl_paddr + 0, 4);
  int y0 = paddr_read(ctl_paddr + 4, 4);
  uint32_t tiles_paddr = paddr_read(ctl_paddr + 8, 4);
  int w = paddr_read(ctl_paddr + 12, 4);
  int h = paddr_read(ctl_paddr + 16, 4);
  int tile_w = paddr_read(ctl_paddr + 20, 4);
  int tile_h = paddr_read(ctl_paddr + 24, 4);

  uint32_t *tiles = (uint32_t *)guest_to_host(tiles_paddr);
  uint32_t *fb = (uint32_t *)vmem;
  uint32_t screen_w = screen_width();

  // 在 Host 端高速执行像素填充
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      int canvas_x = x * tile_w / w;
      int canvas_y = y * tile_h / h;
      fb[(y0 + y) * screen_w + (x0 + x)] = tiles[canvas_y * tile_w + canvas_x];
    }
  }
}

void init_vga() {
  vgactl_port_base = (uint32_t *)new_space(8);
  vgactl_port_base[0] = (screen_width() << 16) | screen_height();

#ifdef CONFIG_HAS_PORT_IO
  add_pio_map("vgactl", CONFIG_VGA_CTL_PORT, vgactl_port_base, 8, NULL);
#else
  add_mmio_map("vgactl", CONFIG_VGA_CTL_MMIO, vgactl_port_base, 8, NULL);
#endif

  fbdraw_paddr_ptr = (uint32_t *)new_space(4);
  add_mmio_map("vga_blit", CONFIG_VGA_CTL_MMIO + 8, fbdraw_paddr_ptr, 4,
               vga_blit_handler);

  // 为 TILEBLIT 分配独立的 MMIO 端口和指针
  tileblit_paddr_ptr = (uint32_t *)new_space(4);
  add_mmio_map("vga_tileblit", CONFIG_VGA_CTL_MMIO + 12, tileblit_paddr_ptr, 4,
               vga_tileblit_handler);

  vmem = new_space(screen_size());
  add_mmio_map("vmem", CONFIG_FB_ADDR, vmem, screen_size(), NULL);
  IFDEF(CONFIG_VGA_SHOW_SCREEN, init_screen());
  IFDEF(CONFIG_VGA_SHOW_SCREEN, memset(vmem, 0, screen_size()));
}
