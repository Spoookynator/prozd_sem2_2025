#pragma once
#include <stdint.h>
#include "stat.h"

class Field
{
public:
	enum Type {
		Empty,
		Relic,
		Trap,
		Well,
	};



	// Type of field, field level, is revealed
	Field(Type = Empty,int8_t = 0, bool = false);

	bool isRevealed() const;

	void setRevealed(bool);
	char getSymbol() const;

	Stat getStat() const;
	Type getType() const;


private:
	Type type;
	
	bool revealed;
	char symbol;

	Stat stat;
};
