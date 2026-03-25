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
		color{WHITE} {}

	Entity(Texture2D texture, Color color):
		position{0,0},	
		texture{texture},
		color{color} {}

	Entity(Vector2 position, Texture2D texture, Color color):
		position{position},	
		texture{texture},
		color{color} {}

	const Vector2& GetPosition() const { return position;}
	void SetPosition(Vector2 value) {position = value;}
	float GetPositionX() {return position.x;}
	float GetPositionY() {return position.y;}
	const float GetWidth() const {return texture.width;}
	void SetTexture(Texture2D& texture) {this->texture = texture;}
	const Texture2D& GetTexture() const {return texture;}

	virtual void DisplayEntity();
};
