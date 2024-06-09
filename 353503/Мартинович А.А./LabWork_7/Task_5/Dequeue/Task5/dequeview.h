#ifndef DEQUEVIEW_H
#define DEQUEVIEW_H

#include "dequeue.h"
#include "QTextEdit"

class DequeView : public QTextEdit, public Deque<int>
{
public:
    DequeView(QWidget *parent = nullptr);

    void showDeque();
};

#endif // DEQUEVIEW_H
