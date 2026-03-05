#include "player.h"

void Player::MoveRight(){
	position.x += speed * GetFrameTime();
}

void Player::MoveLeft(){
	position.x -= speed * GetFrameTime();
}

void Player::UpdateCanShootState(float& seconds){
	if(!canShoot){
		seconds += GetFrameTime();
		if(seconds >= shootCountdown){
			canShoot = true;
			seconds = 0.f;
		}
	}
}
