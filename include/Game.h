#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <string>
#include "Component.h"
#include "Room.h"
#include "Item.h"
#include "Container.h"
#include "Creature.h"

class Game {
public:
	Game( const char * xmlfile );
	virtual ~Game( );
	void ShowObjects( );
    //void Begin( ); /* TODO: game play! */
	std::vector<Room *> rooms;
	std::vector<Item *> items;
    std::vector<Container *> containers;
	std::vector<Creature *> creatures;
	bool game_over = false;
};

#endif /* GAME_H */
