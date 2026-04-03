#pragma once

#include "Entity/entity.h"

class Player: public Entity{
	private:
	float speed;
	int lives;
	bool canShoot;
	float secondsAfterShoot;
	float shootCountdown;

	public:
	Player():
		Entity(),
		speed{0.f},
		lives{0},
		canShoot{true},
		secondsAfterShoot{0.f},
		shootCountdown{0} {}

	Player(float speed, float shootCountdown, Texture2D texture, Color color, int lives):
		Entity(texture, color),
		canShoot{true},
		shootCountdown{shootCountdown},
		speed{speed},
		secondsAfterShoot{0.f},
		lives{lives} {}

	Player(Vector2 position, float speed, bool canShoot, float shootCountdown, Texture2D texture, Color color, int lives):
		Entity(position, texture, color),
		canShoot{canShoot},
		shootCountdown{shootCountdown},
		speed{speed},
		secondsAfterShoot{0.f},
		lives{lives} {}

	bool GetCanShoot() { return canShoot;}
	void SetCanShoot(bool value) { canShoot = value;}
	int GetLives() {return lives;}
	int DecrementLives() {return --lives;} //Does this return the end result?
		
	void ResetPlayer(int lives);
	void MoveRight();
	void MoveLeft();
	void UpdateCanShootState(); //function to be used on the game loop
};
