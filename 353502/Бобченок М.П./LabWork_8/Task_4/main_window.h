//
// Created by u on 31.05.24.
//

#ifndef TASK3_MAIN_WINDOW_H
#define TASK3_MAIN_WINDOW_H

#include <QWidget>
#include <QRandomGenerator>
#include "HashTable.h"


QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget {
Q_OBJECT

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    static int hash(int n)
    {
        long long mod = 1e9;
        int res = 0;
        int p = 31;
        long long cur = 1;

        while (n > 0)
        {
            res += (n % 10) * cur;
            res %= mod;

            cur *= p;
            cur %= mod;

            n /= 10;
        }

        return res;
    }


    void showTable();

    int size = 10;

    Ui::main_window *ui;

    HashTable<int, int, int (*) (int) > hashTable;

public:
    main_window(QWidget *parent = nullptr);
    ~main_window();

};


#endif //TASK3_MAIN_WINDOW_H
