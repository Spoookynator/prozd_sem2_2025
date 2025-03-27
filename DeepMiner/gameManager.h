#pragma once
#include "baseRobot.h"
#include "world.h"

class GameManager
{
public:
	GameManager();


	void startGame(World& world);
private:
	int totalCollectedPoints;
	int gamesPlayed;
	int gamesWon;

	BaseRobot* robots[3]; // stores all the robot types
};