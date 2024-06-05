cmake_minimum_required(VERSION 3.5)

project(Simulation VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp mainwindow.h mainwindow.ui
        drawergl.h drawergl.cpp
        Consts.h
        object.h object.cpp
        field.h field.cpp
        cell.h cell.cpp
        coord.h coord.cpp
        direction.h direction.cpp
        graphic.h graphic.cpp
        settings.h
        genomslistwidget.h genomslistwidget.cpp
        settingsmenu.h settingsmenu.cpp settingsmenu.ui
        vectorfileio.h vectorfileio.cpp
        createpopulationmenu.h createpopulationmenu.cpp createpopulationmenu.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Simulation
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Simulation APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Simulation SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Simulation
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Simulation PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Simulation PRIVATE Qt6::OpenGLWidgets)

set_target_properties(Simulation PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Simulation)
endif()
