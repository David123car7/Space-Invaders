#pragma once

#include "raylib.h"

class SoundController{
	private:
	Sound bulletSound;
	Sound invaderDeathSound;
	Sound playerDeathSound;
	
	public:
	SoundController():
		bulletSound{LoadSound("resources/sounds/shoot.wav")},
		invaderDeathSound{LoadSound("resources/sounds/invaderkilled.wav")},
		playerDeathSound{LoadSound("resources/sounds/explosion.wav")} {}

	void PlayBulletSound();
	void PlayInvaderDeathSound();
	void PlayPlayerDeathSound();

};
