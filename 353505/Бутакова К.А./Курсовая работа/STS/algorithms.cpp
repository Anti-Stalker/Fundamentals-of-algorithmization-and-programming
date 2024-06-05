#include "algorithms.h"
#include "mapcell.h"

#include <QVector>
#include <QPair>

QVector<QPair<int, int>> PathfindingAlgorithm::m_path = {};

void Node::setPos(int x, int y)
{
    pos_x = x;
    pos_y = y;
    F_cost = 10e6;
    parent = nullptr;
}

void Node::setG(int x)
{
    G_cost = x;
}

void Node::setH(int endX, int endY)
{
    H_cost = abs(pos_x - endX) + abs(pos_y - endY);
}

void Node::setParent(Node* p)
{
    parent = p;
}

bool Node::operator==(Node node)
{
    if(this->pos_x == node.pos_x && this->pos_y == node.pos_y)
    {
        return true;
    }
    return false;
}


void PathfindingAlgorithm::init(int N, bool** array)
{
    m_dN = N;
    m_NodeMap = new Node*[m_dN];
    for(int i = 0; i < m_dN; ++i)
    {
        m_NodeMap[i] = new Node[m_dN];
    }

    for(int i = 0; i < m_dN; ++i)
    {
        for(int j = 0; j < m_dN; ++j)
        {
            m_NodeMap[i][j].setPos(i, j);
            m_NodeMap[i][j].setParent(nullptr);
            if(array[i][j])
            {
                m_NodeMap[i][j].setObstacle(true);
            }
            else
            {
                m_NodeMap[i][j].setObstacle(false);
            }
        }
    }
    m_path.resize(100);
    printf("init\n");
}

void PathfindingAlgorithm::setPoint(int startX, int StartY, int endX, int endY)
{
    m_startX = startX;
    m_startY = StartY;
    m_endX = endX;
    m_endY = endY;
    startNode = &m_NodeMap[m_startX][m_startY];
    endNode = &m_NodeMap[m_endX][m_endY];
    for(int i = 0; i < m_dN; ++i)
    {
        for(int j = 0; j < m_dN; ++j)
        {
            m_NodeMap[i][j].setH(endX, endY);
        }
    }
    printf("set point\n");
}

void PathfindingAlgorithm::FindPath()
{
    PathfindingAlgorithm::m_path.clear();
    QVector<Node*> open, closed;
    startNode->setG(0);
    startNode->setF(startNode->getG() + startNode->getH());
    open.push_back(startNode);
    while(1)
    {
        Node* currentNode = lowest(open);
        int currentIndex = open.indexOf(currentNode);

        closed.push_back(currentNode);
        currentIndex = closed.indexOf(currentNode);
        open.removeAt(open.indexOf(currentNode));
        currentNode = closed[currentIndex];

        if(currentNode->x() == m_endX && currentNode->y() == m_endY)
        {
            break;
        }

        QVector<Node*> nbNode;
        int i = currentNode->x(), j = currentNode->y();
        if(i+1<m_dN)    nbNode.push_back(&m_NodeMap[i+1][j]);
        if(i-1>=0)    nbNode.push_back(&m_NodeMap[i-1][j]);
        if(j+1<m_dN)    nbNode.push_back(&m_NodeMap[i][j+1]);
        if(j-1>=0)    nbNode.push_back(&m_NodeMap[i][j-1]);


        for(int i = 0; i < nbNode.size(); ++i)
        {
            Node* neighbour = nbNode[i];
            if(closed.indexOf(neighbour) == -1 && !neighbour->isObstacle())
            {
                int F_fromCurrent = currentNode->getG()+1 + neighbour->getH();
                if( F_fromCurrent < neighbour->getF())
                {
                    neighbour->setG(currentNode->getG()+1);
                    neighbour->setF(F_fromCurrent);
                    neighbour->setParent(currentNode);
                }
                if(open.indexOf(neighbour) == -1)
                {
                    open.push_back(neighbour);
                }
            }
        }
    }

    if(endNode->getParent() != nullptr)
    {
        printf("path found.\n");
        PathReload(endNode);
        printf("reloaded\n");
    }
    else
    {
        printf("Error: path no found\n");
    }
}

void PathfindingAlgorithm::checkParent()
{
    for(int i = 0; i < m_dN; ++i)
    {
        for(int j = 0; j < m_dN; ++j)
        {
            Node* p = &m_NodeMap[i][j];
            if(p->getParent() == nullptr) printf(" (%d, %d) has no currents\n", p->x(), p->y());
            else printf(" (%d, %d) <- (%d, %d)\n", p->x(), p->y(), p->getParent()->x(), p->getParent()->y());
        }
    }
}

Node* PathfindingAlgorithm::lowest(QVector<Node*> &list)
{
    int min = 10e6;
    Node *node = nullptr, *nodeOther = nullptr;
    for(int i = 0; i < list.size(); ++i)
    {
        if(list[i]->getF() < min)
        {
            min = list[i]->getF();
            node = list[i];
        }
    }
    return node;

}

void PathfindingAlgorithm::PathReload(Node* endNode)
{
    PathfindingAlgorithm::m_path.clear();
    Node* current = endNode;
    PathfindingAlgorithm::m_path.push_front(QPair<int, int>(endNode->x(), endNode->y()));
    printf("push (%d, %d)\n", endNode->x(), endNode->y());
    while(current->getParent() != nullptr)
    {
        PathfindingAlgorithm::m_path.push_front(QPair<int, int>(current->x(), current->y()));
        current = current->getParent();
    }
    return;
}

void PathfindingAlgorithm::PrintPath()
{
    printf("work %d\n", PathfindingAlgorithm::m_path.size());
    for(int i = 0; i < PathfindingAlgorithm::m_path.size(); ++i)
    {
        printf("go to (%d, %d)\n", PathfindingAlgorithm::m_path[i].first, PathfindingAlgorithm::m_path[i].second);
    }
}
