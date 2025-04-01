#include <iostream>
#include <random>
#include "bot.h"
#include "bots.h"
#include "log.h"

void handleBotInput(Bot* bot)
{
    if (!bot) return;

    if (bot->getIsCpu()) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<int> dist(0, 4);

        Direction dir;
        do {
            dir = static_cast<Direction>(dist(gen)); 
        } while (!bot->step(dir));
        
        LOG("moved bot");
        return;
    }

    char input;
    Direction dir = Still;

    std::cout << "Enter direction (WASD to move, F to stay still): ";
    std::cin >> input;

    switch (tolower(input)) {
    case 'w': dir = Up; break;
    case 'a': dir = Left; break;
    case 's': dir = Down; break;
    case 'd': dir = Right; break;
    case 'f': dir = Still; break;
    default:
        std::cout << "Invalid input. Try again.\n";
        handleBotInput(bot);
        return;
    }

    if (!bot->step(dir)) {
        std::cout << "Invalid move. Staying still.\n";
        bot->step(Still);
    }
}


void selectBotTypes(Bot*& bot1, Bot*& bot2)
{
    int type;
    bool isCpu;

    std::cout << "Select type for Bot 1 (1 = DoubleBot, 2 = SortBot, 3 = TripleBot): ";
    while (!(std::cin >> type) || type < 1 || type > 3) {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Enter 1-3: ";
    }

    std::cout << "Is Bot 1 a CPU? (1 = Yes, 0 = No): ";
    while (!(std::cin >> isCpu) || (isCpu != 0 && isCpu != 1)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Enter 1 (CPU) or 0 (Human): ";
    }

    delete bot1;
    if (type == 1) bot1 = new Doublebot(isCpu, Position(0, 0));
    else if (type == 2) bot1 = new SortBot(isCpu, Position(0, 0));
    else if (type == 3) bot1 = new TripleBot(isCpu, Position(0, 0));
    

    std::cout << "Select type for Bot 2 (1 = DoubleBot, 2 = SortBot, 3 = TripleBot): ";
    while (!(std::cin >> type) || type < 1 || type > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Enter 1-3: ";
    }


    std::cout << "Is Bot 2 a CPU? (1 = Yes, 0 = No): ";
    while (!(std::cin >> isCpu) || (isCpu != 0 && isCpu != 1)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Enter 1 (CPU) or 0 (Human): ";
    }

    delete bot2;
    if (type == 1) bot2 = new Doublebot(isCpu, Position(4, 4));
    else if (type == 2) bot2 = new SortBot(isCpu, Position(4, 4));
    else if (type == 3) bot2 = new TripleBot(isCpu, Position(4, 4));
}
