#include "Entity/entity.h"
#include "Other/constants.h"
#include "raylib.h"
#include "Player/player.h"
#include "Invader/invader.h"
#include "Bullet/bullet.h"
#include "InvadersManagement/invadersManagement.h"
#include "BulletsManagement/bulletsManagement.h"
#include "TexturesManagement/texturesManagement.h"
#include <vector>

int main(void)
{
	const int screenWidth = WINDOW_WIDTH;
	const int screenHeight = WINDOW_HEIGHT;

	InitWindow(screenWidth, screenHeight, "Space Invaders");
	
	const char* playerPath  = "resources/player.png";
	const char* bulletPath = "resources/bullet.png";
	const char* invaderPath = "resources/invader.png";

	TexturesManagement texturesManagement(playerPath, bulletPath, invaderPath);	
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

	InvadersManagement invadersMng(true, 0, false);
	BulletsManagement bulletsMng;
	Player player(playerStartPos, 300.f, true, 1, texturesManagement.GetPlayerTexture(),BLUE,3);

	invadersMng.SpawnInvaders(invaderStartPos, texturesManagement.GetInvaderTexture());

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
			Bullet bullet(bulletStartPos, 800.f, texturesManagement.GetBulletTexture(),WHITE,3);
			bulletsMng.AddBullet(bullet);
			player.SetCanShoot(false);
		}
		
		player.UpdateCanShootState(secondsAfterShoot);
		invadersMng.MoveInvaders(secondsAfterMoved);
		
		//Removes the bullets when they go out of the game window
		for(int i=0; i<bulletsMng.bullets.size(); i++){
				float bulletPosX = bulletsMng.bullets[i].GetPositionX();

				bulletsMng.bullets[i].Shoot();
				if(bulletsMng.bullets[i].GetPositionY() <= 0){
					bulletsMng.RemoveBullet(i);
					TraceLog(LOG_INFO, "Bullet Destroyed");
					continue;
				}

				for(int j=0; j<INVADERS_X_SIZE; j++){
					bool bulletCollision = false;
					for(int k=0; k<INVADERS_Y_SIZE; k++){
						if(!invadersMng.invaders[j][k].GetIsAlive())		
							continue;	

						float invaderPosX = invadersMng.invaders[j][k].GetPositionX();
						
						//Cheks if it should check for collisions 
						//As it stands only makes sense to static obstacles, i need to change this to work to moving obstacles
						//Maybe i can create a formula to predict what the bullet hits according to the bullet and invaders speed
						/*if(bulletPosX + bulletWidth < invaderPosX 
								|| bulletPosX > invaderPosX + invaderWidth){
							TraceLog(LOG_INFO, "Bullet Ignored");
							continue;
						}*/

						if(CheckCollisionCircles(
							bulletsMng.bullets[i].GetPosition(),
							texturesManagement.GetBulletTexture().width/2, 
							invadersMng.invaders[j][k].GetPosition(),
							invaderWidth/2	
						))
						{
							TraceLog(LOG_INFO, "Invader Killed");
							bulletsMng.RemoveBullet(i);
							bulletCollision = true;
							invadersMng.invaders[j][k].SetIsAlive(false);
							break;
						}
					}
					if(bulletCollision) break;
				}

		}	

		BeginDrawing();
			
			invadersMng.DisplayInvaders();	
			bulletsMng.DisplayBullets();
			player.DisplayEntity();
			
			ClearBackground(BLACK);

		EndDrawing();
	}
	
	CloseWindow();                
	return 0;
}
