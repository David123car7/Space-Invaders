#include "SoundController/soundController.h"
#include <raylib.h>

void SoundController::PlayBulletSound(){
	PlaySound(bulletSound);
}

void SoundController::PlayInvaderDeathSound(){
	PlaySound(invaderDeathSound);
}

void SoundController::PlayPlayerDeathSound(){
	PlaySound(playerDeathSound);
}

