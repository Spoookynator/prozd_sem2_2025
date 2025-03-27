#pragma once
#include <vector>

class World
{
public:
	World(int maxPoints);
	~World();

	void generateWorld(int x, int y, int z);

	void printWorld(int p1X = -1, int p1Y = -1, int p2X = -1, int p2Y = -1);

	void shuffleWord();

	auto& getWorld() { return world; }

private:
	std::vector<std::vector<std::vector<int>>> world;
	int maxPoints;

	int x, y, z;
};