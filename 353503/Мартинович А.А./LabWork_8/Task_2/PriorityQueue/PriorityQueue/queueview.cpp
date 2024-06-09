#include "queueview.h"

QueueView::QueueView(QWidget *parent) : QTextEdit(parent), PriorityQueue<int>()
{
    setReadOnly(true);
}



void QueueView::updateView()
{
    QTextEdit::clear();
    printQueue(0, 0);

}

void QueueView::printQueue(size_t i, int level = 0)
{
    if (i >= sizevar) {
        return;
    }
    printQueue(i*2+1, level+1);
    append(QString("\t").repeated(level) +  QString::number(PriorityQueue::data[i]));
    printQueue(i*2+2, level+1);
}
