#include "entity.h"

void Entity::LoadEntity(){
	DrawTextureV(texture, position, RED);
}

void Entity::UnloadEntity(){
	UnloadTexture(texture);       
}





