#pragma once

#include <string>

bool is_integer(std::string number);

int read_choice(std::string message, std::string error_message, int end_answer_range);

std::string read_name(std::string message, std::string error_message);