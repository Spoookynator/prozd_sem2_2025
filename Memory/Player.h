#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
#include "Card.h"


class Player
{
    public:
        Player();
        int getPlayerMove(Card& topCard);
        void drawCard(std::unique_ptr<Card> cardToDraw);
        std::unique_ptr<Card> playCard(int index);
        bool isFinished();
        void printHand();

    private:
        std::vector<std::unique_ptr<Card>> hand;
};
