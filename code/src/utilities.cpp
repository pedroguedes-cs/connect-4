#include <iostream>

#include "../include/utilities.hpp"


void horizontal_row(int columns)
{
    int row_size = columns * 5;

    for (int i = 0; i < row_size; i++)
    {
        std::cout << '-';
    }
}