#pragma once

#include "../Invader/invader.h"
#include "../Other/constants.h"
#include <vector>

class InvadersManagement{
	public:
	std::vector<Invader> invaders;	
	bool canMove;
	float moveCountdown;
	bool hitLeft; 
	float leftCorner;
	float rightCorner;
	
	InvadersManagement(bool canMove, float moveCountdown, bool hitLeft):
		canMove{canMove},
		moveCountdown{moveCountdown},
		hitLeft{hitLeft},
		leftCorner{0.f},
		rightCorner{0.f} {}

	void DisplayInvaders();
	void SpawnInvaders(Vector2 startPos, Texture2D texture, float shootCountdown);
	bool RemoveInvader(unsigned int pos);
	void UpdateCanMoveState(float& seconds); //function to be used on the game loop
	
	/**
	 * @brief Handles invaders movement  
	 *
	 * @param[[TODO:direction]] seconds Seconds 
	 * @param[[TODO:direction]] bordersGap Gap between the screen borders 
	 * @param[[TODO:direction]] invaderWidth Width of the invaders texture
	 */
	void MoveInvaders(float& seconds, float speed, float bordersGap, float invaderWidth);
	Vector2 GetRandomInvaderBulletPos(float bulletHeight);
	
};
