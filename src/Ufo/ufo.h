#pragma once

#include "raylib.h"
#include "../Invader/invader.h"

class Ufo: public Invader{
	private:
	bool canMove;
	bool isOnLeft;
	bool isOnRight;
	bool isHidden;
	float stopTimer;
	float secondsAfterStop;

	public:
	Ufo():
		Invader{},
		canMove{false},
		isOnLeft{false},
		isOnRight{false},
		isHidden{false},
		stopTimer{0.f},
		secondsAfterStop{0.f} {}

	Ufo(Vector2 position, Texture2D texture, Color color, float stopTimer,
			bool isOnLeft, bool canMove):
		Invader(position, texture, color),
		canMove{canMove},
		isOnRight{!isOnLeft},
		isOnLeft{isOnLeft},
		stopTimer{stopTimer},
		secondsAfterStop{0.f} {}
	
	void MoveUfo(int speed);
	void UpdateCanMoveState();
	void UpdateIsHiddenState();
	void KillUfo(Texture2D killedTexture);
	bool HandleUfoDeath();


	Vector2 GetBulletPosition(int bulletHeight);
	void SetCanMove(bool value) {canMove = value;}
	void SetIsOnLeft(bool value) {isOnLeft = value;}
	void SetIsOnRight(bool value) {isOnRight = value;}
	void SetStopTimer(float value) {stopTimer = value;}
	void SetSecondsAfterStop(float value) {secondsAfterStop = value;}
	void SetIsHidden(bool value) {isHidden = value;}
};
