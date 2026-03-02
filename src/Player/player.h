#pragma once 

#include "raylib.h"
#include <string>

class Player{
	private:
	float speed;
	Vector2 position;
	Texture2D texture;
	int lives;
	Color color;

	public:
	Player(float speed, int posX, int posY, const char* texturePath, Color color, int lives):
		speed{speed},
		position{ (float)posX/2, (float)posY/2 },
		texture{LoadTexture(texturePath)},
		color{color},
		lives{lives}  {}

	void LoadPlayer();
	void UnloadPlayer(); 
	void MoveRight();
	void MoveLeft();
};
