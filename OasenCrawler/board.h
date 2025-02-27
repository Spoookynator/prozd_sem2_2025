#pragma once
#include "field.h"
#include "constants.h"

class Board 
{
public:
	Board();
	void printBoard() const;
private:
	Field playingField[Constants::MAX_FIELDSIZE][Constants::MAX_FIELDSIZE];
	
	int8_t relicCount;
	int8_t enemyCount;

	void generateBoard();
};

Field::Type randomFieldType();