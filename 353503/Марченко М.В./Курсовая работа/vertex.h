#ifndef VERTEX_H
#define VERTEX_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QTextDocument>
#include <QGraphicsTextItem>
#include <QCoreApplication>



class Vertex: public QObject, public QGraphicsEllipseItem
{
     Q_OBJECT
public:

    explicit Vertex(QGraphicsItem *parent = 0);
    int m_vertexNumber ;
    void setVertexNumber(int number);
    void setVertexNumber1(int number);

int vertexNumber() const { return m_vertexNumber; }
protected:
    // Shift + левая кнопка: сделать выбор Alt: подготовиться к масштабированию
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    // Alt + перетаскивание: масштабирование и перемещение
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    // Делаем элемент доступным для использования qgraphicsitem_cast

    int type() const;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;

private slots:
    void updateNumber();
    void onEditingFinished();
public:
     void setButtonClicked(bool clicked) {isButtonClicked = clicked; }
     QPointF m_centerPointF;
signals:
 void vertexSelected(int vertexNumber);
    void vertexMoved();
    void vertexResized(qreal radius);
    void rightClicked(Vertex* vertex);
private:
bool isButtonClicked = false;
    bool m_bResizing;
     QGraphicsTextItem *textItem;
};

#endif // VERTEX_H
