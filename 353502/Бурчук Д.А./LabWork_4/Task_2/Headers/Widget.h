#ifndef LAB_4_TASK_1_WIDGET_H
#define LAB_4_TASK_1_WIDGET_H

#include "QPainter"
#include "QSpinBox"
#include "QTimer"
#include "QTime"
#include "QLabel"
#include "QTableWidgetItem"
#include "QPushButton"
#include "QLineEdit"
#include "QTableView"
#include "Sorting.h"
#include <algorithm>
#include <random>


class Widget : public QWidget {
Q_OBJECT
    std::vector<int> array;

    Sorting s;

    enum SortMode {
        sorting,
        sorted
    };

    SortMode mode;

    QPushButton *interpolationSortButton;
    QPushButton *heapSortButton;
    QPushButton *mergeSortButton;
    QPushButton *quickSortButton;
    QPushButton *shuffleButton;
    QPushButton *binSearchButton;
    QSpinBox *sizeSpinBox;

    QTableWidget *speedTableWidget;

    QLineEdit *searchLineEdit;
    QLabel *numberLabel;

    int selectedElement;

    void greenForSorted();

public:
    Widget();

    void paintEvent(QPaintEvent *event);

private slots:

    void sortArrayInterpolation();

    void sortArrayHeap();

    void sortArrayMerge();

    void sortArrayQuick();

    void randomise();

    void search();

    void activateButtons();

    void deactivateButtons();

    void clearLineEdit();

    void changeSelectedElement(int pos);

    void setArray();
};


#endif //LAB_4_TASK_1_WIDGET_H
