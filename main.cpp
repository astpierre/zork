#include "Player.h"
#include <iostream>

int main(int argc, char * argv[]) {
    // Create Player objects and assign addresses to pointers
    Player * andrew = new Player("Andy");
    Player * jeff = new Player("Jeff");

    // Call setWinner function on objects pointed to by pointers
    andrew->setWinner(true);
    jeff->setWinner(true);

    // Use isWinner to determine what to output
    if(andrew->isWinner()){
        std::cout << "Name: "<< andrew->getName()<< " Win? yes"<< std::endl;
    } else {
        std::cout << "Name: "<< andrew->getName()<< " Win? no" << std::endl;
    }

    if(jeff->isWinner()){
        std::cout << "Name: "<< jeff->getName()<< " Win? yes" << std::endl;
    } else {
        std::cout << "Name: "<< jeff->getName()<< " Win? no" << std::endl;
    }

    return 0;
}