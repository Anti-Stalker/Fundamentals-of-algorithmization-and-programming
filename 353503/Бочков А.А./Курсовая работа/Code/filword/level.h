#ifndef LEVEL_H
#define LEVEL_H
#pragma once

#include <QFile>
#include <QMainWindow>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPalette>
#include <QPixmap>
#include <QTimer>
#include <QWidget>
#include <bor.h>
#include <mainwindow.h>
#include <player.h>
#include <set>
#include <unistd.h>

namespace Ui {
class Level;
}

class Level : public QMainWindow
{
    Q_OBJECT

protected:
    void resizeEvent(QResizeEvent *event) override
    {
        QPixmap bkgnd("../filword/фон2.jpeg");
        //qDebug() << size;
        bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Window, bkgnd);
        setPalette(palette);

        QMainWindow::resizeEvent(event);
    }

public:
    explicit Level(QWidget *parent = nullptr);
    ~Level();

private slots:
    void Timer_slot();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

private:
    void updateStatistic();
    QTimer *levelTimer;
    Player player;
    QColor colors[10] = {Qt::green,
                         QColor(175, 0, 0) /*темно-красный*/,
                         Qt::blue,
                         QColor(223, 0, 255) /*фиолетовый*/,
                         QColor(102, 230, 217) /*бирюзовый*/,
                         QColor(0, 100, 0) /*темно-зеленый*/,
                         QColor(0, 0, 150) /*темно-синий*/,
                         QColor(255, 132, 143) /*розовый*/,
                         QColor(255, 135, 0) /*оранжевый*/,
                         Qt::gray};
    std::set<std::pair<int, std::pair<int, int> > > cells;
    bor *allWords = new bor();
    QMessageBox msgBox;
    std::set<std::pair<int, int> > sortWordLength;
    std::set<QString> listWords, listFoundWords;
    QPointF mousePos;
    int wordsSize[15], rightWord = 0, showLetters[15], levelTime = 0, hints = 0, bonusMoney = 0,
                       intLevel[10][10], deadlockness[10][10], lengthWord[15], numEnterCells = 0,
                       siz, numWord;
    QString words[100001], enterWord = "";
    bool freedom[10][10], mouseFlag = false, otherLevelFlag = false;
    std::pair<int, int> wordCells[15][15], mouseCell, enterCells[50], corner, bonusCell,
        deltaCell[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    QChar charLevel[10][10];
    void fillLevel(int);
    void generateLevel(int, int);
    bool exist(int, int, int);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    Ui::Level *ui;
};

#endif // LEVEL_H
