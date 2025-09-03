#pragma once

#include <vector>

class Board
{
    private:

        int rows;
        int columns;
        std::vector<std::vector<char>> grid;

    public:

        Board();
        
        Board(int rows, int columns);

        void show();

        char get(int row, int column);

        bool set(int column, char character);

        bool is_full();

        void clear();
};