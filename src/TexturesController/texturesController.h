#pragma once

#include "raylib.h"

class TexturesController{
	private:
	Texture2D player;
	Texture2D bullet;
	Texture2D invaderA0;
	Texture2D invaderA1;
	Texture2D invaderB0;
	Texture2D invaderB1;
	Texture2D invaderC0;
	Texture2D invaderC1;
	Texture2D invaderExplosion;
	Texture2D ufo;

	public:
	TexturesController():
		invaderA0{LoadTexture("resources/textures/invader_a0.png")},
		invaderA1{LoadTexture("resources/textures/invader_a1.png")},
		invaderB0{LoadTexture("resources/textures/invader_b0.png")},
		invaderB1{LoadTexture("resources/textures/invader_b1.png")},
		invaderC0{LoadTexture("resources/textures/invader_c0.png")},
		invaderC1{LoadTexture("resources/textures/invader_c1.png")},
		ufo{LoadTexture("resources/textures/ufo.png")},
		invaderExplosion{LoadTexture("resources/textures/invader_explosion.png")},
		player{LoadTexture("resources/textures/player.png")},
		bullet{LoadTexture("resources/textures/bullet.png")} {}

	const Texture2D& GetPlayerTexture() const { return player;}
	int GetPlayerWidth() { return player.width;}
	int GetPlayerHeight() {return player.height;}
	
	//Bullet Textures
	const Texture2D& GetBulletTexture() const { return bullet;} 
	int GetBulletWidth() {return bullet.width;}
	int GetBulletHeight() {return bullet.height;}
	
	//Invader Textures
	const Texture2D& GetInvaderTextureA0() const { return invaderA0;}
	int GetInvaderWidthA0() {return invaderA0.width;}
	int GetInvaderHeightA0() {return invaderA0.height;}
	const Texture2D& GetInvaderTextureB0() const { return invaderB0;}
	int GetInvaderWidthB0() {return invaderB0.width;}
	int GetInvaderHeightB0() {return invaderB0.height;}
	const Texture2D& GetInvaderTextureC0() const { return invaderC0;}
	int GetInvaderWidthC0() {return invaderC0.width;}
	int GetInvaderHeightC0() {return invaderC0.height;}
	const Texture2D& GetInvaderTextureA1() const { return invaderA1;}
	int GetInvaderWidthA1() {return invaderA1.width;}
	int GetInvaderHeightA1() {return invaderA1.height;}
	const Texture2D& GetInvaderTextureB1() const { return invaderB1;}
	int GetInvaderWidthB1() {return invaderB1.width;}
	int GetInvaderHeightB1() {return invaderB1.height;}
	const Texture2D& GetInvaderTextureC1() const { return invaderC1;}
	int GetInvaderWidthC1() {return invaderC1.width;}
	int GetInvaderHeightC1() {return invaderC1.height;}
	const Texture2D& GetInvaderExplosionTexture() const { return invaderExplosion;}
	const Texture2D& GetUfoTexture() const {return ufo;}
	int GetUfoWidth() {return ufo.width;}
	int GetUFoHeight() {return ufo.height;}

};
