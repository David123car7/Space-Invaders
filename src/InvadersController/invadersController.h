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
	bool canMoveDown;
	float leftCorner;
	float rightCorner;

	public:
	InvadersController(float moveCountdown):
		canMove{true},
		secondsAfterMoved{0.f},
		moveCountdown{moveCountdown},
		canMoveDown{false},
		hitLeft{false},
		leftCorner{0.f},
		rightCorner{0.f} {}
	
	std::vector<Invader>& GetInvaders() {return invaders;}
	void DisplayInvaders();
	void SpawnInvaders(Vector2 startPos, Texture2D textureA0, Texture2D textureB0, Texture2D textureC0,  float shootCountdown, Color color);
	void HandleAnimations(Texture2D textureA0, Texture2D textureB0, Texture2D textureC0, Texture2D textureA1, Texture2D textureB1, Texture2D textureC1);
	void ResetInvaders();
	bool RemoveInvader(unsigned int pos);
	int CalculateInvaderBonus(unsigned int pos);
	int GetInvaderRow(unsigned int pos);
	void UpdateCanMoveState(); //function to be used on the game loop
	
	/**
	 * @brief Handles invaders movement  
	 *
	 * @param[[TODO:direction]] seconds Seconds 
	 * @param[[TODO:direction]] bordersGap Gap between the screen borders 
	 * @param[[TODO:direction]] invaderWidth Width of the invaders texture
	 */
	void MoveInvaders(int speed, int bordersGap, float invaderWidth);
	void MoveAllInvadersLeft(float speed);
	void MoveAllInvadersRight(float speed);
	void MoveAllInvadersDown(float speed);
	Vector2 GetRandomInvaderBulletVector(float bulletHeight);
};
