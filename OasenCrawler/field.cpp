#include <random>
#include "field.h"
#include "constants.h"

Field::Field(Type type, int8_t level, bool revealed) : type(type), revealed(revealed)
{
	this->stat = Stat();

	switch (type)
	{
	case Field::Empty:
		this->symbol = Constants::EMPTY_SYMBOL;
		break;
	case Field::Relic:
		this->symbol = Constants::RELIC_SYMBOL;
		this->revealed = true;
		break;
	case Field::Trap:
		this->symbol = Constants::TRAP_SYMBOL;

		switch (rand() % 3)
		{
		case 0:
			this->stat = Stat(Stat::Intelligence, level);
			break;
		case 1:
			this->stat = Stat(Stat::Luck, level);
			break;
		case 2:
			this->stat = Stat(Stat::Strength, level);
			break;
		}
		break;
	case Field::Well:
		this->symbol = Constants::WELL_SYMBOL;
		this->stat = Stat(Stat::Luck, level);
		break;
	default:
		this->symbol = '?'; // 'unknown field type	
		break;
	}
}

bool Field::isRevealed() const
{
	return this->revealed;
}

void Field::setRevealed(bool input)
{
	this->revealed = input;
}

char Field::getSymbol() const
{
	return this->symbol;
}

Stat Field::getStat() const
{
	return this->stat;
}

Field::Type Field::getType() const
{
	return this->type;
}