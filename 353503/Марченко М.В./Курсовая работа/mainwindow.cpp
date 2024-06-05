#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBoxLayout>
#include <QDialog>
#include <QLabel>
#include <QDebug>
#include <QInputDialog>
#include <graph.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new MyScene();
    scene->setSceneRect(0, 0, 400, 300);

    view = new QGraphicsView(this);
    view->setScene(scene);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QPushButton *button1 = new QPushButton("Поиск в ширину");
    button1->setFixedSize(120, 30); // Установка фиксированного размера кнопки
    connect(button1, &QPushButton::clicked, this, &MainWindow::onButton1Clicked);

    QPushButton *button2 = new QPushButton("Поиск в глубину");
    button2->setFixedSize(120, 30); // Установка фиксированного размера кнопки
    connect(button2, &QPushButton::clicked, this, &MainWindow::onButton2Clicked);

    QPushButton *button3 = new QPushButton("Алгоритм Дейкстры");
    button3->setFixedSize(120, 30); // Установка фиксированного размера кнопки
    connect(button3, &QPushButton::clicked, this, &MainWindow::onButton3Clicked);

    QPushButton *button4 = new QPushButton("Алгоритм Прима");
    button4->setFixedSize(120, 30); // Установка фиксированного размера кнопки
    connect(button4, &QPushButton::clicked, this, &MainWindow::onButton4Clicked);

    QPushButton *button5 = new QPushButton("Алгоритм Тарьяна");
    button5->setFixedSize(120, 30); // Установка фиксированного размера кнопки
    connect(button5, &QPushButton::clicked, this, &MainWindow::onButton5Clicked);

    QPushButton *button6 = new QPushButton("Инструкция");
    button6->setFixedSize(120, 30); // Установка фиксированного размера кнопки
    connect(button6, &QPushButton::clicked, this, &MainWindow::onButton6Clicked);

    graph = scene->graph;

    textLabel = new QLabel();
    textLabel->setFixedSize(120, 100);
    textLabel->setWordWrap(true);

   // textLabel->setMaximumHeight(30);  // Устанавливаем максимальную высоту текстового поля

    QHBoxLayout *textLayout = new QHBoxLayout;
    textLayout->addWidget(textLabel);

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(button1);
    vLayout->addWidget(button2);
    vLayout->addWidget(button3);
    vLayout->addWidget(button4);
    vLayout->addWidget(button5);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(textLayout);
    mainLayout->addLayout(vLayout);
    mainLayout->addWidget(button6);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addLayout(mainLayout);
    hLayout->addWidget(view);

    QWidget *widget = new QWidget;
    widget->setLayout(hLayout);

    setCentralWidget(widget);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete view;
}
void MainWindow::onButton1Clicked()
{
    // Отключаем все предыдущие соединения
    Disconnect();

    // Подключаем сигналы заново
    for (Vertex* vertex : graph->m_vertices) {
        connect(vertex, &Vertex::vertexSelected, this, &MainWindow::onVertexSelected1);
        vertex->setButtonClicked(true);
    }

//    qDebug() << "Зашло в кнопку";
    textLabel->setText("Выберите вершину, с которой начать поиск в ширину");
}

void MainWindow::onVertexSelected1(int selectedVertexNumber)
{
//    qDebug() << "Зашло в выбор вершины ";
    textLabel->clear();
    QVector<int> result = graph->BFS(selectedVertexNumber);  // Вызываем BFS и получаем результат

    // Создаем диалоговое окно
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Результат BFS");

    // Создаем метку для отображения результата
    QLabel* resultLabel = new QLabel(dialog);
    QString resultText;
    for (int i : result) {
         resultText += "Посещена вершина " + QString::number(i) + "\n";
    }
    resultLabel->setText(resultText);

    // Создаем вертикальный макет и добавляем метку
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    layout->addWidget(resultLabel);

    dialog->setLayout(layout);
    dialog->exec();
    for (Vertex* vertex : graph->m_vertices) {
        vertex->setButtonClicked(false);
    }
}

void MainWindow::onButton2Clicked()
{
     Disconnect();

    // Подключаем сигналы заново
    for (Vertex* vertex : graph->m_vertices) {
        connect(vertex, &Vertex::vertexSelected, this, &MainWindow::onVertexSelected2);
        vertex->setButtonClicked(true);
    }
//    qDebug() << "Зашло в кнопук";
    textLabel->setText("Выберите вершину, с которой начать поиск в глубину");
}

void MainWindow::onVertexSelected2(int selectedVertexNumber)
{
//    qDebug() << "Зашло в выбор вершины ";
    textLabel->clear();
    QVector<int> result = graph->DFS(selectedVertexNumber);
    // Создаем диалоговое окно
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Результат DFS");

    // Создаем метку для отображения результата
    QLabel* resultLabel = new QLabel(dialog);
    QString resultText ;
    for (int i : result) {
        resultText += "Посещена вершина " + QString::number(i) + "\n";
    }
    resultLabel->setText(resultText);

    // Создаем вертикальный макет и добавляем метку
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    layout->addWidget(resultLabel);

    dialog->setLayout(layout);
    dialog->exec();
    for (Vertex* vertex : graph->m_vertices) {
        vertex->setButtonClicked(false);
    }
}
void MainWindow::onButton3Clicked()
{
    end_vertex = -1;
    start_vertex = -1;
     Disconnect();
    for (Vertex* vertex : graph->m_vertices) {
        connect(vertex, &Vertex::vertexSelected, this, &MainWindow::onVertexSelected3);
        vertex->setButtonClicked(true);
    }
    textLabel->setText("Выберите стартовую вершину для алгоритма Дейкстры");


}
void MainWindow::onVertexSelected3(int selectedVertexNumber)
{
    start_vertex = selectedVertexNumber;
    textLabel->clear();
    Disconnect();
    for (Vertex* vertex : graph->m_vertices) {
        connect(vertex, &Vertex::vertexSelected, this, &MainWindow::onVertexSelected3_1);
        vertex->setButtonClicked(true);
    }
    textLabel->setText("Выберите конечную вершину для алгоритма Дейкстры");
}

void MainWindow::onVertexSelected3_1(int selectedVertexNumber)
{
    textLabel->clear();
    end_vertex = selectedVertexNumber;
    QVector<QVector<int>> result = graph->Dijkstra(start_vertex);

    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Результат алгоритма Дейкстры");

    QLabel* resultLabel = new QLabel(dialog);
    resultLabel->setTextFormat(Qt::PlainText);

    QString resultText = "";

    // Display paths to all vertices
    for (int i = 0; i < graph->m_vertices.size(); ++i)
    {
        if (i == start_vertex)
            continue;

        const QVector<int>& path = result[i];

        if (path.isEmpty())
        {
            // If path is empty, indicate that there is no path to the vertex
            resultText += "Путь до вершины " + QString::number(graph->m_vertices[i]->vertexNumber()) + " не существует.\n";
        }
        else
        {
            // Form the path from vertices
            QString pathText = "";

            // Add the number of the start vertex to the beginning of the path
            pathText += QString::number(graph->m_vertices[start_vertex]->vertexNumber()) + " -> ";

            for (int j = 0; j < path.size(); ++j)
            {
                int vertexNumber = graph->m_vertices[path[j]]->vertexNumber();

                pathText += QString::number(vertexNumber);

                if (j < path.size() - 1)
                    pathText += " -> ";
            }

            resultText += "Путь до вершины " + QString::number(graph->m_vertices[i]->vertexNumber()) + ": " + pathText + "\n";
        }
    }

    resultText += "\n"; // Add a separator before the path to the end_vertex

    const QVector<int>& endPath = result[end_vertex];

    if (endPath.isEmpty())
    {
        // If path is empty, indicate that there is no path to the vertex
        resultText += "Путь до вершины " + QString::number(graph->m_vertices[end_vertex]->vertexNumber()) + " не существует.\n";
    }
    else
    {
        // Form the path from vertices
        QString pathText = "";

        // Add the number of the start vertex to the beginning of the path
        pathText += QString::number(graph->m_vertices[start_vertex]->vertexNumber()) + " -> ";

        for (int j = 0; j < endPath.size(); ++j)
        {
            int vertexNumber = graph->m_vertices[endPath[j]]->vertexNumber();

            pathText += QString::number(vertexNumber);

            if (j < endPath.size() - 1)
                pathText += " -> ";
        }

        resultText += "Результат " + QString::number(graph->m_vertices[end_vertex]->vertexNumber()) + ": " + pathText + "\n";
    }

    // Set the result text to the label
    resultLabel->setText(resultText);

    // Create a vertical layout and add the label
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    layout->addWidget(resultLabel);

    // Set the layout for the dialog window
    dialog->setLayout(layout);

    // Display the dialog window
    dialog->exec();

    // Clear the button state of vertices
    for (Vertex* vertex : graph->m_vertices) {
        vertex->setButtonClicked(false);
    }
}

void MainWindow::resetEdgeColors() {
    MyScene *scene = dynamic_cast<MyScene*>(view->scene());
    if (scene) {
        scene->resetEdgeColors();
    }
}

void MainWindow::onButton4Clicked() {
    Disconnect();
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Алгоритм Прима");

    QLabel *resultLabel = new QLabel();
    resultLabel->setTextFormat(Qt::PlainText);

    QVector<QPair<int, int>> mst = graph->primMST();

    QString resultText = "Результат:\n";
    for (const QPair<int, int>& edge : mst) {
        int from = edge.first;
        int to = edge.second;
        qreal weight = graph->getEdgeWeight(from, to);

        resultText += QString("%1 - %2 : %3\n").arg(from).arg(to).arg(weight);
    }

    resultLabel->setText(resultText);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(resultLabel);
    dialog->setLayout(layout);

    MyScene *scene = dynamic_cast<MyScene*>(view->scene());
    if (scene) {
        scene->highlightMSTEdges(mst);
    }

    // Связываем сигнал rejected() с слотом resetEdgeColors()
    connect(dialog, &QDialog::rejected, this, &MainWindow::resetEdgeColors);

    dialog->exec();
}

void MainWindow::onButton5Clicked()
{
     Disconnect();
    QVector<QVector<int>> sccList = graph->tarjanSCC();

    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Алгоритм Тарьяна");

    QVBoxLayout *layout = new QVBoxLayout(dialog);
    QLabel *titleLabel = new QLabel("Сильно связные компоненты:");
    layout->addWidget(titleLabel);

    for (const QVector<int> &scc : sccList) {
        QString sccText = "Компонента: ";
        for (int vertex : scc) {
            sccText += QString::number(vertex) + " ";
        }

        QLabel *sccLabel = new QLabel(sccText);
        layout->addWidget(sccLabel);
    }

    dialog->setLayout(layout);
    dialog->show();
}

void MainWindow::onButton6Clicked()
{
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Инструкция");

    QScrollArea *scrollArea = new QScrollArea(dialog);
    scrollArea->setWidgetResizable(true);

    QWidget *scrollWidget = new QWidget(scrollArea);
    QLabel *label = new QLabel(scrollWidget);

    label->setText("ДОБАВЛЕНИЕ ВЕРШИНЫ\n\n"
                   "Сделайте двойной клик левой кнопкой мыши в пустом месте поля.\n\n\n"
                   "РЕДАКТИРОВАНИЕ ВЕРШИНЫ\n\n"
                   "Для изменения размера вершины зажмите клавишу Alt и, кликнув на край вершины левой кнопкой мыши, масштабируйте ее.\n"
                   "Для перемещения вершины зажмите левую кнопку мыши над ней и перетащите вершину, перемещая мышь по сцене.\n\n\n"
                   "ДОБАВЛЕНИЕ РЕБРА\n\n"
                   "Правой кнопкой мыши выберите начальную вершину ребра. Она подсветится зеленым цветом.\n"
                   "Затем правой кнопкой нажмите на вершину, в которую нужно провести ребро.\n"
                   "Если вы хотите добавить ориентированные ребро, зажмите клавишу Alt при выборе второй вершины.\n\n\n"
                   "РЕДАКТИРОВАНИЕ РЕБРА\n\n"
                   "Чтобы изменить вес ребра, просто нажмите на текст, находящийся над линией ребра.\n\n\n"
                   "УДАЛЕНИЕ ЭЛЕМЕНТОВ ГРАФА\n\n"
                   "Выделите нужную вершину или ребро (нажав на них левой кнопкой мыши) и сочетанием клавиш Shift + Del удалите данный элемент.\n\n");
    label->setWordWrap(true);

    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollWidget);
    scrollLayout->addWidget(label);
    scrollWidget->setLayout(scrollLayout);
    scrollArea->setWidget(scrollWidget);

    QVBoxLayout *dialogLayout = new QVBoxLayout(dialog);
    dialogLayout->addWidget(scrollArea);
    dialog->setLayout(dialogLayout);

    dialog->resize(500, 500);
    dialog->show();
}

void MainWindow::Disconnect() {
    for (Vertex* vertex : graph->m_vertices) {
        disconnect(vertex, &Vertex::vertexSelected, this, nullptr);
    }
}
