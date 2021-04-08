cmake_minimum_required(VERSION 3.16)
project(pokebox C)

set(CMAKE_C_STANDARD 99)

add_executable(pokebox main.c
        SaveManager.c SaveManager.h
        dataStructures.c dataStructures.h
        PokeBox.c PokeBox.h
        Pokemon.c Pokemon.h
        PokeDex.c PokeDex.h
        SpriteManager.c SpriteManager.h
        Util.c Util.h
        PokeType.c PokeType.h
        utils.c utils.h)