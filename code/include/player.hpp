#pragma once 

#include <string>


class Player 
{
    std::string name;
    char symbol;

    public:

        // Constructors
        Player();
        Player(std::string name, char symbol);

        // Getters
        std::string get_name() const;
        char get_symbol() const;

        // Setters
        void set_name(std::string);
        void set_symbol(char symbol);
};