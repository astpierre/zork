#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <vector>
#include <string>
#include "Component.h"
#include "tinyxml2.h"
using namespace tinyxml2;

class Item: public Component {
public:
    Item( XMLElement * );
    virtual ~Item( );

    void setOwner( std::string );
    std::string getOwner( );

    void setWriting( std::string );
    std::string getWriting( );

    void setTurnOnPrint( std::string );
    std::string getTurnOnPrint( );

    void setTurnOnAction( std::string );
    std::string getTurnOnAction( );

private:
    std::string owner = "";
    std::string writing = "";
    std::string turn_on_print = "";
    std::string turn_on_action = "";
};

#endif /* ITEM_H */
