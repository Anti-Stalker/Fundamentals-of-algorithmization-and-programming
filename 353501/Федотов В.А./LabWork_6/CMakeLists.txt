cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets PrintSupport)
qt_standard_project_setup()

#Task 1
qt_add_executable(Task_1
    Task_1/main.cpp Task_1/mainwindow.cpp Task_1/mainwindow.h Task_1/mainwindow.ui
    Task_1/Song.h
)

target_link_libraries(Task_1 PRIVATE Qt6::Widgets Qt6::PrintSupport)

set_target_properties(Task_1 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

#Task 2
qt_add_executable(Task_2
    Task_2/main.cpp Task_2/mainwindow.cpp Task_2/mainwindow.h Task_2/mainwindow.ui
    Task_2/Subtask1/Subtask1.cpp Task_2/Subtask1/Subtask1.ui
    Task_2/Subtask2/Subtask2.cpp Task_2/Subtask2/Subtask2.ui
    Task_2/Subtask3/Subtask3.cpp Task_2/Subtask3/Subtask3.ui
    Task_2/Subtask4/Subtask4.cpp Task_2/Subtask4/Subtask4.ui
)

target_link_libraries(Task_2 PRIVATE Qt6::Widgets)

set_target_properties(Task_2 PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)


