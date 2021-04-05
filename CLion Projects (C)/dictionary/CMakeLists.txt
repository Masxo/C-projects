cmake_minimum_required(VERSION 3.16)
project(dictionary C)

set(CMAKE_C_STANDARD 99)

add_executable(dictionary main.c)

target_link_libraries(dictionary m)