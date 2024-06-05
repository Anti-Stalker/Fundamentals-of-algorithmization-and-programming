#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "workers.h"
#include <QString>
#include <QDate>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
QT_BEGIN_NAMESPACE
namespace Ui
{
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
    void on_openfile_btn_clicked();

    void on_sorter_clicked();

    void on_fiosearch_btn_clicked();

private:
    Ui::MainWindow *ui;
    QVector<Workers> worker;
};
#endif // MAINWINDOW_H
