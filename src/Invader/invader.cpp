#include "invader.h"
#include <raylib.h>

void Invader::MoveRight(float speed){
	position.x += speed * GetFrameTime();

}

void Invader::MoveLeft(float speed){
	position.x -= speed * GetFrameTime();
}

void Invader::MoveDown(float speed){
	position.y += speed * GetFrameTime();
}

void Invader::DisplayEntity() {
	DrawTextureV(texture, position, color); 
}

Vector2 Invader::GetBulletPosition(float bulletWidth){	
	float posX = position.x + (float)texture.width / 2 - bulletWidth / 2;
	float posY = position.y + texture.height;
	return {posX, posY};
}

bool Invader::HandleDeath(float timer){
	if(isDeath){
		if(deathTimer >= timer){
			return true; 
		}
		deathTimer += GetFrameTime();			
	}
	return false;
}
