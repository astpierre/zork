cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

project(zork)

add_library(zorklib
    include/Component.h
    include/Trigger.h
    include/Creature.h
    include/tinyxml2.h
    src/tinyxml2.cpp
    src/Component.cpp
    src/Trigger.cpp
    src/Creature.cpp
)

target_include_directories(
  zorklib
  PUBLIC
    "include"
)

add_executable(zork_test
  src/main.cpp
)

target_link_libraries(zork_test zorklib)
