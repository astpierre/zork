//
// Created by Jeff on 3/11/2019.
//

#ifndef ZORK_CONTAINER_H
#define ZORK_CONTAINER_H
#include "Component.h"
#include "Item.h"
#include <vector>
class Container : public Component{
public:
    virtual ~Container();

    std::vector <std::string> accept;
    std::vector <Item *> items;
};

#endif //ZORK_CONTAINER_H