#include "productsort.h"

ProductSort::ProductSort() {

}

void ProductSort::insertionSortIncrease(QVector<Product*> *array, int start_index, int end_index)
{
    for (int i = start_index + 1; i <= end_index; i++)
    {
        Product* temp = array->at(i);
        int j = i - 1;
        while(j >= start_index && temp->getBestPrice() < array->at(j)->getBestPrice())
        {
            (*array)[j+1] = array->at(j);
            j--;
        }
        (*array)[j+1] = temp;
    }
}

void ProductSort::mergeIncrease(QVector<Product*> *array, int start_index, int mid, int end_index)
{
    int left_size = mid - start_index + 1;
    int right_size = end_index - mid;
    QVector<Product*> left_array(left_size);
    QVector<Product*> right_array(right_size);

    for (int i = 0; i < left_size; i++)
    {
        left_array[i] = array->at(start_index + i);
    }

    for (int i = 0; i < right_size; i++)
    {
        right_array[i] = array->at(mid + 1 + i);
    }

    int i = 0;
    int j = 0;
    int k = start_index;

    for (; i < left_size && j < right_size; k++)
    {
        if(left_array[i]->getBestPrice() <= right_array[j]->getBestPrice())
        {
            (*array)[k] = left_array[i];
            i++;
        }
        else
        {
            (*array)[k] = right_array[j];
            j++;
        }
    }
    for (; i < left_size ;i++ , k++)
    {
        (*array)[k] = left_array[i];
    }
    for (; j < right_size; j++ , k++)
    {
        (*array)[k] = right_array[j];
    }
}

void ProductSort::timsortIncrease(QVector<Product*> *array)
{
    while(!array->isEmpty() && !array->back()->getIsProduct()) {
        array->pop_back();
    }

    for (int i = 0; i < (*array).size(); i += RUN)
    {
        insertionSortIncrease(array, i, qMin((i+RUN-1), ((array)->size() - 1)));
    }

    for (int n = RUN; n < (*array).size(); n *= 2)
    {
        for (int start_index = 0; start_index < array->size(); start_index += 2*n)
        {
            int mid = start_index + n - 1;
            int end_index = qMin((start_index + 2*n - 1),((*array).size()-1));

            if(mid < end_index)
            {
                mergeIncrease(array, start_index, mid, end_index);
            }
        }
    }
}


void ProductSort::insertionSortDecrease(QVector<Product*> *array, int start_index, int end_index)
{

    for (int i = start_index + 1; i <= end_index; i++)
    {
        Product* temp = array->at(i);
        int j = i - 1;

        while(j >= start_index && temp->getBestPrice() > array->at(j)->getBestPrice())
        {
            (*array)[j+1] = array->at(j);
            j--;
        }
        (*array)[j+1] = temp;
    }
}

void ProductSort::mergeDecrease(QVector<Product*> *array, int start_index, int mid, int end_index)
{
    int left_size = mid - start_index + 1;
    int right_size = end_index - mid;
    QVector<Product*> left_array(left_size);
    QVector<Product*> right_array(right_size);

    for (int i = 0; i < left_size; i++)
    {
        left_array[i] = array->at(start_index + i);
    }

    for (int i = 0; i < right_size; i++)
    {
        right_array[i] = array->at(mid + 1 + i);
    }

    int i = 0;
    int j = 0;
    int k = start_index;

    for (; i < left_size && j < right_size; k++)
    {
        if(left_array[i]->getBestPrice() >= right_array[j]->getBestPrice())
        {
            (*array)[k] = left_array[i];
            i++;
        }
        else
        {
            (*array)[k] = right_array[j];
            j++;
        }
    }
    for (; i < left_size ;i++ , k++)
    {
        (*array)[k] = left_array[i];
    }
    for (; j < right_size; j++ , k++)
    {
        (*array)[k] = right_array[j];
    }
}

void ProductSort::timsortDecrease(QVector<Product*> *array)
{
    while(!array->isEmpty() && array->back()->getBestPrice() == 0) {
        array->pop_back();
    }
    for (int i = 0; i < (*array).size(); i += RUN)
    {
        insertionSortDecrease(array, i, qMin((i+RUN-1), ((array)->size() - 1)));
    }

    for (int n = RUN; n < (*array).size(); n *= 2)
    {
        for (int start_index = 0; start_index < array->size(); start_index += 2*n)
        {
            int mid = start_index + n - 1;
            int end_index = qMin((start_index + 2*n - 1),((*array).size()-1));

            if(mid < end_index)
            {
                mergeDecrease(array, start_index, mid, end_index);
            }
        }
    }
}

void ProductSort::threeWayQuickSortIncrease(QVector<Product*> *array, int low, int high) {
    if (low >= high) return;

    QString pivot = array->at(low)->getName();

    int lt = low;
    int gt = high;
    int i = low + 1;

    while (i <= gt) {
        if (array->at(i)->getName() < pivot) {
            std::swap((*array)[i], (*array)[lt]);
            lt++;
            i++;
        } else if (array->at(i)->getName() > pivot) {
            std::swap((*array)[i], (*array)[gt]);
            gt--;
        } else {
            i++;
        }
    }
    threeWayQuickSortIncrease(array, low, lt - 1);
    threeWayQuickSortIncrease(array, gt + 1, high);
}

void ProductSort::threeWayQuickSortDecrease(QVector<Product*> *array, int low, int high) {
    if (low >= high) return;
    while(!array->isEmpty() && array->back()->getBestPrice() == -1) {
        array->pop_back();
    }
    QString pivot = array->at(low)->getName();
    int lt = low;
    int gt = high;
    int i = low + 1;
    while (i <= gt) {
        if (array->at(i)->getName() > pivot) {
            std::swap((*array)[i], (*array)[lt]);
            lt++;
            i++;
        } else if (array->at(i)->getName() < pivot) {
            std::swap((*array)[i], (*array)[gt]);
            gt--;
        } else {
            i++;
        }
    }
    threeWayQuickSortDecrease(array, low, lt - 1);
    threeWayQuickSortDecrease(array, gt + 1, high);
}
