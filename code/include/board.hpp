#pragma once

#include <vector>
#include <map>

#include "play.hpp"
#include "position.hpp"

class Board
{
    private:

        int rows;
        int columns;
        std::vector<std::vector<char>> grid;

        std::map<int, int> drop_positions;
        Play last_play;

    public:

        // Constructors
        Board();
        Board(int rows, int columns);

        // Gameover
        bool is_full() const;
        char check_win() const;

        // Getters
        char get_symbol(int row, int column) const;
        int get_drop_position(int column) const;

        // Setters
        bool set(int column, char character);
        void clear();

        // Printers
        void show() const;
};

// Check win functions

char check_row(Play last, int rows, int columns, std::vector<std::vector<char>> grid);

char check_column(Play last, int rows, int columns, std::vector<std::vector<char>> grid);

char check_primary_diagonal(Play last, int rows, int columns, std::vector<std::vector<char>> grid);

char check_secundary_diagonal(Play last, int rows, int columns, std::vector<std::vector<char>> grid);