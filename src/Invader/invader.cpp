#include "invader.h"

void Invader::MoveRight(){
	position.x += speed * GetFrameTime();
}

void Invader::MoveLeft(){
	position.x -= speed * GetFrameTime();
}

void Invader::UpdateCanShootState(float& seconds){
	if(!canShoot){
		seconds += GetFrameTime();
		if(seconds >= shootCountdown){
			canShoot = true;
			seconds = 0.f;
		}
	}
}

void Invader::DisplayEntity() {
	if(isAlive) DrawTextureV(texture, position, color); 
}

Vector2 Invader::GetBulletPosition(float bulletWidth){	
	float posX = position.x + (float)texture.width / 2 - bulletWidth / 2;
	float posY = position.y + texture.height;
	return {posX, posY};
}
