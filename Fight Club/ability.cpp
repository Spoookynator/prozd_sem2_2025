#include "ability.h"
#include <random>
#include <iostream>
#include <string>
#include "character.h"

bool Heal::useOn(Character* self, Character* target)
{
	if (self->getHp() == self->getMaxHp() || self->getMana() < 10)
	{
		std::cout << "Hp is full!" << std::endl;
		return false;
	}

	self->changeHp(10);
	self->changeMana(-10);

	std::cout << target->getName() << " healed " << target->getName() << " for 10 hp!" << std::endl;
	return true;
}

bool GenderSwap::useOn(Character* self, Character* target)
{
	if (self->getMana() < 25) return false;

	self->changeMana(-25);

	std::random_device rd;  // Uses a hardware entropy source if available
	std::mt19937 gen(rd()); // Mersenne Twister PRNG seeded with rd
	std::uniform_int_distribution<int> dist(1, 100);

	if (dist(gen) <= 40)
	{
		int damage = (double)target->getMaxHp() * -0.25f;
		target->changeHp(damage);
		std::cout << "Uh oh, spell failed, dealt " << damage << " damage to " << target->getName() << std::endl;
	}
	else {
		std::cout << "Swapped gender without incident :)" << std::endl;
	}

	return false;
}

bool Bite::useOn(Character* self, Character* target)
{
	self->changeMana(9);
	self->changeHp(7);

	target->changeHp(-10);
	target->changeMana(-2);

	std::cout << self->getName() << " bit " << target->getName() << " for 10 damage! Heal by 7 and regenerate 9 Mana." << std::endl;

	return true;
}

bool Slap::useOn(Character* self, Character* target)
{
	if (self->getMana() != self->getMaxMana())
	{
		std::cout << "You don't have enough mana to slap!" << std::endl;
		return false;
	}

	self->changeMana(-self->getMaxMana());

	self->changeHp(-10);
	target->changeHp(-target->getMaxHp() + 1);

	std::cout << target->getName() << " slapped " << target->getName() << " for " << target->getMaxHp() - 1 << " damage! You loose 10 hp." << std::endl;
	return true;
}
