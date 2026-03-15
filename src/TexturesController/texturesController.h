#pragma once

#include "raylib.h"

class TexturesController{
	private:
	Texture2D player;
	Texture2D bullet;
	Texture2D invader;

	public:
	TexturesController(const char* playerPath, const char* bulletPath, const char* invaderPath):
		invader{LoadTexture(invaderPath)},
		player{LoadTexture(playerPath)},
		bullet{LoadTexture(bulletPath)} {}

	const Texture2D& GetPlayerTexture() const { return player;}
	int GetPlayerTextureWidth() { return player.width;}
	int GetPlayerTextureHeight() {return player.height;}
	const Texture2D& GetBulletTexture() const { return bullet;} 
	int GetBulletTextureWidth() {return bullet.width;}
	int GetBulletTextureHeight() {return bullet.height;}
	const Texture2D& GetInvaderTexture() const { return invader;}
	int GetInvaderTextureWidth() {return invader.width;}
	int GetInvaderTextureHeight() {return invader.height;}
};
