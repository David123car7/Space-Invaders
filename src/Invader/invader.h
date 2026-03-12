#pragma once

#include "../Entity/entity.h"

class Invader: public Entity {
	private:
	bool isAlive;
	float speed;
	bool canShoot;
	int shootCountdown;

	public:
	Invader():
		speed{0.0},
		canShoot{true},
		isAlive{true},
		shootCountdown{0} {}

	Invader(Vector2 position, bool isAlive, float speed, bool canShoot, int shootCountdown, Texture2D texture, Color color):
		Entity(position, texture, color),
		isAlive{isAlive},
		canShoot{canShoot},
		shootCountdown{shootCountdown},
		speed{speed} {}

	bool GetCanShoot() { return canShoot;}
	void SetCanShoot(bool value) { canShoot = value;}
	bool GetIsAlive() { return isAlive;}
	void SetIsAlive(bool value) {isAlive = value;}

	void MoveRight();
	void MoveLeft();
	void UpdateCanShootState(float& seconds); //function to be used on the game loop
	void DisplayEntity() override;
};
