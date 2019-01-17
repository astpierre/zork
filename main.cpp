#include "Player.h"
#include <iostream>

// Function prototypes
std::string truth(int binaryVal);

// Main function [point of entry]
int main(int argc, char * argv[]) {
    // Create Player objects and assign addresses to pointers
    // Note: we are allocating the objects on the heap (keyword: new)
    Player * andrew = new Player("Andy",0);
    Player * jeff = new Player("Jeff",0);

    // Use isWinner to determine what to output
    std::cout << "Name: "<< andrew->getName()<<" Score: "<<andrew->getScore()<< " Win yet? "<<truth(andrew->isWinner())<< std::endl;
    std::cout << "Name: "<< andrew->getName()<<" Score: "<<jeff->getScore()<< " Win yet? "<<truth(jeff->isWinner())<< std::endl;

    // Using loops to do stuff [for and while]
    int i;
    for(i=0; i<9; i++) { andrew->plusOneScore(); }
    while(i>-1){ jeff->plusOneScore(); i--; }

    // Check the results on our objects
    std::cout<<"Name: "<<andrew->getName()<<" Score: "<<andrew->getScore()<<" Win yet? "<<truth(andrew->isWinner())<<std::endl;
    std::cout<<"Name: "<<jeff->getName()<<" Score: "<<jeff->getScore()<<" Win yet? "<<truth(jeff->isWinner())<<std::endl;

    // Return success
    return 0;
}

// Other functions
std::string truth(int binaryVal) {
    if(binaryVal){
        return "YES";
    } else {
        return "NO";
    }
}