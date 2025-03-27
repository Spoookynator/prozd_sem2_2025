#pragma once
#include "world.h"
#include <array>
#include <cmath>
#include <random>

#include <iostream>

World::World(int maxPoints)
{
	this->maxPoints = 0;

	this->x = 0;
	this->y = 0;
	this->z = 0;
}

World::~World()
{
}


void World::generateWorld(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	
	this->maxPoints = 0;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 9);

	std::uniform_int_distribution<> negativeChance(1, 100);
	std::uniform_int_distribution<> negative(-3, -1);

	std::vector<std::vector<int>> intermediary;

	this->world.resize(x, std::vector<std::vector<int>> (y, std::vector<int>(z)));

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < z; k++) {
				if (negativeChance(gen) <= 5)
				{
					world.at(i).at(j).at(k) = negative(gen);
				}
				else {
					int value = dis(gen);
					world.at(i).at(j).at(k) = value;

					this->maxPoints += value;
				}
				
			}
		}
	}

}

char getLayerChar(double percent) {
	char layers[10] = { '.', ',', ':', '-', '+', '!', '?', '%', '#', '@' };

	int index = std::floor(percent * 10) - 1;

	if (index >= 10) {
		index = 9;
	}

	if (index == 0)
	{
		return ' ';
	}
	return layers[index];
}

void World::printWorld(int p1X, int p1Y, int p2X, int p2Y)
{
	std::cout << "World:\n";

	for (int i = 0; i < world.size(); i++)
	{
		for (int j = 0; j < world.at(0).size(); j++)
		{
			double percent = (double)world.at(i).at(j).size() / (double)this->z;

			if (i == p1X && j == p1Y)
			{
				std::cout << "\033[32m" << getLayerChar(percent) << "\033[0m" << " ";
			}
			else if (i == p2X && j == p2Y)
			{
				std::cout << "\033[31m" << getLayerChar(percent) << "\033[0m" << " ";
			}
			else

			std::cout << getLayerChar(percent) << " ";
		}
		
		std::cout << "\n";
	}
}

void World::shuffleWord()
{
}
