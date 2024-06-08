#include "../Headers/Widget.h"

#include <ctime>

void Widget::paintEvent(QPaintEvent *event) {
    QPainter *painter = new QPainter(this);
    painter->setBrush(Qt::gray);
    painter->setPen(Qt::black);
    for (int i = 0; i < array.size(); ++i) {
        if (i == selectedElement && mode == sorting) { painter->setBrush(Qt::red); }
        else if (i == selectedElement && mode == sorted) { painter->setBrush(Qt::green); }
        painter->drawRect((i + 2) * 7 * 100 / array.size(), 300, 7 * 100 / array.size(),
                          -(array[i] * 500) / (int) (array.size()));
        if (i == selectedElement) { painter->setBrush(Qt::gray); }
    }
    painter->end();
}

Widget::Widget() {
    mode = sorting;
    selectedElement = -1;

    for (int i = 50; i > -50; --i) {
        array.emplace_back(rand() % 2 == 0 ? (rand() % 80) : -(rand() % 80));
    }

    interpolationSortButton = new QPushButton("Interpolation Sort", this);
    interpolationSortButton->setGeometry(800, 20, 180, 30);
    connect(interpolationSortButton, SIGNAL(clicked(bool)), SLOT(sortArrayInterpolation()));

    heapSortButton = new QPushButton("Heap Sort", this);
    heapSortButton->setGeometry(800, 60, 180, 30);
    connect(heapSortButton, SIGNAL(clicked(bool)), SLOT(sortArrayHeap()));

    mergeSortButton = new QPushButton("Merge Sort", this);
    mergeSortButton->setGeometry(800, 100, 180, 30);
    connect(mergeSortButton, SIGNAL(clicked(bool)), SLOT(sortArrayMerge()));

    quickSortButton = new QPushButton("Quick Sort", this);
    quickSortButton->setGeometry(800, 140, 180, 30);
    connect(quickSortButton, SIGNAL(clicked(bool)), SLOT(sortArrayQuick()));

    shuffleButton = new QPushButton("Shuffle", this);
    shuffleButton->setGeometry(800, 180, 180, 30);
    connect(shuffleButton, SIGNAL(clicked(bool)), SLOT(randomise()));

    binSearchButton = new QPushButton("Search", this);
    binSearchButton->setGeometry(800, 220, 180, 30);
    connect(binSearchButton, SIGNAL(clicked(bool)), SLOT(search()));

    searchLineEdit = new QLineEdit(this);
    searchLineEdit->setGeometry(800, 260, 180, 30);

    numberLabel = new QLabel(this);
    numberLabel->setGeometry(800, 300, 180, 30);

    sizeSpinBox = new QSpinBox(this);
    sizeSpinBox->setGeometry(800, 340, 180, 30);
    sizeSpinBox->setMinimum(10);
    sizeSpinBox->setMaximum(150);
    connect(sizeSpinBox, SIGNAL(valueChanged(int)), SLOT(setArray()));

    speedTableWidget = new QTableWidget(this);
    speedTableWidget->setGeometry(800, 400, 180, 300);
    speedTableWidget->setColumnCount(3);
    speedTableWidget->setRowCount(0);
    speedTableWidget->setColumnWidth(0, 30);
    speedTableWidget->setColumnWidth(1, 50);
    speedTableWidget->setColumnWidth(2, 100);
    speedTableWidget->setHorizontalHeaderLabels(
            QStringList() << "T" << "C" << "S");

    connect(&s, SIGNAL(updateWiget()), SLOT(update()));
    connect(&s, &Sorting::sortingSetSelectedPosition, this, &Widget::changeSelectedElement);

    randomise();
}

void Widget::sortArrayInterpolation() {
    QTime time;
    deactivateButtons();
    time.start();
    s.InterpolationSort(array.data(), array.size());
    QTableWidgetItem *item = new QTableWidgetItem(QString("I"));
    speedTableWidget->setRowCount(speedTableWidget->rowCount() + 1);
    speedTableWidget->setItem(speedTableWidget->rowCount() - 1, 0, item);
    item = new QTableWidgetItem(QString(QString::number(array.size())));
    speedTableWidget->setItem(speedTableWidget->rowCount() - 1, 1, item);
    item = new QTableWidgetItem(QString(QString::number(time.elapsed())));
    speedTableWidget->setItem(speedTableWidget->rowCount() - 1, 2, item);
    update();
    greenForSorted();
    activateButtons();

}

void Widget::sortArrayHeap() {
    QTime time;
    deactivateButtons();
    time.start();
    s.HeapSort(array.data(), array.size());
    QTableWidgetItem *item = new QTableWidgetItem(QString("H"));
    speedTableWidget->setRowCount(speedTableWidget->rowCount() + 1);
    speedTableWidget->setItem(speedTableWidget->rowCount() - 1, 0, item);
    item = new QTableWidgetItem(QString(QString::number(array.size())));
    speedTableWidget->setItem(speedTableWidget->rowCount() - 1, 1, item);
    item = new QTableWidgetItem(QString(QString::number(time.elapsed())));
    speedTableWidget->setItem(speedTableWidget->rowCount() - 1, 2, item);
    update();
    greenForSorted();
    activateButtons();
}

void Widget::sortArrayMerge() {
    QTime time;
    deactivateButtons();
    time.start();
    s.MergeSort(array.data(), array.size());
    QTableWidgetItem *item = new QTableWidgetItem(QString("M"));
    speedTableWidget->setRowCount(speedTableWidget->rowCount() + 1);
    speedTableWidget->setItem(speedTableWidget->rowCount() - 1, 0, item);
    item = new QTableWidgetItem(QString(QString::number(array.size())));
    speedTableWidget->setItem(speedTableWidget->rowCount() - 1, 1, item);
    item = new QTableWidgetItem(QString(QString::number(time.elapsed())));
    speedTableWidget->setItem(speedTableWidget->rowCount() - 1, 2, item);
    update();
    greenForSorted();
    activateButtons();
}

void Widget::sortArrayQuick() {
    QTime time;
    deactivateButtons();
    time.start();
    s.QuickSort(array.data(), 0, array.size() - 1);
    QTableWidgetItem *item = new QTableWidgetItem(QString("Q"));
    speedTableWidget->setRowCount(speedTableWidget->rowCount() + 1);
    speedTableWidget->setItem(speedTableWidget->rowCount() - 1, 0, item);
    item = new QTableWidgetItem(QString(QString::number(array.size())));
    speedTableWidget->setItem(speedTableWidget->rowCount() - 1, 1, item);
    item = new QTableWidgetItem(QString(QString::number(time.elapsed())));
    speedTableWidget->setItem(speedTableWidget->rowCount() - 1, 2, item);
    update();
    greenForSorted();
    activateButtons();
}

void Widget::randomise() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(std::begin(array), std::end(array), g);
    binSearchButton->setEnabled(false);
    update();
}

void Widget::activateButtons() {
    interpolationSortButton->setEnabled(true);
    heapSortButton->setEnabled(true);
    mergeSortButton->setEnabled(true);
    quickSortButton->setEnabled(true);
    shuffleButton->setEnabled(true);
    binSearchButton->setEnabled(true);
}

void Widget::deactivateButtons() {
    interpolationSortButton->setEnabled(false);
    heapSortButton->setEnabled(false);
    mergeSortButton->setEnabled(false);
    quickSortButton->setEnabled(false);
    shuffleButton->setEnabled(false);
    binSearchButton->setEnabled(false);
}

void Widget::search() {
    bool isNumber;
    int number = searchLineEdit->text().toDouble(&isNumber);
    if (isNumber) {
        if (number == -1) {
            numberLabel->setText(QString::number(-1));
        } else {
            deactivateButtons();
            numberLabel->setText(QString::number(
                    s.BinPow(s.BinSearch(array.data(), 0, array.size(), number), array.size(), abs(number))));
            update();
            activateButtons();
        }
    } else {
        searchLineEdit->setText("Error");
        QTimer::singleShot(600, this, SLOT(clearLineEdit()));
    }
}

void Widget::clearLineEdit() {
    searchLineEdit->setText("");
}

void Widget::changeSelectedElement(int pos) {
    selectedElement = pos;
}

void Widget::greenForSorted() {
    mode = sorted;
    for (int i = 0; i < array.size(); ++i) {
        selectedElement = i;
        update();
        QCoreApplication::processEvents();
        QThread::msleep(4);
    }
    selectedElement = -1;
    mode = sorting;
    update();
}

void Widget::setArray() {
    array.clear();
    int size = sizeSpinBox->value();
    for (int i = -size; i < size; ++i) {
        array.emplace_back(i);
    }
    QCoreApplication::processEvents();
    randomise();
    update();
}

