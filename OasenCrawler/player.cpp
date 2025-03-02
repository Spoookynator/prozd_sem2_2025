#include <iostream>
#include "player.h"


Player::Player(int32_t hp) : Entity(Position(0, 0), hp)
{
	this->relicCount = 0;
	this->intelligence.value = 0;
	this->strength.value = 0;
	this->luck.value = 0;
	this->level = 0;
	this->experience = 0;
}

Player::~Player()
{
}

bool Player::moveNorth()
{
	return this->move(-1,0);
}

bool Player::moveSouth()
{
	return this->move(1, 0);
}

bool Player::moveEast()
{
	return this->move(0, 1);

}

bool Player::moveWest()
{
	return this->move(0, -1);
}

void Player::printStats() const
{
	std::cout << "----- Player -----\n";
	std::cout << "Level: " << (int)this->level << ", ";
	std::cout << "Exp: " << (int)this->experience << "/" << (int)this->getRequiredExp() << "\n";
	std::cout << "Relics: " << (int)this->relicCount << "\n";
	std::cout << "Health: " << (int)this->getCurrentHp() << "/" << (int)this->getMaxHp() << "\n";
	std::cout << "Intelligence: " << (int)this->intelligence.value << ", ";
	std::cout << "Strength: " << (int)this->strength.value << ", ";
	std::cout << "Luck: " << (int)this->luck.value << "\n";
	std::cout << "\n";
}

void Player::gainExperience()
{
	this->experience++;
	if (this->experience >= this->getRequiredExp())
	{
		this->experience = 0;
		this->levelUp();
	}
}

void Player::getRelic()
{
	this->relicCount++;
}

Stat Player::getStatFromType(Stat::Type type)
{
	switch (type)
	{
	case Stat::Intelligence:
		return this->intelligence;
	case Stat::Strength:
		return this->strength;
	case Stat::Luck:
		return this->luck;
	default:
		return this->intelligence;
	}
}

void Player::reduceStat(Stat::Type type)
{
	switch (type)
	{
	case Stat::Intelligence:
		this->intelligence.value--;
		break;
	case Stat::Strength:
		this->strength.value--;
		break;
	case Stat::Luck:
		this->luck.value--;
		break;

	default:
		break;
	}
}

void Player::gainItem(Stat::Type)
{

}


void Player::levelUp()
{
	this->level++;

	char input = NULL;
	do
	{
		if (input == NULL)
		{
			std::cout << "You have leveled up! Choose a stat to increase (i, s, l): ";
		}
		else {
			std::cout << "Invalid input, please choose a stat to increase (i, s, l): ";
		}
		std::cin >> input;

		switch (input)
		{
		case 'i':
			this->intelligence.value++;
			return;
		case 's':
			this->strength.value++;
			return;
		case 'l':
			this->luck.value++;
			return;
		default:
			break;
		}
	} while (true);
}

int32_t Player::getRequiredExp() const
{
	if (this->level == 0)
	{
		return 1;
	}

	return this->level;
}
