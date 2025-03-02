#pragma once
#include <stdint.h>
#include <string>

// Intelligence: chance of revealing tiles
// Strength: chance of defeating enemies
// Luck: chance of getting more health from wells
struct Stat
{
	enum Type {
		None,
		Intelligence,
		Strength,
		Luck,
	};
	int8_t value;
	Type type;

	Stat(Type = None, int8_t = 0);

	std::string toString() const;
	
};