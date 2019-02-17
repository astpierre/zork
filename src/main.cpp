#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Trigger.h"
#include "Component.h"
#include "tinyxml2.h"

// Macro to check XML parsing
// Forward declaration of functions used by the main function
static std::string getElementText(tinyxml2::XMLElement *_element);
static std::vector<std::string> getTextList(tinyxml2::XMLElement *_element);

int main(void) {
    /* GAME SETUP */
    // Open XML file
    tinyxml2::XMLDocument doc;
    doc.LoadFile("test.xml");

    // Parse XML file
    tinyxml2::XMLNode * pRoot = doc.FirstChild();
    if (pRoot == nullptr) std::cout << "ERROR\n";
    tinyxml2::XMLElement * pElement = pRoot->FirstChildElement("creature");
    std::string creatureName = getElementText(pElement->FirstChildElement("name"));
	std::cout << " Name of creature: " << creatureName << std::endl;

    // Create all objects (all roooms and items)
    // Populate all objects

    /* RUN GAME */
    // Prompt for command
    // |-> If (trigger) --> Execute (trigger)
    // |-> Else --> Execute (command)
    //      |--> If (trigger) --> Execute (trigger)

    /* EXIT */
    return EXIT_SUCCESS;
}

// This is a simple utility function to get a value as long as the node is not null
static std::string getElementText(tinyxml2::XMLElement *_element) {
    std::string value;
    if(_element != NULL) {
        value = _element->GetText();
    }

    return value;
}

// This function gets a list of elements within "D" tags in an element, then puts them in a vector
static std::vector<std::string> getTextList(tinyxml2::XMLElement *_element) {
    tinyxml2::XMLElement *pRoot;
    std::vector<std::string> strings;
    if(_element != NULL) {
        pRoot = _element->FirstChildElement("D");
        while(pRoot) {
            strings.push_back(pRoot->GetText());
            pRoot = pRoot->NextSiblingElement("D");
        }
    }
    return strings;
}
