#include "invadersManagement.h"
#include <raylib.h>

void InvadersManagement::DisplayInvaders(){
	for(int i=0; i<INVADERS_X_SIZE; i++){
		for(int j=0; j<INVADERS_Y_SIZE; j++){
			invaders[i][j].DisplayEntity();
		}
	}
}

void InvadersManagement::SpawnInvaders(Vector2 startPos, Texture2D texture){
	Vector2 enemyPos = startPos;
	for(int i=0; i<INVADERS_X_SIZE; i++){
		for(int j=0; j<INVADERS_Y_SIZE; j++){
			Invader invader(enemyPos, true, 1000.f, true, 1, texture, RED);
			invaders[i][j] = invader;
			enemyPos.y -= texture.height * 2;
		}
		enemyPos.x += texture.width * 2;
		enemyPos.y = startPos.y;
	}
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

void InvadersManagement::MoveInvaders(float& seconds){
	if(canMove){
		for(int i=0; i<INVADERS_X_SIZE; i++){
			for(int j=0; j<INVADERS_Y_SIZE; j++){
				invaders[i][j].MoveLeft();
			}
		}
		canMove = false;
	}
	else{
		UpdateCanMoveState(seconds);
	}
}
