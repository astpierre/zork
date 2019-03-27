#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include "Component.h"
#include "Container.h"
#include "Trigger.h"
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
