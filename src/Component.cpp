#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include "Component.h"
#include "tinyxml2.h"
using namespace tinyxml2;

Component::Component( ) { }
Component::~Component( ) { }

std::string Component::getName( void ) { return name; }
std::string Component::getStatus( void ) { return status; }
std::string Component::getDescription( void ) { return description; }

void Component::setName( std::string newName ) {
    this->name = newName;
    return;
}
void Component::setStatus( std::string newStatus ) {
    this->status = newStatus;
    return;
}
void Component::setDescription( std::string newDescription ) {
    this->description = newDescription;
    return;
}
void Component::addTrigger( Trigger * trig ) {
    this->triggers.push_back(trig);
    return;
}
void Component::showTriggers( ) {
    for(auto i : triggers) {
        std::cout << "Trigger type: "<< i->getMode() << std::endl;
        std::cout << "Trigger print: "<< i->getPrint() << std::endl;
    }
    return;
}
