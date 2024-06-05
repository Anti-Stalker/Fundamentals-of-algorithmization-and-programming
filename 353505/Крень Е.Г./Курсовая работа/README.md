# РАЗРАБОТКА КЛИЕНТ-СЕРВЕРНОЙ ИГРЫ "Hexagonal Map"

Данная папка содержит разработанный курсовой проект с блок-схемами, приложенными к пояснительной записке данного проекта, с ссылками на реализацию данных алгоритмов в программе. 

## Блок-схема алгоритма, реализующего процедурную генерацию карты

Применяется в: `Hexagonal Map/Server/src/game.cpp`в методе generateMap()

![Algorithm scheme](schemes/1.png)

## Блок-схема алгоритма, реализующего обработку нажатия мыши

Применяется в: `Hexagonal Map/Client/src/gamewindow.cpp`в методе mousePressEvent()

![Algorithm scheme](schemes/2.png)

## Блок-схема алгоритма, реализующего генерацию строений

Применяется в: `Hexagonal Map/Server/src/game.cpp`в методе generateMap()

![Algorithm scheme](schemes/3.png)

## Блок-схема алгоритма, реализующего определение победителя в битве

Применяется в: `Hexagonal Map/Server/src/server.cpp`в методе ReadSlot()

![Algorithm scheme](schemes/4.png)

## Блок-схема алгоритма, реализующего передачу данных между клиентом и сервером

Применяется в: `Hexagonal Map/Server/src/server.cpp`в методе ReadSlot(), `Hexagonal Map/Client/src/mainwindow.cpp`в методе ReadSlot()

![Algorithm scheme](schemes/5.png)
