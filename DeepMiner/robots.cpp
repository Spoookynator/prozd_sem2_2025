#include "robots.h"
#include <random>
#include "misc.h"

#include <iostream>

int MathBot::mine(std::vector<std::vector<std::vector<int>>>& world)
{

	auto& z = world.at(getX()).at(getY());

	if (z.empty())
	{
		return 0;
	}

	sortVector(z, false);

	int points = z.back();

	addPoints(points);

	z.pop_back();

	return points;
}

int DoubleBot::mine(std::vector<std::vector<std::vector<int>>>& world)
{
	auto& z = world.at(getX()).at(getY());
	if (z.empty())
	{
		return 0;
	}
	int points = 0;

	for (int i = 0; i < 2; i++)
	{
		points += z.back();	
		z.pop_back();
	}

	this->addPoints(points);
	return points;
}

int GamblerBot::mine(std::vector<std::vector<std::vector<int>>>& world)
{
	auto& z = world.at(getX()).at(getY());

	if (z.empty())
	{
		return 0;
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 1);

	int points = 0;

	if (dis(gen))
	{
		points += z.back() * 2;
	}
	else {
		points += z.back() / 2; 
	}
	
	z.pop_back();
	addPoints(points);
	return points;
}
