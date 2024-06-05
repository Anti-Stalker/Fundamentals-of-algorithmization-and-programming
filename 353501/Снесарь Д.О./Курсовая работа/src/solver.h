#ifndef SOLVER_H
#define SOLVER_H

#include <stack>
#include <QDebug>
#include <QVector>
struct Node
{
    Node* top;
    Node* bottom;
    Node* left;
    Node* right;
    Node* colHeader;
    int row;
    int column;
    int value;
    bool header;
    Node()
    {
        top=bottom=left=right=colHeader=nullptr;
        row=column=value=-1;
        header=false;
    }
    Node(int r,int c,int v)
    {
        top=bottom=left=right=colHeader=nullptr;
        row=r;
        column=c;
        value=v;
        header=false;
    }
};

class Solver
{
public:
    Solver();
    ~Solver();
    bool initialize();
    bool AddColumn(Node* newNode);
    void print();
    std::stack<Node>* solve(const QVector<QVector<int>>& field);
private:

    QVector<QVector<int>>* inField;
    QVector<QVector<int>>* outField;

    const int ROW_OFFSET = 0;
    const int COL_OFFSET = 81;
    const int CELL_OFFSET = 162;
    const int BOX_OFFSET = 243;
    const int MATRIX_SIZE = 9;
    const int MAX_COLS = 324;
    const int MAX_ROWS = 729;

    const int COL_BOX_DIVISOR = 3;
    const int ROW_BOX_DIVISOR = 3;




    Node* Root;
    std::stack<Node>* workingSolution;
    bool Solved;
    int totalCompetition;

    bool AddColumnHelp(Node* newNode, Node* r);
    bool isEmpty();
    void deleteMatrix();
    void cover(Node* r);
    void uncover(Node* r);
    Node* find(Node* find);
    bool solve();
    Node* chooseNextColumn(int& count);
};

#endif // SOLVER_H
