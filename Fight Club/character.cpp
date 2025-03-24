#include "character.h"
#include <string>
#include "ability.h"

Character::Character(std::string name, int maxHp, int maxMana)
{
	this->hp = maxHp;
	this->maxHp = maxHp;
	this->mana = maxMana;
	this->maxMana = maxMana;
	this->name = name;
}

Character::~Character()
{
	delete ability1;
	delete ability2;
}

void Character::setAbility1(Ability* ab)
{
	ability1 = ab;
}

void Character::setAbility2(Ability* ab)
{
	ability2 = ab;
}

std::string Character::getAbility1Name()
{
	if (this->ability1 != nullptr)
	{
		return ability1->getName();
	}
	else {
		return "Not Set";
	}
}

std::string Character::getAbility2Name()
{
	if (this->ability2 != nullptr)
	{
		return ability2->getName();
	}
	else {
		return "Not Set";
	}
}

int Character::getHp()
{
	return hp;
}

int Character::getMana()
{
	return mana;
}

int Character::getMaxHp()
{
	return maxHp;
}

int Character::getMaxMana()
{
	return maxMana;
}

void Character::changeHp(int hp)
{
	if (this->hp + hp < 0)
	{
		this->hp = 0;
	}
	else if (this->hp + hp > maxHp)
	{
		this->hp = maxHp;
	}
	else
	{
		this->hp += hp;
	}
}

void Character::changeMana(int mana)
{
	if (this->mana + mana < 0)
	{
		this->mana = 0;
	}
	else if (this->mana + mana > maxMana)
	{
		this->mana = maxHp;
	}
	else
	{
		this->mana += mana;
	}
}

std::string Character::getName()
{
	return this->name;
}

bool Character::useAbility1(Character* target)
{
	return this->ability1->useOn(this, target);
}

bool Character::useAbility2(Character* target)
{
	return this->ability2->useOn(this, target);
}

bool Character::getIsCpu()
{
	return isCpu;
}

void Character::setIsCpu(bool isCpu)
{
	this->isCpu = isCpu;
}


Fighter::Fighter(std::string name) : Character(name, 100, 50)
{
	setAbility1(new Bite);
	setAbility2(new Slap);
}

Healer::Healer(std::string name) : Character(name, 70, 100)
{
	setAbility1(new Heal);
	setAbility2(new GenderSwap);
}

Gambler::Gambler(std::string name) : Character(name, 77, 177)
{
	setAbility1(new GenderSwap);
	setAbility2(new Slap);
}
