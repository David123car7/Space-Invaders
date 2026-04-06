#pragma once

#include "Entity/entity.h"

class Invader: public Entity {
	private: 
	int pos;

	protected:
	bool isDeath;
	float secondsAfterDeath;
	float deathTimer;
	
	public:
	Invader():
		Entity{},
		isDeath{false},
		deathTimer{0.f},
		pos{-1} {}

	Invader(Vector2 position, Texture2D texture, Color color, int pos, float deathTimer):
		Entity(position, texture, color),
		isDeath{false},
		deathTimer{deathTimer},
		secondsAfterDeath{0.f},
		pos{pos} {}

	Invader(Vector2 position, Texture2D texture, Color color):
		Entity(position, texture, color),
		isDeath{false},
		deathTimer{0.f},
		pos{-1} {}

	void MoveRight(float speed);
	void MoveLeft(float speed);
	void MoveDown(float speed);
	Vector2 GetBulletPosition(float bulletWidth);
	void DisplayEntity() override;
	void SetIsDeath(bool value) {isDeath = value;}
	virtual bool HandleDeath();
	int GetInvaderPos() {return pos;}
};
