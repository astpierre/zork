#include "Container.h"
#include "Trigger.h"
#include "tinyxml2.h"
#include <iostream>
#include <vector>
#include <string>
using namespace tinyxml2;

Container::Container( XMLElement * containerElement ) {
    /* Container name, status, description */
    if(containerElement->FirstChildElement("name") != nullptr) {
        setName(containerElement->FirstChildElement("name")->GetText());
    } else {
        setName("NONE");
    }
    if(containerElement->FirstChildElement("status") != nullptr) {
        setStatus(containerElement->FirstChildElement("status")->GetText());
    } else {
        setStatus("NONE");
    }
    if(containerElement->FirstChildElement("description") != nullptr) {
        setDescription(containerElement->FirstChildElement("description")->GetText());
    } else {
        setDescription("NONE");
    }

    /* Container accept element present? */
    XMLElement * pAccept = nullptr;
    pAccept = containerElement->FirstChildElement("accept");
    if(pAccept != nullptr) {
        while(pAccept) {
            this->accept.push_back(pAccept->GetText( ));
            pAccept = pAccept->NextSiblingElement("accept");
        }
    } else {
        this->acceptAll = true;
    }

    /* Container accept element present? */
    XMLElement * pItems = nullptr;
    pItems = containerElement->FirstChildElement("item");
    while(pItems) {
        addItem(pItems->GetText( ));
        pItems = pItems->NextSiblingElement("item");
    }

    /* Container triggers */
    XMLElement * pTrigger = nullptr;
    pTrigger = containerElement->FirstChildElement("trigger");
    while(pTrigger) {
        Trigger * t = new Trigger(pTrigger);
        addTrigger(t);
        pTrigger = pTrigger->NextSiblingElement("trigger");
    }

    return;
}

Container::~Container( ) { }

void Container::addItem( std::string newItem ) {
    this->items.push_back(newItem);
}
void Container::removeItem( std::string oldItem ) {
    for(unsigned i = 0; i < this->items.size(); i++) {
        if(this->items[i] == oldItem) {
            this->items.erase(this->items.begin()+i);
        }
    }
}
std::vector<std::string> Container::getItems( ) {
    return this->items;
}
