#include "mainwindow.h"

#include <QApplication>
#include "QRandomGenerator"
#include "QTextStream"

int64_t Median(int64_t a, int64_t b, int64_t c) {
    if (a >= b && a <= c || a >= c && a <= b) {
        return a;
    }
    else if (b >= a && b <= c || b >= c && b <= a) {
        return b;
    }
    else {
        return c;
    }
}

QVector<int64_t> MedianVector(QVector<int64_t> &arr){
    int64_t new_size = arr.size() / 3;
    QVector<int64_t> new_arr;
    for (int i = 0; i < new_size*3; i+=3) {
        new_arr.push_back(Median(arr[i], arr[i+1], arr[i+2]));
    }
    if (arr.size() - new_size*3 == 2) {
        new_arr.push_back((arr[new_size*3] + arr[new_size*3+1])/2);
    }
    else if (arr.size() - new_size*3 == 1) {
        new_arr.push_back(arr[new_size*3]);
    }
    return new_arr;
}

int main(int argc, char *argv[])
{
    const int32_t MIN_SIZE = 1;
    const int32_t MAX_SIZE = 30;
    const int32_t MAX_VALUE = 1000;

    QTextStream out(stdout);

    QVector<int64_t> arr;
    int64_t size = MIN_SIZE + QRandomGenerator::global()->bounded(MAX_SIZE - MIN_SIZE);

    for (int i = 0; i < size; i++) {
        arr.push_back(QRandomGenerator::global()->bounded(MAX_VALUE));
    }

    for (auto a: arr){
        out << a << " ";
    }
    out << "\n";

    QVector<int64_t> median_arr = MedianVector(arr);
    for (auto a: median_arr){
        out << a << " ";
    }
    out << "\n";
}
