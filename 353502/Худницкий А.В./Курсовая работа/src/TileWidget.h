  #ifndef TILEWIDGET_H
#define TILEWIDGET_H

#include <QWidget>
#include "levelgenerator.h"

class TileWidget : public QWidget {
    Q_OBJECT
public:
    explicit TileWidget(QWidget *parent = nullptr);

    void setType(TileType type);

    TileType m_type;
protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // TILEWIDGET_H
