cmake_minimum_required(VERSION 3.27)
project(task2_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(task2_1 main.cpp
        mainwindow/mainwindow.cpp
        mainwindow/mainwindow.h
        mainwindow/mainwindow.ui)
target_link_libraries(task2_1
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

