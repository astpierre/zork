#include "Condition.h"
#include <iostream>
#include <string>
#include "tinyxml2.h"
using namespace tinyxml2;

Condition::Condition( XMLElement * ConditionElement ) {
    if(ConditionElement->FirstChildElement("status") != nullptr) {
        this->status = ConditionElement->FirstChildElement("status")->GetText();
    } else this->status = "NONE";

    if(ConditionElement->FirstChildElement("has") != nullptr) {
        this->has = ConditionElement->FirstChildElement("has")->GetText();
    } else this->has = "NONE";

    if(ConditionElement->FirstChildElement("object") != nullptr) {
        this->object = ConditionElement->FirstChildElement("object")->GetText();
    } else this->object = "NONE";

    if(ConditionElement->FirstChildElement("owner") != nullptr) {
        this->owner = ConditionElement->FirstChildElement("owner")->GetText();
    } else this->owner = "NONE";
}

Condition::~Condition( ) { }

void Condition::setHas( std::string h ) { has = h; }
std::string Condition::getHas( ) {  return has;  }

void Condition::setOwner( std::string o ) { owner = o; }
std::string Condition::getOwner( ) {  return owner;  }

void Condition::setObject( std::string o ) {  object = o;  }
std::string Condition::getObject( ) {  return object;  }

void Condition::setStatus( std::string s ) {  status = s;  }
std::string Condition::getStatus( ) {  return status;  }

bool Condition::satisfies( std::string h, std::string obj, std::string own ) {
    if(this->has == h) {
        if(this->object == obj) {
            if(this->owner == own) {
                return true;
            }
        }
    }
    return false;
}
