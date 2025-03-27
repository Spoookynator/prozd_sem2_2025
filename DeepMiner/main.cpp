#include "gameManager.h"
#include "world.h"

int main() {
	World world(100);

	GameManager gameManager;

	gameManager.startGame(world);
}