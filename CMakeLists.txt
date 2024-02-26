cmake_minimum_required(VERSION 3.9)

project(tictactoe-cpp)

#include(${PROJECT_SOURCE_DIR}/cmake/SetEnv.cmake)

set(CMAKE_CXX_STANDARD 20)

add_executable(tictactoe src/tictactoe.cpp)