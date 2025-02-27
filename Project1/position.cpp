#include <iostream>
#include "position.h"

Position::Position(double x, double y) {
	this->x = x;
	this->y = y;
}

void Position::print() {
	std::cout << "(" << this->x << ", " << this->y << ")";
}

