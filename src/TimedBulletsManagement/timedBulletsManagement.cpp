#include "timedBulletsManagement.h"
#include <raylib.h>

void TimedBulletsManagement::UpdateCanShootState(){
	if(!canShoot){
		if(secondsAfterShoot >= countDown){
			secondsAfterShoot = 0.f;
			canShoot = true;
		}
	}
}

void TimedBulletsManagement::UpdateSecondsAfterShoot(){
	secondsAfterShoot += GetFrameTime();
}

void TimedBulletsManagement::SpawnBullet(Vector2 position, float speed, Texture2D texture, Color color){
	if(!canShoot) return;
	Bullet bullet(position, speed, texture, color);
	TraceLog(LOG_INFO, "Bullet spawned");
	bullets.push_back(bullet);
}

bool TimedBulletsManagement::ShootBulletUp(int pos){;
	if(pos > bullets.size()-1) return false;
	bullets[pos].ShootUp();
	canShoot = false;
	return true;
}

bool TimedBulletsManagement::ShootBulletDown(int pos){;
	if(pos > bullets.size()-1) return false;
	bullets[pos].ShootDown();
	canShoot = false;
	return true;
}
