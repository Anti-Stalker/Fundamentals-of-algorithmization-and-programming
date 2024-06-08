#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QListWidget>
#include "queue.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_ConvertToCircularButton_clicked();



    void on_EnqueueFrontButton_clicked();

    void on_EnqueueBackButton_clicked();

    void on_DequeueFrontButton_clicked();

    void on_DequeueBackButton_clicked();

private:
    Ui::MainWindow *ui;
    Queue queue;
};

#endif // MAINWINDOW_H
