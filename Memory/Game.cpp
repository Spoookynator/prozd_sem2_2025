#include "Game.h"

Game::Game()
{
    //ctor
    activePlayer = 0;
    setupPlay(2);
    gameLoop();
}

// to copy a unique_ptr to a variable, function or return value you have to move it!
// e.g.
// std::unique_ptr<Card> myUniqueptrVar = std::move(whereMyCardComesFrom)
// OR
// return std::move(myUniqueptrReturn)
// OR
// myFunctionCall(std::move(myUniquePtrParameter))

// Beware of hidden copies and their consequences!
// -
// for(unique_ptr<Card> p : myUniqueptrVector)
// or
// for(Player p : players)
// doesn't compile because in both cases a unique_ptr would be copied
// (Player has a vector<unique_ptr> which would be copied)
// -
// void doSomething(Player p) {...}
// Player p;
// doSomething(p);
// doesn't compile because it's passing a Player object by value (i.e. a copy is created)


void Game::setupPlay(int playerCount) {
	// Create Player-vector
	// Create all cards in play (in the drawPile)
	// Shuffle and give 6 to each player
	// reveal one card to begin
}

bool Game::isFinished() {
	// Return whether one of the players has finished (use the corresponding player-function)
}

void Game::gameLoop() {
	// While game is running show the top card
	// Call getPlayerMove
	// Either draw a card (-1) or play the corresponding card
	// Hand over the turn to the next player (use the variable activePlayer)
}
