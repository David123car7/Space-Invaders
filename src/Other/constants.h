#pragma once

#include "raylib.h"
#include <string>
#include <string_view>

namespace Constants {
inline constexpr int WINDOW_WIDTH = 1920;
inline constexpr int WINDOW_HEIGHT = 1080;
inline const int INVADERS_X_SIZE = 10;
inline const int INVADERS_Y_SIZE = 5;
inline const std::string UI_SCORE_TEXT = "Score: ";
inline const std::string UI_LIVES_TEXT = "Lives: ";
inline const int PLAYER_LIVES = 3;
inline const int INVADERS_SPEED = 5000;
inline const int UFO_SPEED = 500;
inline const Color UFO_COLOR = RED;
inline const float DEATH_ANIMATION_TIME = 0.1;
inline const int BORDERS_GAP = 300;
inline const int UI_TEXT_SIZE = 75;
inline const Color INVADERS_COLOR = WHITE;
inline const Color BULLET_COLOR = WHITE;
inline const float UFO_STOP_TIMER = 10.f;
inline const int INVADER_SIZE = 40;
inline const int BULLET_WIDTH = 12;
inline const int BULLET_HEIGHT = 28;
} // namespace Constants
