#ifndef TILE_H
#define TILE_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QBrush>
#include <QMouseEvent>

class Tile :public QObject, public QGraphicsRectItem
{
  Q_OBJECT
public:
    Tile(int row, int col, double size);
  //  Tile();

    void setPos(int row, int col, double size);
    void setNumber(int n);
    void setTileSize(double size);
    int getRow();
    int getCol();
    void hilight();
    void hilightInsertion();
    void removeHilight();
    void selected(bool is);
    void setIncorrect();
    int getNumber();
    bool isCorrect();
    void setIsChangeable(bool value);
    bool getIsChaneable();
private:
    int row_;
    int col_;
    double size_;
    QColor curColor;
    QColor mainColor = QColor("#F4F8FD");
    QColor secondaryColor = QColor("#EBEEED");
    QColor insertionColor = QColor("#B3B6BA");
    QColor incorrectColor = QColor("#F48889");
    QString number = "";
    bool isSelected_;
    bool isChangeable = true;

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
signals:
    void tileClicked(Tile* tile);

};




#endif // TILE_H
