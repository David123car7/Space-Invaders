#pragma once

#include "../Invader/invader.h"
#include "../Other/constants.h"

class InvadersManagement{
	public:
	Invader invaders[INVADERS_X_SIZE][INVADERS_Y_SIZE];
	bool canMove;
	float moveCountdown;
	
	InvadersManagement(bool canMove, float moveCountdown):
		canMove{canMove},
		moveCountdown{moveCountdown} {}

	void DisplayInvaders();
	void SpawnInvaders(Vector2 startPos, Texture2D texture);
	void UpdateCanMoveState(float& seconds); //function to be used on the game loop
	void MoveInvaders(float& seconds);
};
