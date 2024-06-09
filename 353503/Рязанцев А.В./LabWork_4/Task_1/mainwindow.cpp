#include "mainwindow.h"
#include "./ui_mainwindow.h"

const int ARRSIZELIMIT = 999;
const int LimitOfSize = 100;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineSize->setInputMask("000");
    ui->lineSearch->setInputMask("00");
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete[] arr;
}

void MainWindow::FillArray()
{
    arr = new int[size];

    srand(time(0));

    for(auto index{0}; index < size; ++index)
    {
        arr[index] = rand() % LimitOfSize;
    }
}

void MainWindow::PrintLine()
{
    Output_Array += "\n-----------------------------------------------------\n";

    // for(auto Index{0}; Index < size; ++Index)
    // {
    //     Output_Array += " -  - ";
    // }

    //Output_Array += "\n";
}

void MainWindow::DisplayArray()
{
    QString Number_to_convert;

    for(auto Index{0}; Index < size; ++Index)
    {
        Number_to_convert.setNum(arr[Index]);
        Output_Array += Number_to_convert + " ";
    }

    PrintLine();
    ui->textEdit->setText(Output_Array);
}

void MainWindow::on_CreateArray_clicked()
{
    IsSorted = false;

    ui->textEdit->clear();
    Output_Array = "";

    size = ui->lineSize->text().toInt();

    if(size == 0){
        qWarning() << "Enter any number but not 0";
        return;
    }

    FillArray();
    DisplayArray();
}


void MainWindow::on_SortBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        Curr_Sorting = Quick;
        break;
    case 1:
        Curr_Sorting = Merge;
        break;
    case 2:
        Curr_Sorting = Heap;
        break;
    default:
        break;
    }
}


void MainWindow::on_SortButton_clicked()
{
    if(!size){
        return;
    }

    counter = 0;
    IsSorted = true;

    switch (Curr_Sorting) {
    case Quick:
        QuickSort(arr, 0, size - 1, counter);
        DisplayArray();
        break;
    case Merge:
        MergeSort(arr, 0, size - 1, size, counter);
        DisplayArray();
        break;
    case Heap:
        HeapSort(arr, size, counter);
        DisplayArray();
        break;
    default:
        break;
    }

    ui->lineTime->setText(QString().setNum(counter));
}


void MainWindow::on_SearchButton_clicked()
{
    if(!IsSorted){
        return;
    }

    int num_to_find = ui->lineSearch->text().toInt();

    int index = BinSearch(arr, 0, size, num_to_find);

    if(index == -1)
    {
        ui->lineResult->setText("Element not found");
    }
    else
    {
        ui->lineResult->setText(QString().setNum(index + 1));
    }
}

