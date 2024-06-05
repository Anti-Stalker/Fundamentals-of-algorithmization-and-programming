#ifndef BOR_H
#define BOR_H
#pragma once

#include <QMainWindow>
#include <QString>

struct vertex
{
    int next[33];
    bool leaf;
};

class bor
{
public:
    vertex T[1000001];
    int sz;
    bor();
    void addWord(QString);
    bool findWord(QString);
};

#endif // BOR_H
