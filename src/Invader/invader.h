#pragma once

#include "../Entity/entity.h"

class Invader: public Entity {
	private:
	float speed;
	bool canShoot;
	int shootCountdown;

	public:
	Invader():
		speed{0.0},
		canShoot{false},
		shootCountdown{0} {}

	Invader(Vector2 position, float speed, bool canShoot, int shootCountdown, Texture2D texture, Color color):
		Entity(position, texture, color),
		canShoot{canShoot},
		shootCountdown{shootCountdown},
		speed{speed} {}

	bool GetCanShoot() { return canShoot;}
	void SetCanShoot(bool value) { canShoot = value;}

	void MoveRight();
	void MoveLeft();
	void UpdateCanShootState(float& seconds); //function to be used on the game loop
};
