#include <tuple>
#include "Player.h"

// Getters
const std::string &Player::getName() const { return name; }
int Player::getScore() const { return score; }

// Setters
void Player::changeName(const std::string &name) { Player::name = name; }
void Player::plusOneScore() { Player::score += 1; }

// Constructor
Player::Player(const std::string &name, int score) : name(name),score(score) {}

// Destructor
Player::~Player() {}

// Misc methods
bool Player::isWinner() const {
    if(score >= 10){
        return true;
    } else {
        return false;
    }
}