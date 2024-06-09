#include "mapview.h"

MapView::MapView(QWidget *parent):
    QTextEdit(parent),
    UnorderedMap<QString>(100)
{
    setReadOnly(true);
}

void MapView::showMap()
{
    QTextEdit::clear();
    for (int i = 0; i < _size; i++) {
        insertPlainText(QString::number(i) + "\t");

        if (_keys[i].taken) {
            QString text = _values[i];
            size_t index = _keys[i].key;

            insertPlainText(QString::number(index) + ": " + text);
        }

        append("\n");
    }
}
