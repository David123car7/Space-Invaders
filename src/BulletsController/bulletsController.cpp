#include "BulletsController/bulletsController.h"
#include "Other/constants.h"

void BulletsController::DisplayBullets(){
	for(int i=0; i<bullets.size(); i++){
		bullets[i].DisplayEntity();
	}
}

bool BulletsController::HandleOutOfBounds(int pos){
	if(pos >= bullets.size()) return false;	
	bool res = false;
	int posY = bullets[pos].GetPositionY();
	if(posY <= 0 || posY >= WINDOW_HEIGHT){
		TraceLog(LOG_INFO, "Bullet out of bounds");
		res = RemoveBullet(pos);
	}
	return res;
}

void BulletsController::SpawnBullet(Vector2 position, float speed, Texture2D texture, Color color){
	Bullet bullet(position, speed, texture, color);
	TraceLog(LOG_INFO, "Bullet spawned");
	bullets.push_back(bullet);
}

bool BulletsController::RemoveBullet(unsigned int pos){
	if(pos >= bullets.size()) return false;	
	bullets[pos] = bullets.back();
	bullets.pop_back();
	return true;
}

void BulletsController::ShootBulletsUp(){;
	for(int i=0; i<bullets.size(); i++){
		bullets[i].ShootUp();
		HandleOutOfBounds(i);	
	}
}

void BulletsController::ShootBulletsDown(){;
	for(int i=0; i<bullets.size(); i++){
		bullets[i].ShootUp();
		HandleOutOfBounds(i);	
	}
}

