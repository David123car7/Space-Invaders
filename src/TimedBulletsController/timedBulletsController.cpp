#include "TimedBulletsController/timedBulletsController.h"
#include <raylib.h>

void TimedBulletsController::UpdateCanShootState(){
	if(!canShoot){
		secondsAfterShoot += GetFrameTime();
		if(secondsAfterShoot >= countDown){
			secondsAfterShoot = 0.f;
			canShoot = true;
		}
	}
}

void TimedBulletsController::SpawnBullet(Vector2 position, float speed, Texture2D texture, Color color){
	if(!canShoot) return;
	Bullet bullet(position, speed, texture, color);
	TraceLog(LOG_INFO, "Bullet spawned");
	bullets.push_back(bullet);
}

void TimedBulletsController::ShootBulletsUp(){;
	for(int i=0; i<bullets.size(); i++){
		bullets[i].ShootUp();
		HandleOutOfBounds(i);	
	}
	canShoot = false;
}

void TimedBulletsController::ShootBulletsDown(){;
	for(int i=0; i<bullets.size(); i++){
		bullets[i].ShootDown();
		HandleOutOfBounds(i);	
	}
	canShoot = false;
}
