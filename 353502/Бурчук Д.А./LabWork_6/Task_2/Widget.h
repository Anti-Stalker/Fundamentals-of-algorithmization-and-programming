#ifndef UNTITLED_WIDGET_H
#define UNTITLED_WIDGET_H
#define SPLITTER "!"

#include <QWidget>
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QValidator>
#include <fstream>
#include <QKeyEvent>

#include "Motorbike.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
Q_OBJECT

    int mode;

public:
    explicit Widget(QWidget *parent = nullptr);

    ~Widget() override;

    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::Widget *ui;

    bool eventFilter(QObject* object, QEvent* event) override;

private slots:

    void execution(int mode);

    void firstTask();

    void firstTaskPrint();

    void secondTask();

    void secondTaskPrint();

    void thirdTask();

    void thirdTaskPrint();

    void fourthTask();

    void fourthTaskPrint();

    void fifthTask();

    void fifthTaskPrint();
};


#endif //UNTITLED_WIDGET_H
