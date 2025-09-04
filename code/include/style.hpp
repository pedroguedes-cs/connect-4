#pragma once

#include <string>


void title(std::string title);

void subtitle(std::string subtitle);

void print_line();


// Messages
void print_round(int round, std::string name, char symbol);

void print_invalid_play();

void print_winner(std::string name);

void print_draw();

void print_exiting();

void print_bye();


// Board.show()
void horizontal_row(int columns);

void print_indexes(int columns);