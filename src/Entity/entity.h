#pragma once 

#include "raylib.h"
#include <string>

class Entity{
	protected:
	Texture2D texture;
	Vector2 position;
	Color color;

	public:
	Entity():
		texture{0},
		position{0,0},
		color{RED} {}

	Entity(Vector2 position, Texture2D texture, Color color):
		position{position},	
		texture{texture},
		color{color} {}

	Entity(Vector2 position, float speed, Texture2D texture, Color color):
		position{position},	
		texture{texture},
		color{color} {}
	
	const Vector2& GetPosition() const { return position;}
	float GetPositionX() {return position.x;}
	float GetPositionY() {return position.y;}
	const float GetWidth() const {return texture.width;}

	virtual void DisplayEntity();
};
