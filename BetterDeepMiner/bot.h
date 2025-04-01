#pragma once
#include "position.h"
#include "map.h"

enum Direction
{
	Left,
	Right,
	Up,
	Down,
	Still
};

class Bot
{
public:
	Bot(bool isCpu, Position position) : position(position)
	{
		this->isCpu = isCpu; 
		this->score = 0; 
	};

	virtual int mine(Map3D& map) = 0;

	bool step(Direction dir);

	bool getIsCpu() const { return this->isCpu; };

	Position getPos() const { return this->position; };

	int getScore() { return this->score; };
protected:
	int score;
	bool isCpu;

	Position position;
private:

};