#include "Component.h"

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
