cmake_minimum_required(VERSION 3.28)
project(Lab4Task4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Lab4Task4 main.cpp
        Widget.cpp
        Widget.h
        Widget.ui
        my_stl/Vector.h
        my_stl/Pair.h
)
target_link_libraries(Lab4Task4
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

