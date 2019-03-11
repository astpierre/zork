#include <iostream>
#include <vector>
#include <string>
#include <iterator> // for iterators
#include "../include/Component.h"

Component::Component( ) { }
Component::~Component( ) { }

std::string Component::getName( void ) { return name; }
std::string Component::getStatus( void ) { return status; }
std::string Component::getDescription( void ) { return description; }

void Component::setName( std::string newName ) {
    name = newName;
    return;
}
void Component::setStatus( std::string newStatus ) {
    status = newStatus;
    return;
}
void Component::setDescription( std::string newDescription ) {
    description = newDescription;
    return;
}
void Component::addTrigger( Trigger * trig ) {
    this->triggers.push_back(trig);
    return;
}
void Component::showTriggers( ) {
    //std::vector<Trigger*>::iterator ptr = this->triggers->begin();
    //for(auto it=std::begin(triggers); it!=std::end(triggers); ++it) {
    for(auto i : triggers) {
        std::cout << "Trigger type: "<< i->getMode() << std::endl;
        std::cout << "Trigger print: "<< i->getPrint() << std::endl;
    }
    return;
}
