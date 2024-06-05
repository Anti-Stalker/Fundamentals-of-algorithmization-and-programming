#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "vertex.h"
#include "edge.h"
#include "myscene.h"
#include <QTextEdit>
#include <graph.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLabel* label1;
    int selectedVertexNumber;

    void Disconnect();

public slots:
    void onButton1Clicked();
    void onButton2Clicked();
    void onButton3Clicked();
    void onButton4Clicked();
    void onButton5Clicked();
    void onButton6Clicked();
    void onVertexSelected1(int vertexNumber);
    void onVertexSelected2(int vertexNumber);
    void onVertexSelected3(int selectedVertexNumber);
    void onVertexSelected3_1(int selectedVertexNumber);
    void resetEdgeColors();
private:
    int start_vertex;
    int end_vertex;
    QLabel *textLabel;
    Graph* graph;
    Ui::MainWindow *ui;
    Vertex *vertex;
    MyScene *scene;
    QGraphicsView *view;
    //Edge *edge;
};
#endif // MAINWINDOW_H
