#pragma once

#include <vector>
#include <memory>
#include "Card.h"
#include "NumberCard.h"
#include "Player.h"

class Game
{
    public:
        Game();

    private:
        void setupPlay(int playerCount);
        bool isFinished();
        void gameLoop();
        int activePlayer;
        std::vector<std::unique_ptr<Card>> drawPile, discardPile;
        std::vector<Player> players;

};