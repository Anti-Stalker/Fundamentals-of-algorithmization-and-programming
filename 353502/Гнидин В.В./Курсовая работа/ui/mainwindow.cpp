//
// Created by volodya-petarda on 5/3/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include <QPainter>
#include "mainwindow.h"
#include "ui_mainwindow.h"


mainwindow::mainwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainwindow) {
    board = new Board();
    isEnd = 0;
    ui->setupUi(this);
    createBoard();
    evaluator = new GPUNeuralNetwork();
    BaseNeuralNetwork *pr = new GPUNeuralNetwork();
    evaluator->load("evaluator.txt");
    pr->load("predictor.txt");
    predictor = new NeuralMinimaxMovePredictor(pr, evaluator);
    QTimer *timer = new QTimer(this);
    timer->setInterval(50);
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(botMove()));
    connect(this->ui->playWhite, SIGNAL(clicked()), this, SLOT(resetWhite()));
    connect(this->ui->playBlack, SIGNAL(clicked()), this, SLOT(resetBlack()));
}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::createBoard() {
    buttons = std::vector<std::vector<Button*>>(8, std::vector<Button*>(8));

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            buttons[i][j] = new Button(i * 8 + j, this);
            buttons[i][j]->setFixedSize(115, 115);
            buttons[i][j]->move( j * 115 + 75, (7 - i) * 115 + 75);
            QPalette pal = buttons[i][j]->palette();
            if((i + j) % 2 == 0)
                pal.setColor(QPalette::Button, QColor(118, 150, 86));
            else
                pal.setColor(QPalette::Button, QColor(238, 238, 210));
            buttons[i][j]->setAutoFillBackground(true);
            buttons[i][j]->setPalette(pal);
            connect(buttons[i][j], SIGNAL(clicked(int)), this, SLOT(getClickedPos(int)));
        }
    }
    drawBoard();
}

void mainwindow::drawBoard() {
    int **field = board->getField();
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            QPalette pal = buttons[i][j]->palette();
            std::string move = "a1a1";
            move[1] += lastPos.first;
            move[0] += lastPos.second;
            move[3] += i;
            move[2] += j;
            if((i + j) % 2 == 0)
                pal.setColor(QPalette::Button, QColor(118, 150, 86));
            else
                pal.setColor(QPalette::Button, QColor(238, 238, 210));
            if(lastPos.first == i && lastPos.second == j){
                pal.setColor(QPalette::Button, QColor(215, 48, 30));
            }
            else if(lastPos.first != -1 && board->isPossibleMove(move)){
                pal.setColor(QPalette::Button, QColor(255, 98, 80));
            }
            buttons[i][j]->setAutoFillBackground(true);
            buttons[i][j]->setPalette(pal);
            buttons[i][j]->update();

            if(field[i][j] == 0)
                buttons[i][j]->setIcon(QIcon());
            if(field[i][j] == 1)
                buttons[i][j]->setIcon(QIcon("../ui/images/whitepawn.png"));
            if(field[i][j] == 2)
                buttons[i][j]->setIcon(QIcon("../ui/images/whiterook.png"));
            if(field[i][j] == 3)
                buttons[i][j]->setIcon(QIcon("../ui/images/whitebishop.png"));
            if(field[i][j] == 4)
                buttons[i][j]->setIcon(QIcon("../ui/images/whiteknight.png"));
            if(field[i][j] == 5)
                buttons[i][j]->setIcon(QIcon("../ui/images/whitequeen.png"));
            if(field[i][j] == 6)
                buttons[i][j]->setIcon(QIcon("../ui/images/whiteking.png"));
            if(field[i][j] == 7)
                buttons[i][j]->setIcon(QIcon("../ui/images/blackpawn.png"));
            if(field[i][j] == 8)
                buttons[i][j]->setIcon(QIcon("../ui/images/blackrook.png"));
            if(field[i][j] == 9)
                buttons[i][j]->setIcon(QIcon("../ui/images/blackbishop.png"));
            if(field[i][j] == 10)
                buttons[i][j]->setIcon(QIcon("../ui/images/blackknight.png"));
            if(field[i][j] == 11)
                buttons[i][j]->setIcon(QIcon("../ui/images/blackqueen.png"));
            if(field[i][j] == 12)
                buttons[i][j]->setIcon(QIcon("../ui/images/blackking.png"));

            buttons[i][j]->setIconSize(QSize(115, 115));
        }
    }
    this->ui->evaluation->setText(QString::fromStdString(std::to_string(evaluation)));
    QPixmap pm;
    evaluation = 1.0f - evaluation;
    if(evaluation <= 0.05)
        pm = QPixmap("../ui/images/-9.jpg");
    if(evaluation >= 0.05 && evaluation <= 0.12)
        pm = QPixmap("../ui/images/-8.png");
    if(evaluation >= 0.12 && evaluation <= 0.20)
        pm = QPixmap("../ui/images/-7.jpg");
    if(evaluation >= 0.20 && evaluation <= 0.26)
        pm = QPixmap("../ui/images/-6.jpg");
    if(evaluation >= 0.26 && evaluation <= 0.30)
        pm = QPixmap("../ui/images/-5.png");
    if(evaluation >= 0.30 && evaluation <= 0.34)
        pm = QPixmap("../ui/images/-4.jpg");
    if(evaluation >= 0.34 && evaluation <= 0.38)
        pm = QPixmap("../ui/images/-3.jpg");
    if(evaluation >= 0.38 && evaluation <= 0.42)
        pm = QPixmap("../ui/images/-2.png");
    if(evaluation >= 0.42 && evaluation <= 0.46)
        pm = QPixmap("../ui/images/-1.png");
    if(evaluation >= 0.46 && evaluation <= 0.54)
        pm = QPixmap("../ui/images/0.png");

    evaluation = 1.0f - evaluation;
    if(evaluation >= 0.42 && evaluation <= 0.46)
        pm = QPixmap("../ui/images/1.jpg");
    if(evaluation >= 0.38 && evaluation <= 0.42)
        pm = QPixmap("../ui/images/2.jpg");
    if(evaluation >= 0.34 && evaluation <= 0.38)
        pm = QPixmap("../ui/images/3.jpeg");
    if(evaluation >= 0.30 && evaluation <= 0.34)
        pm = QPixmap("../ui/images/4.png");
    if(evaluation >= 0.26 && evaluation <= 0.30)
        pm = QPixmap("../ui/images/5.jpg");
    if(evaluation >= 0.20 && evaluation <= 0.26)
        pm = QPixmap("../ui/images/6.jpg");
    if(evaluation >= 0.12 && evaluation <= 0.20)
        pm = QPixmap("../ui/images/7.png");
    if(evaluation >= 0.05 && evaluation <= 0.12)
        pm = QPixmap("../ui/images/8.jpg");
    if(evaluation <= 0.05)
        pm = QPixmap("../ui/images/9.jpg");

    ui->image->setPixmap(pm);
    ui->image->setScaledContents(true);
}

void mainwindow::getClickedPos(int ind) {
    if(isEnd != 0)
        return;
    std::pair<int, int> curPos = {ind / 8, ind % 8};
    if(isBotWhite == !board->getIsWhiteMove() && lastPos.first != -1){
        std::string move = "a1a1";
        move[1] += lastPos.first;
        move[0] += lastPos.second;
        move[3] += curPos.first;
        move[2] += curPos.second;
        if(board->isPossibleMove(move)){
            board->move(move);
            lastPos = curPos;
            float *t = evaluator->predict(board->extendedEncodeBoard());
            evaluation = 1.0f - *t;
            isEnd = board->isEnd();
        }
        else {
            lastPos = {-1, -1};
        }
    }
    else{
        lastPos = curPos;
    }
    drawBoard();
}

void mainwindow::botMove() {
    if(!isEnd && isBotWhite == board->getIsWhiteMove()){
        std::string move = predictor->predictMove(*board);
        board->move(move);
        lastPos = {move[3] - '1', move[2] - 'a'};
        isEnd = board->isEnd();
        float *t = evaluator->predict(board->extendedEncodeBoard());
        evaluation = *t;
        drawBoard();
    }
}

void mainwindow::resetWhite() {
    board = new Board();
    isEnd = 0;
    isBotWhite = false;
    evaluation = 0.5;
    drawBoard();
}

void mainwindow::resetBlack() {
    board = new Board();
    isEnd = 0;
    isBotWhite = true;
    evaluation = 0.5;
    drawBoard();
}
