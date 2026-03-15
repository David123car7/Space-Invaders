#include "gameController.h"
#include "../Other/constants.h"
#include <string>

void GameController::Start(){
	SpawnInvaders();
	SpawnPlayer();
	uiController.SetScoreText(UI_SCORE_TEXT + std::to_string(score));
	uiController.SetLivesText(UI_LIVES_TEXT + std::to_string(player.GetLives()));
}

void GameController::Update(){
	player.UpdateCanShootState();
	bulletsInvaderController.UpdateCanShootState();

	invadersController.MoveInvaders(3000.f, 200.f, texturesController.GetInvaderWidth());
	
	InvadersShoot();
	bulletsPlayerController.ShootBulletsUp();

	CheckCollisionsPlayerBulletsAndInvaders();
	CheckCollisionsPlayerAndInvadersBullets();
}

void GameController::Render(){
	invadersController.DisplayInvaders();	
	bulletsInvaderController.DisplayBullets();
	bulletsPlayerController.DisplayBullets();
	player.DisplayEntity();
	uiController.DisplayUI();
}

void GameController::HandleInput(){
	float playerPosX = player.GetPositionX();
	float playerPosY = player.GetPositionY();

	if (IsKeyDown(KEY_RIGHT) && playerPosX < WINDOW_WIDTH - texturesController.GetPlayerWidth()) player.MoveRight();
	if (IsKeyDown(KEY_LEFT) && playerPosX > 0) player.MoveLeft(); 
	if (IsKeyDown(KEY_SPACE) && player.GetCanShoot()) PlayerShootInput();
}

void GameController::CheckCollisionsPlayerBulletsAndInvaders(){
	std::vector<Bullet> bullets = bulletsPlayerController.GetBullets();
	std::vector<Invader> invaders = invadersController.GetInvaders();
	for(int i=0; i<bullets.size(); i++){
		for(int j=0; j<invaders.size(); j++){
			float invaderPosX = invaders[j].GetPositionX();
			if(CheckCollisionCircles(
				bullets[i].GetPosition(),
				(float)texturesController.GetBulletWidth()/2, 
				invaders[j].GetPosition(),
				(float)texturesController.GetInvaderWidth()/2	
			))
			{
				bulletsPlayerController.RemoveBullet(i);
				invadersController.RemoveInvader(j);
				score++;
				uiController.SetScoreText(UI_SCORE_TEXT + std::to_string(score));
				break;
			}
		}
	}
}

void GameController::CheckCollisionsPlayerAndInvadersBullets(){
	std::vector<Bullet> bullets = bulletsInvaderController.GetBullets();

	for(int i=0; i<bullets.size(); i++){
		if(CheckCollisionCircles(
			bullets[i].GetPosition(),
			(float)texturesController.GetBulletWidth()/2, 
			player.GetPosition(),
			(float)texturesController.GetPlayerWidth()/2	
		))
		{
			bulletsInvaderController.RemoveBullet(i);
			break;
		}
	}
}

void GameController::SpawnPlayer(){
	Vector2 playerStartPos{
		(float)WINDOW_WIDTH/2 - (float)texturesController.GetPlayerWidth() / 2, 
		(float)WINDOW_HEIGHT - 150 - (float)texturesController.GetPlayerWidth() / 2
	};
	player.SetPosition(playerStartPos);
}

void GameController::SpawnInvaders(){
	Vector2 invaderStartPos{
		(float)WINDOW_WIDTH/2 -  (float)texturesController.GetPlayerWidth() / 2, 
		(float)WINDOW_HEIGHT/2 - (float)texturesController.GetPlayerWidth() / 2
	};
	invadersController.SpawnInvaders(invaderStartPos, texturesController.GetInvaderTexture(), 1);
}

void GameController::PlayerShootInput(){
	float posX = player.GetPositionX() + player.GetWidth() / 2 - (float)texturesController.GetBulletWidth() / 2;
	float posY = player.GetPositionY() - texturesController.GetBulletHeight();
	Vector2 bulletStartPos{posX, posY};
	bulletsPlayerController.SpawnBullet(bulletStartPos, 1000.f, texturesController.GetBulletTexture(), WHITE);
	player.SetCanShoot(false);
}

void GameController::InvadersShoot(){
	Vector2 invBulletPos = invadersController.GetRandomInvaderBulletPos(texturesController.GetBulletHeight());
	bulletsInvaderController.SpawnBullet(invBulletPos, 1000.f, texturesController.GetBulletTexture(), YELLOW);
	bulletsInvaderController.ShootBulletsDown();
}


