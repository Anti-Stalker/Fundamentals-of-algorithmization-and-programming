cmake_minimum_required(VERSION 3.28)
project(Lab8Task1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Lab8Task1 main.cpp
        Widget.cpp
        Widget.h
        Widget.ui
        BinarySearchTree.h
)
target_link_libraries(Lab8Task1
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

