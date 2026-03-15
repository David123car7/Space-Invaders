#include "invadersManagement.h"
#include <string>
#include <raylib.h>

void InvadersManagement::DisplayInvaders(){
	for(int i=0; i<invaders.size(); i++){
		invaders[i].DisplayEntity();
	}
}

void InvadersManagement::SpawnInvaders(Vector2 startPos, Texture2D texture, float shootCountdown){
	Vector2 enemyPos = startPos;
	leftCorner = startPos.x;
	TraceLog(LOG_INFO, std::to_string(leftCorner).c_str());
	int maxInvaders = INVADERS_X_SIZE * INVADERS_Y_SIZE;
	int rowCount = 0;
	for(int i=0; i<maxInvaders; i++){
		if(rowCount == INVADERS_X_SIZE){
			enemyPos.y -= texture.height * 2;
			enemyPos.x = startPos.x;
			rowCount = 0;
		}
		Invader invader(enemyPos, true, shootCountdown, texture, RED);
		invaders.push_back(invader); 	
		if(i == maxInvaders-1) {
			rightCorner = enemyPos.x;
			TraceLog(LOG_INFO, std::to_string(rightCorner).c_str());
		}
		enemyPos.x += texture.width * 2;
		rowCount++;
	}
}

bool InvadersManagement::RemoveInvader(unsigned int pos){
	if(pos > invaders.size()-1) return false;
	invaders[pos] = invaders.back();
	invaders.pop_back();
	return true;
}

void InvadersManagement::UpdateCanMoveState(float& seconds){
	if(!canMove){
		seconds += GetFrameTime();
		if(seconds >= moveCountdown){
			canMove = true;
			seconds = 0.f;
		}
	}
}

void InvadersManagement::MoveInvaders(float& seconds, float speed, float bordersGap, float invaderWidth){
	if(canMove){
		if(leftCorner <= bordersGap){
			hitLeft = true;	
		}
		else if(rightCorner >=  WINDOW_WIDTH - invaderWidth - bordersGap){
			hitLeft = false;
		}

		for(int i=0; i<invaders.size(); i++){
				if(hitLeft) invaders[i].MoveRight(speed);
				else invaders[i].MoveLeft(speed);
		}

		if(hitLeft){				
			rightCorner += speed * GetFrameTime();
			leftCorner += speed * GetFrameTime();
		}	
		else{
			rightCorner -= speed * GetFrameTime();
			leftCorner -= speed * GetFrameTime();
		}
		canMove = false;
	}
	else{
		UpdateCanMoveState(seconds);
	}
}

Vector2 InvadersManagement::GetRandomInvaderBulletPos(float bulletHeight){
	int pos = std::rand() % invaders.size();
	Invader* invader = &invaders[pos];
	float posX = invader->GetPositionX() + invader->GetWidth() / 2;
	float posY = invader->GetPositionY() + bulletHeight;
	return {posX, posY};
}
