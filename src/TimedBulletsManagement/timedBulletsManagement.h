#pragma once

#include "../BulletsManagement/bulletsManagement.h"

class TimedBulletsManagement: public BulletsManagement{
	public:
	float secondsAfterShoot;
	float countDown;
	bool canShoot;

	TimedBulletsManagement():
		countDown{0.f},
		secondsAfterShoot{0.f},
		canShoot{false} {}

	TimedBulletsManagement(float countDown):
		countDown{countDown},
		secondsAfterShoot{0.f},
		canShoot{true} {}
		
	virtual void SpawnBullet(Vector2 position, float speed, Texture2D texture, Color color) override;
	void UpdateSecondsAfterShoot();
	void UpdateCanShootState();
	bool ShootBulletUp(int pos) override;	
	bool ShootBulletDown(int pos) override;	
};
