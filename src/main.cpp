#include "GameController/gameController.h"
#include "Other/constants.h"
#include "raylib.h"

int main(void) {
  const int screenWidth = Constants::WINDOW_WIDTH;
  const int screenHeight = Constants::WINDOW_HEIGHT;

  InitWindow(screenWidth, screenHeight, "Space Invaders");
  InitAudioDevice();

  GameController gameController(1.5f, 1.f, 1000.f, 0.4, BLUE,
                                Constants::PLAYER_LIVES, 50, 50,
                                Constants::WINDOW_WIDTH - 450, 50);

  gameController.Start();

  SetTargetFPS(60);
  while (!WindowShouldClose()) {

    gameController.HandleInput();
    gameController.Update();

    BeginDrawing();
    gameController.Render();
    ClearBackground(BLACK);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
