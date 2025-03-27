#include "baseRobot.h"

BaseRobot::BaseRobot()
{
	points = 0;
	x = 0;
	y = 0;
	shuffles = 0;
}

void BaseRobot::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void BaseRobot::move(int x, int y)
{
	this->x += x;
	this->y += y;
}

void BaseRobot::addPoints(int points)
{
	this->points += points;
}
