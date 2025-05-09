#include "NumberCard.h"

NumberCard::NumberCard(int number, enum Color color) : Card(color), number(number)
{
    //ctor
}

char NumberCard::getValue() {
    return '0' + number;
}

void NumberCard::print() {
    std::cout << number;
    switch(color) {
    case red:
        std::cout << "Rot";
        break;
    case blue:
        std::cout << "Blau";
        break;
    case green:
        std::cout << "Gruen";
        break;
    case yellow:
        std::cout << "Gelb";
        break;
    }
    std::cout << " ";
}
