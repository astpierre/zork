#include <iostream>
#include <vector>
#include <string>
#include "Component.h"
#include "Room.h"
#include "Trigger.h"
#include "tinyxml2.h"
using namespace tinyxml2;

Room::Room( XMLElement * roomElement ) {
    /* Room name, status, description, type */
    if(roomElement->FirstChildElement("name") != nullptr) {
        setName(roomElement->FirstChildElement("name")->GetText());
    } else {
        setName("NONE");
    }
    if(roomElement->FirstChildElement("status") != nullptr) {
        setStatus(roomElement->FirstChildElement("status")->GetText());
    } else {
        setStatus("NONE");
    }
    if(roomElement->FirstChildElement("description") != nullptr) {
        setDescription(roomElement->FirstChildElement("description")->GetText());
    } else {
        setDescription("NONE");
    }
    if(roomElement->FirstChildElement("type") != nullptr) {
        setType(roomElement->FirstChildElement("type")->GetText());
    }

    /* Room items */
    XMLElement * pItems = nullptr;
    pItems = roomElement->FirstChildElement("item");
    while(pItems) {
        addItem(pItems->GetText( ));
        pItems = pItems->NextSiblingElement("item");
    }

    /* Room triggers */
    XMLElement * pTrigger = nullptr;
    pTrigger = roomElement->FirstChildElement("trigger");
    while(pTrigger) {
        Trigger * t = new Trigger(pTrigger);
        addTrigger(t);
        pTrigger = pTrigger->NextSiblingElement("trigger");
    }

    /* Room creatures */
    XMLElement * pCreature = nullptr;
    pCreature = roomElement->FirstChildElement("creature");
    while(pCreature) {
        addCreature(pCreature->GetText( ));
        pCreature = pCreature->NextSiblingElement("creature");
    }

    /* Room containers */
    XMLElement * pContainer = nullptr;
    pContainer = roomElement->FirstChildElement("creature");
    while(pContainer) {
        addContainer(pContainer->GetText( ));
        pContainer = pContainer->NextSiblingElement("container");
    }

    /* TODO: create borders */
}

Room::~Room( ) { }

void Room::addItem( std::string item ) {
    this->items.push_back(item);
}
void Room::removeItem( std::string item ) {
    for(unsigned i = 0; i < this->items.size(); i++) {
        if(this->items[i] == item) {
            this->items.erase(this->items.begin()+i);
        }
    }
}

void Room::setType( std::string type ) {
    this->roomType = type;
}
std::string Room::getType( ) {
    return this->roomType;
}

void Room::addContainer( std::string container ) {
    this->containers.push_back(container);
}
void Room::removeContainer( std::string container ) {
    for(unsigned i = 0; i < this->containers.size(); i++) {
        if(this->containers[i] == container) {
            this->containers.erase(this->containers.begin()+i);
        }
    }
}

void Room::addCreature( std::string creature ) {
    this->creatures.push_back(creature);
}
void Room::removeCreature( std::string creature ) {
    for(unsigned i = 0; i < this->creatures.size(); i++) {
        if(this->creatures[i] == creature) {
            this->creatures.erase(this->creatures.begin()+i);
        }
    }
}

//void Room::addBorder( XMLElement * ) { } /* TODO: Borders! */

std::vector<std::string> Room::getItems( ) {
    return this->items;
}
std::vector<std::string> Room::getContainers( ) {
    return this->containers;
}
std::vector<std::string> Room::getCreatures( ) {
    return this->creatures;
}
