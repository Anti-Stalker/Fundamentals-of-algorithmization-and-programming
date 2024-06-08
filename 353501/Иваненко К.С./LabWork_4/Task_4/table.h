#ifndef TABLE_H
#define TABLE_H

#include <QMainWindow>
#include <QString>

#include "ui_mainwindow.h"
#include "vector.h"

class table
{
    Ui::MainWindow *mui;
    vector<int> myVector;

public:
    table() {}
    void getvector(const vector<int> tmp)
    {
        myVector = tmp;
        myVector[0] = -1;
    }
    void getui(Ui::MainWindow *u)
    {
        mui = u;
    }
    void updatetable()
    {
        qDebug() << myVector.size() << " " << myVector.capacity();
        mui->vectortable->setColumnCount(myVector.size());
        mui->vectortable->setRowCount(2);
        for (int i = 0; i < myVector.size(); ++i)
        {
            QTableWidgetItem *itm = new QTableWidgetItem(QString::number(myVector[i]));
            QTableWidgetItem *itm2 = new QTableWidgetItem(QString::number(i));
            mui->vectortable->setItem(0, i, itm2);
            mui->vectortable->setItem(1, i, itm);
        }
    }
    void pushback(int tmp)
    {
        myVector.push_back(tmp);
        updatetable();
    }
    void res(int r)
    {
        myVector.resize(r);
        updatetable();
    }
    void showat(int tmp)
    {
        int number = (myVector[tmp]);
        if (!(tmp > myVector.size()) || !(myVector.capacity() == 1))
            mui->showtext->setText(QString::number(number));
        else
            mui->showtext->setText("Error");
    }
    void endshow()
    {
        mui->showtext->setText(QString::number(myVector[myVector.size() - 1]));
    }
    void beginshow()
    {
        mui->showtext->setText(QString::number(myVector[0]));
    }
    void showcap()
    {
        mui->showtext->setText(QString::number(myVector.capacity()));
    }
    void clearpressed()
    {
        myVector.clear();
        updatetable();
    }
    void isempty()
    {
        QString s = "";
        if (myVector.empty())
        {
            s = "Is empty";
        }
        else
        {
            s = "Isn't empty";
        }
        mui->showtext->setText(s);
    }
    void erasepressed(int tmp)
    {
        myVector.erase(tmp);
        updatetable();
    }
    void pbpressed()
    {
        myVector.pop_back();
        updatetable();
    }
    void sizepressed()
    {
        mui->showtext->setText(QString::number(myVector.size()));
    }
    void insertpressed(int pos, int tmp)
    {
        myVector.insert(pos, tmp);
        updatetable();
    }

private slots:

    void on_backbutton_clicked();
    void on_beginbutton_clicked();
    void on_capacitybutton_clicked();
};

#endif // TABLE_H