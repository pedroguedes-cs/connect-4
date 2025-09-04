#include <iostream>

#include "../include/menu.hpp"
#include "../include/style.hpp"


void print_menu()
{
    subtitle("MENU:");
    std::cout << "[1] PLAY\n";
    std::cout << "[2] HOW TO PLAY?\n";
    std::cout << "[3] EXIT\n";
}

void how_to_play()
{
    subtitle("HOW TO PLAY");
    std::cout << "- Pick a column and drop your piece in. Gravity does the rest - it falls straight to the bottom.\n";
    std::cout << "- Take turns with your opponent, one piece at a time.\n";
    std::cout << "- Your mission: line up 4 of your own pieces.\n";
    std::cout << "- You can connect them sideways, up and down, or even diagonally - creativity counts.\n";
    std::cout << "- Whoever connects 4 first is the champion.\n";
    std::cout << "- If the board fills up and no one has 4 in a row... it's a draw!\n";
}

