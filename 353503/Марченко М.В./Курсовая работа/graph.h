#ifndef GRAPH_H
#define GRAPH_H
#include "vertex.h"
#include "edge.h"
#include <QLabel>
class Graph
{

public:
    Graph();
    QVector<Vertex*> m_vertices;
    QVector<Edge*> m_edges;

    QVector<int> BFS(int start_vertex);
    QVector<int> DFS(int start_vertex);
    QVector<QVector<int>>Dijkstra(int start_vertex);
    QVector<QPair<int, int>> primMST();
    QVector<QVector<int>> tarjanSCC();
    Edge* findEdge(int vertexNumber1, int vertexNumber2);
    qreal getEdgeWeight(int from, int to);
    int findVertexFrom(const QPair<int, qreal>& edge, const QVector<bool>& selected, const QVector<QVector<int>>& adjacencyList);
private:

    QVector<QVector<int>> createAdjacencyList();
    QVector<QVector<int>> createAdjacencyList1();
    QVector<QVector<int>> adjacencyList;
};

#endif // GRAPH_H
