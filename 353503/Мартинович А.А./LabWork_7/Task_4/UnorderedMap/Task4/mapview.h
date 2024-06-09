#ifndef MAPVIEW_H
#define MAPVIEW_H
#include <QTextEdit>
#include "unorderedmap.h"

class MapView: public QTextEdit, public UnorderedMap<QString>
{
public:
    MapView(QWidget *parent = nullptr);

    void showMap();
};

#endif // MAPVIEW_H
