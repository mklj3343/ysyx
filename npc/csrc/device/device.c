#include<common.h>
#include<utils.h>
#ifndef CONFIG_TARGET_AM
#include <SDL2/SDL.h>
#endif
#define TIMER_HZ 60

void init_map();
void init_serial();
void init_timer();
void init_vga();
void init_i8042();

void vga_update_screen();
void send_key(uint8_t, bool);
void device_update() {

  static uint64_t last = 0; // 只初始化一次
  uint64_t now = get_time();
  if (now - last < 1000000 / TIMER_HZ) {
    return; // 限制更新频率
  }
  last = now;
  
  IFDEF(CONFIG_HAS_VGA, vga_update_screen());

#ifndef CONFIG_TARGET_AM
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    // 轮询 SDL 事件
    switch (event.type) {
    case SDL_QUIT:
      npc_state.state = NPC_QUIT;
      break;
#ifdef CONFIG_HAS_KEYBOARD
    // If a key was pressed
    case SDL_KEYDOWN:
    case SDL_KEYUP: {
      uint8_t k = event.key.keysym.scancode; // 获取键码
      bool is_keydown = (event.key.type == SDL_KEYDOWN);
      // printf("11111\n");
      send_key(k, is_keydown);
      break;
    }
#endif
    default:
      break;
    }
  }
#endif
}

void sdl_clear_event_queue() {
#ifndef CONFIG_TARGET_AM
  SDL_Event event;
  while (SDL_PollEvent(&event))
    ;
#endif
}

void init_device(){
    init_map();
    IFDEF(CONFIG_HAS_SERIAL, init_serial());
    IFDEF(CONFIG_HAS_TIMER, init_timer());
    IFDEF(CONFIG_HAS_VGA, init_vga());
    IFDEF(CONFIG_HAS_KEYBOARD, init_i8042());
}