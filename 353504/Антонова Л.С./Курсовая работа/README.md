# Разработка приложения для игры в нарды

Реализация игрового проекта: игры в нарды вдвоем на одном устройстве и против ИИ игрока.

## Алгоритм выполнения хода

Применяется в: `Backgammon/game.cpp` в методе tryMakeMove()

![Algorithm1 scheme](schemes/1.drawio.png)

## Алгоритм считывания значений с кубиков

Применяется в: `Backgammon/game.cpp` в методе getDicesMovements()

![Algorithm2 scheme](schemes/2.drawio.png)

## Алгоритм проверки доступности хода

Применяется в: `Backgammon/game.cpp` в методе validateMovement()

![Algorithm3 scheme](schemes/3.drawio.png)

## Алгоритм присвоения типа хода

Применяется в: `Backgammon/game.cpp` в методе getMoveType()

![Algorithm4 scheme](schemes/4.drawio.png)

## Алгоритм реализации бота

Применяется в: `Backgammon/game.cpp` в методе aiMove()

![Algorithm5 scheme](schemes/5.drawio.png)
