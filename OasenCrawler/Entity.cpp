#include <iostream>
#include "Entity.h"
#include "constants.h"

bool Entity::move(int8_t x, int8_t y) {
	if (this->position.x - x < 0 || 
		this->position.y - y < 0 ||
		this->position.x + x > Constants::MAX_FIELDSIZE ||
		this->position.y + y > Constants::MAX_FIELDSIZE) return false;
	

	this->position.x + x;
	this->position.y + y;

	return true;
}

Position Entity::getPosition() const {
	return this->position;
}

void Entity::printPosition() const {
	std::cout << "(" << this->position.x << ", ";
	std::cout << this->position.y << ")" << std::endl;
}