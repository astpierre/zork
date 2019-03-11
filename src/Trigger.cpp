#include "../include/Trigger.h"
#include "../include/tinyxml2.h"
#include <iostream>
#include <string>

using namespace tinyxml2;
// Forward declaration of functions used by the main function
static std::string getElementText(tinyxml2::XMLElement *_element);

Trigger::Trigger( XMLElement * triggerElement ) {
    std::string m = getElementText(triggerElement->FirstChildElement("type"));
    //XMLElement * conditionElement = triggerElement->FirstChildElement("condition");
    std::string p = getElementText(triggerElement->FirstChildElement("print"));
    mode = m;
    print = p;
}

Trigger::~Trigger( ) { }

std::string Trigger::getCommand( void ) {  return command;  }
std::string Trigger::getPrint( void ) {  return print;  }
bool Trigger::getReadyStatus( void ) {  return ready;  }
std::string Trigger::getMode( void ) {  return mode;  }
int Trigger::getTimesUsed( void ) {  return times_used;  }

void Trigger::setCommand( std::string newCommand ) {
    // TODO: Maybe perform check on command?
    command = newCommand;
    return;
}
void Trigger::setReady( bool value ) {
    ready = value;
    return;
}
void Trigger::changeMode( std::string newMode ) {
    if(newMode.compare("always") == 0) {
        this->mode = newMode;
    } else if(newMode.compare("single") == 0) {
        this->mode = newMode;
    } else {
        std::cout << "Unsupported mode: " << newMode << std::endl;
        return;
    }
    return;
}
void Trigger::incrTimesUsed( void ) {
    this->times_used += 1;
    return;
}
// This is a simple utility function to get a value as long as the node is not null
static std::string getElementText(XMLElement *_element) {
    std::string value;
    if(_element != NULL) {
        value = _element->GetText();
    } else {
        return "\0";
    }
    return value;
}
