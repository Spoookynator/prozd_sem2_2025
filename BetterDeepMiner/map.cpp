#include "map.h"
#include <random>
#include <algorithm>
#include <iostream>

#include "log.h"


Map3D::Map3D(int8_t sizeX, int8_t sizeY, int8_t sizeZ)
{
	this->map.resize(sizeX, std::vector<std::vector<int>>(sizeY, std::vector<int>(sizeZ)));

	LOG("Resized Map to (%d, %d, %d)", sizeX, sizeY, sizeZ);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 9);

	for (auto& vec : this->map)
	{
		for (auto& vec2 : vec)
		{
			for (auto& num : vec2)
			{
				num = dis(gen);
			}
		}
	}

	LOG("Generated Map");
}

void sortRandom(std::vector<int>& vec);

void sortAscending(std::vector<int>& vec);

void sortDescending(std::vector<int>& vec);

void Map3D::sortPosition(Position pos, Sort sort)
{	

	if (!pos.isValid(this->map.size(), this->map.at(0).size())) return;
	if (this->map.at(pos.x).at(pos.y).empty()) return;

	auto& vec = this->map.at(pos.x).at(pos.y);

	switch (sort)
	{
	case Random:
		sortRandom(vec);
		LOG("Sorted Vec Random");
		break;
	case Ascending:
		sortAscending(vec);
		LOG("Sorted Vec Ascending");
		break;
	case Descending:
		sortDescending(vec);
		LOG("Sorted Vec Descending");

		break;
	default:
		break;
	}
}

void Map3D::printPosition(Position pos)
{
	if (!pos.isValid(this->map.size(), this->map.at(0).size())) return;

	for (auto& num : this->map.at(pos.x).at(pos.y))
	{
		std::cout << num << " ";
	}

	std::cout << "\n";
}

int Map3D::minePosition(Position pos)
{
    if (this->map.at(pos.x).at(pos.y).empty()) {
        return 0;
    }

    int points = this->map.at(pos.x).at(pos.y).back();
    this->map.at(pos.x).at(pos.y).pop_back(); 

    return points;
}


char getLayerChar(double percent) {
	char layers[10] = { '.', ',', ':', '-', '+', '!', '?', '%', '#', '@' };

	int index = std::floor(percent * 10) - 1;

	if (index >= 10) {
		index = 9;
	}

	if (index < 0)
	{
		return ' ';
	}
	return layers[index];
}

void Map3D::display(int max, Position p1, Position p2)
{
	std::cout << "World:\n";

	for (int i = 0; i < this->map.size(); i++)
	{
		for (int j = 0; j < this->map.at(0).size(); j++)
		{
			double percent = (double)this->map.at(i).at(j).size() / (double)max;

			if (i == p1.x && j == p1.y)
			{
				char c = getLayerChar(percent);

				if (c == ' ') c = 'o';
				std::cout << "\033[32m" << c << "\033[0m" << " ";
			}
			else if (i == p2.x && j == p2.y)
			{
				char c = getLayerChar(percent);

				if (c == ' ') c = 'o';
				std::cout << "\033[31m" << c << "\033[0m" << " ";
			}
			else
			{
				std::cout << getLayerChar(percent) << " ";
			}
		}

		std::cout << "\n";
	}
}

bool Map3D::isEmpty()
{
	for (const auto& x_layer : map) {
		for (const auto& y_column : x_layer) {
			if (!y_column.empty()) {
				return false;
			}
		}
	}
	return true;
}

void sortRandom(std::vector<int>& vec) {

	if (vec.size() <= 1) return;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, vec.size() - 1);

	for (int i = 0; i < vec.size(); i++)
	{
		std::swap(vec.at(i), vec.at(dis(gen)));
	}
}

void sortAscending(std::vector<int>& vec)
{
	std::sort(vec.begin(), vec.end());
}

void sortDescending(std::vector<int>& vec)
{
	std::sort(vec.begin(), vec.end(), std::greater<int>());
}
