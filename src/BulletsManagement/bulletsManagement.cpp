#include "bulletsManagement.h"

void BulletsManagement::DisplayBullets(){
	for(int i=0; i<bullets.size(); i++){
		bullets[i].DisplayEntity();
	}
}

bool BulletsManagement::HandleOutOfBounds(int pos){
	bool res = false;
	if(bullets[pos].GetPositionY() <= 0){
		TraceLog(LOG_INFO, "Bullet out of bounds");
		res = RemoveBullet(pos);
	}
	return res;
}

void BulletsManagement::SpawnBullet(Vector2 position, float speed, Texture2D texture, Color color){
	Bullet bullet(position, speed, texture, color);
	bullets.push_back(bullet);
}

bool BulletsManagement::RemoveBullet(unsigned int pos){
	if(pos >= bullets.size()) return false;	
	bullets[pos] = bullets.back();
	bullets.pop_back();
	return true;
}
