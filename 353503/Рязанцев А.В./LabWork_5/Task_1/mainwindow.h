#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "alllanguages.h"
#include "qpushbutton.h"
#include "texttoenter.h"

#include <QMainWindow>
#include <QTimer>

enum Languages{
    Arabic,
    Belarusian,
    English,
    Franch,
    German,
    Hebrew
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void FillButtons();

    void Addtext();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_lineInput_textEdited(const QString &text);

    void on_Start_clicked();

    void UpdateInfo();
    void on_Stop_clicked();

private:
    Ui::MainWindow *ui;

    bool IsActive = false;

    QVector<QPushButton*> keysButton;

    QTimer* Timer;

    float SymbolsInMin;
    float PassedTime = 0;
    float PressedButtons = 0;
    float CorrectButtons = 0;
    float accuracy;

    TextToEnter textToEnter;
    AllLanguages allLanguages;
    QString TextToInput;
    QString Inputedtext;
    QString languageOnKeys;
};
#endif // MAINWINDOW_H
