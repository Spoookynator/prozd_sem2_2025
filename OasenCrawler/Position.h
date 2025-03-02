#pragma once
#include <stdint.h>
#include <utility>

struct Position
{
	Position(uint8_t, uint8_t);

	uint8_t x, y;

	// first is x, second is y
	std::pair<int8_t, int8_t> distance_to(Position);

	bool isEqualPosition(Position) const;
};