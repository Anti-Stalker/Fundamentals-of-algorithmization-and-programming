# Приложение для анализа игровых сценариев и принятия решений на основе теории вероятностей. 

включает в себя две симуляции ("Бросок монеты" и "Боулинг") и две стратегические игры ("Башни" и "Эволюция города"), каждая из которых предлагает уникальные возможности для анализа и стратегии.

## Метод Монте-Карло реализованный в симуляции подброса монеты (используется в [coinsimulation.cpp](https://github.com/Artiomsin/Fundamentals-of-algorithmization-and-programming/blob/course_paper/353504/%D0%A1%D0%B8%D0%BD%D1%8F%D0%BA%D0%BE%D0%B2%20%D0%90.%20%D0%90./%D0%9A%D1%83%D1%80%D1%81%D0%BE%D0%B2%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/coinsimulation.cpp) в методе double CoinSimulation::simulateCoinTossProbability(double tilt, int numTosses, double force, double mass). Применяется там же)

![image](https://github.com/Artiomsin/Fundamentals-of-algorithmization-and-programming/assets/149619968/5ce5f48b-184a-4a98-9eb3-29dc9f4816f7)

## Алгоритм по расчету взвешенного угла наклона монеты (используется в [coinsimulation.cpp](https://github.com/Artiomsin/Fundamentals-of-algorithmization-and-programming/blob/course_paper/353504/%D0%A1%D0%B8%D0%BD%D1%8F%D0%BA%D0%BE%D0%B2%20%D0%90.%20%D0%90./%D0%9A%D1%83%D1%80%D1%81%D0%BE%D0%B2%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/coinsimulation.cpp) в методе double CoinSimulation::calculateWeightedAngle(double angle, double force, double mass). Применяется там же)

![image](https://github.com/Artiomsin/Fundamentals-of-algorithmization-and-programming/assets/149619968/2d201a78-1900-45e1-bf49-5fbade1931bb)

## Алгоритм выполнения Байесовских сетей реализованный в стратегической игре "Башни" (используется в [mainwindow.cpp](https://github.com/Artiomsin/Fundamentals-of-algorithmization-and-programming/blob/course_paper/353504/%D0%A1%D0%B8%D0%BD%D1%8F%D0%BA%D0%BE%D0%B2%20%D0%90.%20%D0%90./%D0%9A%D1%83%D1%80%D1%81%D0%BE%D0%B2%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/mainwindow.cpp) в методе void MainWindow::updateProbabilities(int playerFortressStrength, int computerFortressStrength, int defenseStrategy, int attackStrategy). Применяется там же)

![image](https://github.com/Artiomsin/Fundamentals-of-algorithmization-and-programming/assets/149619968/f74f9958-e6b5-4843-9a56-c35ec35d8eee)

## Алгоритм основанный на Марковских моделях и цепях реализованный в стратегической игре "Эволюция города" (используется в [mainwindow.cpp](https://github.com/Artiomsin/Fundamentals-of-algorithmization-and-programming/blob/course_paper/353504/%D0%A1%D0%B8%D0%BD%D1%8F%D0%BA%D0%BE%D0%B2%20%D0%90.%20%D0%90./%D0%9A%D1%83%D1%80%D1%81%D0%BE%D0%B2%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/mainwindow.cpp) в методе void MainWindow::simulateDisasterEvent(). Применяется там же)

![image](https://github.com/Artiomsin/Fundamentals-of-algorithmization-and-programming/assets/149619968/66a282b4-9eda-4c40-ab32-aaf9e410d8ba)

## Алгоритм по построению графика зависимости вероятности выпадения орла и решки от количества подбросов монеты (используется в [mainwindow.cpp](https://github.com/Artiomsin/Fundamentals-of-algorithmization-and-programming/blob/course_paper/353504/%D0%A1%D0%B8%D0%BD%D1%8F%D0%BA%D0%BE%D0%B2%20%D0%90.%20%D0%90./%D0%9A%D1%83%D1%80%D1%81%D0%BE%D0%B2%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/mainwindow.cpp) в методе void MainWindow::plotCoinTossProbabilityGraph(int maxTosses, double tilt, double force, double mass). Применяется там же)

![image](https://github.com/Artiomsin/Fundamentals-of-algorithmization-and-programming/assets/149619968/623b21ec-b604-4163-8515-b30dc76be7df)




