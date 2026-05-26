#include "action.hpp"
#include "raylib.h"
#include "input.hpp"

void KeyboardInput::RegisterInputAction(ACTION &action) const {
  if (IsKeyDown(KEY_A) || IsKeyDown(KEY_H) || IsKeyDown(KEY_LEFT)) {
    action = ACTION::MOVE_LEFT;
  }

  if (IsKeyDown(KEY_D) || IsKeyDown(KEY_L) || IsKeyDown(KEY_RIGHT)) {
    action = ACTION::MOVE_RIGHT;
  }

  if (IsKeyDown(KEY_S) || IsKeyDown(KEY_J) || IsKeyDown(KEY_DOWN)) {
    action = ACTION::MOVE_DOWN;
  }

  if (IsKeyPressed(KEY_SPACE)) {
    action = ACTION::FREE_FALL;
  }

  if (IsKeyPressed(KEY_Z)) {
    action = ACTION::ROTATE_CLOCKWISE;
  }

  if (IsKeyPressed(KEY_X)) {
    action = ACTION::ROTATE_COUNTERCLOCKWISE;
  }
};
