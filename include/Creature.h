#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <vector>
#include <string>
#include "Component.h"
#include "Attack.h"
#include "tinyxml2.h"
using namespace tinyxml2;

class Creature: public Component {
public:
    Creature( XMLElement * );
    virtual ~Creature( );

    std::vector<std::string> getVulnerabilities( );

private:
    std::vector<std::string> vulnerabilities;
};

#endif /* CREATURE_H */
