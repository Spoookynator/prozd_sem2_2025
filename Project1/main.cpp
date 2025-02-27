#include <iostream>
#include "position.h"
#include "rectangle.h"


int main() {
	Rectangle rect = Rectangle(Position(1.3f, 2.01f), 4.2f, 3.4f);

	std::cout << "Bottom Left: ";
	rect.getBottomLeft().print();

	std::cout << "\n";

	std::cout << "Top Right: ";
	rect.getTopRight().print();
	std::cout << "\n";


	std::cout << "Area: " << rect.getArea() << "\n";
	

}