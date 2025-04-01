#include "position.h"
#include "log.h"

Position::Position(int8_t x, int8_t y)
{
	this->x = x;
	this->y = y;
}

bool Position::isValid(int maxX, int maxY) const
{
	if (this->x < 0 || this->y < 0 || this->x > maxX || this->y > maxY)
	{
		LOG("Invalid Position: (%d,%d)", this->x, this->y);
		return false;
	}

	return true;
}
