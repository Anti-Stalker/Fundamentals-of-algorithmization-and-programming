#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Vector.h>
#include <Pair.h>
#include <QStandardItemModel>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_at_clicked();

    void on_pushButton_capacity_clicked();

    void on_pushButton_empty_clicked();

    void on_pushButton_maxSize_clicked();

    void on_pushButton_popBack_clicked();

    void on_pushButton_size_clicked();

    void on_pushButton_data_clicked();

    void on_pushButton_pushBack_clicked();

    void on_pushButton_resize_clicked();

    void on_pushButton_reserve_clicked();

    void on_pushButton_erase_clicked();

private:
    Ui::MainWindow *ui;

    Vector<int> vec{10, 20};

    void updateVec();
};
#endif // MAINWINDOW_H
