#include <iostream>
#include "board.h"


Board::Board() : relicCount(0), enemyCount(0)
{
	generateBoard();
}

Field::Type randomFieldType() {

	int8_t weights[4] = { Constants::EMPTY_FIELD_WEIGHT, Constants::TRAP_FIELD_WEIGHT, Constants::RELIC_FIELD_WEIGHT, Constants::WELL_FIELD_WEIGHT };
	
	int totalWeights = 0;
	
	for (int i = 0; i < 4; i++) {
		totalWeights += weights[i];
	}

	int randomNumber = rand() % totalWeights;

	for (int i = 0; i < 4; i++) {
		if (randomNumber < weights[i]) {
			switch (i) {
			case 0:
				return Field::Empty;
			case 1:
				return Field::Trap;
				break;
			case 2:
				return Field::Relic;
				break;
			case 3:
				return Field::Well;
				break;
			}
			return Field::Empty;
		}
		randomNumber -= weights[i];
	}
}

void Board::printBoard() const
{
	std::cout << "\n";
	for (int i = 0; i < Constants::MAX_FIELDSIZE; i++)
	{
		for (int k = 0; k < Constants::PRINT_FIELD_SPACING; k++)
		{
			std::cout << " ";
		}

		for (int j = 0; j < Constants::MAX_FIELDSIZE; j++)
		{
			if (this->playingField[i][j].isRevealed())
			{
				std::cout << this->playingField[i][j].getSymbol();
			}
			else {
				std::cout << Constants::EMPTY_SYMBOL;
			}
			
			if (j < Constants::MAX_FIELDSIZE - 1)
			{

				for (int k = 0; k < Constants::PRINT_FIELD_SPACING; k++)
				{
					std::cout << " ";
				}
			}
		}
		for (int k = 0; k < Constants::PRINT_FIELD_SPACING / 2; k++)
		{
			std::cout << "\n";
		}
	}
}

void Board::generateBoard()
{
	// reset relic count before generating new board
	this->relicCount = 0;

	for (int i = 0; i < Constants::MAX_FIELDSIZE; i++)
	{
		for (int j = 0; j < Constants::MAX_FIELDSIZE; j++)
		{
			Field::Type type = randomFieldType();
			this->playingField[i][j] = Field(Position(i, j), type);
			std::cout << "(" << this->playingField[i][j].getSymbol() << ", " << this->playingField[i][j].getStat() << ")" << "\n";

			if (type == Field::Relic) this->relicCount++;
		}
	}

	if (this->relicCount == 0)
	{
		for (int i = 0; i < Constants::MAX_FIELDSIZE; i++)
		{
			for (int j = 0; j < Constants::MAX_FIELDSIZE; j++)
			{
				if (this->playingField[i][j].getType() == Field::Empty) this->playingField[i][j] = Field(Position(i, j), Field::Relic);
			}
		}
	}
}
