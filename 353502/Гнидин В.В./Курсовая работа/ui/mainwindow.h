//
// Created by volodya-petarda on 5/3/24.
//

#ifndef CHESS_MAINWINDOW_H
#define CHESS_MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <vector>
#include <QDebug>
#include <QTimer>
#include "Button.h"
#include "../src/chess/Board.h"
#include "../src/chess/NeuralMinimaxMovePredictor.h"
#include "../src/neural_network/BaseNeuralNetwork.h"
#include "../src/neural_network/GPUNeuralNetwork.h"


QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

private:
    bool isBotWhite = false;
    int isEnd = -1;
    double evaluation = 0.5;
    MinimaxMovePredictor *predictor;
    BaseNeuralNetwork *evaluator;
    std::pair<int, int> lastPos = {-1, -1};
    Board *board;
    Ui::mainwindow *ui;

    void createBoard();

    void drawBoard();

    std::vector<std::vector<Button*>> buttons;
public slots:
    void resetWhite();
    void resetBlack();
    void botMove();
    void getClickedPos(int ind);
};


#endif //CHESS_MAINWINDOW_H
