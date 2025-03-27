#include "gameManager.h"
#include <iostream>
#include <random>
#include "robots.h"
#include "world.h"

GameManager::GameManager()
{
	totalCollectedPoints = 0;
	gamesPlayed = 0;
	gamesWon = 0;

	robots[0] = new MathBot();
	robots[1] = new DoubleBot();
	robots[2] = new GamblerBot();
}

void showMenu() {
    std::cout << "Choose your robot:\n";
    std::cout << "1. MathBot\n";
    std::cout << "2. DoubleBot\n";
    std::cout << "3. GamblerBot\n";
    std::cout << "Enter your choice (1-3): ";
}
void showCPUMenu() {
    std::cout << "\nUse CPU to play?\n";
    std::cout << "1. Yes (CPU plays)\n";
    std::cout << "2. No (You play)\n";
    std::cout << "Enter your choice (1-2): ";
}

void movementMenu() {
    std::cout << "\nMove your character:\n";
    std::cout << "A. Left\n";
    std::cout << "D. Right\n";
    std::cout << "W. Up\n";
    std::cout << "S. Down\n";
    std::cout << "F. Stay still\n";
    std::cout << "Enter your choice (1-5): ";
}

bool isValidMove(int x, int y, std::vector<std::vector<std::vector<int>>>& world) {
    int worldWidth = world.at(0).size();
    int worldHeight = world.size();

    // Check bounds
    if (x < 0 || x >= worldWidth || y < 0 || y >= worldHeight) {
        return false;
    }

    return true;
}

void moveCPU(int x, int y, std::vector<std::vector<std::vector<int>>>& world) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<char> moves = { 'A', 'D', 'W', 'S', 'F' };

    while (true) {
        char randomMove = moves[gen() % moves.size()];
        int newX = x, newY = y;

        switch (randomMove) {
        case 'A': newX--; break;
        case 'D': newX++; break;
        case 'W': newY--; break;
        case 'S': newY++; break;
        case 'F': return;
        }

        if (isValidMove(newX, newY, world)) {
            x = newX;
            y = newY;
            return;
        }
    }
}

void GameManager::startGame(World& world) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 3);

    int userChoice;
    int isCpu;
    do {
        showMenu();
        std::cin >> userChoice;
    } while (userChoice < 1 || userChoice > 3);

    do
    {
        showCPUMenu();
        std::cin >> isCpu;
    } while (isCpu < 1 || isCpu > 2);


    // Pick a random bot for the CPU (must be different from userChoice)
    int cpuChoice;
    do {
        cpuChoice = dis(gen);
    } while (cpuChoice == userChoice);

    std::cout << "\nYou chose ";
    switch (userChoice) {
        case 1: std::cout << "MathBot"; break;
        case 2: std::cout << "DoubleBot"; break;
        case 3: std::cout << "GamblerBot"; break;
    }

    std::cout << ", the CPU will play as ";
    switch (cpuChoice) {
        case 1: std::cout << "MathBot"; break;
        case 2: std::cout << "DoubleBot"; break;
        case 3: std::cout << "GamblerBot"; break;
    }
    std::cout << ".\n";

    BaseRobot* p1 = this->robots[userChoice - 1];
    BaseRobot* p2 = this->robots[cpuChoice - 1];

    p2->setPosition(4, 4);

    world.generateWorld(5, 5, 10);

    world.printWorld(p1->getX(), p1->getY(), p2->getX(), p2->getY());


    while(true)
    {
    if (isCpu == 1)
    {
        moveCPU(p1->getX(), p2->getY(), world.getWorld());
    }
    else {
        char moveChoice;

        int newX = p1->getX(), newY = p1->getY();
        do
        {
            do {
                movementMenu();
                std::cin >> moveChoice;
                moveChoice = std::toupper(moveChoice); // Convert to uppercase for case insensitivity
            } while (moveChoice != 'A' && moveChoice != 'D' &&
                moveChoice != 'W' && moveChoice != 'S' && moveChoice != 'F');

            switch (moveChoice) {
            case 'A': newX--; break; // Left
            case 'D': newX++; break; // Right
            case 'W': newY--; break; // Up
            case 'S': newY++; break; // Down
            case 'F': return; // Stay still, no change
            }
        } while (!isValidMove(newX, newY, world.getWorld()));
    }

    
    

    moveCPU(p2->getX(), p2->getY(), world.getWorld());

    p1->mine(world.getWorld());
    p2->mine(world.getWorld());

    world.printWorld();
    }
}