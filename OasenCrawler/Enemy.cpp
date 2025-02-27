#include "Enemy.h"
#include <iostream>

Entity::Entity(Position startingPosition) : position(startingPosition) {};

void Entity::printPosition() {
	std::cout << "(" << this->position.x << ", ";
	std::cout << this->position.y << ")" << std::endl;
}