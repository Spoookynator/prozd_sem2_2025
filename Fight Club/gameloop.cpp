#include <iostream>
#include <string>
#include "gameloop.h"
#include "character.h"
#include "fight.h"
#include "ability.h"

void customizeCharacter(Character* character) {  
   int ability1, ability2;  
   std::cout << "Customize abilities for " << character->getName() << std::endl;  
   std::cout << "Ability 1: [1: Heal, 2: Bite, 3: Slap, 4: GenderSwap]: ";  
   std::cin >> ability1;  
   std::cout << "Ability 2: [1: Heal, 2: Bite, 3: Slap, 4: GenderSwap]: ";  
   std::cin >> ability2;  

   switch (ability1) {  
       case 1: character->setAbility1(new Heal()); break;  
       case 2: character->setAbility1(new Bite()); break;  
       case 3: character->setAbility1(new Slap()); break;  
       case 4: character->setAbility1(new GenderSwap()); break;  
       default: std::cout << "Invalid ability choice for Ability 1." << std::endl; return;  
   }  

   switch (ability2) {  
       case 1: character->setAbility2(new Heal()); break;  
       case 2: character->setAbility2(new Bite()); break;  
       case 3: character->setAbility2(new Slap()); break;  
       case 4: character->setAbility2(new GenderSwap()); break;  
       default: std::cout << "Invalid ability choice for Ability 2." << std::endl; return;  
   }  
}

void startLoop() {
    Character* characters[4] = {};

    characters[0] = new Fighter("Enemy");
    characters[1] = new Healer("Healer");
    characters[2] = new Gambler("Gambler");
    characters[3] = new Character("Player", 90, 60);

    int choice;
    while (true) {
        std::cout << "1. Customize Player Character\n2. Start Battle\n3. Exit\nChoose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            customizeCharacter(characters[3]);
        } else if (choice == 2) {
            int char1, char2;
            bool isCpu1, isCpu2;
            std::cout << "Choose two characters for battle (0-3): ";
            std::cin >> char1 >> char2;
            std::cout << "Is character " << char1 << " CPU? (1 for yes, 0 for no): ";
            std::cin >> isCpu1;
            std::cout << "Is character " << char2 << " CPU? (1 for yes, 0 for no): ";
            std::cin >> isCpu2;
            characters[char1]->setIsCpu(isCpu1);
            characters[char2]->setIsCpu(isCpu2);

            if (characters[char1]->getAbility1Name() == "Not Set" || 
                characters[char1]->getAbility2Name() == "Not Set" ||
                characters[char2]->getAbility1Name() == "Not Set" ||
                characters[char1]->getAbility2Name() == "Not Set")
            {
				std::cout << "Player doesnt have enough abilities set. Please customize before starting battle." << std::endl;
                std::cin.clear();
                continue;
            }

            startFight(characters[char1], characters[char2]);
            continue;
        } else if (choice == 3) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    for (int i = 0; i < 4; i++) {
        delete characters[i];
    }
}