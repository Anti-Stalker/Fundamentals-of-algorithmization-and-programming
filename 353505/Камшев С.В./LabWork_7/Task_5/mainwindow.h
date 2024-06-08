#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QRadioButton>

// #include "deque"
// #include "deque.cpp"
#include "intvalidator.h"
#include "doublevalidator.h"
#include "d2.h"

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

    QPushButton *PushFrontButton;
    QPushButton *PushBackButton;
    QPushButton *PopFrontButton;
    QPushButton *PopBackButton;
    QPushButton *ClearButton;
    QPushButton *SizeButton;
    QPushButton *EmptyButton;


    QLineEdit *listLineEdit;
    QLineEdit *ItemLineEdit;

    QRadioButton *intQRadioButton;
    QRadioButton *doubleRadioButton;
    QRadioButton *stringRadioButton;

    Deque <int> deque;

    void showInformatoin();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
