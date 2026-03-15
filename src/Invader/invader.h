#pragma once

#include "../Entity/entity.h"

class Invader: public Entity {
	private:
	bool canShoot;
	int shootCountdown;

	public:
	Invader():
		canShoot{true},
		shootCountdown{0} {}

	Invader(Vector2 position, bool canShoot, int shootCountdown, Texture2D texture, Color color):
		Entity(position, texture, color),
		canShoot{canShoot},
		shootCountdown{shootCountdown} {}

	bool GetCanShoot() { return canShoot;}
	void SetCanShoot(bool value) { canShoot = value;}

	void MoveRight(float speed);
	void MoveLeft(float speed);
	Vector2 GetBulletPosition(float bulletWidth);
	void UpdateCanShootState(float& seconds); //function to be used on the game loop
	void DisplayEntity() override;
};
