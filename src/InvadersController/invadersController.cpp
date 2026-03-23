#include "invadersController.h"
#include <chrono>
#include <string>
#include <raylib.h>

void InvadersController::DisplayInvaders(){
	for(int i=0; i<invaders.size(); i++){
		invaders[i].DisplayEntity();
	}
}

void InvadersController::SpawnInvaders(Vector2 startPos, Texture2D textureA0, Texture2D textureB0, 
	Texture2D textureC0, float shootCountdown, Color color){
	Vector2 enemyPos = startPos;
	leftCorner = startPos.x;
	int maxInvaders = INVADERS_X_SIZE * INVADERS_Y_SIZE;
	int rowCounter = 0;
	int counter = 0;
	Texture2D currentTexture = textureA0;
	for(int i=0; i<maxInvaders; i++){
		if(counter == INVADERS_X_SIZE){
			enemyPos.y -= currentTexture.height * 2;
			enemyPos.x = startPos.x;
			counter = 0;
			rowCounter++;
			if(rowCounter == 2) currentTexture = textureB0;
			else if(rowCounter == 4) currentTexture = textureC0;
		}
		Invader invader(enemyPos, true, shootCountdown, currentTexture, color);
		invaders.push_back(invader); 	
		if(i == maxInvaders-1) {
			rightCorner = enemyPos.x;
		}
		enemyPos.x += currentTexture.width * 2;
		counter++;
	}
}

void InvadersController::ResetInvaders(){
	invaders.clear();
	canMove = true;
	secondsAfterMoved = 0.f;
	hitLeft = false;
	canMoveDown = false;
	leftCorner = 0.f;
	rightCorner = 0.f;
}

bool InvadersController::RemoveInvader(unsigned int pos){
	if(pos > invaders.size()-1) return false;
	invaders[pos] = invaders.back();
	invaders.pop_back();
	return true;
}

void InvadersController::UpdateCanMoveState(){
	if(!canMove){
		secondsAfterMoved += GetFrameTime();
		if(secondsAfterMoved >= moveCountdown){
			canMove = true;
			secondsAfterMoved = 0.f;
		}
	}
}

void InvadersController::MoveInvaders(int speed, int bordersGap, float invaderWidth){
	if(canMove){
		if(leftCorner <= bordersGap){
			hitLeft = true;	
		}
		else if(rightCorner >=  WINDOW_WIDTH - invaderWidth - bordersGap){
			hitLeft = false;
		}	

		if(hitLeft){				
			if(!canMoveDown) canMoveDown = true;
			MoveAllInvadersRight(speed);
			rightCorner += speed * GetFrameTime();
			leftCorner += speed * GetFrameTime();
		}	
		else{
			if(canMoveDown){
				MoveAllInvadersDown(speed);
				canMoveDown = false;
			}
			else { 
				MoveAllInvadersLeft(speed);
				rightCorner -= speed * GetFrameTime();
				leftCorner -= speed * GetFrameTime();
			}
		}
		
		canMove = false;
	}
	else{
		UpdateCanMoveState();
	}
}

void InvadersController::MoveAllInvadersRight(float speed){
	for(int i=0; i<invaders.size(); i++){
		invaders[i].MoveRight(speed);
	}
}

void InvadersController::MoveAllInvadersLeft(float speed){
	for(int i=0; i<invaders.size(); i++){
		invaders[i].MoveLeft(speed);
	}
}

void InvadersController::MoveAllInvadersDown(float speed){
	for(int i=0; i<invaders.size(); i++){
		invaders[i].MoveDown(speed);
	}
}



Vector2 InvadersController::GetRandomInvaderBulletVector(float bulletHeight){
	int pos = std::rand() % invaders.size();
	Invader* invader = &invaders[pos];
	float posX = invader->GetPositionX() + invader->GetWidth() / 2;
	float posY = invader->GetPositionY() + bulletHeight;
	return {posX, posY};
}

int InvadersController::CalculateInvaderBonus(unsigned int pos){
	int row = GetInvaderRow(pos);
	switch(row){
		case 0: return 10;
		case 1: return 25;
		case 2: return 50;
		case 3: return 100;
		case 4: return 125;
		default: return 0;
	}
}

int InvadersController::GetInvaderRow(unsigned int pos){
	int j = pos / INVADERS_X_SIZE;
	TraceLog(LOG_INFO, "%d", j);
	return j;
}
