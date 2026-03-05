#include "Entity/entity.h"
#include "raylib.h"
#include "TexturesManagement/texturesManagement.h"
#include "Player/player.h"
#include "Bullet/bullet.h"
#include <vector>

int main(void)
{
	const int screenWidth = 1280;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "Space Invaders");
	
	const char* playerPath  = "resources/player.png";
	const char* bulletPath = "resources/bullet.png";
	TexturesManagement texturesManagement(playerPath, bulletPath);	
	
	Vector2 playerPos{(float)screenWidth/2, (float)screenHeight/2};
	Player player(playerPos, 300.f, true, 1, texturesManagement.GetPlayerTexture(),BLUE,3);
	std::vector<Bullet> bullets;

	float secondsAfterShoot = 0;

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		float playerPosX = player.GetPositionX();
		float playerPosY = player.GetPositionY();

		if (IsKeyDown(KEY_RIGHT) && playerPosX < screenWidth - texturesManagement.GetPlayerTexture().width) player.MoveRight();
		if (IsKeyDown(KEY_LEFT) && playerPosX > 0) player.MoveLeft(); 
		if (IsKeyDown(KEY_SPACE) && player.GetCanShoot()){
			float posX = playerPosX + player.GetWidth() / 2 - (float)texturesManagement.GetBulletTexture().width / 2;
			float posY = playerPosY - (float)texturesManagement.GetBulletTexture().height;
			Vector2 bulletStartPos{posX, posY};
			Bullet bullet(bulletStartPos, 500.f, texturesManagement.GetBulletTexture(),WHITE,3);
			bullets.push_back(bullet);
			player.SetCanShoot(false);
		}
	
		BeginDrawing();

			for(int i=0; i<bullets.size(); i++){
				if(bullets[i].GetPositionY() <= 0){
					if(i == 0) bullets[i] = bullets.back();	
					bullets.pop_back();
					continue;
				}
				else
					bullets[i].DisplayEntity();

				bullets[i].Shoot();
			}

			player.DisplayEntity();

			ClearBackground(BLACK);

		EndDrawing();
		
		player.UpdateCanShootState(secondsAfterShoot);
	}
	
	CloseWindow();                // Close window and OpenGL context
	return 0;
}
