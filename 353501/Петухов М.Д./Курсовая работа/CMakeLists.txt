cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(farm
  main.cpp mainwindow.cpp mainwindow.h mainwindow.ui
  Animal.cpp Animal.h
  Grass.cpp Grass.h
  CustomGraphicsScene.cpp CustomGraphicsScene.h
  Egg.cpp Egg.h
  dialog.cpp dialog.h dialog.ui
  widget.cpp widget.h widget.ui
  Bear.cpp Bear.h
  factory.cpp factory.h
  product.cpp product.h
  winDialog.cpp winDialog.h winDialog.ui
  xorshiftplus.cpp xorshiftplus.h
  rulesDialog.cpp rulesDialog.h rulesDialog.ui
)


target_link_libraries(farm PRIVATE Qt6::Widgets)

set_target_properties(farm PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
