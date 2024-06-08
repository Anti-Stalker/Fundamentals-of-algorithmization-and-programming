#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QFileDialog>
#include <QMainWindow>
#include <QTextCharFormat>
#include <QTimer>
#include "keyboardvisualizer.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setTextToWrite(QString& text);
    void ColorText(QChar newChar);
    void skip(int ms);
    void outputStat();

private slots:
    void updateTimer();

    void on_pushButton_chooseText_clicked();

    void on_ChangeLang_currentIndexChanged(int index);

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_TextInput_textChanged(const QString &arg1);

private:
    Ui::MainWindow* ui;
    KeyboardVisualizer* _keyboard;

    QString _currentText
        = "Summer is the time when the sun shines brightly and the sky is almost always blue ";
    QTimer* _timer;
    int time_sec = 0;
    int time_Msec = 0;
    int time_min = 0;

    int _charCntr = 0;
    float mistakes = 0;
    float correct = 0;
    int lang = 0;
    int words = 0;
    int isCorrect = 0;
    QVector <QString> KeyLayout;

    QTextCharFormat redF;
    QTextCharFormat greenF;
    QTextCharFormat blackF;
};
#endif // MAINWINDOW_H
