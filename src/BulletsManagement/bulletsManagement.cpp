#include "bulletsManagement.h"
#include "../Other/constants.h"

void BulletsManagement::DisplayBullets(){
	for(int i=0; i<bullets.size(); i++){
		bullets[i].DisplayEntity();
	}
}

bool BulletsManagement::HandleOutOfBounds(int pos){
	if(pos >= bullets.size()) return false;	
	bool res = false;
	int posY = bullets[pos].GetPositionY();
	if(posY <= 0 || posY >= WINDOW_HEIGHT){
		TraceLog(LOG_INFO, "Bullet out of bounds");
		res = RemoveBullet(pos);
	}
	return res;
}

void BulletsManagement::SpawnBullet(Vector2 position, float speed, Texture2D texture, Color color){
	Bullet bullet(position, speed, texture, color);
	TraceLog(LOG_INFO, "Bullet spawned");
	bullets.push_back(bullet);
}

bool BulletsManagement::RemoveBullet(unsigned int pos){
	if(pos >= bullets.size()) return false;	
	bullets[pos] = bullets.back();
	bullets.pop_back();
	return true;
}

bool BulletsManagement::ShootBulletUp(int pos){;
	if(pos >= bullets.size()) return false;	
	bullets[pos].ShootUp();
	return true;
}

bool BulletsManagement::ShootBulletDown(int pos){;
	if(pos >= bullets.size()) return false;	
	bullets[pos].ShootDown();
	return true;
}

