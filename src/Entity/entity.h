#pragma once 

#include "raylib.h"
#include <string>

class Entity{
	private:
	Texture2D texture;

	protected:
	Vector2 position;
	Color color;

	public:
	Entity(float speed, int posX, int posY, const char* texturePath, Color color):
		position{ (float)posX/2, (float)posY/2 },
		texture{LoadTexture(texturePath)},
		color{color} {}

	void LoadEntity();
	void UnloadEntity(); 

};
