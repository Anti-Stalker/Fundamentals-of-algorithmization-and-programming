#include "Widget.h"
#include "ui_Widget.h"

#include "SpasgialTable.h"


Widget::Widget(QWidget *parent) :
        QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    SpecialHashTable hashTable;

    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < 30; ++i) {
        int key = rand() % 21 - 10; // ключи от -10 до 10
        int value = rand() % 100;   // произвольные значения
        hashTable.insert(key, value);
    }

    std::cout << "Initial hash table:" << std::endl;
    hashTable.print();

    // Удаляем записи с отрицательными ключами
    hashTable.removeNegativeKeys();

    std::cout << "\nHash table after removing negative keys:" << std::endl;
    hashTable.print();
}

Widget::~Widget() {
    delete ui;
}
