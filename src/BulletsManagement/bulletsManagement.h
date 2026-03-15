#pragma once

#include <vector>
#include "../Bullet/bullet.h"

class BulletsManagement{
	public:
	std::vector<Bullet> bullets;

	void DisplayBullets();
	bool HandleOutOfBounds(int pos);
	void SpawnBullet(Vector2 position, float speed, Texture2D texture, Color color);
	bool RemoveBullet(unsigned int pos);
};
