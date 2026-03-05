#pragma once

#include "raylib.h"

class TexturesManagement{
	private:
	Texture2D player;
	Texture2D bullet;

	public:
	TexturesManagement(const char* playerPath, const char* bulletPath):
		player{LoadTexture(playerPath)},
		bullet{LoadTexture(bulletPath)} {}

	const Texture2D& GetPlayerTexture() const { return player;}
	const Texture2D& GetBulletTexture() const { return bullet;}
};
