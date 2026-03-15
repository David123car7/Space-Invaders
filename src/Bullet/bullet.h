#pragma once

#include "raylib.h"
#include "../Entity/entity.h"

class Bullet: public Entity{
	private:
	Vector2 startPosition;
	float speed;
	
	public:
	Bullet(Vector2 position, float speed, Texture2D texture, Color color):
		speed{speed},
		startPosition{position},
		Entity(position, texture, color) {}
	
	void ShootUp();
	void ShootDown();
};
