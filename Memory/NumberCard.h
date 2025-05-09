#pragma once

#include "Card.h"

class NumberCard : public Card
{
    public:
        NumberCard(int number, enum Color color);
        char getValue() override;
        void print() override;

    private:
        int number;
};