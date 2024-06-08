//
// Created by u on 28.05.24.
//

#ifndef TASK1_MAIN_WINDOW_H
#define TASK1_MAIN_WINDOW_H

#include <QWidget>
#include <QTimer>
#include <QString>
#include <QKeyEvent>
#include <QKeySequenceEdit>
#include <QCoreApplication>
#include <QEvent>
#include <QLabel>
#include <QDebug>
#include <QFileDialog>
#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <string>


QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget {
Q_OBJECT

private:
    QString text;
    int cur = 0;
    clock_t cur_time = 0;
    clock_t range = 20;
    clock_t t = 0;
    bool working = false;
    void setText(const QString& lan);

private slots:
    void open();
    void updateWindow();

public:
    explicit main_window(QWidget *parent = nullptr);

    void keyPressEvent(QKeyEvent* event) override;

    ~main_window() override;

private:
    int comboIndex = -1;
    int cor = 0, wrong = 0;
    int sm = 0;
    std::set<std::pair<int, int> > st;
    std::vector<int> keys{81, 87, 69, 82, 84, 89, 85, 73, 79, 80, 91, 93, 65, 83, 68, 70, 71, 72, 74, 75, 76, 59, 39, 90, 88, 67, 86, 66, 78, 77, 44, 46, 32, 16777219};
    std::vector<QLabel *> labels;
    std::string file;
    QString allLan[8];
    QString en = "qwertyuiop[]asdfghjkl;'zxcvbnm,. ";
    QString ru = "йцукенгшщзхъфывапролджэячсмитьбю ";
    QString de = "qwertzuiopü+asdfghjklöäyxcvbnm,. ";
    QString fr = "azertyuiop^$qsdfghjklmùwxcvbn,;: ";
    QString ar = "ضصثقفغعهخحجدشسيبلاتنمكطئءؤرلاىةوز";
    QString by = "йцукенгшўзх'фывапролджэячсмітьбю ";
    QString he = "/'קראטוןםפ][שדגכעיחלךף,זסבהנמצתץ c";
    QString zh = "qwertyuiop[]asdfghjkl;'zxcvbnm,. ";

    Ui::main_window *ui;
};


#endif //TASK1_MAIN_WINDOW_H
