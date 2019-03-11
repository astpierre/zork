//
// Created by Jeff on 3/11/2019.
//

#ifndef ZORK_ITEM_H
#define ZORK_ITEM_H
#include <vector>
#include <string>
#include "TurnOn.h"
class Item : public Component {
public:
    std::string writing;
    TurnOn * turnOn;

};
#endif //ZORK_ITEM_H
