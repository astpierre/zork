#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <string>
#include "Component.h"
//#include "Room.h"
#include "Item.h"
//#include "Container.h"
#include "Creature.h"

class Game {
public:
	Game( const char * xmlfile );
	virtual ~Game( );
	void ShowObjects( );
    //void Begin( );
	std::vector<std::string> rooms; /* TODO: Change to <Room *> */
	std::vector<Item *> items;
    std::vector<std::string> containers; /* TODO: Change to <Container *> */
	std::vector<Creature *> creatures;
	bool game_over = false;
};

#endif /* GAME_H */
