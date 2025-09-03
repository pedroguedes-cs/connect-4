#pragma once

#include "player.hpp"
#include "board.hpp"

class Game
{
    int rounds;
    int mode;
    Board board;
    Player player1;
    Player player2;

    public:
        Game();
        void run();
};