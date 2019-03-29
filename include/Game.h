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
	void addToInventory( std::string obj );
	void displayInventory( );
	bool inventoryContains( std::string obj );
	void removeFromInventory(std::string obj);
	Room * getRoomByName( std::string roomName );
	Item * getItemByName( std::string itemName );
	Container * getContainerByName( std::string containerName );
	Creature * getCreatureByName( std::string creatureName );
	bool checkInput( std::string userInput );
	std::vector<std::string> splitString( const std::string s, const std::string delim );
	bool moveCommand( std::string cmd );
	void changeRoom( std::string cmd );
	bool prelimTriggerCheck( std::vector<std::string> cmdLine );
	void takeCommand( std::vector<std::string> cmdLine );
	std::string searchAllForType( std::string objName );
	void handleTrigger(Trigger * t);
	bool checkConditions(Trigger * t);

    void Play( ); /* TODO: game play! */
	std::vector<Room *> rooms;
	std::vector<Item *> items;
    std::vector<Container *> containers;
	std::vector<Creature *> creatures;
	bool game_over = false;
	std::vector<std::string> inventory;
	std::vector<std::string> game_commands = {  "n", "s", "e", "w", "i",
                                    			"take", "open", "open exit",
                                    			"read", "drop", "put", "turn", "attack"
                                 			 };
	std::vector<std::string> movement_commands = { "n", "s", "e", "w" };
	Room * curr_room = nullptr;
};

#endif /* GAME_H */
