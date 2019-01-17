#ifndef ZORK_PLAYER_H
#define ZORK_PLAYER_H

#include <string>
#include <iostream>

class Player {
public:
    /* Public data members and function members are like
     * an API for the instance of the class */

    // Destructor
    virtual ~Player();

    // Constructor
    Player(const std::string &name,int score);

    // Getters
    int getScore() const;
    const std::string &getName() const;

    // Setters
    void plusOneScore();
    void changeName(const std::string &name);

    // Misc methods
    bool isWinner() const;

private:
    /* Private data members and function members are not
     * accessible by users of an instance of the class */

    // Data members
    int score = 0;
    std::string name;
};

#endif //ZORK_PLAYER_H
