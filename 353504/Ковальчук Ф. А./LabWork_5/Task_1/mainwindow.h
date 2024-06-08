#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QMainWindow>
#include "QTimer"
#include "QElapsedTimer"
#include "QPushButton"
#include "QMap"
#include "QKeyEvent"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent *event);
private slots:
    void on_languageChangeComboBox_currentIndexChanged(int index);

    void on_startButton_clicked();

    void on_openTestButton_clicked();
private:
    QStringList currTest;

    Ui::MainWindow *ui;

    int currLocal;

    bool checkTest();

    bool isTesting = false;

    int currNeededSimb = 0;
    int currTestNum = 0;

    void setButtons();

    QElapsedTimer* timer = new QElapsedTimer();
    QTimer* updateTimer = new QTimer();

    int words = 0;
    int rightSymbols = 0;
    int allSymbols = 0;

    void updateInfo();

    void workWithEvent(QKeyEvent *event);

    QString ButtonColors(int key);
    void setText();

    QString state = "Начать";

public:
    void keyPressEventTaked(QKeyEvent *event);
    void setKeys(int);
public slots:
    void handleButtonClicked();
private:
    QMap<int, QPushButton *> buttonsMap;
};
#endif // MAINWINDOW_H
