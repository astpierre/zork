#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../include/Trigger.h"
#include "../include/Creature.h"
#include "../include/Component.h"
#include "../include/tinyxml2.h"
using namespace tinyxml2;

// Macro to check XML parsing
#define XMLCHECK(ptr) (nullptr==ptr)

// Forward declaration of functions used by the main function
static std::string getElementText(XMLElement *_element);

int main(void) {
    /* GAME SETUP */
    // Open XML file
    XMLDocument doc;
    doc.LoadFile("test.xml");

    // Parse XML file
    XMLNode * pRoot = doc.FirstChild(); // pRoot == <map>
    if(XMLCHECK(pRoot)) std::cout << "ERROR\n"; // check fail

    // Create all objects (all roooms and items)
    // Populate all objects

    // Grab a creature element from the XML file
    XMLElement * pElement = pRoot->FirstChildElement("creature");
    if(XMLCHECK(pRoot)) std::cout << "ERROR\n"; // check fail
    // Create creature
    Creature * creature = new Creature(pElement);
    std::cout << "Creature name: " << creature->getName() << std::endl;
    std::cout << "Creature vulnerability: " << creature->getVulnerability() << std::endl;
    creature->showTriggers();

    /* RUN GAME */
    // Prompt for command
    // |-> If (trigger) --> Execute (trigger)
    // |-> Else --> Execute (command)
    //      |--> If (trigger) --> Execute (trigger)

    /* EXIT */
    return EXIT_SUCCESS;
}

// This is a simple utility function to get a value as long as the node is not null
static std::string getElementText(XMLElement *_element) {
    std::string value;
    if(_element != NULL) {
        value = _element->GetText();
    }
    return value;
}
