cmake_minimum_required(VERSION 3.16)
project(bmp_reader C)

set(CMAKE_C_STANDARD 99)

add_executable(bmp_reader main.c)

target_link_libraries(bmp_reader m)
