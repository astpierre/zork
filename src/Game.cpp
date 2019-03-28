#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <fstream>
#include <iterator>
#include "Component.h"
#include "Container.h"
#include "Trigger.h"
#include "Creature.h"
#include "Room.h"
#include "Item.h"
#include "Game.h"
#include "tinyxml2.h"
using namespace tinyxml2;

Game::~Game( ) { } /* Deconstructor */

Game::Game( const char * xmlfile ) { /* Constructor */
    /* Open XML file using tinyxml2 */
    XMLDocument doc;
    doc.LoadFile(xmlfile);

    /* Parse XML file */
    XMLNode * pRoot = doc.FirstChildElement("map"); // pRoot == <map>

    //~~ Populate all objects ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /******************************************************
     * For Rooms, Items, Containers, and Creatures, add
     * each to a member vector of Game and pass the XML
     * element to the respective constructor of each obj.
     * Each constructor will properly handle any meta-
     * field of the respective obj.
     *****************************************************/

    /* Rooms */
    XMLElement * pRoom = nullptr;
    pRoom = pRoot->FirstChildElement("room");
    while(pRoom) {
        Room * r = new Room(pRoom);
        this->rooms.push_back(r);
        pRoom = pRoom->NextSiblingElement("room");
    }

    /* Creatures */
    XMLElement * pCreature = nullptr;
    pCreature = pRoot->FirstChildElement("creature");
    while(pCreature) {
        Creature * c = new Creature(pCreature);
        this->creatures.push_back(c);
        pCreature = pCreature->NextSiblingElement("creature");
    }

    /* Items */
    XMLElement * pItem = nullptr;
    pItem = pRoot->FirstChildElement("item");
    while(pItem) {
        Item * item = new Item(pItem);
        this->items.push_back(item);
        pItem = pItem->NextSiblingElement("item");
    }

    /* Containers */
    XMLElement * pContainer = nullptr;
    pContainer = pRoot->FirstChildElement("container");
    while(pContainer) {
        Container * container = new Container(pContainer);
        this->containers.push_back(container);
        pContainer = pContainer->NextSiblingElement("container");
    }

}

void Game::ShowObjects( ) {
    std::cout << "Displaying game components: "<<std::endl;
    for(auto i : this->rooms) {
        std::cout << "Room name: "<< i->getName( ) << std::endl;
        std::cout << "Room status: "<< i->getStatus( ) << std::endl;
        std::cout << "Room description: "<< i->getDescription( ) << std::endl;
        std::vector<std::string> iList = i->getItems( );
        std::cout << "Room items: ";
        for(auto j : iList) {
            std::cout << j << "  ";
        }
        std::cout << '\n';
        std::vector<std::string> conList = i->getContainers( );
        std::cout << "Room containers: ";
        for(auto j : conList) {
            std::cout << j << "  ";
        }
        std::cout << '\n';
        std::vector<std::string> creList = i->getCreatures( );
        std::cout << "Room creatures: ";
        for(auto j : creList) {
            std::cout << j << "  ";
        }
        std::cout << '\n';
        i->showBorders( );

        i->showTriggers( );
        std::cout << std::endl;
    }
    for(auto i : this->creatures) {
        std::cout << "Creature name: "<< i->getName( ) << std::endl;
        std::vector<std::string> vList = i->getVulnerabilities( );
        for(auto j : vList) {
            std::cout << "Creature vulnerability: "<< j << std::endl;
        }
        i->showTriggers( );
        std::cout << '\n';
    }
    for(auto i : this->items) {
        std::cout << "Item name: "<< i->getName( ) << std::endl;
        std::cout << "Item status: "<< i->getStatus( ) << std::endl;
        std::cout << "Item owner: "<< i->getOwner( ) << std::endl;
        std::cout << "Item turnon action: "<< i->getTurnOnAction( ) << std::endl;
        i->showTriggers( );
        std::cout << '\n';
    }
    for(auto i : this->containers) {
        std::cout << "Container name: "<< i->getName( ) << std::endl;
        std::cout << "Container status: "<< i->getStatus( ) << std::endl;
        std::cout << "Container description: "<< i->getDescription( ) << std::endl;
        std::vector<std::string> iList = i->getItems( );
        std::cout << "Container items: ";
        for(auto j : iList) {
            std::cout << j << "  ";
        }
        std::cout << '\n';
        i->showTriggers( );
    }
    std::cout << '\n';
}
bool Game::moveCommand( std::string cmd ) {
    for(auto i : this->movement_commands) {
        if(i == cmd) return true;
    }
    return false;
}
void Game::Play( ) {
    curr_room = getRoomByName("Entrance"); // Games always start here
    std::string userInputStr = "";
    std::vector<std::string> userInputSplitted;
    std::string cmd = "";
    bool trigCheck = false;
    while(!game_over) { /* Handle user input. */
        std::cout << "\nEnter command: ";
        std::getline(std::cin, userInputStr);
        std::cout << std::endl;
        userInputSplitted = splitString(userInputStr, " ");
        cmd = userInputSplitted[0];

        if(checkInput(cmd)) {
            /* Do a preliminary check on triggers */
            trigCheck = prelimTriggerCheck(userInputSplitted);
            if(!trigCheck) {
                if(cmd == "i") { /* Display inventory */
                    addToInventory("sword"); /* TODO: remove after testing */
                    addToInventory("fire"); /* TODO: remove after testing */
                    displayInventory();

                } else if(moveCommand(cmd)) { /* Attempt to change room */
                    changeRoom(cmd);

                } else if(cmd == "take") { /* Attempt to add an item to inventory */
                    std::cout << "taking " << userInputSplitted[1] << '\n';
                    /* TODO: implement take checks if item is present in a container or curr_room */

                } else if(cmd == "open" && userInputSplitted[1] == "exit") { /* Attempt to exit game. */
                    std::cout << "Game Over\n"; /* TODO: only exit if room type = 'exit' */
                    game_over = true;

                } else if(cmd == "open") { /* Attempt to open a container. */
                    std::cout << "opening " << userInputSplitted[1] << '\n';
                    /* TODO: implement open checks if container conditions are met */
                    /* TODO: implement container display function [ see displayInventory() ] */

                } else if(cmd == "read") { /* Attempt to read writing on an item in inventory. */
                    std::cout << "reading " << userInputSplitted[1] << '\n';
                    /* TODO: check if item is in inventory then use getWriting to view item writing */

                } else if(cmd == "drop") { /* Attempt to drop an item from inventory. */
                    std::cout << "dropping " << userInputSplitted[1] << '\n';
                    /* TODO: Check if item is in inventory then add item to current room. */

                } else if(cmd == "put") { /* Attempt to put an item in container. */
                    std::cout << "putting " << userInputSplitted[1] << " in " << userInputSplitted[3] << '\n';
                    /* TODO: Check if item is in inventory and add it to container if container conditions are met */

                } else if(cmd == "turn" && userInputSplitted[1] == "on") { /* Attempt to activate an item in inventory */
                    std::cout << "turning on " << userInputSplitted[2] << '\n';
                    /* TODO: Check if item is in inventory and activate it if conditions are met */

                } else if(cmd == "attack") { /* Attempt to use an item on a creature. */
                    std::cout << "Attacking " << userInputSplitted[1] << " with " << userInputSplitted[2] << '\n';
                    /* TODO: Check if item is in inventory then check if creature is in curr_room, then check for trigs */
                }

            }
        } else if(cmd == "q") { /* Quit game, game over. */
            std::cout << "Quitting game!" << std::endl;
            game_over = true;
        } else { /* Invalid command, prompt for user input again. */
            std::cout << "Invalid comand!" << std::endl;
        }
    }
}



bool Game::inventoryContains( std::string obj ) {
    for(auto i : this->inventory) {
        if(i == obj) return true;
    }
    return false;
}
bool Game::checkInput( std::string userInput ) {
    for(auto i : this->game_commands) {
        if(i == userInput) return true;
    }
    return false;
}
void Game::addToInventory( std::string obj ) {
    this->inventory.push_back(obj);
}
void Game::removeFromInventory( std::string obj ) {
    for(unsigned i = 0; i < this->inventory.size(); i++) {
        if(this->inventory[i] == obj) {
            this->inventory.erase(this->inventory.begin()+i);
        }
    }
}
void Game::displayInventory( ) {
    unsigned int l = inventory.size();
    for(auto i : this->inventory) {
        if(l == 1) {
            std::cout << i << '\n';
        } else {
            std::cout << i << ", ";
        }
        l -= 1;
    }
}

void Game::changeRoom( std::string cmd ) {
    std::string dir = "";
    std::string rName = "";
    std::string targetDir = "";

    if(cmd == "n") targetDir = "north";
    else if(cmd == "s") targetDir = "south";
    else if(cmd == "e") targetDir = "east";
    else if(cmd == "w") targetDir = "west";

    std::vector<std::tuple<std::string, std::string>> brdrs = curr_room->getBorders();
    for(auto i : brdrs) {
        std::tie(dir, rName) = i;
        if(targetDir == dir) {
            curr_room = getRoomByName(rName);
            std::cout << "Current room: "<< rName << '\n';
            std::cout << "Description: " << curr_room->getDescription() << "\n";
            return;
        }
    }
    std::cout << "Cannot go that direction." << "\n";
}

Room * Game::getRoomByName( std::string roomName ) {
    for(auto i : this->rooms) {
        if(i->getName() == roomName) return i;
    }
    return nullptr;
}
Item * Game::getItemByName( std::string itemName ) {
    for(auto i : this->items) {
        if(i->getName() == itemName) return i;
    }
    return nullptr;
}
Container * Game::getContainerByName( std::string containerName ) {
    for(auto i : this->containers) {
        if(i->getName() == containerName) return i;
    }
    return nullptr;
}
Creature * Game::getCreatureByName( std::string creatureName ) {
    for(auto i : this->creatures) {
        if(i->getName() == creatureName) return i;
    }
    return nullptr;
}
std::string Game::searchAllForType(std::string objName) {
    if(getRoomByName(objName) != nullptr) return "room";
    if(getCreatureByName(objName) != nullptr) return "creature";
    if(getContainerByName(objName) != nullptr) return "container";
    if(getItemByName(objName) != nullptr) return "item";
    return "NONE";
}

bool Game::prelimTriggerCheck( std::vector<std::string> cmdLine ) {
    /* Get context */
    std::vector<std::string> curr_creatures = curr_room->getCreatures();
    std::vector<std::string> curr_containers = curr_room->getContainers();
    std::vector<std::string> curr_items = curr_room->getItems();
    std::vector<Trigger *> trigger_vector;
    bool gotAtLeastOne = false;

    /* Check creature triggers */
    for(auto i : curr_creatures){
        Creature * c = getCreatureByName(i);
        trigger_vector = c->getTriggers();
        for(auto j : trigger_vector) {
            if(j->getCommand() == cmdLine[0]) {
                if(((j->getMode() == "single") && (j->getTimesUsed() < 1)) ||
                    (j->getMode() != "single")) {
                    if(checkConditions(j)) {
                        gotAtLeastOne = true;
                        handleTrigger(j);
                    }
                }
            }
        }
    }
    /* Check current room triggers */
    trigger_vector = curr_room->getTriggers();
    for(auto j : trigger_vector) {
        if(j->getCommand() == cmdLine[0]) {
            if(((j->getMode() == "single") && (j->getTimesUsed() < 1)) ||
                (j->getMode() != "single")) {
                if(checkConditions(j)) {
                    gotAtLeastOne = true;
                    handleTrigger(j);
                }
            }
        }
    }
    /* Check container triggers */
    for(auto i : curr_containers){
        Container * c = getContainerByName(i);
        trigger_vector = c->getTriggers();
        for(auto j : trigger_vector) {
            if(j->getCommand() == cmdLine[0]) {
                if(((j->getMode() == "single") && (j->getTimesUsed() < 1)) ||
                    (j->getMode() != "single")) {
                    if(checkConditions(j)) {
                        gotAtLeastOne = true;
                        handleTrigger(j);
                    }
                }
            }
        }
    }
    /* Check item triggers */
    for(auto i : curr_items){
        Item * it = getItemByName(i);
        trigger_vector = it->getTriggers();
        for(auto j : trigger_vector) {
            if(j->getCommand() == cmdLine[0]) {
                if(((j->getMode() == "single") && (j->getTimesUsed() < 1)) ||
                    (j->getMode() != "single")) {
                    if(checkConditions(j)) {
                        gotAtLeastOne = true;
                        handleTrigger(j);
                    }
                }
            }
        }
    }
    return gotAtLeastOne;
}

bool Game::checkConditions(Trigger * t) {
    bool cond_verified = false;
    std::vector<Condition *> condition_vector = t->getConditions();
    for(auto k : condition_vector) {
        if(k->getOwner() == "inventory"){
            std::string itemName = k->getObject();
            // Check if item is in inventory
            if(inventoryContains(itemName)) {
                if(k->getHas() == "yes") cond_verified = true;
                else if(k->getHas() == "no") {
                    return false;
                }
            } else {
                if(k->getHas() == "no") cond_verified = true;
                else if(k->getHas() == "yes") {
                    return false;
                }
            }
        } else if(k->getOwner() != "NONE") {
            std::string itemName = k->getObject();
            Container * c = getContainerByName(k->getOwner());

            // Check if container has object
            if(c->containerContains(itemName)) {
                if(k->getHas() == "yes") cond_verified = true;
                else if(k->getHas() == "no") {
                    return false;
                }
            } else {
                if(k->getHas() == "no") cond_verified = true;
                else if(k->getHas() == "yes") {
                    return false;
                }
            }
        }
        if(cond_verified != true) {
            Item * it = getItemByName(k->getObject());
            if(k->getStatus() == it->getStatus()) cond_verified = true;
            else return false;
        }
    }
    return true;
}

void Game::handleTrigger(Trigger * t) {
    std::cout << t->getPrint() << '\n';
    std::vector<std::string> triggerActionSplitted;
    triggerActionSplitted = splitString(t->getCommand(), " ");
    std::string cmd = "";
    if(triggerActionSplitted[0] == "Update") { /* Update status of object */
        std::string itemType = searchAllForType(triggerActionSplitted[1]);
        if(itemType == "room") {
            Room * x = getRoomByName(triggerActionSplitted[1]);
            x->setStatus(triggerActionSplitted[3]);
        }
        if(itemType == "item") {
            Item * x = getItemByName(triggerActionSplitted[1]);
            x->setStatus(triggerActionSplitted[3]);
        }
        if(itemType == "container") {
            Container * x = getContainerByName(triggerActionSplitted[1]);
            x->setStatus(triggerActionSplitted[3]);
        }
        if(itemType == "creature") {
            Creature * x = getCreatureByName(triggerActionSplitted[1]);
            x->setStatus(triggerActionSplitted[3]);
        }

    } else if(triggerActionSplitted[0] == "Add") {
        /* TODO: Add action */
        std::cout<<"Add "<<triggerActionSplitted[1] <<" to "<< triggerActionSplitted[3]<<'\n';

    } else if(triggerActionSplitted[0] == "Delete") {
        /* TODO: Delete action */
        std::cout << "Delete "<<triggerActionSplitted[1] <<" from game." << '\n';
    }
}

std::vector<std::string> Game::splitString(const std::string s, const std::string delim) {
    std::vector<std::string> splitted;
    size_t prev=0, pos=0;
    do {
        pos = s.find(delim, prev);
        if(pos == std::string::npos) pos = s.length();
        std::string spl = s.substr(prev, pos-prev);
        if(!spl.empty()) splitted.push_back(spl);
        prev = pos + delim.length();
    } while(pos < s.length() && prev < s.length());
    return splitted;
}
