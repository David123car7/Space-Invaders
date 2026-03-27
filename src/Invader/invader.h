#pragma once

#include "../Entity/entity.h"

class Invader: public Entity {
	private:
	bool isDeath;
	float deathTimer;
	int pos;
	
	public:
	Invader(Vector2 position, Texture2D texture, Color color, int pos):
		Entity(position, texture, color),
		isDeath{false},
		deathTimer{0.f},
		pos{pos} {}

	void MoveRight(float speed);
	void MoveLeft(float speed);
	void MoveDown(float speed);
	Vector2 GetBulletPosition(float bulletWidth);
	void DisplayEntity() override;
	void SetIsDeath(bool value) {isDeath = value;}
	bool HandleDeath(float timer);
	int GetInvaderPos() {return pos;}
};
