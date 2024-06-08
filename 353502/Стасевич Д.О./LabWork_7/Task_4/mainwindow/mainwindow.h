//
// Created by darina on 5/28/24.
//

#ifndef TASK4_MAINWINDOW_H
#define TASK4_MAINWINDOW_H

#include <QWidget>
#include <time.h>

#include "../HashTable/HashTable.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

private:
    Ui::mainwindow *ui;
    HashTable* h16 = new HashTable(16);
    HashTable* h64 = new HashTable(64);
    HashTable* h128 = new HashTable(128);
    HashTable* h2048 = new HashTable(2048);

    void DisplayCollisions();

private slots:
    void add_clicked();
    void remove_clicked();
    void find_clicked();
};


#endif //TASK4_MAINWINDOW_H
