#ifndef ITEM_H
#define ITEM_H

#include <QString>
#include <QPixmap>

struct Item {
    QString name;
    QPixmap image;
    int cost;
    QString desc;
};

#endif // ITEM_H
