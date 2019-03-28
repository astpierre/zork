#ifndef CONDITION_H
#define CONDITION_H
#include <iostream>
#include <vector>
#include <string>
#include "tinyxml2.h"
using namespace tinyxml2;

class Condition {
public:
    Condition( XMLElement * ConditionElement );
    virtual ~Condition( );

    void setHas(std::string h);
    void setOwner(std::string o);
    void setObject(std::string o);
    void setStatus(std::string s);
    std::string getHas( );
    std::string getOwner( );
    std::string getObject( );
    std::string getStatus( );

    bool satisfies(std::string h, std::string obj, std::string own );

private:
    std::string has = "";
    std::string object = "";
    std::string owner = "";
    std::string status = "";
};

#endif /* CONDITION_H */
