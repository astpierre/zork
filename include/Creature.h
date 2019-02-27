#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <vector>
#include <string>
#include "Component.h"
#include "tinyxml2.h"
using namespace tinyxml2;

class Creature: public Component {
public:
    Creature( XMLElement * creatureElement );
    virtual ~Creature( );

    void setVulnerability( std::string );
    std::string getVulnerability( );


private:
    std::string vulnerability = "";
};

#endif /* CREATURE_H */
