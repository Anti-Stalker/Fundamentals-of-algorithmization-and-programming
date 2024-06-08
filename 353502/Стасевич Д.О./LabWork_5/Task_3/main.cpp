#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "BitSet/MyBitset.h"

#include <bitset>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MyBitset bts2(5), bts3(5);
    /*std::cout << bts.to_string() << std::endl;
    std::cout << bts.size() << " " << bts.all() << " " << bts.any() << " " << bts.none() << std::endl;
    bts.set();
    std::cout << bts.to_string() << std::endl;
    std::cout << bts.size() << " " << bts.all() << " " << bts.any() << " " << bts.none() << std::endl;
    bts.reset(10);
    bts.reset(20);
    bts.reset(40);
    std::cout << bts.to_string() << std::endl;
    std::cout << bts.size() << " " << bts.all() << " " << bts.any() << " " << bts.none() << std::endl;
    std::cout << bts.test(10) << " " << bts.test(11) << std::endl;

    std::bitset<5> bts2;
    std::bitset<5> bts3;*/

    bts2.flip();
    bts2.set(2);
    bts2.set(0);
    bts3.set(0);
    bts3.set(1);

    std::cout << bts2.to_string() << " " << bts3.to_string() << std::endl;
    std::cout << (bts2 ^ bts3).to_string() << std::endl;
    exit(0);
}
