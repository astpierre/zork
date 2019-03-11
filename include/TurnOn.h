//
// Created by Jeff on 3/11/2019.
//

#ifndef ZORK_TURNON_H
#define ZORK_TURNON_H

#include <string>
class TurnOn {
public:
    virtual ~TurnOn();
    void setPrint(std::string print);
    std::string getPrint();
    void setAction(std::string action);
    std::string getAction();

private:
    std::string print;
    std::string action;
};
#endif //ZORK_TURNON_H
