cmake_minimum_required(VERSION 3.28)
project(lab3_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab3_3 main.cpp
        reverser.cpp
        reverser.h
        widget.cpp
        widget.h
)
target_link_libraries(lab3_3
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

