#pragma once

#include "../Entity/entity.h"

class Invader: public Entity {
	private:
	bool isDeath;
	float deathTimer;
	
	public:
	Invader(Vector2 position, Texture2D texture, Color color):
		Entity(position, texture, color),
		isDeath{false},
		deathTimer{0.f} {}

	void MoveRight(float speed);
	void MoveLeft(float speed);
	void MoveDown(float speed);
	Vector2 GetBulletPosition(float bulletWidth);
	void UpdateCanShootState(float& seconds); //function to be used on the game loop
	void DisplayEntity() override;
	void SetIsDeath(bool value) {isDeath = value;}
	bool HandleDeath(float timer);
};
