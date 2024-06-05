# РАЗРАБОТКА ОПТИМИЗИРУЮЩЕГО КОМПИЛЯТОРА ДЛЯ СТЕК-МАШИНЫ

Даный проект заключается в создание оптимизируещего компилятора для стек машины для микропроцессорной архитектуры EasyCPU. Такой компилятор значительно увеличивает скорость програм написанныхх с применением стек инструкций, благодаря заменяющим оптимизациям и аллокации регистров.

## Функциональная схема програмного средства
![Algorithm scheme](schemes/func1.png)

## Функциональная схема компиляции и оптимизации
![Algorithm scheme](schemes/func2.png)

## Схема алгоритма аллокации свободных регистров

Применяется в: `easycpu_lib/src/stack/opt/comp.rs`

![Algorithm scheme part 1](schemes/block1a.png)
![Algorithm scheme part 2](schemes/block1b.png)


## Схема алгоритма подбора и применения заменяющих оптимизаций

Применяется в: `easycpu_lib/src/stack/opt/optim.rs`

![Algorithm scheme](schemes/block2.png)



## Схема алгоритма генерации инструкции загрузки константы

Применяется в: `easycpu_lib/src/asm/load_const.rs`

![Algorithm scheme](schemes/block3.png)


## Схема алгоритма взятия блока кода

Применяется в: `easycpu_lib/src/parser/parse.rs`

![Algorithm scheme part 1](schemes/block4a.png)
![Algorithm scheme part 2](schemes/block4b.png)


## Схема алгоритма генерации отчёта

Применяется в: `easycpu_test/genreport.py`

![Algorithm scheme](schemes/block5.png)
