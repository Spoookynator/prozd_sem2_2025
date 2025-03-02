#pragma once
#include "Position.h"

class Entity
{
public:
	Entity(Position, int32_t);

	void printPosition() const;
	Position getPosition() const;

	int8_t getCurrentHp() const;
	int8_t getMaxHp() const;

	// ensures that the currentHp does not go below 0, does not return any value
	// manually check if hp is at 0 later
	void takeDamage(uint8_t);

	// ensures that the currentHp does not go above maxHp, does not return any value
	void heal(uint8_t);
	void setPosition(Position);

protected:
	// returns true on valid and false on invalid move
	bool move(int8_t, int8_t);


	int32_t currentHp, maxHp;

private:
	Position position;
};