cmake_minimum_required(VERSION 3.28)
project(Lab8Task2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Lab8Task2 main.cpp
        Widget.cpp
        Widget.h
        Widget.ui
        BinaryHeap.cpp
        BinaryHeap.h
        ArrayBH.cpp
        ArrayBH.h
        ListBH.cpp
        ListBH.h)
target_link_libraries(Lab8Task2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

