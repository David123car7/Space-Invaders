#include "Other/constants.h"
#include "raylib.h"
#include "GameController/gameController.h"

int main(void)
{
	const int screenWidth = WINDOW_WIDTH;
	const int screenHeight = WINDOW_HEIGHT;

	InitWindow(screenWidth, screenHeight, "Space Invaders");
	
	const char* playerPath  = "resources/player.png";
	const char* bulletPath = "resources/bullet.png";
	const char* invaderPath = "resources/invader.png";

	GameController gameController(1.f, 1.f, playerPath, bulletPath, invaderPath, 1000.f, 0.5, BLUE, PLAYER_LIVES, 50, 50, WINDOW_WIDTH - 450, 50);

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
