#include "rectangle.h"

Rectangle::Rectangle(Position position, double width, double height)
{
	this->width = width;
	this->height = height;
	this->position = position;
}

void Rectangle::setPosition(double, double)
{
}

double Rectangle::getArea()
{
	return this->width * this->height;
}

Position Rectangle::getBottomLeft()
{	

	double x = this->position.x - this->width;
	double y = this->position.y - this->height;
	Position posBl = Position(x, y);

	return posBl;
}

Position Rectangle::getTopRight()
{
	return this->position;
}
