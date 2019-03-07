#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Trigger.h"
#include "Creature.h"
#include "Component.h"
#include "Game.h"
#include "Item.h"
#include "tinyxml2.h"
using namespace tinyxml2;

// Main entrypoint
int main(void) {
    /* GAME SETUP */
    Game * game = new Game("test.xml"); // Construct the game
    game->ShowObjects( ); // Show results after construction

    /* RUN GAME */
    // Prompt for command
    // |-> If (trigger) --> Execute (trigger)
    // |-> Else --> Execute (command)
    //      |--> If (trigger) --> Execute (trigger)

    /* EXIT */
    return EXIT_SUCCESS;
}
