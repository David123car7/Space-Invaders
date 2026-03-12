#include "bulletsManagement.h"

void BulletsManagement::DisplayBullets(){
	for(int i=0; i<bullets.size(); i++){
		bullets[i].DisplayEntity();
	}
}

void BulletsManagement::AddBullet(Bullet& bullet){
	bullets.push_back(bullet);
}

bool BulletsManagement::RemoveBullet(unsigned int pos){
	if(pos >= bullets.size()) return false;	
	bullets[pos] = bullets.back();
	bullets.pop_back();
	return true;
}
