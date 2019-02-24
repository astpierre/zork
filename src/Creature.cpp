#include "Creature.h"
#include "Trigger.h"
#include "tinyxml2.h"
#include <iostream>
#include <string>

using namespace tinyxml2;

// Forward declaration of functions used by the main function
static std::string getElementText(tinyxml2::XMLElement *_element);

Creature::Creature( XMLElement * creatureElement ) {
    std::cout << "Creating a new creature object" << '\n';
    std::string creatureName = getElementText(creatureElement->FirstChildElement("name"));
    std::string creatureVulnerability = getElementText(creatureElement->FirstChildElement("vulnerability"));

    // TODO: Attack object (PASS XMLElement to attack constructor)

    XMLElement * triggerElement = creatureElement->FirstChildElement("trigger");
    Trigger * t = new Trigger(triggerElement);
    addTrigger(t);
    triggerElement = triggerElement->NextSiblingElement("trigger");
    Trigger * t2 = new Trigger(triggerElement);
    addTrigger(t2);
    setName(creatureName);
    setVulnerability(creatureVulnerability);

    return;
}

Creature::~Creature( ) { }

void Creature::setVulnerability( std::string newVulnerability ) {
    vulnerability = newVulnerability;
    return;
}
std::string Creature::getVulnerability( ) {
    return vulnerability;
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
