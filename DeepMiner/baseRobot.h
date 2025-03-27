#pragma once
#include <vector>

class BaseRobot
{
public:

	BaseRobot();
	~BaseRobot() = default;

	void setPosition(int x, int y);


	virtual int mine(std::vector<std::vector<std::vector<int>>>& world) = 0;

	void move(int x, int y);

	int getX() const { return x; }
	int getY() const { return y; }
	int getPoints() const { return points; }

	void addPoints(int points);
private:
	int x, y;
	int points;
	int shuffles;
};