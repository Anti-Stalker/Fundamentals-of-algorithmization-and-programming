cmake_minimum_required(VERSION 3.28)
project(lab4_4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab4_4 main.cpp
    mainwindow.cpp
    mainwindow.h
    iterator.h
    pair.h
    vector.h
        reverseIterator.h
)
target_link_libraries(lab4_4
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

