#include "invadersManagement.h"
#include <string>
#include <raylib.h>

void InvadersManagement::DisplayInvaders(){
	for(int i=0; i<invaders.size(); i++){
		invaders[i].DisplayEntity();
	}
}

void InvadersManagement::SpawnInvaders(Vector2 startPos, Texture2D texture, float shootCountdown, float speed){
	Vector2 enemyPos = startPos;
	int maxInvaders = INVADERS_X_SIZE * INVADERS_Y_SIZE;
	int rowCount = 0;
	for(int i=0; i<maxInvaders; i++){
		if(rowCount == INVADERS_X_SIZE){
			enemyPos.y -= texture.height * 2;
			enemyPos.x = startPos.x;
			rowCount = 0;
		}
		Invader invader(enemyPos, true, speed, true, shootCountdown, texture, RED);
		invaders.push_back(invader); 	
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

void InvadersManagement::MoveInvaders(float& seconds, float bordersGap, float invaderWidth){
	if(canMove){
		/*
		if(invaders[0][0].GetPositionX() <= bordersGap){
			hitLeft = true;	
		}
		else if(invaders[INVADERS_X_SIZE-1][INVADERS_Y_SIZE-1].GetPositionX() >=  WINDOW_WIDTH - invaderWidth - bordersGap){
			hitLeft = false;
		}*/

		for(int i=0; i<invaders.size(); i++){
				if(hitLeft) invaders[i].MoveRight();
				else invaders[i].MoveLeft();
		}
		canMove = false;
	}
	else{
		UpdateCanMoveState(seconds);
	}
}
