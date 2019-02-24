#ifndef ATTACK_H
#define ATTACK_H
#include <iostream>
#include <vector>
#include <string>
#include "Trigger.h"
#include "tinyxml2.h"
using namespace tinyxml2;

class Attack: public Trigger {
public:
    Attack( XMLElement * attackElement );
    virtual ~Attack( );

private:
    std::vector <std::string> actions;
};

#endif /* ATTACK_H */
