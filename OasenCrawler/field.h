#pragma once
#include "position.h"
#include "constants.h"

class Field
{
public:
	enum Type {
		Empty,
		Relic,
		Trap,
		Well,
	};

	// Position Object, Type Object, Is Revealed
	Field(Position = Position(0,0), Type = Empty, bool = false);

	Position getPosition() const;
	bool isRevealed() const;
	char getSymbol() const;

	Constants::Stat getStat() const;
	Type getType() const;

private:
	Position position;
	Type type;
	
	bool revealed;
	char symbol;

	Constants::Stat stat;
};
