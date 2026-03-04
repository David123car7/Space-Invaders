#include "Entity/entity.h"
#include "raylib.h"
#include "Player/player.h"
#include "Bullet/bullet.h"

int main(void)
{
	const int screenWidth = 1920;
	const int screenHeight = 1080;

	InitWindow(screenWidth, screenHeight, "Space Invaders");
	
	const char* texturePath = "resources/player.png";
	const char* bulletPath = "resources/bullet.png";
	Player player(150.f, screenWidth, screenHeight, texturePath,RED,3);

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

	// Main game lookp
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();

		if (IsKeyDown(KEY_RIGHT)) player.MoveRight();
		if (IsKeyDown(KEY_LEFT)) player.MoveLeft(); 
		if (IsKeyDown(KEY_SPACE)){
			Bullet bullet(150.f, screenWidth, screenHeight, bulletPath,BLACK,3);
			bullet.LoadEntity();
		}
		
			player.LoadEntity();
			ClearBackground(RAYWHITE);

		EndDrawing();
	}
	
	player.UnloadEntity();
	CloseWindow();                // Close window and OpenGL context
	return 0;
}
