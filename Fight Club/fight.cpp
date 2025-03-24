#include "fight.h"
#include <iostream>
#include <random>

void printCharacter(Character* c)
{
	std::cout << "--------------------------------" << std::endl;

	std::cout << c->getName() << " has " << c->getHp() << " hp and " << c->getMana() << " mana." << std::endl;
	std::cout << "--------------------------------" << std::endl;
}

int chooseAbility(Character* c)
{
	int choice;
	std::cout << "Choose an ability for " << c->getName() << std::endl;
	std::cout << "1. " << c->getAbility1Name() << std::endl;
	std::cout << "2. " << c->getAbility2Name() << std::endl;
	std::cin >> choice;
	return choice;
}


void startFight(Character* c1, Character* c2)
{
	while (true) {
		c1->changeMana(c1->getManaRegen());
		c2->changeMana(c2->getManaRegen());

		printCharacter(c1);
		printCharacter(c2);

		if (c1->getIsCpu())
		{
			std::random_device rd;  // Uses a hardware entropy source if available
			std::mt19937 gen(rd()); // Mersenne Twister PRNG seeded with rd
			std::uniform_int_distribution<int> dist(1, 100);

			if (dist(gen) <= 50)
			{
				c1->useAbility1(c2);
			}
			else
			{
				c1->useAbility2(c2);
			}
		}
		else
		{
			int choice = chooseAbility(c1);
			if (choice == 1)
			{
				c1->useAbility1(c2);
			}
			else
			{
				c1->useAbility2(c2);
			}
		}

		if (c2->isDead())
		{
			std::cout << c2->getName() << " has died!" << std::endl;
			c2->addLoss();
			c1->addWin();
			break;
		}

		if (c2->getIsCpu())
		{
			std::random_device rd;  // Uses a hardware entropy source if available
			std::mt19937 gen(rd()); // Mersenne Twister PRNG seeded with rd
			std::uniform_int_distribution<int> dist(1, 100);
			if (dist(gen) <= 50)
			{
				c2->useAbility1(c1);
			}
			else
			{
				c2->useAbility2(c1);
			}
		}
		else
		{
			int choice = chooseAbility(c2);
			if (choice == 1)
			{
				c2->useAbility1(c1);
			}
			else
			{
				c2->useAbility2(c1);
			}
		}

		if (c1->isDead())
		{
			std::cout << c1->getName() << " has died!" << std::endl;
			c1->addLoss();
			c2->addWin();
			break;
		}
	}
}