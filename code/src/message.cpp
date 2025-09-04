#include <iostream>

#include "../include/message.hpp"


void print_winner(std::string name)
{
    std::cout << "And the winner is... " << name << "! Four in a row, unstoppable!\n";
}

void print_draw()
{
    std::cout << "It's a tie! The board is full, but the glory is empty.\n";
}

void print_exiting()
{
    std::cout << "Closing the game... packing up the pieces.\n";
}

void print_bye()
{
    std::cout << "\nGoodbye, challenger! Come back for another round.\n\n\n\n";
}