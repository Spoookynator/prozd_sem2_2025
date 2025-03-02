#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	enum Pattern
	{
		Random,
		Chase,
		Stationary,
	};
	
	Enemy(Pattern, Position,int8_t, int8_t);

	void movePattern(Position);

	int8_t getDamage() const;

	Pattern getPattern() const;

private:
	int damage;
	Pattern pattern;
};