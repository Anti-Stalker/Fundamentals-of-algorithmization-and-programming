#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include "vertex.h"
#include "graph.h"
#include "myscene.h"
#include "edge.h"
#include <QGuiApplication>

void MyScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
//    qDebug() << "Custom scene clicked.";
    QGraphicsScene::mousePressEvent(event);
    if (!event->isAccepted()) {
        if (event->button() == Qt::LeftButton) {

            QPointF point = event->scenePos();

            Vertex *item = new Vertex();
            connect(item, &Vertex::rightClicked, this, &MyScene::createEdge);

            item->setRect(point.x()-25, point.y()-25, 60, 60);
            item->setVertexNumber(m_vertexCounter++);
            addItem(item);
            graph->m_vertices.push_back(item);
//            qDebug() << "Размер вектора: " << graph->m_vertices.size();
        }
    }
}


void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);

    if (lastEdge ) {
        QPen pen = lastEdge->pen();
        pen.setWidthF(2.5);
        lastEdge->setPen(pen);
        lastEdge = nullptr;
    }
    QList<QGraphicsItem*> itemsList = items(event->scenePos());

    for (QGraphicsItem* item : itemsList) {
        Edge* edge = qgraphicsitem_cast<Edge*>(item);
        if (edge) {

            QPen pen = edge->pen();
            pen.setWidthF(5);
            edge->setPen(pen);
            lastEdge = edge;
            break;
        }
    }
}

void MyScene::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Delete && event->modifiers() == Qt::ShiftModifier) {
        while (!selectedItems().isEmpty()) {
            QGraphicsItem* item = selectedItems().front();
            if (Vertex* vertex = dynamic_cast<Vertex*>(item)) {
                int deletedVertexNumber = vertex->vertexNumber();
                 m_vertexCounter--;
                for (int i = 0; i < graph->m_edges.size(); ) {
                    Edge* edge = graph->m_edges[i];
                    if (edge->startVertex() == vertex || edge->endVertex() == vertex) {
                        removeItem(edge);
                        graph->m_edges.remove(i);
                        delete edge;
                    }
                    else {
                        ++i;
                    }
                }
                removeItem(item);
                graph->m_vertices.removeAll(dynamic_cast<Vertex*>(item));
                if (vertex == tempVertex) {
                    tempVertex = nullptr;
                }
                delete item;
                item = nullptr;

                QVector<Vertex*> sortedVertices = graph->m_vertices;
                std::sort(sortedVertices.begin(), sortedVertices.end(), [](Vertex* a, Vertex* b) {
                    return a->vertexNumber() < b->vertexNumber();
                });

                for (Vertex* v : sortedVertices) {
                    if (v->vertexNumber() > deletedVertexNumber) {
                        v->setVertexNumber(v->vertexNumber() - 1);
                    }
                }

            } else if (Edge* edge = dynamic_cast<Edge*>(item)) {
                graph->m_edges.removeAll(edge);
                delete edge;
                item = nullptr;

                if (edge == lastEdge) {
                    lastEdge = nullptr;
                }
            }
       }
    } else {
        QGraphicsScene::keyPressEvent(event);
    }
}



void MyScene::createEdge(Vertex* vertex)
{
    if (tempVertex == nullptr) {
        tempVertex = vertex;
        QColor color(143, 226, 176);
        tempVertex->setBrush(QBrush(color));
    }
    else {
        if (tempVertex == nullptr) {
            return;
        }

        bool edgeExists = false;
        for (Edge* existingEdge : graph->m_edges) {
            if ((existingEdge->startVertex() == tempVertex && existingEdge->endVertex() == vertex) ||
                (existingEdge->startVertex() == vertex && existingEdge->endVertex() == tempVertex)) {
                edgeExists = true;
                break;
            }
        }

        if (!edgeExists) {

            bool isShiftPressed = QGuiApplication::keyboardModifiers() & Qt::ShiftModifier;
            Edge* edge = new Edge(tempVertex, vertex, isShiftPressed);
            connect(tempVertex, &Vertex::vertexMoved, edge, &Edge::updatePosition);
            connect(vertex, &Vertex::vertexMoved, edge, &Edge::updatePosition);
            connect(tempVertex, &Vertex::vertexResized, edge, &Edge::updateSize);
            connect(vertex, &Vertex::vertexResized, edge, &Edge::updateSize);
            graph->m_edges.push_back(edge);
            edge->setWeight(0);
            addItem(edge);
        }

        tempVertex->setBrush(QBrush(Qt::white));
        tempVertex = nullptr;
    }
}

void MyScene::highlightMSTEdges(const QVector<QPair<int, int>>& mstEdges) {
    // Сначала сбросим цвет всех рёбер к стандартному
    for (Edge* edge : graph->m_edges) {
        QPen pen = edge->pen();
        pen.setColor(Qt::black); // Стандартный цвет рёбер
        edge->setPen(pen);
    }

    // Теперь установим цвет для рёбер остовного дерева
    for (const QPair<int, int>& edgePair : mstEdges) {
        Vertex* startVertex = graph->m_vertices[edgePair.first];
        Vertex* endVertex = graph->m_vertices[edgePair.second];

        for (Edge* edge : graph->m_edges) {
            if ((edge->startVertex() == startVertex && edge->endVertex() == endVertex) ||
                (edge->startVertex() == endVertex && edge->endVertex() == startVertex)) {
                QPen pen = edge->pen();
                pen.setColor(Qt::green); // Цвет рёбер остовного дерева
                edge->setPen(pen);
                break;
            }
        }
    }
}

void MyScene::resetEdgeColors() {
    for (Edge* edge : graph->m_edges) {
        QPen pen = edge->pen();
        pen.setColor(Qt::black); // Вернуть к стандартному цвету
        edge->setPen(pen);
    }
}



