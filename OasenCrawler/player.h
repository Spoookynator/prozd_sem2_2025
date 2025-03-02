#pragma once
#include "entity.h"
#include "stat.h"

class Player : public Entity
{
public:
	Player(int32_t);
	~Player();

	// movement
	bool moveNorth();
	bool moveSouth();
	bool moveEast();
	bool moveWest();

	void printStats() const;

	void gainExperience();
	void gainItem(Stat::Type = Stat::None); 

	void getRelic();

	Stat getStatFromType(Stat::Type);

	void reduceStat(Stat::Type);

	bool useSword();
	bool useScroll();
	bool usePotion();


private:
	void levelUp();	

	int32_t getRequiredExp() const;
	int8_t relicCount;
	int8_t level;
	int32_t experience;

	Stat intelligence;
	Stat strength;
	Stat luck;

	// items, which are just simple integers since it would not make sense to make a whole new class for them
	// this game is not focused on the items, they are kinda just a side thing, so an intricate item system would just be wasted time and effort
	int8_t swords;
	int8_t teleportScrolls;
	int8_t potions;
};