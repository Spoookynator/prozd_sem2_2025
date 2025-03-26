#pragma once
#include <vector>

class Game
{
public:
	Game(int);
	~Game();

	void generateWorld(int x, int y, int z);
private:
	std::vector<std::vector<std::vector<int>>> world;
	int maxPoints;
};