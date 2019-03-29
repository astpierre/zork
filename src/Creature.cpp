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

    /* Stores attack object */
    XMLElement * pattack = nullptr;
    pattack = creatureElement->FirstChildElement("attack");
    XMLElement * pCondition = nullptr;
    while(pattack) {
        pCondition = pattack->FirstChildElement("condition");
        Condition * c = new Condition(pCondition);
        this->attackConditions.push_back(c);
        this->attackPrint = (pattack->FirstChildElement("print")->GetText());
        pattack = pattack->NextSiblingElement("attack");
    }

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
std::string Creature::getAttackPrint(){
    return this->attackPrint;
}

