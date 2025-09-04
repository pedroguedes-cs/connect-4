#pragma once

#include <string>

std::string strip(std::string text);

std::string upper(std::string text);

bool is_integer(std::string number);

int read_choice(std::string message, std::string error_message, int end_answer_range);

std::string read_name(std::string message, std::string error_message);