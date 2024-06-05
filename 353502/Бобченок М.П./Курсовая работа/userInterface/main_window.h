//
// Created by u on 03.05.24.
//

#ifndef FULLBREAD_MAIN_WINDOW_H
#define FULLBREAD_MAIN_WINDOW_H

#include <QWidget>
#include "../developersMenu/Menu.h"
#include <QString>


QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget
{
Q_OBJECT

private slots:
    void generate();
    void showSettings();
    void fullScreen();

private:
    bool isFullScreen = false;
    bool generating = false;
    Network n;

public:
    explicit main_window(QWidget *parent = nullptr);

    ~main_window() override;

private:
    Ui::main_window *ui;
};


#endif //FULLBREAD_MAIN_WINDOW_H
