#include "Entity/entity.h"
#include "InvadersManagement/invadersManagement.h"
#include "raylib.h"
#include "TexturesManagement/texturesManagement.h"
#include "Player/player.h"
#include "Invader/invader.h"
#include "Bullet/bullet.h"
#include <vector>

int main(void)
{
	const int screenWidth = 1920;
	const int screenHeight = 1080;

	const int invadersMax = 55;

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

	Player player(playerStartPos, 300.f, true, 1, texturesManagement.GetPlayerTexture(),BLUE,3);
	InvadersManagement invaders(true, 1);

	invaders.SpawnInvaders(invaderStartPos, texturesManagement.GetInvaderTexture());

	std::vector<Bullet> bullets;

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
			Bullet bullet(bulletStartPos, 500.f, texturesManagement.GetBulletTexture(),WHITE,3);
			bullets.push_back(bullet);
			player.SetCanShoot(false);
		}

		invaders.MoveInvaders(secondsAfterMoved);

		BeginDrawing();
			
			invaders.DisplayInvaders();	
			
			//Checks for collisions betwen invaders and bullets
			for(int i=0; i<bullets.size(); i++){
				float bulletPosX = bullets[i].GetPositionX();

				bullets[i].Shoot();

				if(bullets[i].GetPositionY() <= 0){
					if(i == 0) bullets[i] = bullets.back();	
					bullets.pop_back();
					TraceLog(LOG_INFO, "Bullet Destroyed");
					continue;
				}
				else{
					bullets[i].DisplayEntity();


					/*for(int j=0; j<invaders.size(); j++){
						float invaderPosX = invaders[j].GetPositionX();
						
						//Cheks if it should check for collisions 
						//As it stands only makes sense to static obstacles, i need to change this to work to moving obstacles
						//Maybe i can create a formula to predict what the bullet hits according to the bullet and invaders speed
						if(bulletPosX + bulletWidth < invaderPosX 
								|| bulletPosX > invaderPosX + invaderWidth){
							TraceLog(LOG_INFO, "Bullet Ignored");
							continue;
						}

						if(CheckCollisionCircles(
							bullets[i].GetPosition(),
							texturesManagement.GetBulletTexture().height, 
							invaders[j].GetPosition(),
							invaderWidth	
						))
						{
							TraceLog(LOG_INFO, "Invader Killed");
							invaders[i] = invaders.back();
							invaders.pop_back();
							bullets.pop_back(); //need to check this
						}
					}*/
				}

			}

			player.DisplayEntity();

			ClearBackground(BLACK);

		EndDrawing();
		
		player.UpdateCanShootState(secondsAfterShoot);
	}
	
	CloseWindow();                
	return 0;
}
