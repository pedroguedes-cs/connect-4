#include <iostream>

#include "../include/board.hpp"
#include "../include/style.hpp"

// Constructors
Board::Board()
{
    rows = 6;
    columns = 7;

    grid.resize(rows);

    // Grid
    for (int i = 0; i < rows; i++)
    {
        grid[i].resize(columns, '-');
    }  

    // Drop positions
    for (int i = 0; i < columns; i++)
    {
        drop_positions[i] = rows - 1;
    }

    last_play = {'-', {0, 0}};
}

Board::Board(int rows, int columns)
{
    this->rows = rows;
    this->columns = columns;

    grid.resize(rows);

    // Grid
    for (int i = 0; i < rows; i++)
    {
        grid[i].resize(columns, '-');
    }
    
    // Drop positions
    for (int i = 0; i < columns; i++)
    {
        drop_positions[i] = rows - 1;
    }

    last_play = {'-', {0, 0}};
}

// Gameover
bool Board::is_full() 
{
    bool full = true;

    for (int i = 0; i < columns; i++)
    {
        if (drop_positions[i] >= 0)
        {
            full = false;
            break;
        }
    }

    return full;
}

char Board::check_win() const
{
    char character = last_play.symbol;

    if (check_row(last_play, rows, columns, grid) == character || check_column(last_play, rows, columns, grid) == character || check_primary_diagonal(last_play, rows, columns, grid) == character || check_secundary_diagonal(last_play, rows, columns, grid) == character)
    {
        return character;
    }

    return '-';
}

// Getters
int Board::get_rows() const
{
    return rows;
}

int Board::get_columns() const
{
    return columns;
}

char Board::get_symbol(int row, int column) const
{
    return grid[row][column];
}

int Board::get_drop_position(int column) 
{
    return drop_positions[column];
}

// Setters
bool Board::set(int column, char character)
{
    if (drop_positions[column] == -1)
    {
        return false;
    }
    else
    {
        grid[drop_positions[column]][column] = character;
        last_play = {character, {drop_positions[column], column}};
        drop_positions[column]--;
        return true;
    }
}

void Board::clear()
{
    for (auto &p : drop_positions)
    {
        p.second = rows - 1;
    }

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            grid[r][c] = '-';
        }
    }
}

// Printers
void Board::show() const
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





// Check win funtions

char check_row(Play last, int rows, int columns, std::vector<std::vector<char>> grid)
{
    int character = last.symbol;
    int counter = 0;

    for (int c = last.position.column - 3; c <= last.position.column + 3; c++)
    {
        if (c < 0 || c >= columns)
        {
            continue;
        }

        if (grid[last.position.row][c] == character)
        {
            counter++;
        } 

        else 
        {
            counter = 0;
        }

        if (counter == 4)
        {
            return character;
        }
    }

    return '-';
}

char check_column(Play last, int rows, int columns, std::vector<std::vector<char>> grid)
{
    int character = last.symbol;
    int counter = 0;

    for (int r = last.position.row - 3; r <= last.position.row + 3; r++)
    {
        if (r < 0 || r >= rows)
        {
            continue;
        }

        if (grid[r][last.position.column] == character)
        {
            counter++;
        } 

        else 
        {
            counter = 0;
        }

        if (counter == 4)
        {
            return character;
        }
    }

    return '-';
}

char check_primary_diagonal(Play last, int rows, int columns, std::vector<std::vector<char>> grid)
{
    int character = last.symbol;
    int counter = 0;

    int runner_row = last.position.row - 3;
    int runner_column = last.position.column - 3;


    while (runner_row <= last.position.row + 3)
    {
        if (runner_row < 0 || runner_row >= rows || runner_column < 0 || runner_column >= columns)
        {
            runner_row++;
            runner_column++;
            continue;
        }

        if (grid[runner_row][runner_column] == character)
        {
            counter++;
        } 

        else
        {
            counter = 0;
        }

        if (counter == 4)
        {
            return character;
        }

        runner_row++;
        runner_column++;
    }

    return '-';
}

char check_secundary_diagonal(Play last, int rows, int columns, std::vector<std::vector<char>> grid)
{
    int character = last.symbol;
    int counter = 0;

    int runner_row = last.position.row + 3;
    int runner_column = last.position.column - 3;


    while (runner_row >= last.position.row - 3)
    {
        if (runner_row < 0 || runner_row >= rows || runner_column < 0 || runner_column >= columns)
        {
            runner_row--;
            runner_column++;
            continue;
        }

        if (grid[runner_row][runner_column] == character)
        {
            counter++;
        } 

        else
        {
            counter = 0;
        }

        if (counter == 4)
        {
            return character;
        }

        runner_row--;
        runner_column++;
    }

    return '-';
}
