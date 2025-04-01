#pragma once
#include <vector>
#include "position.h"
typedef std::vector < std::vector<std::vector<int>>> vector3D;
 
enum Sort
{
	Random,
	Ascending,
	Descending
};

class Map3D
{
public:
	Map3D(int8_t sizeX, int8_t sizeY, int8_t sizeZ);

	void sortPosition(Position pos, Sort sort);

	void printPosition(Position pos);

	int minePosition(Position pos);

	void display(int max, Position p1 = Position(-1,-1), Position p2 = Position(-1, -1));

	bool isEmpty();
private:
	vector3D map;
};