cmake_minimum_required(VERSION 3.27)
project(NeuralNetwork CUDA CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(NeuralNetwork main.cpp
        src/neural_network/CPUNeuralNetwork.cpp
        src/neural_network/CPUNeuralNetwork.h
        src/linear_algebra/CPULinearAlgebra.cpp
        src/linear_algebra/CPULinearAlgebra.h
        src/neural_network/ActivationTypes.h
        src/chess/Board.cpp
        src/chess/Board.h
        src/neural_network/CPUNeuralNetwork.cpp
        src/neural_network/CPUNeuralNetwork.h
        src/neural_network/BaseNeuralNetwork.h
        src/neural_network/GPUNeuralNetwork.cu
        src/neural_network/GPUNeuralNetwork.h
        src/linear_algebra/GPULinearAlgebra.cu
        src/linear_algebra/GPULinearAlgebra.h
        test.cu
        test.h
        src/chess/MinimaxMovePredictor.cpp
        src/chess/MinimaxMovePredictor.h
        src/chess/NeuralMinimaxMovePredictor.cpp
        src/chess/NeuralMinimaxMovePredictor.h
        ui/mainwindow.cpp
        ui/mainwindow.h
        ui/mainwindow.ui
        ui/Button.cpp
        ui/Button.h
)
target_link_libraries(NeuralNetwork -lcublas -lcurand
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets)