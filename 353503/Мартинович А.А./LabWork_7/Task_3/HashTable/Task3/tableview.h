#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QWidget>
#include "hashtable.h"
#include "QTextEdit"

class TableView : public QTextEdit, public HashTable<QString>
{
    Q_OBJECT

public:
    explicit TableView(QWidget *parent = nullptr);
    ~TableView();

    void showTable();


};

#endif // TABLEVIEW_H
