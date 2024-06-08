#include <QApplication>

#include "Widget.h"
#include <iostream>
#include "my_stl/Vector.h"
#include "my_stl/Pair.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    /*Widget widget;
    widget.show();
    return QApplication::exec();*/

    /*my::Vector<int> vector1(new int[]{2, 3, 4, 5}, 4);
    my::Vector<int> vector2(new int[]{}, 0);
    vector1.print();
    std::cout << vector2.max_size() << ' ' << vector1.at(3) << std::endl;
    int &ad = vector1.at(3);
    ad = 3;
    vector1.emplace_back(88);
    //vector1[4] = 8;
    std::cout << vector1.capacity() << " vector[4] = " << vector1[4];
    //vector1.assign(new int[]{2, 3, 4, 5},1);
    //vector1[4] = 8;
    std::cout << vector1.capacity() << " vector[4] = " << vector1[2];
    //vector1.pop_back();

    my::Pair<int, double> i(2, 5.2);
    my::Pair<int, int> j(2, 3);
    std::cout << std::endl << "equal : " << (i == j) << std::endl;

    //pair< vector<int>, vector<pair<int,double>>>

    my::Vector< my::Pair<int, double>> kaka;
    kaka.emplace_back(i);

    my::Pair<my::Vector<int>, my::Vector<my::Pair<int, double>>> Vadimka(vector1,kaka);

    std::cout << Vadimka.second[0].second;*/
    my::Vector<int> biba;
    biba.push_back(1);
    biba.insert(0, 3);
    std::cout << biba[0];
    return 0;
}
