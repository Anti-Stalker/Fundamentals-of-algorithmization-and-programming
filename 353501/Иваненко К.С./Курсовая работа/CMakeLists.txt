cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(Obsidian
  main.cpp
  mainwindow.cpp mainwindow.h mainwindow.ui
  noteslistwidget.cpp noteslistwidget.h noteslistwidget.ui
  note.h
  notesmanager.cpp notesmanager.h
  notewidget.cpp notewidget.h
  renamedialog.cpp renamedialog.h renamedialog.ui
  xlmstorage.cpp xlmstorage.h
  graphwidget.cpp graphwidget.h graphwidget.ui
  moveitem.cpp moveitem.h
)

target_link_libraries(Obsidian PRIVATE Qt6::Widgets)

set_target_properties(Obsidian PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
