// Created by Jeff on 3/11/2019.
// Updated by Andrew on 03/26/2019

#ifndef ZORK_CONTAINER_H
#define ZORK_CONTAINER_H
#include "Component.h"
#include "Item.h"
#include <vector>
class Container : public Component{
public:
    Container( XMLElement * );
    virtual ~Container();
    virtual void addItem( std::string );
    virtual void removeItem( std::string );
    virtual std::vector<std::string> getItems( );

    bool open = false;
    bool acceptAll = false;
    std::vector <std::string> accept;
    std::vector <std::string> items;
};

#endif //ZORK_CONTAINER_H
