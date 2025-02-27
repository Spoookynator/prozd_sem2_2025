#include <random>
#include "field.h"
#include "constants.h"

Field::Field(Position pos, Type type, bool revealed) : position(pos), type(type), revealed(revealed)
{
	this->stat = Constants::Stat::None;
	this->revealed = false;

	switch (type)
	{
	case Field::Empty:
		this->symbol = Constants::EMPTY_SYMBOL;
		break;
	case Field::Relic:
		this->symbol = Constants::RELIC_SYMBOL;
		this->stat = Constants::Stat::Intelligence;
		this->revealed = true;
		break;
	case Field::Trap:
		this->symbol = Constants::TRAP_SYMBOL;

		switch (rand() % 3)
		{
		case 0:
			this->stat = Constants::Stat::Intelligence;
			break;
		case 1:
			this->stat = Constants::Stat::Luck;
			break;
		case 2:
			this->stat = Constants::Stat::Dexterity;
			break;
		}
		break;
	case Field::Well:
		this->symbol = Constants::WELL_SYMBOL;
		this->stat = Constants::Stat::Luck;
		break;
	default:
		this->symbol = '?'; // 'unknown field type	
		break;
	}
}

Position Field::getPosition() const
{
	return this->position;
}

bool Field::isRevealed() const
{
	return this->revealed;
}

char Field::getSymbol() const
{
	return this->symbol;
}

Constants::Stat Field::getStat() const
{
	return this->stat;
}

Field::Type Field::getType() const
{
	return this->type;
}
