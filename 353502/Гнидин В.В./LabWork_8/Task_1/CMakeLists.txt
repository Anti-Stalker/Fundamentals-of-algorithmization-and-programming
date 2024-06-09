cmake_minimum_required(VERSION 3.28)
project(lab7_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab7_2 main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        main.cpp
        BaseTree.cpp
        BaseTree.h
        BinaryTree.cpp
        BinaryTree.h
        ScapegoatTree.cpp
        ScapegoatTree.h
        Treap.cpp
        Treap.h
)
target_link_libraries(lab7_2
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

