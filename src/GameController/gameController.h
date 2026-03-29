#pragma once

#include "../InvadersController/invadersController.h"
#include "../BulletsController/bulletsController.h"
#include "../TimedBulletsController/timedBulletsController.h"
#include "../TexturesController/texturesController.h"
#include "../UIController/uiController.h"
#include "../SoundController/soundController.h"
#include "../Ufo/ufo.h"

#include "../Player/player.h"

class GameController{
	private:
	InvadersController invadersController;
	BulletsController bulletsPlayerController;
	TimedBulletsController bulletsInvaderController;
	TimedBulletsController bulletsUfoController;
	TexturesController texturesController;
	UIController uiController;
	SoundController soundController;
	Player player;
	Ufo ufo;
	int score;
	
	public:
	GameController(float invadersMoveTimer,float invadersShootTimer, float speed, float shootCountdown, 
			Color color, int lives, float scorePosX, float scorePosY, float livesPosX, float livesPosY):
		invadersController{invadersMoveTimer},
		texturesController{},
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
	void CheckCollisionsPlayerBulletsAndUfo();
	void CheckCollisionsPlayerAndInvadersBullets();
	void CheckCollisionsPlayerAndInvaders();
	void CheckCollisionsPlayerAndUfoBullets();

	void RefreshUI();
		
	//Invaders
	void SpawnInvaders();
	void SpawnUfo();
	void InvadersShoot();
	void UfoShoot();
	void CalculateBonus();

	//Player
	void SpawnPlayer();
	void PlayerShootInput();
	void HandlePlayerDamage();
};


