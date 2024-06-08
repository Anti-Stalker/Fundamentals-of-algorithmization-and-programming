cmake_minimum_required(VERSION 3.27)
project(task1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(task1 main.cpp
        main_window.cpp
        main_window.h
        main_window.ui
        Treap.h)
target_link_libraries(task1
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

