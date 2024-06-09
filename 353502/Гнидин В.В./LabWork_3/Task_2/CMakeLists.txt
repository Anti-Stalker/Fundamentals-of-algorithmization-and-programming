cmake_minimum_required(VERSION 3.28)
project(lab3_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab3_2 main.cpp
widget.cpp
widget.h
ackermanfunctioncalculator.cpp
ackermanfunctioncalculator.h)

target_link_libraries(lab3_2
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

