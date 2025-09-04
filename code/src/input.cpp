#include <iostream>

#include "../include/input.hpp"


bool is_integer(std::string number)
{
    if (number.empty())
    {
        return false;
    }

    if (number == "+" || number == "-")
    {
        return false;
    }

    for (auto i = number.begin(); i < number.end(); i++)
    {
        if ((*i == '+' || *i == '-') && i != number.begin())
        {
            return false;
        }

        if (*i != '-' && *i != '+' && (*i < '0' || *i > '9'))
        {
            return false;
        }
    }

    return true;
}

int read_choice(std::string message, std::string error_message, int end_answer_range)
{
    std::string choice;

    while (true)
    {
        std::cout << "\n" << message;

        if (getline(std::cin,choice) && is_integer(choice) && stoi(choice) >= 1 && stoi(choice) <= end_answer_range)
        {
            return stoi(choice);
        }

        std::cout << error_message << "\n";
    }
}

std::string read_name (std::string& message, std::string& error_message)
{
    std::string name;

    while (true)
    {
        std::cout << "\n" << message;

        if (getline(std::cin,name) && !name.empty())
        {
            return name;
        }

        std::cout << error_message << "\n";
    }
}