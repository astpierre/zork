#include "Trigger.h"

Trigger::Trigger( ) { }
Trigger::~Trigger( ) { }

std::string Trigger::getCommand( void ) {  return command;  }
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
