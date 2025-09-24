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

char Board::check_win() 
{
    char character = last_play.symbol;

    if (this->check_row() == character || this->check_column() == character || this->check_primary_diagonal() == character || this->check_secundary_diagonal() == character)
    {
        return character;
    }

    return '-';
}

char Board::check_row()
{
    int character = last_play.symbol;
    int counter = 0;

    for (int c = last_play.position.column - 3; c <= last_play.position.column + 3; c++)
    {
        if (c < 0 || c >= columns)
        {
            continue;
        }

        if (grid[last_play.position.row][c] == character)
        {
            counter++;
        } 

        else 
        {
            counter = 0;
        }

        if (counter == 4)
        {
            Position begin = {last_play.position.row, c - 3};
            Position end = {last_play.position.row, c};
            this->winner_board(begin, end);
            return character;
        }
    }

    return '-';
}

char Board::check_column()
{
    int character = last_play.symbol;
    int counter = 0;

    for (int r = last_play.position.row - 3; r <= last_play.position.row + 3; r++)
    {
        if (r < 0 || r >= rows)
        {
            continue;
        }

        if (grid[r][last_play.position.column] == character)
        {
            counter++;
        } 

        else 
        {
            counter = 0;
        }

        if (counter == 4)
        {
            Position begin = {r - 3, last_play.position.column};
            Position end = {r, last_play.position.column};
            this->winner_board(begin, end);
            return character;
        }
    }

    return '-';
}

char Board::check_primary_diagonal()
{
    int character = last_play.symbol;
    int counter = 0;

    int runner_row = last_play.position.row - 3;
    int runner_column = last_play.position.column - 3;


    while (runner_row <= last_play.position.row + 3)
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
            Position begin = {runner_row - 3, runner_column - 3};
            Position end = {runner_row, runner_column};
            this->winner_board(begin, end);
            return character;
        }

        runner_row++;
        runner_column++;
    }

    return '-';
}

char Board::check_secundary_diagonal()
{
    int character = last_play.symbol;
    int counter = 0;

    int runner_row = last_play.position.row + 3;
    int runner_column = last_play.position.column - 3;


    while (runner_row >= last_play.position.row - 3)
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
            Position begin = {runner_row + 3, runner_column - 3};
            Position end = {runner_row, runner_column};
            this->winner_board(begin, end);
            return character;
        }

        runner_row--;
        runner_column++;
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

void Board::winner_board(Position begin, Position end)
{
    int runner_row = begin.row;
    int runner_column = begin.column;

    // Row
    if (begin.row == end.row)
    {
        for (int i = 0; i < 4; i++, runner_column++)
        {
            grid[runner_row][runner_column] = '*';
        }
    }
    //Column
    else if (begin.column == end.column)
    {
        for (int i = 0; i < 4; i++, runner_row++)
        {
            grid[runner_row][runner_column] = '*';
        }
    }
    // Primary Diagonal
    else if (begin.row < end.row)
    {
        for (int i = 0; i < 4; i++, runner_row++, runner_column++)
        {
            grid[runner_row][runner_column] = '*';
        }
    }
    // Secondary Diagonal
    else 
    {
        for (int i = 0; i < 4; i++, runner_row--, runner_column++)
        {
            grid[runner_row][runner_column] = '*';
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
                if (grid[r][c] == '-')
                {
                    std::cout << "| " << ' ' << " |";
                }
                else
                {
                    std::cout << "| " << grid[r][c] << " |";
                }
               
            }
            else
            {
                if (grid[r][c] == '-')
                {
                    std::cout << " " << ' ' << " |";
                }
                else
                {
                    std::cout << " " << grid[r][c] << " |";
                }
            }
        }

        std::cout << "\n";

        horizontal_row(columns);

        std::cout << "\n";
    }
}



