#include <iostream>

#include "../include/board.hpp"
#include "../include/game.hpp"
#include "../include/input.hpp"
#include "../include/menu.hpp"
#include "../include/play.hpp"
#include "../include/player.hpp"
#include "../include/position.hpp"
#include "../include/style.hpp"

Game::Game()
{
    round = 0;
    player1 = {"PLAYER 1", 'x'};
    player2 = {"PLAYER 2", 'o'};
}

void Game::run()
{
    bool gameover;
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
                round = 0;
                gameover = false;
                has_winner = false;
                board.clear();

                subtitle("ENTER PLAYER NAMES");
                player1.set_name(read_name("Player 1: ", "Invalid! Please type something."));
                player2.set_name(read_name("Player 2: ", "Invalid! Please type something."));

                print_line();

                while(true)
                {
                    Player current_player;

                    for (int turn = 0; turn < 2; turn++)
                    {
                        if (turn == 0)
                        {
                            round++;
                            current_player = player1;
                        }
                        else
                        {
                            current_player = player2;
                        }

                        print_round(round, current_player.get_name(), current_player.get_symbol());
                        board.show();
                        while (!board.set(read_choice("Column: ", "Please try again a valid number.", board.get_columns()) - 1, current_player.get_symbol()))
                        {
                            print_invalid_play();
                        }

                        if (board.check_win() == current_player.get_symbol())
                        {
                            has_winner = true;
                            name_winner = current_player.get_name();
                            gameover = true;
                            break;
                        }
                        
                        if (board.is_full())
                        {
                            gameover = true;
                            break;
                        }

                        print_line();
                    }

                    if (gameover)
                    {
                        break;
                    }

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
                exit = true;
                print_exiting();
                break;
        }

        print_line();

        if (exit)
        {
            break;
        }
    }

    print_bye();
    
}