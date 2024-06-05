#ifndef GENOMSLISTWIDGET_H
#define GENOMSLISTWIDGET_H

#include <QListWidget>
#include "Consts.h"
#include "settings.h"

class GenomsListWidget : public QListWidget
{
public:
    GenomsListWidget(QObject *parent);
    void setGenoms(const QVector<QVector<int>> &genoms);
    void clearList();

private:
    QVector<QVector<int>> saved_genoms;

};

#endif // GENOMSLISTWIDGET_H
