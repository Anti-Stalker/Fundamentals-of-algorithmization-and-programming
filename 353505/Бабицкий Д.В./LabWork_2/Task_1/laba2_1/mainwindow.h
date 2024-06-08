#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTableWidget>
#include<QLayout>
#include<QTableWidgetItem>
#include<QFile>
#include<QList>
#include<QTextStream>
#include <QFileDialog>
#include<QMessageBox>
#include"date.h"
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
    bool check (QString,int ,bool);
    bool ch(int);
    void cr(QString);
    ~MainWindow();




private slots:

    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

    void on_pushButton_clicked();







    void on_lineEdit_4_textEdited(const QString &arg1);



    void on_pushButton_5_clicked() ;

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

private:
    QTableWidget *tableWidget;
    Ui::MainWindow *ui;
    QList <QTableWidgetItem> item;
    QList <Date> *date =new QList <Date>;
    Date *d;
    int rest=0;
    int out=0;
    void openfile();
    int sch=1;
    bool fl=0;
    QString filep="/home/paul/laba_3/laba3_1/old.txt";
    bool fl1=0;
    bool fl2=0;
    bool fl3=0;
    int tempd=0;
    QString a;
    int year;
    bool fl4=0;
    QString files;
};
#endif // MAINWINDOW_H
