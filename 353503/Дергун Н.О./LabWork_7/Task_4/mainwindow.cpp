#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::collectData(size_t times[NUM_TABLES][NUM_OCCUPANCY_LEVELS]) {
    for (int i = 0; i < NUM_TABLES; ++i) { // all sizes
        for (int p = 1; p <= NUM_OCCUPANCY_LEVELS; ++p) { // different occupancy
            double occupancy = p * 10.0 / 100.0;
            size_t totalAverageTime = 0;
            for (int k = 0; k < SAMPLE_SIZE; ++k) { // for average
                _table = StrHashTable<int>(TABLE_SIZES[i]);
                auto keys = fillIn(occupancy * TABLE_SIZES[i], _table);
                size_t averageTime = 0;
                size_t repeats = 0;
                for (int j = 0; j < keys.size(); ++j) { // check all keys
                    size_t start = __rdtsc();
                    _table.get(keys[j]);
                    size_t end = __rdtsc();
                    averageTime += end - start;
                    ++repeats;
                }
                averageTime /= repeats;
                totalAverageTime += averageTime;
            }
            times[i][p - 1] = totalAverageTime / SAMPLE_SIZE;
        }
    }
}

void MainWindow::createSeries(size_t times[NUM_TABLES][NUM_OCCUPANCY_LEVELS], QLineSeries* series[NUM_TABLES]) {
    for (int i = 0; i < NUM_TABLES; ++i) {
        series[i] = new QLineSeries();
        for (int p = 0; p < NUM_OCCUPANCY_LEVELS; ++p) {
            double occupancy = 0.1 * (p + 1);
            series[i]->append(occupancy * 100, times[i][p]);
        }
    }
}

void MainWindow::configureCharts(QLineSeries* series[NUM_TABLES], QChart* charts[NUM_TABLES], QChartView* chartViews[NUM_TABLES], QGridLayout* layout) {
    QString titles[NUM_TABLES] = {
        "Table Size: 16",
        "Table Size: 64",
        "Table Size: 128",
        "Table Size: 2048"
    };

    for (int i = 0; i < NUM_TABLES; ++i) {
        charts[i] = new QChart();
        charts[i]->addSeries(series[i]);
        charts[i]->setTitle(titles[i]);
        charts[i]->createDefaultAxes();

        QValueAxis *axisX = new QValueAxis();
        axisX->setTitleText("Occupancy (%)");
        axisX->setLabelFormat("%d");
        axisX->setTickCount(NUM_OCCUPANCY_LEVELS + 1);
        charts[i]->setAxisX(axisX, series[i]);

        QValueAxis *axisY = new QValueAxis();
        axisY->setTitleText("Time (ticks)");
        charts[i]->setAxisY(axisY, series[i]);

        chartViews[i] = new QChartView(charts[i]);
        chartViews[i]->setRenderHint(QPainter::Antialiasing);

        layout->addWidget(chartViews[i], i % 3, i / 3);
    }
}

void MainWindow::initUI() {
    size_t times[NUM_TABLES][NUM_OCCUPANCY_LEVELS] = {0};

    collectData(times);

    QLineSeries* series[NUM_TABLES];
    createSeries(times, series);

    QChart* charts[NUM_TABLES];
    QChartView* chartViews[NUM_TABLES];
    QGridLayout* layout = new QGridLayout();
    configureCharts(series, charts, chartViews, layout);

    setTable(layout);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

QString MainWindow::getRandStr(uint minSize, uint maxSize)
{
    if (minSize > maxSize) {
        std::swap(minSize, maxSize);
    }

    uint size = QRandomGenerator::global()->bounded(minSize, maxSize + 1);
    QString randStr;

    for (uint i = 0; i < size; ++i) {
        QChar randomChar = static_cast<char>(QRandomGenerator::global()->bounded('A', 'Z' + 1));
        randStr.append(randomChar);
    }
    return randStr;
}

QVector<QString> MainWindow::fillIn(uint size, StrHashTable<int> &table)
{
    table.clear();
    QVector<QString> vec;

    for (uint i = 0; i < size; ++i) {
        vec.push_back(getRandStr(MIN_STR_SIZE, MAX_STR_SIZE));
        table.add(vec.back(), i);
    }
    return vec;
}

void MainWindow::setTable(QGridLayout* layout)
{
    _tableWidget = new QTableWidget(this);
    _tableWidget->setColumnCount(2);
    auto collisions = _table.collisions();
    for (const auto& collision : collisions) {
        int row = _tableWidget->rowCount();
        _tableWidget->insertRow(row);

        QTableWidgetItem* indexItem = new QTableWidgetItem(QString::number(collision.first));
        QTableWidgetItem* descriptionItem = new QTableWidgetItem(collision.second);

        _tableWidget->setItem(row, 0, indexItem);
        _tableWidget->setItem(row, 1, descriptionItem);
    }
    layout->addWidget(_tableWidget, 1, 1, 2, 1);
}
