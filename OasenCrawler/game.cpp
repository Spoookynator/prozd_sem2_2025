#include <iostream>
#include "game.h"
#include "player.h"
#include "board.h"

char playerMoveInput(Player&);


void Game::startGame()
{
	srand(time(NULL));

	Player player(Constants::PLAYER_HP);
	Board board(player);
	while (true)
	{
		// show
		board.processTurn();

		board.printBoard();
		board.printBoardStats();

		player.printStats();

		// check if player is dead
		// check if player has potion - use that instead
		if (player.getCurrentHp() <= 0)
		{
			if (player.usePotion())
			{
				std::cout << "You almost died, but your potion saved you!\n";
				player.heal(1);
			}
			else {
				break;
			}
			
		}

		// input
		playerMoveInput(player);

		board.moveEnemies();
		// if player is on a field, do field action
		// check if enemy is on same field as player


		// clear console depending on os
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
	}
}

bool movePlayer(Player& player, char direction);

char playerMoveInput(Player& player)
{
	char input = NULL;
	do
	{
		if (input == NULL)
		{
			std::cout << "Enter a direction (w,a,s,d): ";

		}
		else {
			std::cout << "Invalid input, please enter a direction (w,a,s,d): ";
		}

		std::cin >> input;

		if (movePlayer(player, input)) {
			break;
		}

	} while (true);

	return input; 
}

bool movePlayer(Player& player, char direction) {
	switch (direction)
	{
	case 'w':
		return player.moveNorth();
	case 'a':
		return player.moveWest();
	case 's':
		return player.moveSouth();
	case 'd':
		return player.moveEast();
	default:
		return false;
	}
}