#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

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

private slots:
    void answer();
    int ackermann(int m, int n);

private:
    Ui::MainWindow *ui;
    QPushButton *pushButton;
    QLineEdit *input1LineEdit;
    QLineEdit *input2LineEdit;
    QLabel *resultLabel;

};
#endif // MAINWINDOW_H
