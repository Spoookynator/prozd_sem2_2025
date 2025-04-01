#include "bots.h"

int Doublebot::mine(Map3D& map)
{
	int points = 0;

	for (int i = 0; i < 2; i++)
	{
		points += map.minePosition(this->position);
	}

	this->score += points;
	return points;
}

int SortBot::mine(Map3D& map)
{
	int points = 0;
	map.sortPosition(this->position, Ascending);
	points += map.minePosition(this->position);

	this->score += points;

	return points;
}

int TripleBot::mine(Map3D& map)
{
	map.sortPosition(this->position, Descending);

	int points = 0;

	for (int i = 0; i < 3; i++)
	{
		points += map.minePosition(this->position);
	}

	points *= 0.7; // für nächste stufe weg

	this->score += points;
	return points;
}
