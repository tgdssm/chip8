cmake_minimum_required(VERSION 3.26)
project(chip8)

set(CMAKE_CXX_STANDARD 17)



set(SDL2_PATH /opt/homebrew/Cellar/sdl2/2.28.3)

set(SDL2_INCLUDE_DIR ${SDL2_PATH}/include)
set(SDL2_LIB_DIR ${SDL2_PATH}/lib)

find_package(SDL2 REQUIRED PATHS ${SDL2_PATH})

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(chip8 main.cpp
        Chip8.cpp
        Chip8.h
        Display.cpp
        Display.h)

target_link_libraries(${PROJECT_NAME} SDL2::SDL2)