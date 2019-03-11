cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

project(zork)

add_library(include
    include/Component.h
    include/Trigger.h
    include/Creature.h
    include/Item.h
    include/Container.h
    include/TurnOn.h
    include/tinyxml2.h
    src/tinyxml2.cpp
    src/Component.cpp
    src/Container.cpp
    src/Trigger.cpp
    src/Turnon.cpp
    src/Creature.cpp
    src/Item.cpp
)


add_executable(zork_test
  src/main.cpp
)

target_link_libraries(zork_test zorklib)