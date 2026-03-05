#include "bullet.h"
#include <raylib.h>

void Bullet::Shoot(){
	position.y -= speed * GetFrameTime();
	position.x  = startPosition.x;
}
