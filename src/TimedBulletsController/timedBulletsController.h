#pragma once

#include "../BulletsController/bulletsController.h"

class TimedBulletsController: public BulletsController{
	public:
	float secondsAfterShoot;
	float countDown;
	bool canShoot;

	TimedBulletsController():
		countDown{0.f},
		secondsAfterShoot{0.f},
		canShoot{false} {}

	TimedBulletsController(float countDown):
		countDown{countDown},
		secondsAfterShoot{0.f},
		canShoot{true} {}
		
	virtual void SpawnBullet(Vector2 position, float speed, Texture2D texture, Color color) override;
	void UpdateSecondsAfterShoot();
	void UpdateCanShootState();
	bool ShootBulletUp(int pos) override;	
	bool ShootBulletDown(int pos) override;	
};
