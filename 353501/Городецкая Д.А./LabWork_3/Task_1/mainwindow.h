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
    void convertToBinary();
    QString decimalToBinary(long double number, int precision);
private:
    Ui::MainWindow *ui;
    QPushButton *button;
    QLineEdit *inputLineEdit;
    QLabel *resultLabel;
};
#endif // MAINWINDOW_H
