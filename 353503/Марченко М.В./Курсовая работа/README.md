# Построитель и анализатор графов

## Блок-схема алгоритма поиска в ширину

Применяется в: `graph.cpp` в функции `QVector<int> Graph:: BFS(int start_vertex)`. Далее результат используется в `void MainWindow::onVertexSelected1(int selectedVertexNumber)`.

![Algorithm scheme](https://github.com/vykyky/Fundamentals-of-algorithmization-and-programming/blob/f0e338bcfd4564a6477101ce721a8027f198933b/353503/%D0%9C%D0%B0%D1%80%D1%87%D0%B5%D0%BD%D0%BA%D0%BE%20%D0%9C.%D0%92./%D0%9A%D1%83%D1%80%D1%81%D0%BE%D0%B2%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/Schemes/Scheme1/Scheme1.png)

## Блок-схема алгоритма поиска в глубину

Применяется в: `graph.cpp` в функции `QVector<int> Graph:: DFS(int start_vertex)`. Далее результат используется в `void MainWindow::onVertexSelected2(int selectedVertexNumber)`.

![Algorithm scheme](https://github.com/vykyky/Fundamentals-of-algorithmization-and-programming/blob/f0e338bcfd4564a6477101ce721a8027f198933b/353503/%D0%9C%D0%B0%D1%80%D1%87%D0%B5%D0%BD%D0%BA%D0%BE%20%D0%9C.%D0%92./%D0%9A%D1%83%D1%80%D1%81%D0%BE%D0%B2%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/Schemes/Scheme2/Scheme2.png)

## Блок-схема алгоритма Дейкстры

Применяется в: `graph.cpp` в функциях `QVector<QVector<int>> Graph::Dijkstra(int start_vertex)`. Далее результат используется в `void MainWindow::onVertexSelected3_1(int selectedVertexNumber)`.

![Algorithm scheme](https://github.com/vykyky/Fundamentals-of-algorithmization-and-programming/blob/f0e338bcfd4564a6477101ce721a8027f198933b/353503/%D0%9C%D0%B0%D1%80%D1%87%D0%B5%D0%BD%D0%BA%D0%BE%20%D0%9C.%D0%92./%D0%9A%D1%83%D1%80%D1%81%D0%BE%D0%B2%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/Schemes/Scheme3/Scheme3.png)

## Блок-схема алгоритма Прима

Применяется в: `graph.cpp` в функции `QVector<QPair<int, int>> Graph::primMST()`. Далее результат используется в `vvoid MainWindow::onButton4Clicked()`.

![Algorithm scheme](https://github.com/vykyky/Fundamentals-of-algorithmization-and-programming/blob/f0e338bcfd4564a6477101ce721a8027f198933b/353503/%D0%9C%D0%B0%D1%80%D1%87%D0%B5%D0%BD%D0%BA%D0%BE%20%D0%9C.%D0%92./%D0%9A%D1%83%D1%80%D1%81%D0%BE%D0%B2%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/Schemes/Scheme4/Scheme4.png)

## Блок-схема алгоритма Тарьяна

Применяется в: `graph.cpp` в функции `QVector<QVector<int>> Graph::tarjanSCC()`. Далее результат используется в `void MainWindow::onButton5Clicked()`.

![Algorithm scheme](https://github.com/vykyky/Fundamentals-of-algorithmization-and-programming/blob/f0e338bcfd4564a6477101ce721a8027f198933b/353503/%D0%9C%D0%B0%D1%80%D1%87%D0%B5%D0%BD%D0%BA%D0%BE%20%D0%9C.%D0%92./%D0%9A%D1%83%D1%80%D1%81%D0%BE%D0%B2%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/Schemes/Scheme5/Scheme5.png)
