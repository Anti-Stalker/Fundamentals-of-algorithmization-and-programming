#include <QApplication>

#include "Widget.h"
#include "iostream"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    /*Widget widget;
    widget.show();
    return QApplication::exec();*/
    Deque d;
    d.push_back(3);
    d.push_back(35);
    d.push_back(36);
    d.push_back(6);
    d.push_front(9);
    d.pop_back();
    for (int i : d) {
        std::cout << i << ' ';
    }
    return 0;
}
