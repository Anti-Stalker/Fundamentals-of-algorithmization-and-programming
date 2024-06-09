cmake_minimum_required(VERSION 3.28)
project(lab8_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab8_3 main.cpp
        Map.h
BaseTree.cpp
BinaryTree.h
        mainwindow.h
        mainwindow.cpp
        main.cpp
        #ScapegoatTree.h
#ScapegoatTree.cpp
#Treap.h
#Treap.cpp
)

target_link_libraries(lab8_3
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

