cmake_minimum_required(VERSION 3.16)
project(Spotify C)

set(CMAKE_C_STANDARD 99)

add_executable(Spotify main.c utils.c utils.h)