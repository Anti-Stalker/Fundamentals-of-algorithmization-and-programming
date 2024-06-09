#include "tableview.h"
#include "ui_tableview.h"

TableView::TableView(QWidget *parent) :
    QTextEdit(parent),
    HashTable<QString>(5)
{
    setReadOnly(true);

}

TableView::~TableView()
{

}

void TableView::showTable()
{
    QTextEdit::clear();
    for (int i = 0; i < _size; i++) {
        insertPlainText(QString::number(i) + "\t");
        Node *temp = _nodes[i];
        while (temp != nullptr) {
            //qDebug() << (QString::number(temp->_key) + ": " + temp->_value + " ");
            insertPlainText(QString::number(temp->_key) + ": " + temp->_value + ", ");
            temp = temp->_next;
        }
        append("\n");
    }
}
