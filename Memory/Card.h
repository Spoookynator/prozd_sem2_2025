#pragma once
#include <iostream>

enum Color {
    blue, green, red, yellow, black
};


class Card
{
    public:
        Card(enum Color color);
        virtual ~Card();
        bool isPlayableOn(Card& other);
        enum Color getColor();
        virtual char getValue() = 0;
        virtual void print() = 0;

    protected:
        enum Color color;
};