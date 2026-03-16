#pragma once

#include "../InvadersController/invadersController.h"
#include "../BulletsController/bulletsController.h"
#include "../TimedBulletsController/timedBulletsController.h"
#include "../TexturesController/texturesController.h"
#include "../UIController/uiController.h"
#include "../Player/player.h"

class GameController{
	private:
	InvadersController invadersController;
	BulletsController bulletsPlayerController;
	TimedBulletsController bulletsInvaderController;
	TexturesController texturesController;
	UIController uiController;
	Player player;
	int score;
	
	public:
	GameController(float invadersMoveTimer, float invadersShootTimer, const char* playerPath, const char* bulletPath, const char* invaderPath, 
			float speed, int shootCountdown, Color color, int lives, float scorePosX, float scorePosY, float livesPosX, float livesPosY):
		invadersController{invadersMoveTimer},
		texturesController(playerPath, bulletPath, invaderPath),
		bulletsPlayerController{},
		player{speed, shootCountdown, texturesController.GetPlayerTexture(), color, lives},
		bulletsInvaderController{invadersShootTimer},
		uiController{scorePosX, scorePosY, livesPosX, livesPosY},
		score{0} {}
	
	void Start();
	void Update();
	void Render();
	void HandleInput();
	void RestartGame();
	void CheckCollisionsPlayerBulletsAndInvaders();
	void CheckCollisionsPlayerAndInvadersBullets();
		
	//Invaders
	void SpawnInvaders();
	void InvadersShoot();
	void CalculateBonus();

	//Player
	void SpawnPlayer();
	void PlayerShootInput();
};


