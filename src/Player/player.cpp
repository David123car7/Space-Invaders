#include "player.h"

void Player::MoveRight(){
	position.x += speed * GetFrameTime();
}

void Player::MoveLeft(){
	position.x -= speed * GetFrameTime();
}
