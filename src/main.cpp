#include "Entity/entity.h"
#include "Other/constants.h"
#include "raylib.h"
#include "Player/player.h"
#include "Invader/invader.h"
#include "Bullet/bullet.h"
#include "InvadersController/invadersController.h"
#include "BulletsController/bulletsController.h"
#include "TimedBulletsController/timedBulletsController.h"
#include "TexturesController/texturesController.h"
#include <vector>

int main(void)
{
	const int screenWidth = WINDOW_WIDTH;
	const int screenHeight = WINDOW_HEIGHT;

	InitWindow(screenWidth, screenHeight, "Space Invaders");
	
	const char* playerPath  = "resources/player.png";
	const char* bulletPath = "resources/bullet.png";
	const char* invaderPath = "resources/invader.png";

	TexturesController texturesManagement(playerPath, bulletPath, invaderPath);	
	float playerWidth = texturesManagement.GetPlayerTextureWidth();	
	float playerHeight = texturesManagement.GetPlayerTextureHeight();
	float bulletWidth = texturesManagement.GetBulletTextureWidth();
	float bulletHeight = texturesManagement.GetBulletTextureHeight();
	float invaderWidth = texturesManagement.GetInvaderTextureWidth();
	float invaderHeight = texturesManagement.GetInvaderTextureHeight();

	Vector2 playerStartPos{
		(float)screenWidth/2 - playerWidth / 2, 
		(float)screenHeight - 150 - playerHeight / 2
	};

	Vector2 invaderStartPos{
		(float)screenWidth/2 -  playerWidth / 2, 
		(float)screenHeight/2 - playerHeight / 2
	};

	InvadersController invadersMng(true, 0.8f, false);
	BulletsController bulletsMng;
	TimedBulletsController bulletsInvadersMng(1.f);
	Player player(playerStartPos, 300.f, true, 1, texturesManagement.GetPlayerTexture(),BLUE,3);

	invadersMng.SpawnInvaders(invaderStartPos, texturesManagement.GetInvaderTexture(), 1);

	float secondsAfterShoot = 0;
	float secondsAfterMoved = 0;

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		float playerPosX = player.GetPositionX();
		float playerPosY = player.GetPositionY();

		if (IsKeyDown(KEY_RIGHT) && playerPosX < screenWidth - playerWidth) player.MoveRight();
		if (IsKeyDown(KEY_LEFT) && playerPosX > 0) player.MoveLeft(); 
		if (IsKeyDown(KEY_SPACE) && player.GetCanShoot()){
			float posX = playerPosX + player.GetWidth() / 2 - bulletWidth / 2;
			float posY = playerPosY - bulletHeight;
			Vector2 bulletStartPos{posX, posY};
			bulletsMng.SpawnBullet(bulletStartPos, 1000.f, texturesManagement.GetBulletTexture(), WHITE);
			player.SetCanShoot(false);
		}
		
		Vector2 invBulletPos = invadersMng.GetRandomInvaderBulletPos(bulletHeight);
		bulletsInvadersMng.SpawnBullet(invBulletPos, 1000.f, texturesManagement.GetBulletTexture(), YELLOW);
		
		player.UpdateCanShootState(secondsAfterShoot);
		bulletsInvadersMng.UpdateSecondsAfterShoot();
		bulletsInvadersMng.UpdateCanShootState();
		invadersMng.MoveInvaders(secondsAfterMoved, 3000.f, 200.f, invaderWidth);

		for(int i=0; i<bulletsInvadersMng.bullets.size(); i++){
			bulletsInvadersMng.ShootBulletDown(i);

			if(bool res = bulletsInvadersMng.HandleOutOfBounds(i); res)
				continue;
		}
		
		//Checks for collisions betwen invaders and player bullets
		for(int i=0; i<bulletsMng.bullets.size(); i++){
				float bulletPosX = bulletsMng.bullets[i].GetPositionX();

				bulletsMng.bullets[i].ShootUp();
				if(bool res = bulletsMng.HandleOutOfBounds(i); res)
					continue;

				for(int j=0; j<invadersMng.invaders.size(); j++){
					float invaderPosX = invadersMng.invaders[j].GetPositionX();
					if(CheckCollisionCircles(
						bulletsMng.bullets[i].GetPosition(),
						bulletWidth/2, 
						invadersMng.invaders[j].GetPosition(),
						invaderWidth/2	
					))
					{
						bulletsMng.RemoveBullet(i);
						invadersMng.RemoveInvader(j);
						break;
					}
				}

		}	

		BeginDrawing();
			invadersMng.DisplayInvaders();	
			bulletsMng.DisplayBullets();
			bulletsInvadersMng.DisplayBullets();
			player.DisplayEntity();
			ClearBackground(BLACK);
		EndDrawing();
	}
	
	CloseWindow();                
	return 0;
}
