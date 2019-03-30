#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Trigger.h"
#include "Creature.h"
#include "Component.h"
#include "Game.h"
#include "Room.h"
#include "Container.h"
#include "Item.h"
#include "tinyxml2.h"
using namespace tinyxml2;

// Main entrypoint
int main(void) {
    /* GAME SETUP */
    Game * game = new Game("test.xml"); // Construct game
    //game->ShowObjects( ); // Show game components

    /* RUN GAME */
    game->Play( ); // Play the game!
    // Prompt for command
    // |-> If (trigger) --> Execute (trigger)
    // |-> Else --> Execute (command)
    //      |--> If (trigger) --> Execute (trigger)

    /* EXIT */
    return EXIT_SUCCESS;
}
