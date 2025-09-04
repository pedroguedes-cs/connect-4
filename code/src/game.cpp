#include <iostream>

#include "../include/board.hpp"
#include "../include/game.hpp"
#include "../include/input.hpp"
#include "../include/menu.hpp"
#include "../include/message.hpp"
#include "../include/play.hpp"
#include "../include/player.hpp"
#include "../include/position.hpp"
#include "../include/style.hpp"

Game::Game()
{
    rounds = 1;
    player1 = {"PLAYER 1", 'x'};
    player2 = {"PLAYER 2", 'o'};
}

void Game::run()
{
    bool has_winner;
    std::string name_winner;
    int choice;
    bool exit = false;

    title("CONNECT 4");

    while (true)
    {
        print_menu();
        choice = read_choice("Enter your choice: ", "Please try again with a valid number.", 3);

        print_line();

        switch(choice)
        {
            case 1:
                has_winner = false;
                board.clear();

                subtitle("ENTER PLAYER NAMES");
                player1.set_name(read_name("Player 1: ", "Invalid! Please type something."));
                player2.set_name(read_name("Player 2: ", "Invalid! Please type something."));

                print_line();

                while(!has_winner && !board.is_full())
                {
                    print_round();

                    board.show;

                    print_round();

                    board.show();
                }

                print_line();

                if (has_winner)
                {
                    print_winner(name_winner);
                }
                else
                {
                    print_draw();
                }

                break;

            case 2:
                how_to_play();
                break;

            case 3:
                print_exiting();
                break;
        }

        print_line();

        if (exit == false)
        {
            break;
        }
    }

    print_bye();
    
}