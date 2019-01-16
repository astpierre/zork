//
// Created by asaintp on 1/16/19.
//

#ifndef ZORK_PLAYER_H
#define ZORK_PLAYER_H

#include <string>
#include <iostream>

class Player {
public:
    Player(const std::string &name);

    int getScore() const;

    void setScore(int score);

    const std::string &getName() const;

    void setName(const std::string &name);

    bool isWinner() const;

    void setWinner(bool winner);

private:
    int score = 0;
    std::string name;
    bool winner = false;
};

#endif //ZORK_PLAYER_H
