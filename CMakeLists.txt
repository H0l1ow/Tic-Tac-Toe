cmake_minimum_required(VERSION 3.10)

project(TicTakToe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIR
    source/main.cpp
    source/Game.cpp
    source/Player.cpp

)

set(HEADER_FILES
    headers/Game.hpp
    headers/Player.hpp
)

add_executable(${PROJECT_NAME} ${SOURCE_DIR} ${HEADER_FILES})