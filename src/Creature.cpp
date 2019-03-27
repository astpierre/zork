#include "Creature.h"
#include "Trigger.h"
#include "tinyxml2.h"
#include <iostream>
#include <string>
using namespace tinyxml2;

Creature::Creature( XMLElement * creatureElement ) {
    /* Creature name */
    if(creatureElement->FirstChildElement("name") != nullptr) {
        setName(creatureElement->FirstChildElement("name")->GetText());
    } else {
        setName("NONE");
    }

    /* Creature vulnerabilities */
    XMLElement * pVulnerability = nullptr;
    pVulnerability = creatureElement->FirstChildElement("vulnerability");
    while(pVulnerability) {
        this->vulnerabilities.push_back(pVulnerability->GetText( ));
        pVulnerability = pVulnerability->NextSiblingElement("vulnerability");
    }

    /* TODO: Attack object (Pass XMLElement to attack constructor) */

    /* Creature triggers */
    XMLElement * pTrigger = nullptr;
    pTrigger = creatureElement->FirstChildElement("trigger");
    while(pTrigger) {
        Trigger * t = new Trigger(pTrigger);
        addTrigger(t);
        pTrigger = pTrigger->NextSiblingElement("trigger");
    }

    return;
}

Creature::~Creature( ) { }

std::vector<std::string> Creature::getVulnerabilities( ) {
    return this->vulnerabilities;
}
