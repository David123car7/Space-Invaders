#pragma once

#include <vector>
#include "../Bullet/bullet.h"

class BulletsController{
	protected:
	std::vector<Bullet> bullets;
	bool HandleOutOfBounds(int pos);

	public:	
	const std::vector<Bullet>& GetBullets() {return bullets;}

	virtual void ShootBulletsUp();
	virtual void ShootBulletsDown();
	void DisplayBullets();
	virtual void SpawnBullet(Vector2 position, float speed, Texture2D texture, Color color);
	bool RemoveBullet(unsigned int pos);
};
