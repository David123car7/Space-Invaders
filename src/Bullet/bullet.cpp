#include "bullet.h"
#include <raylib.h>

void Bullet::ShootUp(){
	position.y -= speed * GetFrameTime();
	position.x  = startPosition.x;
}

void Bullet::ShootDown(){
	position.y += speed * GetFrameTime();
	position.x  = startPosition.x;
}
