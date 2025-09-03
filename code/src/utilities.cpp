#include <iostream>

#include "../include/utilities.hpp"


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