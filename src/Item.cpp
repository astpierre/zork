#include "Item.h"
#include "Trigger.h"
#include "tinyxml2.h"
#include <iostream>
#include <string>
using namespace tinyxml2;

Item::Item( XMLElement * itemElement ) {
    if(itemElement->FirstChildElement("name") != nullptr) {
        setName(itemElement->FirstChildElement("name")->GetText());
    } else {
        setName("NONE");
    }

    if(itemElement->FirstChildElement("status") != nullptr) {
        setStatus(itemElement->FirstChildElement("status")->GetText());
    } else {
        setStatus("NONE");
    }

    if(itemElement->FirstChildElement("owner") != nullptr) {
        setOwner(itemElement->FirstChildElement("owner")->GetText());
    } else {
        setOwner("NONE");
    }

    if(itemElement->FirstChildElement("writing") != nullptr) {
        setWriting(itemElement->FirstChildElement("writing")->GetText());
    } else {
        setWriting("NONE");
    }

    if(itemElement->FirstChildElement("turnon") != nullptr) {
        setTurnOnPrint(itemElement->FirstChildElement("turnon")->FirstChildElement("print")->GetText());
        setTurnOnAction(itemElement->FirstChildElement("turnon")->FirstChildElement("action")->GetText());
    } else {
        setTurnOnPrint("NONE");
        setTurnOnAction("NONE");
    }

    /* TODO: Triggers??? */
}

Item::~Item( ) { }

void Item::setWriting( std::string writingStr ) {
    this->writing = writingStr;
    return;
}
std::string Item::getWriting( ) {
    return this->writing;
}

void Item::setOwner( std::string ownerName ) {
    this->owner = ownerName;
    return;
}
std::string Item::getOwner( ) {
    return this->owner;
}

void Item::setTurnOnPrint( std::string turnOnPrint ) {
    this->turn_on_print = turnOnPrint;
    return;
}
std::string Item::getTurnOnPrint( ) {
    return this->turn_on_print;
}

void Item::setTurnOnAction( std::string turnOnAction ) {
    this->turn_on_action = turnOnAction;
    return;
}
std::string Item::getTurnOnAction( ) {
    return this->turn_on_action;
}
