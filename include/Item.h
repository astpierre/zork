//
// Created by Jeff on 3/11/2019.
//

#ifndef ZORK_ITEM_H
#define ZORK_ITEM_H
#include <vector>
#include <string>
#include "TurnOn.h"
#include "Component.h"
class Item : public Component {
public:
    void setWriting(std::string writing);
    std::string getWriting();
private:
    std::string writing;
    TurnOn * turnOn;

};
#endif //ZORK_ITEM_H
