#pragma once

#include "../InvadersController/invadersController.h"
#include "../BulletsController/bulletsController.h"
#include "../TimedBulletsController/timedBulletsController.h"
#include "../TexturesController/texturesController.h"
#include "../Player/player.h"

class GameController{
	private:
	InvadersController invadersController;
	BulletsController bulletsPlayerController;
	TimedBulletsController bulletsInvaderController;
	TexturesController texturesController;
	Player player;
	
	public:
	GameController(float invadersMoveTimer, float invadersShootTimer, const char* playerPath, const char* bulletPath, const char* invaderPath, 
			float speed, int shootCountdown, Color color, int lives):
		invadersController{invadersMoveTimer},
		texturesController(playerPath, bulletPath, invaderPath),
		bulletsPlayerController{},
		player{speed, shootCountdown, texturesController.GetPlayerTexture(), color, lives},
		bulletsInvaderController{invadersShootTimer} {}
	
	void Start();
	void Update();
	void Render();
	void HandleInput();
	void CheckPlayerBulletsInvadersCollisions();
	
	//Invaders
	void SpawnInvaders();
	void InvadersShoot();

	//Player
	void SpawnPlayer();
	void PlayerShootInput();
};


