cmake_minimum_required(VERSION 3.27)
project(task_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(task_2 main.cpp
        mainwindow/mainwindow.cpp
        mainwindow/mainwindow.h
        mainwindow/mainwindow.ui)
target_link_libraries(task_2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

