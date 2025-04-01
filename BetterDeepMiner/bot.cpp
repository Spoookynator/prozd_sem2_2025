#include "bot.h"

bool Bot::step(Direction dir)
{
	switch (dir)
	{
	case Left:
		if (this->position.y - 1 < 0) return false;
		this->position.y -= 1;
		break;
	case Right:
		if (this->position.y + 1 > 4) return false;
		this->position.y += 1;
		break;
	case Up:
		if (this->position.x - 1 < 0) return false;
		this->position.x -= 1;
		break;
	case Down:
		if (this->position.x + 1 > 4) return false;
		this->position.x += 1;
		break;
	case Still:
		break;
	default:
		return false;
	}

	return true;
}
