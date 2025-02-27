#pragma once

struct Position
{
	Position(double, double);
	Position() = default;
	
	void print();
	double x, y;
};