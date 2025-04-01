#pragma once
#include <cstdint>


struct Position
{
	Position(int8_t x, int8_t y);
	int8_t x, y;
	
	bool isValid(int maxX, int maxY) const;
};