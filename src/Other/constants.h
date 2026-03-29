#pragma once

#include <string>
#include <string_view>
#include "raylib.h"

const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;
const int INVADERS_X_SIZE = 10;
const int INVADERS_Y_SIZE = 5;
const std::string UI_SCORE_TEXT = "Score: ";
const std::string UI_LIVES_TEXT = "Lives: ";
const int PLAYER_LIVES = 3;
const int INVADERS_SPEED = 5000;
const int UFO_SPEED = 500;
const Color UFO_COLOR = RED;
const float DEATH_ANIMATION_TIME = 0.1;
const int BORDERS_GAP = 300;
const int UI_TEXT_SIZE = 75;
const Color INVADERS_COLOR = WHITE;
const Color BULLET_COLOR = WHITE;
const float UFO_STOP_TIMER = 10.f;
const int INVADER_SIZE = 40;
const int BULLET_WIDTH = 12;
const int BULLET_HEIGHT = 28;
