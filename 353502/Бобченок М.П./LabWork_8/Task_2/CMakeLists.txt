cmake_minimum_required(VERSION 3.27)
project(task2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(task2 main.cpp
        Heaps/ArrayHeap.h
        Heaps/PtrHeap.h
        main_window.cpp
        main_window.h
        main_window.ui)
target_link_libraries(task2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

