#include <raylib.h>
#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include <array>
#include <iostream>
#include <memory>
#include <string>

#include "game.hpp"
#include "input.hpp"
#include "size.hpp"

Game* g_game = nullptr;

int main() {
  constexpr Size grid_size = {
      .w = 10,
      .h = 20,
  };
  constexpr int cell_size_px = 40;
  constexpr Size window_size = {
      .w = grid_size.w * cell_size_px,
      .h = grid_size.h * cell_size_px,
  };

  std::string window_title = "Tetris";

  InitWindow(window_size.w, window_size.h, window_title.c_str());

  std::cout << "Starting Tetris." << "\n";

  constexpr int target_fps = 60;
  const std::unique_ptr<Input> input = std::make_unique<KeyboardInput>();
  Game game(grid_size, cell_size_px, *input);

  g_game = &game;

  // game loop
#if defined(PLATFORM_WEB)
  emscripten_set_main_loop([]() { g_game->OnUpdate(); }, 0, 1);
#else
  SetTargetFPS(target_fps);
  // Main game loop
  while (!WindowShouldClose())  // Detect window close
                                // button or ESC key
  {
    g_game->OnUpdate();
  }
#endif
  CloseWindow();

  return 0;
}
