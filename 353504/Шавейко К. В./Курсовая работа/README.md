# СОЗДАНИЕ ПРИЛОЖЕНИЯ ДЛЯ ИГРЫ В БИЛЬЯРД
## Данная папка содержит разработанный курсовой проект с блок-схемами пяти алгоритмов,а также с ссылками на реализацию данных алгоритмов в программе
### Блок-схема алгоритма, реализующего расчёт столкновения шаров
 Применяется в: Fundamentals-of-algorithmization-and-programming/353504/Шавейко К.В./Курсовая работа/basegame.cpp в функции resolveBallCollision(Ball &b1, Ball &b2, QVector2D collisionVector) , результат работы обрабатывается в функции void BaseGame::update(float dtime)

<img width="524" alt="схема1" src="https://github.com/Ksenia654/Fundamentals-of-algorithmization-and-programming/assets/143942997/f484f28e-d827-48d7-ae06-7514ab561a47">

### Блок-схема алгоритма, реализующего отражение шара от края стола
 Применяется в: Fundamentals-of-algorithmization-and-programming/353504/Шавейко К.В./Курсовая работа/basegame.cpp в функции resolveTableCollision(Ball &b, QVector2D collisionVector), результат работы обрабатывается в функции  void BaseGame::update(float dtime)
 
 <img width="524" alt="схема2" src="https://github.com/Ksenia654/Fundamentals-of-algorithmization-and-programming/assets/143942997/ef8901a4-084b-4e78-b725-95f77dc8d9b1">

### Блок-схема алгоритма, реализующего совершение удара с помощью событий мыши
 Применяется в: Fundamentals-of-algorithmization-and-programming/353504/Шавейко К.В./Курсовая работа/cueballcontrolfeature.cpp в функции CueBallControlFeature() , результат работы обрабатывается в функции handleEvent(QMouseEvent* mouse)
 
 <img width="524" alt="схема3" src="https://github.com/Ksenia654/Fundamentals-of-algorithmization-and-programming/assets/143942997/69be0b49-f09f-4330-814e-ce35bfbb53fb">

### Блок-схема алгоритма, реализующего взаимодействие шаров с лузами на столе
 Применяется в: Fundamentals-of-algorithmization-and-programming/353504/Шавейко К.В./Курсовая работа/pocketinteractionfeature.cpp в функции void PocketInteractionFeature::update(float dtime), результат работы обрабатывается в функции GameFeature::update(dtime)
 
<img width="524" alt="схема4" src="https://github.com/Ksenia654/Fundamentals-of-algorithmization-and-programming/assets/143942997/96a06dcb-7255-4e44-bc33-4f1a6be29ba5">

### Блок-схема алгоритма, реализующего визуализацию направления удара
Применяется в: Fundamentals-of-algorithmization-and-programming/353504/Шавейко К.В./Курсовая работа/pocketinteractionfeature.cpp в функции void PocketInteractionFeature::draw(QPainter& painter), результат работы обрабатывается в функции GameFeature::draw(painter)

<img width="524" alt="схема5" src="https://github.com/Ksenia654/Fundamentals-of-algorithmization-and-programming/assets/143942997/c0ef87e9-5fd6-4df3-9184-92be062de1ed">

