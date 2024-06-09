cmake_minimum_required(VERSION 3.28)
project(lab3_1)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab3_1 main.cpp
        bintodecrecursivetranslator.cpp
        bintodecrecursivetranslator.h
        widget.cpp
        widget.h
        widget.ui)

target_link_libraries(lab3_1
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)
