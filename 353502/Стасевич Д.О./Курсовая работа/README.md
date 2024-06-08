#Разработка аналога игры Судоку

Данный курсовой проект представляет приложение, позволяющее играть в Судоку и сохдавать свои головоломки.

##Блок-схема алгоритма, реализующего генерацию полю с заданным ограничением


Применяется в: `SudokuField/PlayersField.cpp`, при вызове конструктора поля, реализована в методе `SimpleLevelGenerate` в `SudokuField/SudokuField.cpp` 


![Algorithm 1 scheme](Schemes/1.png)


##Блок-схема алгоритма, реализующего оценку сложности данного поля


Применяется в: `SudokuField/SudokuField.cpp`, в методе `CalculateDifficulty`, реализована в методе `GetDifficulty` в `SudokuField/SudokuField.cpp` 


![Algorithm 2 scheme](Schemes/2.png)


##Блок-схема алгоритма, реализующего генерацию поля заданной сложности


Применяется в: `SudokuField/PlayersField.cpp`, при вызове конструктора поля, реализована в методе `DifficultLevelGenerate` в `SudokuField/SudokuField.cpp` 


![Algorithm 3 scheme](Schemes/3.png)


##Блок-схема алгоритма, реализующего выдачу подсказки пользователю


Применяется в: `mainwindow/mainwindow.cpp`, в методе `simple_hint_button_clicked`, реализована в методе `GetSimpleHint` в `SudokuField/PlayersField.cpp` 


![Algorithm 4 scheme](Schemes/4.png)


##Блок-схема алгоритма, реализующего выдачу метода решения пользователю 


Применяется в: `mainwindow/mainwindow.cpp`, в методе `clever_hint_button_clicked`, реализована в методе `GetCleverHint` в `SudokuField/Pl   ayersField.cpp`


![Algorithm 5 scheme](Schemes/5.png)
