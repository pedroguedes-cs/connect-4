cmake_minimum_required(VERSION 3.10)

# Project name and language
project(ConnectFour LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Where to put compiled binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include headers
include_directories(${CMAKE_SOURCE_DIR}/code/include)

# Source files
set(SOURCES
    code/src/main.cpp
    code/src/board.cpp
    code/src/game.cpp
    code/src/input.cpp
    code/src/menu.cpp
    code/src/player.cpp
    code/src/style.cpp
)

# Create executable
add_executable(connect4 ${SOURCES})