#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "userinputdialog.h"
#include <cloth.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initUserInput(Cloth);
    Cloth& getUserInitRef();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_print_clicked();

private:
    Cloth strInit;
    Cloth codeInit;
    Cloth ptrInit;
    Cloth refInit;
    Cloth *ptr = &ptrInit;
    Cloth &ref = refInit;

    Ui::MainWindow *ui;
    UserInputDialog* input;

    void initWithStr();
    void initWithCode();
    void initWithPtr();
    void initWithRef();
};
#endif // MAINWINDOW_H
