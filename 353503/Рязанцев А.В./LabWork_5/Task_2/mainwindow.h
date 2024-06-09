#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "string.h"

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
    void on_lineEdit_2_editingFinished();

    void on_lineEdit_editingFinished();

    void on_pushButton_clicked();

    void on_MemMove_clicked();

    void on_pushButton_2_clicked();

    void on_StrCat_clicked();

    void on_MemCmp_clicked();

    void on_Strxfrm_clicked();

    void on_Strtok_clicked();

    void on_Strlrn_clicked();

private:
    Ui::MainWindow *ui;

    String str1;
    String str2;
};
#endif // MAINWINDOW_H
