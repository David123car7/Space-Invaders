#pragma once

#include "../Invader/invader.h"
#include "../Other/constants.h"
#include <vector>

class InvadersController{
	private:
	std::vector<Invader> invaders;	
	bool canMove;
	float secondsAfterMoved;
	float moveCountdown;
	bool hitLeft; 
	float leftCorner;
	float rightCorner;

	public:
	InvadersController(float moveCountdown):
		canMove{true},
		secondsAfterMoved{0.f},
		moveCountdown{moveCountdown},
		hitLeft{false},
		leftCorner{0.f},
		rightCorner{0.f} {}
	
	std::vector<Invader>& GetInvaders() {return invaders;}
	void DisplayInvaders();
	void SpawnInvaders(Vector2 startPos, Texture2D texture, float shootCountdown);
	void ResetInvaders();
	bool RemoveInvader(unsigned int pos);
	int CalculateInvaderBonus(unsigned int pos);
	void UpdateCanMoveState(); //function to be used on the game loop
	
	/**
	 * @brief Handles invaders movement  
	 *
	 * @param[[TODO:direction]] seconds Seconds 
	 * @param[[TODO:direction]] bordersGap Gap between the screen borders 
	 * @param[[TODO:direction]] invaderWidth Width of the invaders texture
	 */
	void MoveInvaders(float speed, float bordersGap, float invaderWidth);
	Vector2 GetRandomInvaderBulletPos(float bulletHeight);
};
