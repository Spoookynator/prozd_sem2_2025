#include "Player.h"

Player::Player()
{
    //ctor
}

int Player::getPlayerMove(Card& topCard) {
	// Find out which option the player wants to choose:
	// Check which cards in hand are playable
	// Ask the player which of those they want to play
	// Return the index of the choice or -1 if the choice was nothing
}

void Player::drawCard(std::unique_ptr<Card> cardToDraw) {
	// Move the passed unique_ptr copy into your Hand
}

std::unique_ptr<Card> Player::playCard(int index) {
	// Move the card the Game tells you into the return value
	// Don't forget to remove that card from the hand of the player! (It's a nullptr now)
}

bool Player::isFinished() {
	// Return true if the player has no cards in hand
}

void Player::printHand() {
    std::cout << "Hand: ";
    for(int i = 0; i < hand.size(); i++) {
        hand.at(i)->print();
    }
    std::cout << "\n";
}
