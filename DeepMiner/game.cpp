#pragma once
#include "game.h"
#include <array>
#include <cmath>
#include <random>

Game::Game(int maxPoints)
{
	this->maxPoints = 0;
}

Game::~Game()
{
}


void Game::generateWorld(int x, int y, int z)
{
	int total = 0;
	int totalBlocks = x * y * z;
	std::vector<int> values;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 9);

	for (int i = 0; i < totalBlocks; i++)
	{
		values.push_back(dis(gen));
		total++;
	}
	

	int vPos = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; i++) {
			for (int k = 0; k < z; k++)
			{
				world.at(i).at(j).at(k) = values.at(vPos);
				vPos++;
			}
		}
	}
	int x = 5, y = 5, z = 10;
}
