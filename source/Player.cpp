#include "../headers/Player.hpp"

Player::Player() : symbol(' '), name("Unnamed") {}

Player::Player(char symbol, const std::string& name)
    : symbol(symbol), name(name) {}

char Player::getSymbol() const {
    return symbol;
}

std::string Player::getName() const {
    return name;
}

void Player::setSymbol(char symbol) {
    this->symbol = symbol;
}

void Player::setName(const std::string& name) {
    this->name = name;
}
