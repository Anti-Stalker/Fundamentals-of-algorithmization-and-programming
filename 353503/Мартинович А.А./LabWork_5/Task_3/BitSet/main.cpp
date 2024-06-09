#include "mainwindow.h"

#include <QApplication>
#include "bitset.h"

int main(int argc, char *argv[])
{
    BitSet<64> a(5);

    qDebug() << (~a).to_string();
}
