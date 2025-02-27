#pragma once
#include "position.h"


class Rectangle
{
public:
	Rectangle(Position, double, double);

	void setPosition(double, double);
	double getArea();

	Position getBottomLeft();
	Position getTopRight();
private:
	double width, height;
	Position position;
};