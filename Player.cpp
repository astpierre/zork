//
// Created by asaintp on 1/16/19.
//

#include "Player.h"

int Player::getScore() const {
    return score;
}

void Player::setScore(int score) {
    Player::score = score;
}

const std::string &Player::getName() const {
    return name;
}

void Player::setName(const std::string &name) {
    Player::name = name;
}

bool Player::isWinner() const {
    return winner;
}

void Player::setWinner(bool winner) {
    Player::winner = winner;
}

Player::Player(const std::string &name) : name(name) {}
