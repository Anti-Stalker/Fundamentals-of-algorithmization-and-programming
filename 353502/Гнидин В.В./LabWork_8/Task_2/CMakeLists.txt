cmake_minimum_required(VERSION 3.28)
project(lab8_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab8_2 main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        heap/HeapList.h
        heap/HeapList.cpp
        heap/HeapArray.h
        heap/HeapArray.cpp
        heap/Heap.cpp
        heap/Heap.h)
target_link_libraries(lab8_2
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

