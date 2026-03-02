#include "player.h"

using namespace std;

void Player::LoadPlayer(){
	DrawTextureV(texture, position, RED);
}

void Player::UnloadPlayer(){
	UnloadTexture(texture);       
}

void Player::MoveRight(){
	position.x += speed * GetFrameTime();
}

void Player::MoveLeft(){
	position.x -= speed * GetFrameTime();
}

