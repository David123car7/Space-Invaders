#pragma once

#include "raylib.h"
#include "../Entity/entity.h"

class Bullet: public Entity{
	private:
	
	public:
	Bullet(float speed, int posX, int posY, const char* texturePath, Color color, int lives):
		Entity(speed, posX, posY, texturePath, color) {}

};
