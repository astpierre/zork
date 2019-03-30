#include "Item.h"
#include "Trigger.h"
#include "tinyxml2.h"
#include <iostream>
#include <string>
using namespace tinyxml2;

Item::Item( XMLElement * itemElement ) {
    /* Item name */
    if(itemElement->FirstChildElement("name") != nullptr) {
        setName(itemElement->FirstChildElement("name")->GetText());
    } else {
        setName("NONE");
    }

    /* Item status */
    if(itemElement->FirstChildElement("status") != nullptr) {
        setStatus(itemElement->FirstChildElement("status")->GetText());
    } else {
        setStatus("NONE");
    }

    /* Item owner */
    if(itemElement->FirstChildElement("owner") != nullptr) {
        setOwner(itemElement->FirstChildElement("owner")->GetText());
    } else {
        setOwner("NONE");
    }

    /* Item writing */
    if(itemElement->FirstChildElement("writing") != nullptr) {
        setWriting(itemElement->FirstChildElement("writing")->GetText());
    } else {
        setWriting("NONE");
    }

    /* Item turnons */
    if(itemElement->FirstChildElement("turnon") != nullptr) {
        setTurnOnPrint(itemElement->FirstChildElement("turnon")->FirstChildElement("print")->GetText());
        setTurnOnAction(itemElement->FirstChildElement("turnon")->FirstChildElement("action")->GetText());
    } else {
        setTurnOnPrint("NONE");
        setTurnOnAction("NONE");
    }

    /* Item triggers */
    XMLElement * pTrigger = nullptr;
    pTrigger = itemElement->FirstChildElement("trigger");
    while(pTrigger) {
        Trigger * t = new Trigger(pTrigger);
        addTrigger(t);
        pTrigger = pTrigger->NextSiblingElement("trigger");
    }
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
