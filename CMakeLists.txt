cmake_minimum_required(VERSION 4.2.3)
project(AirFight)

set(CMAKE_CXX_STANDARD 14)

include_directories(AirFight)


add_executable(

        AirFight

        AirFight/AirFight.cpp
        AirFight/Tile.h
        AirFight/TileData.h
        AirFight/VideoManager.cpp
        AirFight/VideoManager.h
        AirFight/GameManager.cpp
        AirFight/GameManager.h
        AirFight/Grid.cpp
        AirFight/Grid.h
        AirFight/CommandManager.cpp
        AirFight/CommandManager.h
        AirFight/CoordinateParser.cpp
        AirFight/CoordinateParser.h
        AirFight/InputManager.cpp
        AirFight/InputManager.h
)

target_compile_features(AirFight PRIVATE cxx_std_20)