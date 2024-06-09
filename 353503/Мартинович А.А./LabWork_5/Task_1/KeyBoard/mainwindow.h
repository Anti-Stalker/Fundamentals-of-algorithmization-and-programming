#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QKeyEvent"
#include "QGridLayout"
#include "keyboardwidget.h"
#include "dynamictext.h"
#include "QElapsedTimer"
#include "QTimer"
#include "QPushButton"
#include <QFileDialog>
#include "QComboBox"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
private:
    void keyPressEvent(QKeyEvent *event) override;
    void updateInfo();
    void restart();
    void openText();

    QGridLayout *layout;
    KeyboardWidget *keyboard_widget;
    DynamicText *dynamic_text;
    QWidget *central_widget;
    QLabel *words_info;
    QElapsedTimer *timer;
    QTimer *qtimer;
    QPushButton *restart_button;
    QPushButton *open_file_button;
    QComboBox* combo_box;

    QString current_template = R"(1234567890)";
    double time;
    bool timer_work = false;

};
#endif // MAINWINDOW_H
