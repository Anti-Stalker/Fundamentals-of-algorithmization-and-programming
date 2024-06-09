#include "dequeview.h"



DequeView::DequeView(QWidget *parent) : QTextEdit(parent), Deque<int>()
{

}

void DequeView::showDeque()
{
    QTextEdit::clear();
    for (auto i: *this) {
        append(QString::number(i));
    }
}
