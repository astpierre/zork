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
    Game * game = new Game("test.xml");
    //game->ShowObjects( );

    /* RUN GAME */
    game->Play( );

    /* EXIT */
    return EXIT_SUCCESS;
}
