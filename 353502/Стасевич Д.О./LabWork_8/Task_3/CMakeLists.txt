cmake_minimum_required(VERSION 3.27)
project(task3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(task3 main.cpp
        mainwindow/mainwindow.cpp
        mainwindow/mainwindow.h
        mainwindow/mainwindow.ui
        RBTree/RBTree.cpp
        RBTree/RBTree.h
        RBTree/map.h
        RBTree/set.cpp
        RBTree/set.h
        RBTree/unordered_map.cpp
        RBTree/unordered_map.h)
target_link_libraries(task3
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

