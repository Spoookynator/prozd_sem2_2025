#include <iostream>
#include "Entity.h"
#include "constants.h"

Entity::Entity(Position startingPosition, int32_t maxHealth) : position(startingPosition), currentHp(maxHealth),
maxHp(maxHealth)
{};

bool Entity::move(int8_t x, int8_t y) {

	// safeguard to prevent moving outside of the board
	if (this->position.x + x < 0 ||
		this->position.y + y < 0 ||
		this->position.x + x > Constants::MAX_FIELDSIZE - 1 ||
		this->position.y + y > Constants::MAX_FIELDSIZE - 1) return false;
	
	
	this->position.x += x;
	this->position.y += y;

	return true;
}

void Entity::setPosition(Position position)
{
	this->position = position;
}

Position Entity::getPosition() const {
	return this->position;
}

void Entity::printPosition() const {
	std::cout << "(" << (int)this->position.x << ", ";
	std::cout << (int)this->position.y << ")" << std::endl;
}

int8_t Entity::getCurrentHp() const {
	return this->currentHp;
}

int8_t Entity::getMaxHp() const {
	return this->maxHp;
}

void Entity::takeDamage(uint8_t damage) {

	this->currentHp = (this->currentHp - damage) < 0 ? 0 : this->currentHp - damage;
}

void Entity::heal(uint8_t heal) {
	this->currentHp = (this->currentHp + heal) > this->maxHp ? this->maxHp : this->currentHp + heal;
}