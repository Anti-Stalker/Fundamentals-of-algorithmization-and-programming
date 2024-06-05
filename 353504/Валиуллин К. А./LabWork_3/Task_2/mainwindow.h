#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QMessageBox>

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
    void on_pushButton_clicked();
    int akkerman(int m, int n);

private:
    Ui::MainWindow *ui;
    long long m, n, answer;
    QString strM, strN, strAnswer;
    bool correctM, correctN;
};
#endif // MAINWINDOW_H
