#include <iostream>
#include <iomanip>
#include "board.h"
#include "constants.h"


Board::Board(Player& player)
{
	// player with 5 hp
	this->player = &player;

	this->relicCount = 0;
	generateBoard();
}

Field::Type Board::randomFieldType() {

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
			// if the player is on the field, print the player symbol above all else

			if (this->player->getPosition().isEqualPosition(Position(i, j)))
			{
				std::cout << Constants::PLAYER_SYMBOL;

			}
			else {

				bool displayedEnemy = false;
				for (auto& enemy : this->enemies)
				{
					if (enemy.getPosition().isEqualPosition(Position(i, j))) {
						if (enemy.getPattern() == Enemy::Stationary)
						{
							auto distance = enemy.getPosition().distance_to(this->player->getPosition());

							if (std::abs(distance.first) <= 1 && ::abs(distance.second) <= 1)
							{
								displayedEnemy = true;
								std::cout << Constants::ENEMY_SYMBOL;
							}
						}
						else {
						displayedEnemy = true;
						std::cout << Constants::ENEMY_SYMBOL;
						break;
						}
					}
				}

				// dont show whats underneath the enemy
				if (!displayedEnemy) {

				if (this->playingField[i][j].isRevealed())
				{
					std::cout << this->playingField[i][j].getSymbol();
				}
				else {
					std::cout << "*";
				}
				}

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

void Board::printBoardStats() const
{
	std::cout << "----- Board -----\n";
	std::cout << "Level: " << (int)this->level << "\n";
	std::cout << "Relics left: " << (int)this->relicCount << "\n";
	std::cout << "\n";
}

bool wellLucky(int8_t luck);

void Board::processTurn()
{
	// check if player is on a field
	Position playerPosition = this->player->getPosition();
	Field& field = this->playingField[playerPosition.x][playerPosition.y];

	switch (field.getType())
	{
	case Field::Empty:
		break;
	case Field::Relic:
		std::cout << "You found a relic!\n";

		this->player->gainExperience();
		this->player->getRelic();

		// remove relic from board
		field = Field(Field::Empty);
		this->relicCount--;
		break;
	case Field::Trap:
		helperCaseTrap();

		field = Field(Field::Empty);
		break;
	case Field::Well:
		std::cout << "You found a well! Recover 1 hp!\n";
		player->heal(1);

		if (wellLucky(this->player->getStatFromType(Stat::Luck).value))
		{
			int random = rand() % 3;

			std::cout << "LUCKY!\n";
			switch (random)
			{
			case 0:
				std::cout << "Recover 1 hp!";
				this->player->heal(1);
				break;
			case 1:
				std::cout << "Found 1 exp!\n";
				this->player->gainExperience();
				break;
			case 2:
				std::cout << "Found 1 item!\n";
				this->player->gainItem();
				break;
			}
		}
		
		field = Field(Field::Empty);
		break;
	}

	// check if player is touching enemy
	// TODO: item (sword or sth) instakills 1 enemy and gives exp

	std::vector<Enemy>* vec = &this->enemies;
		
	for (auto enemy = vec->begin(); enemy != vec->end(); ) {
		if (enemy->getPosition().isEqualPosition(this->player->getPosition())) {
			std::cout << "Encountered enemy!";
			
			int8_t stat = this->player->getStatFromType(Stat::Strength).value;

			if (stat > 0 && (double)rand() / RAND_MAX < 30.0f / (float)stat)
			{
				std::cout << " Blocked enemy attack!\n";
			}
			else {
				std::cout << " Recieved " << (int)enemy->getDamage() << " damage.\n";
			
				player->takeDamage(enemy->getDamage());
			}

			
			enemy->takeDamage(1);

			std::cout << "Enemy recieved 1 damage!";

			std::cout << "\n";


		}

			if (enemy->getCurrentHp() == 0)
			{
				enemy = vec->erase(enemy);
				std::cout << " Enemy died :( +1 xp\n";
				this->player->gainExperience();
			}
			else {

				enemy++;
			}
	}

	// check if all relics are collected
	if (this->relicCount <= 0)
	{
		std::cout << "Found all relics! Difficulty increases!";
		this->level++;
		this->player->setPosition(Position(0, 0));
		this->generateBoard();

	}
}

void Board::moveEnemies()
{
	for (auto& enemy : this->enemies)
	{
		enemy.movePattern(this->player->getPosition());
	}
}

bool wellLucky(int8_t luck) {
	double random = (double)rand() / RAND_MAX;
	double chance = ((double)luck + 10) / 100.0f;

	if (random < chance)
	{
		return true;
	}

	return false;
}
void Board::helperCaseTrap() {
	Field field = this->playingField[this->player->getPosition().x][this->player->getPosition().y];

	int8_t playerStatLevel = this->player->getStatFromType(field.getStat().type).value;

	std::string statName = field.getStat().toString();

	std::cout << "You stepped on a level " << (int)field.getStat().value 
		<< " " << statName << " trap!\n";
	std::cout << "Your " << statName << " is: "
		<< (int)playerStatLevel << "\n";

	double multiplier = field.getStat().value - (int)playerStatLevel;

	// multiplier behaves normally until it is less than 1
	// multiplier scales down strongly after its below 1
	if (multiplier == 0)
	{
		multiplier = 1.0f;
	}
	else if (multiplier < 0) {
		multiplier = 1.0f / (1.0f + 0.4 * std::abs(multiplier));
	}
	else if (multiplier > 2) {
		multiplier = std::sqrt(multiplier) + 0.5f;
	}

	double hurtChance = Constants::RELIC_HURT_CHANCE * multiplier;

	std::cout << "Hurt chance is: " << std::fixed << std::setprecision(1) << hurtChance * 100 << "%" << "\n";
	
	char input = NULL;
	do
	{
		if (input == NULL)
		{
			std::cout << "Try your luck (1) or permanently loose 1 " << statName << " (2) to escape? ";
		}
		else {
			std::cout << "Invalid input, try again: ";
		}

		std::cin >> input;

	} while (input != '1' && input != '2');
	
	if (input == '1')
	{
		double random = (double)rand() / RAND_MAX;

		if (random < hurtChance)
		{
			std::cout << "You got hurt!\n";
			this->player->takeDamage(1);
		}
		else {
			std::cout << "You escaped!\n";
		}
	}
	else {
		if (this->player->getStatFromType(field.getStat().type).value < 1)
		{
			std::cout << "Not enough " << statName << "! You hurt yourself in confusion!";
			this->player->takeDamage(1);
			return;
		}
		this->player->reduceStat(field.getStat().type);
		std::cout << "You lost 1 " << statName << "!\n";
	}
}

void Board::generateBoard()
{
	
	// generate all enemies, their positions and types
	generateEnemies();

	// reset relic count before generating new board
	this->relicCount = 0;

	for (int i = 0; i < Constants::MAX_FIELDSIZE; i++)
	{
		for (int j = 0; j < Constants::MAX_FIELDSIZE; j++)
		{
			Field::Type type = randomFieldType();

			if (i == 0 && j == 0 && type == Field::Trap)
			{
				type = Field::Empty;
			}

			int8_t rngLevel = (this->level == 0) ? 0 : rand() % this->level;
			this->playingField[i][j] = Field(type, rngLevel);

			int8_t intelligence = player->getStatFromType(Stat::Intelligence).value;

			if (intelligence != 0 && (double)rand() / RAND_MAX < (double)intelligence / 100.0f) {
				this->playingField[i][j].setRevealed(true);
			}
			if (type == Field::Relic) this->relicCount++;
		}
	}

	// if there are no relics, then convert one empty space to a relic
	if (this->relicCount == 0)
	{
		for (int i = 0; i < Constants::MAX_FIELDSIZE; i++)
		{
			for (int j = 0; j < Constants::MAX_FIELDSIZE; j++)
			{
				if (this->playingField[i][j].getType() == Field::Empty) 
				{
					this->playingField[i][j] = Field(Field::Relic, this->level);
					this->relicCount++;
				}

			}
		}
	}
}

void Board::generateEnemies()
{
	for (int i = 0; i < 3; i++)
	{
		int rng = rand() % 3;

		if (rng == 1)
		{
			// spawns stationary enemy with 1 hp and 1 dmg in a random location (except the edges of the board)
			// this enemy is only visible if player is right next to it
			// can spawn on top of relics -> tough luck, get enough strength to try to win the fight
			this->enemies.push_back(Enemy(Enemy::Stationary, Position((rand() % 4) + 1, (rand() % 4) + 1), 1, 2));
		}
		else if (rng == 2)
		{
			// spawns chasing enemy with 1 hp and 1 dmg in the other corner (4,4)
			this->enemies.push_back(Enemy(Enemy::Random, Position(4,4), 1, 1));
		}
		else {
			// spawns randomly moving enemy with 2 hp and 2 dmg in a random location, except (0,0)

			int rngX = rand() % 5;
			int rngY = rand() % 5;

			if (rngX == 0 && rngY == 0)
			{
				rngX++;
			}

			this->enemies.push_back(Enemy(Enemy::Random, Position(rngX, rngY), 2, 1));
		}
	}
}
