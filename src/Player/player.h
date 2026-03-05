#pragma once

#include "../Entity/entity.h"

class Player: public Entity{
	private:
	float speed;
	int lives;
	bool canShoot;
	int shootCountdown;

	public:
	Player(Vector2 position, float speed, bool canShoot, int shootCountdown, Texture2D texture, Color color, int lives):
		Entity(position, texture, color),
		canShoot{canShoot},
		shootCountdown{shootCountdown},
		speed{speed},
		lives{lives} {}

	bool GetCanShoot() { return canShoot;}
	void SetCanShoot(bool value) { canShoot = value;}

	void Shoot();
	void MoveRight();
	void MoveLeft();
	void UpdateCanShootState(float& seconds); //function to be used on the game loop
};
