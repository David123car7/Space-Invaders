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
	int GetPlayerWidth() { return player.width;}
	int GetPlayerHeight() {return player.height;}
	const Texture2D& GetBulletTexture() const { return bullet;} 
	int GetBulletWidth() {return bullet.width;}
	int GetBulletHeight() {return bullet.height;}
	const Texture2D& GetInvaderTexture() const { return invader;}
	int GetInvaderWidth() {return invader.width;}
	int GetInvaderHeight() {return invader.height;}
};
