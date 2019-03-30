#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <vector>
#include <string>
#include "Component.h"
#include "Condition.h"
#include "Attack.h"
#include "tinyxml2.h"
using namespace tinyxml2;

class Creature: public Component {
public:
    Creature(XMLElement *);

    virtual ~Creature();

    std::vector<std::string> getVulnerabilities();

    std::string getAttackPrint();

    void addVulnerability(std::string);

    bool hasVulnerability(std::string);

    void addAttackAction(std::string);

    std::vector<std::string> getAttackActions();

    std::vector<Condition *> getAttackConditions();
private:
    std::vector<std::string> vulnerabilities;
    std::vector<Condition *> attackConditions;
    std::vector<std::string> attackActions;
    std::string attackPrint;

};

#endif /* CREATURE_H */
