//
// Created by u on 31.05.24.
//

#ifndef TASK4_MAIN_WINDOW_H
#define TASK4_MAIN_WINDOW_H

#include <QWidget>
#include <QRandomGenerator>
#include "HashTable.h"


QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget {
Q_OBJECT

private slots:
    void on_pushButton_2_clicked();

private:
    void testLinHashMap(LinearHashTable);
    void testQuadHashMap(QuadHashTable);
    void fillMaps();
    void buildGraphics();

    Ui::main_window *ui;

    LinearHashTable a1 = LinearHashTable(16), b1 = LinearHashTable(64), c1 = LinearHashTable(128), d1 = LinearHashTable(2048);
    QuadHashTable a2 = QuadHashTable(16), b2 = QuadHashTable(64), c2 = QuadHashTable(128), d2 = QuadHashTable(2048);

public:
    main_window(QWidget *parent = nullptr);
    ~main_window();

};


#endif //TASK4_MAIN_WINDOW_H
