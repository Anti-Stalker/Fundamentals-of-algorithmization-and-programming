#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "queue.h"
#include <QFile>

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

    void on_insertButton_clicked();

    void insertElementsBefore(int, QVector<QString>&);

    void on_pushButton_clicked();

    void makeListOfSelectedElems();

    void removeSelectedItemsFromQueue();

    void removeElementByIndex(Queue<QString>& deque, size_t index);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Queue<QString> queue;
    void displayQueue();
    QVector<QString> selectedElems;
};
#endif // MAINWINDOW_H
