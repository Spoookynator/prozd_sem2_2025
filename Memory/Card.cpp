#include "Card.h"

Card::Card(enum Color color) : color(color)
{
    //ctor
}

Card::~Card()
{
    //dtor
}

enum Color Card::getColor() {
    return color;
}

bool Card::isPlayableOn(Card& other) {
    if(other.getColor() == color || other.getValue() == getValue())
        return true;
    return false;
}
