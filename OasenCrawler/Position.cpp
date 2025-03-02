#include "Position.h"

Position::Position(uint8_t x, uint8_t y) {
	this->x = x;
	this->y = y;
}

std::pair<int8_t, int8_t> Position::distance_to(Position pos)
{
	int8_t x_distance = this->x - pos.x;
	int8_t y_distance = this->y - pos.y;

	return std::make_pair(x_distance, y_distance);
}

bool Position::isEqualPosition(Position p) const
{
	bool sameX = this->x == p.x;
	bool sameY = this->y == p.y;

	return (sameX && sameY);
}
