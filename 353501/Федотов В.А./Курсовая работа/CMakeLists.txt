cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(maze
    main.cpp mainwindow.cpp mainwindow.ui

    UI/menu.cpp UI/menu.ui
    UI/game.cpp UI/game.ui
    
    Cell/cell.cpp
    Maze/maze.cpp
    Player/player.cpp
    Enemy/enemy.cpp
    Pathfinder/pathfinder.cpp
    Powerup/powerupTeleport.cpp
    Powerup/powerupInvisible.cpp
    Powerup/basePowerup.cpp
    # Sprites/loader.cpp
)

target_link_libraries(maze PRIVATE Qt6::Widgets)

set_target_properties(maze PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)