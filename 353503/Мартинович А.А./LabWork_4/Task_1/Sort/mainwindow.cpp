#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      central_widget(new QWidget(this)),
      scene(new QGraphicsScene(this)),
      view(new QGraphicsView(scene)), arr(),
      shuffle_button(new QPushButton("shuffle", this)),
      heap_sort_button(new QPushButton("Heap sort", this)),
      quick_sort_button(new QPushButton("Quick sort", this)),
      interpol_sort_button(new QPushButton("Interpol sort", this)),
      merge_sort_button(new QPushButton("Merge sort", this)),
      bin_search_button(new QPushButton("Bin search", this)),
      interpol_search_button(new QPushButton("Interpol search", this)),
      search_spin_box(new QSpinBox(this)),
      layout(new QGridLayout()),
      loop(new QEventLoop(this))
{

    search_spin_box->setMaximum(MAX_NUMBER-1);

    setCentralWidget(central_widget);
    central_widget->setLayout(layout);

    layout->addWidget(view, 3, 0, 1, 6);
    layout->addWidget(shuffle_button, 0, 0, 3, 1);
    layout->addWidget(quick_sort_button, 0, 1, 3, 1);
    layout->addWidget(merge_sort_button, 0, 2, 3, 1);
    layout->addWidget(heap_sort_button, 0, 3, 3, 1);
    layout->addWidget(interpol_sort_button, 0, 4, 3, 1);
    layout->addWidget(search_spin_box, 0, 5);
    layout->addWidget(bin_search_button, 1, 5);
    layout->addWidget(interpol_search_button, 2, 5);


    connect(heap_sort_button, &QPushButton::clicked, this, &MainWindow::startHeapSort);
    connect(quick_sort_button, &QPushButton::clicked, this, &MainWindow::startQuickSort);
    connect(merge_sort_button, &QPushButton::clicked, this, &MainWindow::startMergeSort);
    connect(interpol_sort_button, &QPushButton::clicked, this, &MainWindow::startInterpolSort);
    connect(shuffle_button, &QPushButton::clicked, this, &MainWindow::shuffle);
    connect(bin_search_button, &QPushButton::clicked, this, &MainWindow::startBinSearch);
    connect(interpol_search_button, &QPushButton::clicked, this, &MainWindow::startInterpolSearch);

    shuffle();
    showArr();
}

void MainWindow::shuffle()
{
    if (!is_now_sort) {
        is_now_sort = true;
        arr.clear();
        for (int i = 0; i < ARR_SIZE; ++i) {
          arr.push_back(QRandomGenerator::global()->bounded(MAX_NUMBER));
        }
        showArr();
        is_now_sort = false;
    }
}

void MainWindow::showArr()
{
    scene->clear();
    int32_t size_arr = arr.size();
    for (int i = 0; i < size_arr; i++) {
        scene->addRect(QRectF(i*POST_WIDTH, MAX_NUMBER-arr[i], POST_WIDTH, arr[i]), QPen(Qt::black), QBrush(Qt::black));
    }
    scene->update();
}

void MainWindow::showArrSearch(int s, const QColor &col)
{
    scene->clear();
    int32_t size_arr = arr.size();
    for (int i = 0; i < size_arr; i++) {
        if (i == s) {
            scene->addRect(QRectF(i*POST_WIDTH, MAX_NUMBER-arr[i], POST_WIDTH, arr[i]), QPen(col), QBrush(col));
        }
        else {
            scene->addRect(QRectF(i*POST_WIDTH, MAX_NUMBER-arr[i], POST_WIDTH, arr[i]), QPen(Qt::black), QBrush(Qt::black));
        }
    }
    scene->update();
}

void MainWindow::startHeapSort()
{
    if (!is_now_sort && !isSorted()) {

        timer.restart();
        is_now_sort = true;
        heapSort();
        is_now_sort = false;
        qDebug() << "Время сортировки: " << timer.elapsed() << "ms";
    }
}

void MainWindow::heapify(int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
}

    if (largest != i) {
        skip(SKIP_TIME_SORT);
        showArr();
        std::swap(arr[i], arr[largest]);
        heapify(n, largest);
    }
}

void MainWindow::heapSort()
{
    int32_t n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0],arr[i]);
        heapify(i, 0);
    }
}

void MainWindow::merge(int left, int middle, int right) {
    int left_size = middle - left + 1;
    int right_size = right - middle;

    int* leftArray = new int[left_size];
    int* rightArray = new int[right_size];

    for (int i = 0; i < left_size; i++) {
        leftArray[i] = arr[left + i];
    }

    for (int j = 0; j < right_size; j++) {
        rightArray[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    for (; i < left_size && j < right_size; k++) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
            skip(SKIP_TIME_SORT);
            showArr();
        }
        else {
            arr[k] = rightArray[j];
            j++;

        }
    }


    for (; i < left_size; i++, k++) {
        arr[k] = leftArray[i];
    }


    for (; j < right_size; j++, k++) {
        arr[k] = rightArray[j];
    }

    delete[] leftArray;
    delete[] rightArray;
}

void MainWindow::mergeSort(int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(left, middle);
        mergeSort(middle + 1, right);
        merge(left, middle, right);
        showArr();
    }
}

void MainWindow::startQuickSort()
{
    if (!is_now_sort && !isSorted()) {
        timer.restart();
        is_now_sort = true;
        quickSort(0, arr.size()-1);
        is_now_sort = false;
        qDebug() << "Время сортировки: " << timer.elapsed() << "ms";
    }
}

int MainWindow::partQuickSort(int left, int right) {
    int mid = arr[(left + right) / 2];
    while (left <= right) {
        while (arr[left] < mid) {
            left++;
        }
        while (arr[right] > mid) {
            right--;
        }
        if (left <= right) {
            skip(SKIP_TIME_SORT);
            showArr();
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    return left;
}

void MainWindow::quickSort(int start, int end) {
    if (start >= end) {
        return;
    }
    int part_sort = partQuickSort(start, end);
    skip(SKIP_TIME_SORT/200);
    showArr();
    quickSort(start, part_sort - 1);
    skip(SKIP_TIME_SORT/200);
    showArr();
    quickSort(part_sort, end);

}

void MainWindow::startBinSearch()
{
    if (!is_now_sort && isSorted()) {
        is_now_sort = true;
        binSearh(search_spin_box->value(), 0, arr.size()-1);
        is_now_sort = false;
    }
}

int MainWindow::binSearh(int search, int l, int r)
{
    skip(SKIP_TIME_SEARCH);
    if (arr[r] == search) {
        showArrSearch(r, Qt::green);
        return r;
    }
    if (arr[l] == search) {
        showArrSearch(l, Qt::green);
        return l;
    }
    if (r == l) {
        return -1;
    }
    int mid = (r+l)/2;
    showArrSearch(mid, Qt::red);

    if (arr[mid] >= search) {
        binSearh(search, l, mid);
    }
    else {
        binSearh(search, mid+1, r);
    }
    return -1;
}

bool MainWindow::isSorted()
{
    for (int i = 1; i < ARR_SIZE; ++i) {
        if (arr[i] < arr[i-1]) {
            return false;
        }
    }
    return true;
}

void MainWindow::startInterpolSort()
{
    if (!is_now_sort && !isSorted()) {
        is_now_sort = true;
        interpolationSort(arr, 0, arr.size());
        is_now_sort = false;
    }
}

void MainWindow::interpolationSort(QVector<int> &arr, int start, int size) {
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
    }

    if (min != max) {
        QVector<QVector<int>> bucket(size, QVector<int>());

        for (int i = 0; i < size; i++) {
            int interpolation = static_cast<int>(((arr[i] - min) / static_cast<double>(max - min)) * (size - 1));
            bucket[interpolation].push_back(arr[i]);
        }

        for (int i = 0; i < size; i++) {
            if (bucket[i].size() > 1) {
                interpolationSort(bucket[i], 0, bucket[i].size());
            }
            for (int j : bucket[i]) {
                arr[start++] = j;
                skip(SKIP_TIME_SORT);
                showArr();
            }
        }
    }
}

int MainWindow::interpolationSearch(QVector<int> &arr, int x) {
    int lo = 0;
    int hi = arr.size() - 1;

    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        skip(SKIP_TIME_SEARCH);

        int pos = lo + static_cast<int>((static_cast<double>(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
        showArrSearch(pos, Qt::red);

        if (arr[pos] == x) {
            showArrSearch(pos, Qt::green);
            return pos;
        } else if (arr[pos] < x) {
            lo = pos + 1;
        } else {
            hi = pos - 1;
        }
    }

    return -1;
}

void MainWindow::startInterpolSearch()
{
    if (!is_now_sort && isSorted()) {
        is_now_sort = true;
        interpolationSearch(arr, search_spin_box->value());
        is_now_sort = false;
    }
}

void MainWindow::startMergeSort() {
    if (!is_now_sort && !isSorted()) {
        timer.restart();
        is_now_sort = true;
        mergeSort(0, arr.size()-1);
        is_now_sort = false;
        qDebug() << "Время сортировки: " << timer.elapsed() << "ms";
    }

}

void MainWindow::skip(int ms) {
    QTimer::singleShot(ms, loop, &QEventLoop::quit);
    loop->exec();
}
