#include "Entity.h"

bool Entity::move(int8_t x, int8_t y) {
	if (this->position.x - x < 0 || 
		this->position.y - y < 0 ||
		this->position.x + x > 4 ||
		this->position.y + y > 4) return false;
	

	this->position.x + x;
	this->position.y + y;

	return true;
}