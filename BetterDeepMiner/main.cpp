#include <iostream>
#include "map.h"
#include "bot.h"
#include "input.h"

int main() {
	Map3D map(5,5,10);
	Bot* p1 = nullptr;
	Bot* p2 = nullptr;

	selectBotTypes(p1, p2);

	while (!map.isEmpty()) {
		map.display(10, p1->getPos(), p2->getPos());
		handleBotInput(p1);
		p1->mine(map);
		handleBotInput(p2);
		p2->mine(map);
	}

	std::cout << "P1 Points: " << p1->getScore() << "\n";
	std::cout << "P2 Points: " << p2->getScore() << "\n";

	if (p1->getScore() > p2->getScore())
	{
		std::cout << "P1 Won!" << "\n";
	}
	else if (p1->getScore() < p2->getScore()) {
		std::cout << "P2 Won!" << "\n";

	}
	else {
		std::cout << "Tied!" << "\n";

	}
}