#include "mainwindow.h"
#include "./ui_mainwindow.h"

int LIMITOFSIZE = 100;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineSize->setInputMask("000");
    ui->lineSearch->setInputMask("00");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SizeButton_clicked()
{
    IsSorted = false;

    Output = "";
    ui->textEdit->clear();

    size = ui->lineSize->text().toInt();

    if(!size){
        return;
    }

    array.resize(size);

    FillArray(array);
    PrintArray(array);
}

void MainWindow::FillArray(std::vector<int> &arr)
{
    srand(time(0));

    for(auto index{0}; index < arr.size(); ++index)
    {
        arr[index] = rand() % LIMITOFSIZE;
    }
}

int MainWindow::BinSearch(const std::vector<int>& arr, int l, int r, int num_to_find)
{
    int curr_elem = (l + r) / 2;

    if(r - l == 1 && arr[l] != num_to_find){
        return -1;
    }

    if(arr[curr_elem] == num_to_find)
    {
        return curr_elem;
    }
    else if(arr[curr_elem] < num_to_find)
    {
        return BinSearch(arr, curr_elem + 1, r, num_to_find);
    }
    else if(arr[curr_elem] > num_to_find)
    {
        return BinSearch(arr, l, curr_elem - 1, num_to_find);
    }
}

void MainWindow::InterpolationSort(std::vector<int> &arr)
{
    std::vector<int> divideSize;
    int r = static_cast<int>(arr.size());
    divideSize.push_back(r);
    while (!divideSize.empty())
    {
        int size = divideSize.back();
        divideSize.pop_back();

        int l = r - size;
        int min = arr[l];
        int max = arr[l];

        for(auto Index{l + 1}; Index < r; ++Index)
        {
            if(arr[Index] < min){
                min = arr[Index];
            }
            else if(arr[Index] > max){
                max = arr[Index];
            }
        }

        if(min == max){
            r -= size;
        }
        else
        {
            int  p = 0;
            std::vector<std::vector<int>> bucket(size);

            for(auto Index{l}; Index < r; ++Index)
            {
                p = static_cast<int>(((arr[Index] - min) / static_cast<double>(max - min)) * (size - 1));
                bucket[p].push_back(arr[Index]);
            }
            for(auto i{0}; i < size; ++i)
            {
                if(!bucket[i].empty())
                {
                    for(auto j{0}; j < bucket[i].size(); ++j)
                    {
                        arr[l++] = bucket[i][j];
                    }
                    divideSize.push_back(bucket[i].size());
                }
            }
        }
    }
}

int MainWindow::BinPow(int digit, int powder, int mod)
{
    if(powder == 0)
    {
        return 1;
    }

    if(powder % 2 == 1)
    {
        return (BinPow(digit, powder - 1, mod) * digit) % mod;
    }
    else
    {
        int num = BinPow(digit, powder / 2, mod);
        return (num * num) % mod;
    }
}


void MainWindow::PrintArray(const std::vector<int> &arr)
{
    for(auto index{0}; index < arr.size(); ++index)
    {
        Output += QString().setNum(arr[index]) + " ";
    }
    Output += "\n\n************************************************************************\n";

    ui->textEdit->setText(Output);
}



void MainWindow::on_PowButton_clicked()
{
    if(!IsSorted){
        return;
    }

    int num_to_find = ui->lineSearch->text().toInt();

    if(!num_to_find){
        return;
    }

    int index = BinSearch(array, 0, array.size(), num_to_find);

    if(index == -1)
    {
        ui->ResultLine->setText("No such number");
    }
    else
    {
        int result = BinPow(index, size, num_to_find);
        ui->ResultLine->setText(QString().setNum(result));
    }
}


void MainWindow::on_pushButton_clicked()
{
    if(!size){
        return;
    }

    InterpolationSort(array);
    PrintArray(array);
    IsSorted = true;
}

