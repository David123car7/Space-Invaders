#include "Ufo/ufo.h"
#include "Other/constants.h"
#include <raylib.h>

void Ufo::MoveUfo(int speed){
	if(canMove && !isDeath){
		if(GetPositionX() < 0 - GetWidth() && !isOnLeft){
			canMove = false;
			isOnRight = false;
			isOnLeft = true;
		}
		else if(GetPositionX() > WINDOW_WIDTH + GetWidth() && !isOnRight){
			canMove = false;
			isOnRight = true;
			isOnLeft = false;
		}
		else{
			if(isOnLeft) MoveRight(speed);
			else if(isOnRight) MoveLeft(speed);
		}
	}
	else{
		UpdateCanMoveState();
	}
}

void Ufo::KillUfo(Texture2D killedTexture){
	SetIsDeath(true);
	SetTexture(killedTexture);
}

bool Ufo::HandleDeath(){
	if(isDeath){
		if(secondsAfterDeath >= deathTimer){
			isHidden = true;
			return true;
		}
		secondsAfterDeath += GetFrameTime();			
	}
	return false;
}

void Ufo::UpdateCanMoveState(){
	if(secondsAfterStop > stopTimer){
		canMove = true;
		secondsAfterStop = 0.f;
	}
	else secondsAfterStop += GetFrameTime();
}

Vector2 Ufo::GetBulletPosition(int bulletHeight){
	float posX = GetPositionX() + GetWidth() / 2;
	float posY = GetPositionY() + bulletHeight;
	return {posX, posY};
}
