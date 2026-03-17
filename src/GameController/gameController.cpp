#include "gameController.h"
#include "../Other/constants.h"
#include <raylib.h>
#include <string>

void GameController::Start(){
	SpawnInvaders();
	SpawnPlayer();
}

void GameController::Update(){
	player.UpdateCanShootState();
	bulletsInvaderController.UpdateCanShootState();

	invadersController.MoveInvaders(INVADERS_SPEED, BORDERS_GAP, texturesController.GetInvaderWidth());
	
	InvadersShoot();
	bulletsPlayerController.ShootBulletsUp();

	CheckCollisionsPlayerBulletsAndInvaders();
	CheckCollisionsPlayerAndInvadersBullets();
	CheckCollisionsPlayerAndInvaders();
	RefreshUI();
}

void GameController::Render(){
	invadersController.DisplayInvaders();	
	bulletsInvaderController.DisplayBullets();
	bulletsPlayerController.DisplayBullets();
	player.DisplayEntity();
	uiController.DisplayUI(UI_TEXT_SIZE);
}

void GameController::HandleInput(){
	float playerPosX = player.GetPositionX();
	float playerPosY = player.GetPositionY();

	if (IsKeyDown(KEY_RIGHT) && playerPosX < WINDOW_WIDTH - texturesController.GetPlayerWidth() - BORDERS_GAP) player.MoveRight();
	if (IsKeyDown(KEY_LEFT) && playerPosX > 0 + BORDERS_GAP) player.MoveLeft(); 
	if (IsKeyDown(KEY_SPACE) && player.GetCanShoot()) PlayerShootInput();
}

void GameController::RefreshUI(){
	uiController.SetScoreText(UI_SCORE_TEXT + std::to_string(score));
	uiController.SetLivesText(UI_LIVES_TEXT + std::to_string(player.GetLives()));
}

void GameController::RestartGame(){
	invadersController.ResetInvaders();
	player.ResetPlayer(PLAYER_LIVES);
	score = 0;
	Start();
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
				score += invadersController.CalculateInvaderBonus(j);
				soundController.PlayInvaderDeathSound();
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
			int lives = player.DecrementLives();
			if(lives == 0) RestartGame();
			soundController.PlayPlayerDeathSound();
		}
	}
}

void GameController::CheckCollisionsPlayerAndInvaders(){
	std::vector<Invader> invaders = invadersController.GetInvaders();
	Vector2 playerPos{
		player.GetPositionX() + (float)texturesController.GetPlayerWidth() / 2,
		player.GetPositionY() + (float)texturesController.GetPlayerHeight() / 2
	};
	for(int i=0; i<invaders.size(); i++){
		Vector2 invaderPos{
			invaders[i].GetPositionX() + (float)texturesController.GetInvaderWidth() / 2,
			invaders[i].GetPositionY() + (float)texturesController.GetInvaderHeight() / 2
		};
		if(CheckCollisionCircles(
			playerPos, 
			(float)texturesController.GetPlayerWidth()/2, 
			invaderPos, 
			(float)texturesController.GetInvaderWidth())){
			soundController.PlayPlayerDeathSound();
			RestartGame();
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
		(float)WINDOW_WIDTH/2 - texturesController.GetInvaderWidth() * INVADERS_X_SIZE,  
		(float)WINDOW_HEIGHT/2 - 80
	};
	invadersController.SpawnInvaders(invaderStartPos, texturesController.GetInvaderTexture(), 1, INVADERS_COLOR);
}

void GameController::PlayerShootInput(){
	float posX = player.GetPositionX() + player.GetWidth() / 2 - (float)texturesController.GetBulletWidth() / 2;
	float posY = player.GetPositionY() - texturesController.GetBulletHeight();
	Vector2 bulletStartPos{posX, posY};
	bulletsPlayerController.SpawnBullet(bulletStartPos, 1000.f, texturesController.GetBulletTexture(), WHITE);
	player.SetCanShoot(false);
	soundController.PlayBulletSound();
}

void GameController::InvadersShoot(){
	Vector2 invBulletPos = invadersController.GetRandomInvaderBulletPos(texturesController.GetBulletHeight());
	bulletsInvaderController.SpawnBullet(invBulletPos, 1000.f, texturesController.GetBulletTexture(), YELLOW);
	bulletsInvaderController.ShootBulletsDown();
}

