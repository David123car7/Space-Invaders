#pragma once

#include <vector>
#include "../Bullet/bullet.h"

class BulletsController{
	public:
	std::vector<Bullet> bullets;

	virtual bool ShootBulletUp(int pos);
	virtual bool ShootBulletDown(int pos);
	void DisplayBullets();
	bool HandleOutOfBounds(int pos);
	virtual void SpawnBullet(Vector2 position, float speed, Texture2D texture, Color color);
	bool RemoveBullet(unsigned int pos);
};
