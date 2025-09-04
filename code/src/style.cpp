#include <iostream>
#include <string>

#include "../include/style.hpp"


void title(std::string title)
{
    std::cout << "\n\n---------------------------------------------------------------------------\n";
    std::cout << title << std::endl;
    std::cout << "---------------------------------------------------------------------------\n\n\n";
}

void subtitle(std::string subtitle)
{
    std::cout << subtitle << "\n\n";
}

void print_line()
{
    std::cout << "\n\n---------------------------------------------------------------------------\n\n\n";
}


// Messages
void print_round(int round, std::string name, char symbol)
{
    std::cout << "\nROUND " << round << " [ " << name << " | " << symbol << " ]\n\n\n";
}

void print_invalid_play()
{
    std::cout << "That column is already stuffed! Try another one.\n";
}

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


// Board.show()
void horizontal_row(int columns)
{
    int row_size = columns * 4 + 1;

    for (int i = 0; i < row_size; i++)
    {
        std::cout << '-';
    }
}

void print_indexes(int columns)
{
    for (int i = 1; i <= columns; i++)
    {
        std::cout << "  " << i << " ";
    }

    std::cout << "\n";

    for (int i = 1; i <= columns; i++)
    {
        std::cout << "  | ";
    }

    std::cout << "\n";

    for (int i = 1; i <= columns; i++)
    {
        std::cout << "  v ";
    }

    std::cout << "\n";
}
