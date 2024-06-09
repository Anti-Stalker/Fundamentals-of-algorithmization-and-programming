cmake_minimum_required(VERSION 3.28)
project(lab6_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab6_1 main.cpp mainwindow.cpp mainwindow.h)
target_link_libraries(lab6_1
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

