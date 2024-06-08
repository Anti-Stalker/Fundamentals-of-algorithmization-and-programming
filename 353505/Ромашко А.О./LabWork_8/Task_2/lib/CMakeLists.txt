cmake_minimum_required(VERSION 3.14)

project(lib LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(lib SHARED
  lib_global.h
  lib.cpp
  lib.h
  listnode.h listheap.h listheap.cpp list.pro lib.h lib.cpp lib_global.h CMakeLists.txt.user CMakeLists.txt
  list.pro listheap.cpp listheap.h listnode.h
)

target_link_libraries(lib PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(lib PRIVATE LIB_LIBRARY)
