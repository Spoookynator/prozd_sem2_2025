#pragma once
#include "entity.h"
#include "stat.h"

class Player : public Entity
{
public:
	Player(int32_t);
	~Player();

	bool moveNorth();

	bool moveSouth();

	bool moveEast();

	bool moveWest();

	void printStats() const;

	void gainExperience();

	void getRelic();

	Stat getStatFromType(Stat::Type);

	void reduceStat(Stat::Type);

	void gainItem(Stat::Type = Stat::None); 

private:
	void levelUp();	

	int32_t getRequiredExp() const;
	int8_t relicCount;
	int8_t level;
	int32_t experience;

	Stat intelligence;
	Stat strength;
	Stat luck;
};