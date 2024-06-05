#pragma once
#include "bor.h"

bor::bor()
{
    memset(T[0].next, 255, sizeof T[0].next);
    sz = 1;
}

void bor::addWord(QString s)
{
    int v = 0;
    QChar x(L'а');
    for (int i = 0; i < s.length(); ++i) {
        int c = s[i].unicode() - x.unicode();
        if (c == 33) {
            c = 32;
        }
        if (T[v].next[c] == -1) {
            memset(T[sz].next, -1, sizeof(T[sz].next));
            T[v].next[c] = sz++;
            T[T[v].next[c]].leaf = false;
        }
        v = T[v].next[c];
    }
    T[v].leaf = true;
}

bool bor::findWord(QString s)
{
    int v = 0;
    QChar x(L'а');
    for (int i = 0; i < s.length(); i++) {
        int c = s[i].unicode() - x.unicode();
        if (c == 33) {
            c = 32;
        }
        if (T[v].next[c] == -1) {
            return false;
        }
        v = T[v].next[c];
    }
    return T[v].leaf;
}
