#include "gameController.h"
#include "../Other/constants.h"
#include <raylib.h>
#include <string>

void GameController::Start(){
	SpawnInvaders();
	SpawnPlayer();
	SpawnUfo();
}

void GameController::Update(){
	player.UpdateCanShootState();
	bulletsInvaderController.UpdateCanShootState();
	bulletsUfoController.UpdateCanShootState();

	invadersController.MoveInvaders(INVADERS_SPEED, BORDERS_GAP, INVADER_SIZE);
	ufo.MoveUfo(UFO_SPEED);
	
	invadersController.HandleAnimations(
			texturesController.GetInvaderTextureA0(), 
			texturesController.GetInvaderTextureB0(),
			texturesController.GetInvaderTextureC0(),
			texturesController.GetInvaderTextureA1(),
			texturesController.GetInvaderTextureB1(),
			texturesController.GetInvaderTextureC1()
	);

	invadersController.HandleInvaderDeath();
	if(ufo.HandleDeath()){
		SpawnUfo();
	}

	InvadersShoot();
	UfoShoot();
	bulletsPlayerController.ShootBulletsUp();
	bulletsInvaderController.ShootBulletsDown();
	bulletsUfoController.ShootBulletsDown();

	CheckCollisionsPlayerBulletsAndInvaders();
	CheckCollisionsPlayerAndInvadersBullets();
	CheckCollisionsPlayerAndInvaders();
	CheckCollisionsPlayerBulletsAndUfo();
	RefreshUI();
}

void GameController::Render(){
	invadersController.DisplayInvaders();	
	bulletsInvaderController.DisplayBullets();
	bulletsPlayerController.DisplayBullets();
	ufo.DisplayEntity();
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
				(float)BULLET_WIDTH/2, 
				invaders[j].GetPosition(),
				(float)BULLET_HEIGHT/2	
			))
			{
				bulletsPlayerController.RemoveBullet(i);
				invadersController.KillInvader(j, texturesController.GetInvaderExplosionTexture());
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
			(float)BULLET_WIDTH / 2, 
			player.GetPosition(),
			(float)texturesController.GetPlayerWidth()/2	
		))
		{
			bulletsInvaderController.RemoveBullet(i);
			HandlePlayerDamage();
		}
	}
}

void GameController::CheckCollisionsPlayerAndUfoBullets(){
	std::vector<Bullet> bullets = bulletsUfoController.GetBullets();

	for(int i=0; i<bullets.size(); i++){
		if(CheckCollisionCircles(
			bullets[i].GetPosition(),
			(float)BULLET_WIDTH / 2, 
			player.GetPosition(),
			(float)texturesController.GetPlayerWidth()/2	
		))
		{
			bulletsInvaderController.RemoveBullet(i);
			HandlePlayerDamage();
		}
	}
}

void GameController::CheckCollisionsPlayerBulletsAndUfo(){
	std::vector<Bullet> bullets = bulletsPlayerController.GetBullets();

	for(int i=0; i<bullets.size(); i++){
		if(CheckCollisionCircles(
			bullets[i].GetPosition(),
			(float)BULLET_WIDTH / 2, 
			ufo.GetPosition(),
			(float)texturesController.GetUfoWidth()/2	
		))
		{
			bulletsUfoController.RemoveBullet(i);
			ufo.KillUfo(texturesController.GetInvaderExplosionTexture());
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
			invaders[i].GetPositionX() + (float)INVADER_SIZE / 2,
			invaders[i].GetPositionY() + (float)INVADER_SIZE / 2
		};
		if(CheckCollisionCircles(
			playerPos, 
			(float)texturesController.GetPlayerWidth()/2, 
			invaderPos, 
			INVADER_SIZE)){
			soundController.PlayPlayerDeathSound();
			RestartGame();
		}
	}
}

void GameController::HandlePlayerDamage(){
	int lives = player.DecrementLives();
	if(lives == 0) RestartGame();
	soundController.PlayPlayerDeathSound();
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
		(float)WINDOW_WIDTH/2 - INVADER_SIZE * INVADERS_X_SIZE,  
		(float)WINDOW_HEIGHT/2 - 80
	};
	invadersController.SpawnInvaders(invaderStartPos, texturesController.GetInvaderTextureA0(), 
			texturesController.GetInvaderTextureB0(), texturesController.GetInvaderTextureC0(),
			1, INVADERS_COLOR, DEATH_ANIMATION_TIME);
}

void GameController::SpawnUfo(){
	Vector2 startPos = {-300, 150};
	ufo = {startPos, texturesController.GetUfoTexture(), UFO_COLOR, UFO_STOP_TIMER, true, false};
}

void GameController::PlayerShootInput(){
	float posX = player.GetPositionX() + player.GetWidth() / 2 - (float)BULLET_WIDTH / 2;
	float posY = player.GetPositionY() - texturesController.GetBulletHeight();
	Vector2 bulletStartPos{posX, posY};
	bulletsPlayerController.SpawnBullet(bulletStartPos, 1000.f, texturesController.GetBulletTexture(), BULLET_COLOR);
	player.SetCanShoot(false);
	soundController.PlayBulletSound();
}

void GameController::InvadersShoot(){
	if(!bulletsInvaderController.GetCanShoot()) return;
	Vector2 invBulletPos = invadersController.GetRandomInvaderBulletVector(texturesController.GetBulletHeight());
	bulletsInvaderController.SpawnBullet(invBulletPos, 1000.f, texturesController.GetBulletTexture(), BULLET_COLOR);
}

void GameController::UfoShoot(){
	if(!bulletsUfoController.GetCanShoot()) return;
	Vector2 ufoBulletPos = ufo.GetBulletPosition(texturesController.GetBulletHeight());
	bulletsInvaderController.SpawnBullet(ufoBulletPos, 1000.f, texturesController.GetBulletTexture(), BULLET_COLOR);
}


