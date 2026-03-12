#pragma once

#include <vector>
#include "../Bullet/bullet.h"

class BulletsManagement{
	public:
	std::vector<Bullet> bullets;

	void DisplayBullets();
	void AddBullet(Bullet& bullet);
	bool RemoveBullet(unsigned int pos);
};
