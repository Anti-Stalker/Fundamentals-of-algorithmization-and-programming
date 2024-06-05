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
    void extracted();
    void on_pushButton_clicked();
    long long reverse_number(long long number, long long &answer);

private:
    Ui::MainWindow *ui;
    long long number, answer = 0;
    QString strNumber;
    bool correct;
};
#endif // MAINWINDOW_H
