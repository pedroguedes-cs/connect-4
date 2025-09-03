#include <iostream>

#include "../include/board.hpp"
#include "../include/utilities.hpp"

Board::Board()
{
    rows = 6;
    columns = 7;

    grid.resize(rows);

    for (int i = 0; i < rows; i++)
    {
        grid[i].resize(columns, '-');
    }  
}

Board::Board(int rows, int columns)
{
    this->rows = rows;
    this->columns = columns;

    grid.resize(rows);

    for (int i = 0; i < rows; i++)
    {
        grid[i].resize(columns, '-');
    }  
}

void Board::show()
{
    print_indexes(columns);

    horizontal_row(columns);

    std::cout << "\n";

    for (int r = 0; r < rows; r++)
    {

        for (int c = 0; c < columns; c++)
        {
            if (c == 0)
            {
                std::cout << "| " << grid[r][c] << " |";
            }
            else
            {
                std::cout << " " << grid[r][c] << " |";
            }
        }

        std::cout << "\n";

        horizontal_row(columns);

        std::cout << "\n";
    }
}

char Board::get(int row, int column)
{
    return grid[row][column];
}

bool Board::set(int column, char character)
{
    for (int r = rows - 1; r >= 0; r--)
    {
        if (grid[r][column] == '-')
        {
            grid[r][column] = character;
            return true;
        }
    }

    return false;
}

bool Board::is_full()
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            if (grid[r][c] == '-')
            {
                return false;
            }
        }
    }

    return true;
}

void Board::clear()
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            grid[r][c] = '-';
        }
    }
}