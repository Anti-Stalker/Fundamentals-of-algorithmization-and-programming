#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QMap>
#include <QMessageBox>
#include <QTextEdit>
#include "mybutton.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    QHBoxLayout* firstLayout; //выбор сложности, показ игрового времени и т. д.
    QGridLayout* buttonsLayout; //игровые кнопки
    QVBoxLayout* totalLayout; //содержит предыдущие два макета
    QComboBox* gameDifficulties; //выбрать сложность игры
    MyButton*** buttons; //игровые кнопки
    QPushButton* resetButton; //кнопка сброса для новой игры
    QPushButton* showStatistic; //кнопка, чтобы показать статистику
    QString** buttonText; //тексты, соответствующие кнопкам, например, мина, 1, 2 и т. д.
    QLabel* flags; //показывает, сколько флагов==мин осталось
    QLabel* timeLabel; //показывает время игры
    QTimer* timer; //измеряет игровое время
    double time; //для таймера
    int gameDifficulty; //сохраняет сложность игры: 0 — легкая, 1 — средняя, ​​2 — сложная.
    int buttonRows, buttonColumns; //сохраняются текущие размеры игрового поля
    int countOfMines; //количество мин зависит от сложности
    int disabledButtons; //сколько кнопок больше нельзя использовать
    int countOfFlags; //изначально он хранит количество оставшихся флагов, равное количеству мин
    bool endOfGame; //ложно во время игры, истинно после выигрыша/проигрыша
    QMap <double, QString> statisticEasy;//лучшие результаты сохраняются, время имеет решающее значение
    QMap <double, QString> statisticMedium;
    QMap <double, QString> statisticHard;
    QMessageBox* top10; //показать лучшие результаты
    QPushButton *showRules;
    QTextEdit rules;

    void clearButtons(); //стирает все кнопки с игрового поля
    void setButtons(int n, int m, int size); //устанавливает кнопки
    void setMines();//установка мин
    void setNumbers(); //устанавливает номера кнопок на основе мин
    void onEmptyButtonClicked(int i, int j); //если нажата пустая кнопка; рекурсиz
    void mineClicked(); //если мы нажмем на мину
    void win(); //если выиграли
    void reset(); //сбросить все
    void showTop10(int gameDifficulty);
    QComboBox* createComboBox();

    void BFS(int i, int j);
    long long binomialCoeff(int n, int k);
    void DFS(int x, int y, QVector<QVector<bool>>& visited);
    bool isEulerianCycle();
    double signedArea(int x1, int y1, int x2, int y2, int x3, int y3);
    bool clockwise(int x1, int y1, int x2, int y2, int x3, int y3);
    void sieveOfEratosthenes(QVector<QVector<bool>> &isPrime, int cm);

private slots:
    void difficultyChanged(); //если изменим сложность
    void buttonClicked(); //нажать на кнопку на игровом поле
    void rightButtonClicked(); //если щелкнуть правой кнопкой мыши
    void tick(); //требуется для таймера
};
#endif // MAINWINDOW_H
