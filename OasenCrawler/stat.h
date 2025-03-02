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

	Stat(Type = None, int8_t = 0);

	int8_t value;
	Type type;

	std::string toString() const;
};