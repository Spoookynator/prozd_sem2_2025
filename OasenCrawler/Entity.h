#pragma once
#include "Position.h"

class Entity
{
public:

	void printPosition();
	Entity(Position);

protected:
	// returns true on valid and false on invalid move
	bool move(int8_t, int8_t);

private:
	Position position;
};