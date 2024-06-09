#ifndef QUEUEVIEW_H
#define QUEUEVIEW_H

#include <QTextEdit>
#include "prirityqueue.h"

class QueueView : public QTextEdit, public PriorityQueue<int>
{
public:
    QueueView(QWidget *parent);

    void updateView();

private:
    void printQueue(size_t i, int level);
};

#endif // QUEUEVIEW_H
