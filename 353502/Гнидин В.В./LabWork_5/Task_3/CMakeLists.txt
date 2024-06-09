cmake_minimum_required(VERSION 3.28)
project(lab5_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab5_3 main.cpp
bitset.cpp
bitset.h)
target_link_libraries(lab5_3
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

