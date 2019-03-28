#include "Trigger.h"
#include "Condition.h"
#include <iostream>
#include <string>
#include "tinyxml2.h"
using namespace tinyxml2;

Trigger::Trigger( XMLElement * triggerElement ) {
    if(triggerElement->FirstChildElement("type") != nullptr) {
        changeMode(triggerElement->FirstChildElement("type")->GetText());
    } else {
        changeMode("single");
    }

    if(triggerElement->FirstChildElement("print") != nullptr) {
        setPrint(triggerElement->FirstChildElement("print")->GetText());
    } else {
        setPrint("NONE");
    }

    if(triggerElement->FirstChildElement("command") != nullptr) {
        setCommand(triggerElement->FirstChildElement("command")->GetText());
    } else {
        setCommand("NONE");
    }

    /* Conditions */
    XMLElement * pCondition = nullptr;
    pCondition = triggerElement->FirstChildElement("condition");
    while(pCondition) {
        Condition * c = new Condition(pCondition);
        this->conditions.push_back(c);
        pCondition = pCondition->NextSiblingElement("condition");
    }
}

Trigger::~Trigger( ) { }

void Trigger::setCommand( std::string newCommand ) {
    // TODO: Maybe perform check on command? (for late debugging game run)
    command = newCommand;
    return;
}
std::string Trigger::getCommand( void ) {  return command;  }

void Trigger::setPrint( std::string printStr ) {
    this->print = printStr;
}
std::string Trigger::getPrint( void ) {  return print;  }

void Trigger::setReady( bool value ) {
    ready = value;
    return;
}
bool Trigger::getReadyStatus( void ) {  return ready;  }

void Trigger::changeMode( std::string newMode ) {
    if(newMode.compare("unlimited") == 0) {
        this->mode = newMode;
    } else if(newMode.compare("permanent") == 0) {
        this->mode = newMode;
    } else if(newMode.compare("single") == 0) {
        this->mode = newMode;
    } else {
        std::cout << "Unsupported mode: " << newMode << std::endl;
        return;
    }
    return;
}
std::string Trigger::getMode( void ) {  return mode;  }

void Trigger::incrTimesUsed( void ) {
    this->times_used += 1;
    return;
}
int Trigger::getTimesUsed( void ) {  return times_used;  }

std::vector<Condition *> Trigger::getConditions( ) {
    return this->conditions;
}
