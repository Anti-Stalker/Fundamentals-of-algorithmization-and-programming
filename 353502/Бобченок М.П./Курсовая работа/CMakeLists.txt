cmake_minimum_required(VERSION 3.27)
project(fullBread)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(fullBread main.cpp
        Network/matrixMath/matrixMath.cpp
        Network/matrixMath/matrixMath.h
        Network/Network.cpp
        Network/Network.h
        developersMenu/Menu.cpp
        developersMenu/Menu.h
        settings/paths.h
        userInterface/main_window.cpp
        userInterface/main_window.h
        userInterface/main_window.ui)
target_link_libraries(fullBread
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

