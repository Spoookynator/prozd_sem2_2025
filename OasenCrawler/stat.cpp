#include "stat.h"

Stat::Stat(Type type, int8_t value) : type(type), value(value)
{}

std::string Stat::toString() const
{
	switch (this->type)
	{
	case Intelligence:
		return "Intelligence";
	case Strength:
		return "Strength";
	case Luck:
		return "Luck";
	default:
		return "None";
	}
}
