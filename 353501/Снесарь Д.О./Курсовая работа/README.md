# Реализация программы для игры в судоку

Для сборки изменить пути к файлам сохраненных уровней 

## Блок-схема для функции решения судоку

Применяется в: `src/gamewidget.cpp` в функции void GameWidget::on_solveB_clicked()

![Algorithm scheme](schemes/1.png)

## Блок-схема для оценки сложности уровня

Применяется в: `src/generator.cpp` в функции void Generator::calculateDifficulty()

![Algorithm scheme](schemes/2.png)

## Блок-схема для генерации уровня

Применяется в: `src/gamewidget.cpp` в функции void GameWidget::generateB_Clicked()

![Algorithm scheme](schemes/3.png)

## Блок-схема для создания двусвязного двумерного списка

Применяется в: `src/gamewidget.cpp` в функции void GameWidget::on_solveB_clicked()

![Algorithm scheme](schemes/4.png)

## Блок-схема изменения поля игры

![Algorithm scheme](schemes/5.png)

Применяется в: `src/gamewidget.cpp` в функциях класса gamewidget

## Функциональная схема

![Algorithm scheme](schemes/6.png)
