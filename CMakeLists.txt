cmake_minimum_required(VERSION 3.13)
project(zork)

set(CMAKE_CXX_STANDARD 14)

add_executable(zork main.cpp Player.cpp Player.h rapidxml.hpp rapidxml_iterators.hpp)