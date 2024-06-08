cmake_minimum_required(VERSION 3.28)
project(Lab7Task2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Lab7Task2 main.cpp
        Widget.cpp
        Widget.h
        Widget.ui
        AVLTree.cpp
        AVLTree.h)
target_link_libraries(Lab7Task2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

