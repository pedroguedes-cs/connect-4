#include <string>

#include "../include/player.hpp"

Player::Player()
{
    name = "NO NAME";
    symbol = '-';
}

Player::Player(std::string name, char symbol)
{
    this->name = name;
    this->symbol = symbol;
}

// Getters
std::string Player::get_name() const
{
    return name;
}

char Player::get_symbol() const
{
    return symbol;
}

// Setters
void Player::set_name(std::string name)
{
    this->name = name;
}

void Player::set_symbol(char symbol)
{
    this->symbol = symbol;
}