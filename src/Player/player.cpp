#include "player.h"
#include <raylib.h>

void Player::MoveRight(){
	position.x += speed * GetFrameTime();
}

void Player::MoveLeft(){
	position.x -= speed * GetFrameTime();
}

void Player::UpdateCanShootState(){
	if(!canShoot){
		secondsAfterShoot += GetFrameTime();
		if(secondsAfterShoot >= shootCountdown){
			canShoot = true;
			secondsAfterShoot = 0.f;
		}
	}
}


