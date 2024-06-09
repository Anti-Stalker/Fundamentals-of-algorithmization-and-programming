cmake_minimum_required(VERSION 3.28)
project(lab3_4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab3_4 main.cpp
hanoitowersolver.cpp
        hanoitowersolver.h
        mover.cpp
        mover.h
        widget.cpp
        widget.h
)
target_link_libraries(lab3_4
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

