#include "graph.h"

#include <QQueue>

#include <QStack>
#include <QSet>
Graph::Graph()
{

}
QVector<QVector<int>> Graph::createAdjacencyList() {
    QVector<QVector<int>> adjList(m_vertices.size());

    for (Edge* edge : m_edges) {
        int from = edge->startVertex()->vertexNumber(); // Получаем номер начальной вершины
        int to = edge->endVertex()->vertexNumber();

        adjList[from].append(to); // Добавляем вершину, куда ведет ребро
//        qDebug() << "Добавлено ребро от" << from << "к" << to;

        // Если ребро неориентированное, добавляем обратное ребро
        if (!edge->directed) {
            adjList[to].append(from);
//            qDebug() << "Добавлено обратное ребро от" << to << "к" << from;
        }
    }

    // Выводим полный список смежности
    for (int i = 0; i < adjList.size(); ++i) {
//        qDebug() << "Вершина" << i << "смежна с вершинами:" << adjList[i];
    }

    return adjList;
}

QVector<QVector<int>> Graph::createAdjacencyList1()
{
//    qDebug() <<"сreateAdjacencyList1" ;
    QVector<QVector<int>> adjList(m_vertices.size());

    for (Edge* edge : m_edges) {
        int from = edge->startVertex()->vertexNumber();
        int to = edge->endVertex()->vertexNumber();

        adjList[from].append(to);
        adjList[to].append(from); // Добавляем обратное направление ребра
    }
    // Выводим полный список смежности
    for (int i = 0; i < adjList.size(); ++i) {
        qDebug() << "Вершина" << i << "смежна с вершинами:" << adjList[i];
    }
    return adjList;
}

qreal Graph::getEdgeWeight(int from, int to) {
    for (Edge* edge : m_edges) {
        int start_vertex = edge->startVertex()->vertexNumber();
        int end_vertex = edge->endVertex()->vertexNumber();

        if ((start_vertex == from && end_vertex == to) || (start_vertex == to && end_vertex == from)) {
            return edge->m_weight;
        }
    }

    // Возвращаем бесконечность, если ребро не найдено
    return std::numeric_limits<qreal>::infinity();
}

QVector<int> Graph:: BFS(int start_vertex) {

    adjacencyList = createAdjacencyList();
    QVector<bool> visited(m_vertices.size(), false); // Массив посещенных вершин
    QVector<int> result; // Результирующий вектор для сохранения порядка обхода

    QQueue<int> queue; // Очередь для обхода

    visited[start_vertex] = true; // Помечаем начальную вершину как посещенную
    queue.enqueue(start_vertex); // Добавляем начальную вершину в очередь

    while (!queue.isEmpty())
    {
        int current_vertex = queue.dequeue(); // Извлекаем вершину из очереди
        result.append(current_vertex); // Добавляем вершину в результирующий вектор

        // Получаем список смежных вершин для текущей вершины
        QVector<int> adjacent_vertices = adjacencyList[current_vertex];

        // Обходим смежные вершины
        for (int i = 0; i < adjacent_vertices.size(); ++i)
        {
            int adjacent_vertex = adjacent_vertices[i];

            if (!visited[adjacent_vertex])
            {
                visited[adjacent_vertex] = true; // Помечаем смежную вершину как посещенную
                queue.enqueue(adjacent_vertex); // Добавляем смежную вершину в очередь
            }
        }
    }

    return result;
}

QVector<int> Graph:: DFS(int start_vertex)
{
    adjacencyList = createAdjacencyList();
    QVector<bool> visited(m_vertices.size(), false); // Массив посещенных вершин
    QVector<int> result; // Результирующий вектор для сохранения порядка обхода

    QStack<int> stack; // Стек для обхода

    visited[start_vertex] = true; // Помечаем начальную вершину как посещенную
    stack.push(start_vertex); // Добавляем начальную вершину в стек

    while (!stack.isEmpty())
    {
        int current_vertex = stack.pop(); // Извлекаем вершину из стека
        result.append(current_vertex); // Добавляем вершину в результирующий вектор

        // Получаем список смежных вершин для текущей вершины
        QVector<int> adjacent_vertices = adjacencyList[current_vertex];

        // Обходим смежные вершины
        for (int i = 0; i < adjacent_vertices.size(); ++i)
        {
            int adjacent_vertex = adjacent_vertices[i];

            if (!visited[adjacent_vertex])
            {
                visited[adjacent_vertex] = true; // Помечаем смежную вершину как посещенную
                stack.push(adjacent_vertex); // Добавляем смежную вершину в стек
            }
        }
    }

    return result;
}

QVector<QVector<int>> Graph::Dijkstra(int start_vertex)
{
    QVector<QVector<int>> adjacencyList = createAdjacencyList();
    int num_vertices = m_vertices.size();
    QVector<QVector<int>> paths(num_vertices);
    QVector<qreal> distance(num_vertices, std::numeric_limits<qreal>::infinity());
    QVector<bool> visited(num_vertices, false);

    distance[start_vertex] = 0;

    for (int i = 0; i < num_vertices; ++i) {
        int u = -1;
        qreal min_distance = std::numeric_limits<qreal>::infinity();

        for (int j = 0; j < num_vertices; ++j) {
            if (!visited[j] && distance[j] < min_distance) {
                min_distance = distance[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        for (int adjacent_vertex : adjacencyList[u]) {
            int v = adjacent_vertex;
            qreal weight = getEdgeWeight(u, v); // Получаем вес ребра между вершинами u и v
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                paths[v] = paths[u];
                if (!paths[v].contains(v)) { // Проверяем, содержится ли вершина в пути
                    paths[v].append(v);
                }
            } else if (distance[u] + weight == distance[v] && !paths[v].contains(v)) {
                QVector<int> new_path = paths[u];
                new_path.append(v);
                if (!paths.contains(new_path)) { // Проверяем, существует ли уже такой путь
                    paths.append(new_path);
                }
            }
        }
    }

//    qDebug() << "paths =" << paths;
    return paths;
}

QVector<QPair<int, int>> Graph::primMST() {
    QVector<QVector<int>> adjacencyList = createAdjacencyList1();
    const int V = adjacencyList.size();
    QVector<bool> selected(V, false);
    QVector<QPair<int, int>> mst;
    QVector<QPair<int, qreal>> edges;

    // Инициализация с ребра с минимальным весом
    qreal minWeight = std::numeric_limits<qreal>::max();
    int startVertex = 0;
    for (int i = 0; i < V; ++i) {
        for (int j : adjacencyList[i]) {
            qreal weight = getEdgeWeight(i, j);
            if (weight < minWeight && i != j) { // Исключаем петли
                minWeight = weight;
                startVertex = i;
            }
        }
    }

    selected[startVertex] = true;
    // Добавляем все рёбра, исходящие из начальной вершины
    for (int to : adjacencyList[startVertex]) {
        qreal weight = getEdgeWeight(startVertex, to);
        if (!selected[to] && startVertex != to) { // Исключаем петли
            edges.append(qMakePair(to, weight));
        }
    }

    while (mst.size() < V - 1) {
        // Найти ребро с минимальным весом, ведущее к невыбранной вершине
        minWeight = std::numeric_limits<qreal>::max();
        int from = -1;
        int to = -1;
        for (int i = 0; i < edges.size(); ++i) {
            int v = edges[i].first;
            qreal weight = edges[i].second;
            if (!selected[v] && weight < minWeight) {
                minWeight = weight;
                from = findVertexFrom(edges[i], selected, adjacencyList);
                to = v;
            }
        }

        if (to == -1) {
            qDebug() << "Не удалось найти подходящее ребро";
            break;
        }

        // Добавляем выбранное ребро в остовное дерево
        mst.append(qMakePair(from, to));
        selected[to] = true;

        // Обновляем список рёбер
        edges.clear();
        for (int i = 0; i < V; ++i) {
            if (selected[i]) {
                for (int j : adjacencyList[i]) {
                    if (!selected[j] && i != j) { // Исключаем петли
                        qreal weight = getEdgeWeight(i, j);
                        if (weight < std::numeric_limits<qreal>::max()) { // Исключаем несуществующие рёбра
                            edges.append(qMakePair(j, weight));
                        }
                    }
                }
            }
        }
    }
    return mst;
}

int Graph::findVertexFrom(const QPair<int, qreal>& edge, const QVector<bool>& selected, const QVector<QVector<int>>& adjacencyList) {
    for (int i = 0; i < selected.size(); ++i) {
        if (selected[i]) {
            for (int j : adjacencyList[i]) {
                if (j == edge.first && getEdgeWeight(i, j) == edge.second) {
                    return i;
                }
            }
        }
    }
    return -1; // Если ребро не найдено
}

QVector<QVector<int>> Graph::tarjanSCC() {
    adjacencyList = createAdjacencyList();
    QVector<int> visited(m_vertices.size(), -1); // Массив для хранения времени посещения вершин
    QVector<int> lowLink(m_vertices.size(), 0); // Массив для хранения значений lowLink
    QVector<bool> onStack(m_vertices.size(), false); // Массив для отслеживания вершин на стеке
    QStack<int> stack; // Стек для обхода
    QVector<QVector<int>> sccList; // Результирующий список компонент сильной связности

    int index = 0; // Счетчик для индексов вершин

    // Вспомогательная функция для обхода в глубину и поиска компонент сильной связности
    std::function<void(int)> dfs;

    dfs = [&](int vertex) {
        visited[vertex] = index;
        lowLink[vertex] = index;
        index++;
        stack.push(vertex);
        onStack[vertex] = true;

        // Перебор всех смежных вершин
        for (int adjacent_vertex : adjacencyList[vertex]) {
            if (visited[adjacent_vertex] == -1) {
                dfs(adjacent_vertex);
                lowLink[vertex] = qMin(lowLink[vertex], lowLink[adjacent_vertex]);
            } else if (onStack[adjacent_vertex]) {
                lowLink[vertex] = qMin(lowLink[vertex], visited[adjacent_vertex]);
            }
        }

        // Если vertex - корень компоненты сильной связности
        if (lowLink[vertex] == visited[vertex]) {
            QVector<int> scc;
            int v;
            do {
                v = stack.pop();
                onStack[v] = false;
                scc.append(v);
            } while (v != vertex);

            sccList.append(scc);
        }
    };

    // Запуск DFS для каждой непосещенной вершины
    for (int v = 0; v < m_vertices.size(); ++v) {
        if (visited[v] == -1) {
            dfs(v);
        }
    }

    return sccList;
}

