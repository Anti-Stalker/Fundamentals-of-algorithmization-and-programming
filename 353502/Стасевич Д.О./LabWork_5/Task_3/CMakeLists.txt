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
        BitSet/MyBitset.cpp
        BitSet/MyBitset.h)
target_link_libraries(task3
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

