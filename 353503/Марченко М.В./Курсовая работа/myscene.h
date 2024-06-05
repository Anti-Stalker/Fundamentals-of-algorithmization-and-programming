#ifndef MYSCENE_H
#define MYSCENE_H

#include <QObject> //?
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include "edge.h"
#include "graph.h"

class MyScene: public QGraphicsScene
{

public:
   Graph* graph = new Graph();
    Edge* lastEdge = nullptr;
public slots:
    void createEdge(Vertex* vertex);
    void highlightMSTEdges(const QVector<QPair<int, int>>& mstEdges);
    void resetEdgeColors();
private:
    Vertex* selectedVertex1; // Выбранная первая вершина
    Vertex* selectedVertex2; // Выбранная вторая вершина
protected:
    // Левая кнопка: добавить элемент Правая кнопка: удалить элемент
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);
    // Клавиша Backspace для удаления элемента
    void keyPressEvent(QKeyEvent *event);
    //int m_vertexCounter;

private:

    int m_vertexCounter = 0;
    Vertex *tempVertex = nullptr;
};

#endif // MYSCENE_H
