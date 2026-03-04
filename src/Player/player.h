#pragma once

#include "../Entity/entity.h"

class Player: public Entity{
	private:
	float speed;
	int lives;

	public:
	Player(float speed, int posX, int posY, const char* texturePath, Color color, int lives):
		Entity(speed, posX, posY, texturePath, color),
		speed{speed},
		lives{lives} {}

	void Shoot();
	void MoveRight();
	void MoveLeft();
};
