#pragma once
#include <vector>
#include "field.h"
#include "constants.h"
#include "enemy.h"
#include "player.h"

class Board 
{
public:
	Board(Player& player);

	void printBoard() const;

	void printBoardStats() const;

	void processTurn();

	void moveEnemies();

	Player* player;
	
private:
	Field playingField[Constants::MAX_FIELDSIZE][Constants::MAX_FIELDSIZE];
	
	int8_t relicCount;
	int8_t level;
	
	std::vector<Enemy> enemies;
	
	void generateBoard();

	void generateEnemies();

	static Field::Type randomFieldType();

	void helperCaseTrap();
};

