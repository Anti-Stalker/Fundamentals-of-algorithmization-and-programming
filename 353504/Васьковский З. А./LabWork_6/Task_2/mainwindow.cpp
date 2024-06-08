#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    QFile file_1(FILENAME);
    file_1.open(QIODevice::WriteOnly | QIODevice::Truncate);
    file_1.close();
    QFile file_2(FILEForArray);
    file_2.open(QIODevice::WriteOnly | QIODevice::Truncate);
    file_2.close();
    QFile file_3(FILEForStruct);
    file_3.open(QIODevice::WriteOnly | QIODevice::Truncate);
    file_3.close();
    QFile file_4(FILEBIN);
    file_4.open(QIODevice::WriteOnly | QIODevice::Truncate);
    file_4.close();
}

void MainWindow::on_pushButton_11_clicked()
{
    close();
}

void MainWindow::on_pushButton_clicked()
{
    bool ok = false;
    QString paragraph;
    QString name = QInputDialog::getText(nullptr, "Введите абзац", "Введите строку", QLineEdit::Normal, "", &ok);
    if (ok)
    {
        paragraph = name;
    }

    QFile file(FILENAME);
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Невозможно открыть файл для записи\n";
        file.close();
        return;
    }
    QTextStream out(&file);
    out << paragraph << "\n";
    file.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QFile file(FILENAME);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Невозможно открыть файл для чтения\n";
        file.close();
        return;
    }
    QTextStream in(&file);
    QString info = in.readAll();
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setPlainText(info);
    qDebug() << "Содержимое: " << qPrintable(info);
    file.close();
}

void MainWindow::on_pushButton_3_clicked()
{
    bool ok;
    int size = QInputDialog::getInt(nullptr, "Ввод", "Введите размер массива:", 1, 1, 100, 1, &ok);
    if (!ok)
        return;

    QVector<float> temp;
    for (int i = 0; i < size; ++i)
    {
        float value = QInputDialog::getDouble(nullptr, "Ввод", "Введите значение элемента " + QString::number(i) + ":", 0, -10000, 10000, 5, &ok);
        if (!ok)
            return;
        temp.push_back(value);
    }

    _array.push_back(temp);
    QFile file(FILEForArray);
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Непозможно открыть файл для записи: " << qPrintable(file.errorString());
        return;
    }
    QTextStream out(&file);
    out << size << "\n";
    for (auto value : temp)
        out << value << "\n";

    file.close();
}

void MainWindow::on_pushButton_4_clicked()
{
    QFile file(FILEForArray);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Невозможно открыть файл для чтения: " << qPrintable(file.errorString());
        return;
    }

    QTextStream in(&file);
    QString info;
    while (!in.atEnd())
    {
        int size;
        in >> size;
        if(size!= 0)
        {
            info += "Size: " + QString::number(size) + "\n";

            for (int i = 0; i < size; ++i)
            {
                float value;
                in >> value;
                info += "Элемент_" + QString::number(i+1) + ": " + QString::number(value) + "\n";
            }
        }
    }

    file.close();
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setPlainText(info);
}

void MainWindow::getInputForToy()
{
    bool ok;
    Toy toy;
    int age = QInputDialog::getInt(nullptr, "Выберите игрушку", "Введите возраст игрушки:", 1, 1, 100, 1, &ok);
    if (ok)
    {
        toy._age = age;
    }

    double price = QInputDialog::getDouble(nullptr, "Выберите игрушку", "Введите цену:", 0, 0, 10000, 2, &ok);
    if (ok)
    {
        toy._price = price;
    }

    QString name = QInputDialog::getText(nullptr, "Выберите игрушку", "Выберите имя:", QLineEdit::Normal, "", &ok);
    if (ok)
    {
        toy._name = name.toStdString();
    }

    QStringList items;
    items << "Yes" << "No";
    QString available = QInputDialog::getItem(nullptr, "Выберите игрушку", "Эта игрушка для детей(да/нет)?", items, 0, false, &ok);
    if (ok)
    {
        toy._isForChildern = (available == "Yes");
    }

    _toys.push_back(toy);

    QFile file(FILEForStruct);
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Невозможно открыть файл для записи: " << qPrintable(file.errorString());
        return;
    }
    QTextStream out(&file);
    out << toy._age << ")" << toy._price << ")" << QString::fromStdString(toy._name) << ")" << toy._isForChildern << "\n";
    file.close();
}

void MainWindow::getOutputForToy()
{
    QFile file(FILEForStruct);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Невозможно открыть файл для чтения: " << qPrintable(file.errorString());
        return;
    }

    QTextStream in(&file);
    Toy toy;
    QString str;
    QString info;
    _toys.clear();
    while (!in.atEnd())
    {
        str = in.readLine();
        QStringList list = str.split(")");
        toy._age = list.at(0).toInt();
        toy._price = list.at(1).toDouble();
        toy._name = list.at(2).toStdString();
        toy._isForChildern = list.at(3).toInt();
        _toys.push_back(toy);
        info += "  Возраст: " + QString::number(toy._age) + "  цена: " + QString::number(toy._price) + "  имя: " + QString::fromStdString(toy._name) +
                "  Для детей ? : " + QString::number(toy._isForChildern) + "\n";
    }
    file.close();
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setPlainText(info);
}

void MainWindow::getInputForBinToy()
{
    bool ok;
    Toy toy;
    int age = QInputDialog::getInt(nullptr, "Выберите игрушку", "Введите возраст игрушки:", 1, 1, 100, 1, &ok);
    if (ok)
    {
        toy._age = age;
    }

    double price = QInputDialog::getDouble(nullptr, "Выберите игрушку", "Введите цену:", 0, 0, 10000, 2, &ok);
    if (ok)
    {
        toy._price = price;
    }

    QString name = QInputDialog::getText(nullptr, "Выберите игрушку", "Введите имя:", QLineEdit::Normal, "", &ok);
    if (ok)
    {
        toy._name = name.toStdString();
    }

    QStringList items;
    items << "Yes" << "No";
    QString available = QInputDialog::getItem(nullptr, "Выберите игрушку", "Для детей?", items, 0, false, &ok);
    if (ok)
    {
        toy._isForChildern = (available == "Yes");
    }

    _toys.push_back(toy);

    std::ofstream file(FILEBIN, std::ios::binary | std::ios::app);
    if (!file)
    {
        std::cerr << "Невозможно открыть файл для записи: " << FILEBIN << '\n';
        return;
    }

    file.write(reinterpret_cast<const char*>(&toy._age), sizeof(toy._age));
    file.write(reinterpret_cast<const char*>(&toy._price), sizeof(toy._price));
    uint32_t name_length = toy._name.size();
    file.write(reinterpret_cast<const char*>(&name_length), sizeof(name_length));
    file.write(toy._name.c_str(), name_length);
    file.write(reinterpret_cast<const char*>(&toy._isForChildern), sizeof(toy._isForChildern));

    file.close();
}

void MainWindow::getOutputForBinToy()
{
    std::ifstream file(FILEBIN, std::ios::binary);
    if (!file)
    {
        std::cerr << "Невозможно открыть файл для чтения: " << FILEBIN << '\n';
        return;
    }
    QString info;
    std::vector<Toy> toys;
    Toy toy;
    uint32_t name_length;
    while (file.read(reinterpret_cast<char*>(&toy._age), sizeof(toy._age)) &&
           file.read(reinterpret_cast<char*>(&toy._price), sizeof(toy._price)) &&
           file.read(reinterpret_cast<char*>(&name_length), sizeof(name_length)))
    {
        toy._name.resize(name_length);
        file.read(&toy._name[0], name_length);
        file.read(reinterpret_cast<char*>(&toy._isForChildern), sizeof(toy._isForChildern));
        toys.push_back(toy);
        info += "  Возраст: " + QString::number(toy._age) + "  Цена: " + QString::number(toy._price) + "  Имя: " + QString::fromStdString(toy._name) +
                "  Для детей? : " + QString::number(toy._isForChildern) + "\n";
    }
    file.close();
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setPlainText(info);
}

void MainWindow::on_pushButton_5_clicked()
{
    getInputForToy();
}


void MainWindow::on_pushButton_6_clicked()
{
    getOutputForToy();
}


void MainWindow::on_pushButton_7_clicked()
{
    getInputForBinToy();
}


void MainWindow::on_pushButton_8_clicked()
{
    getOutputForBinToy();
}


void MainWindow::on_pushButton_9_clicked()
{
    bool ok = false;
    QString paragraph;
    QString name = QInputDialog::getText(nullptr, "Введите абзац", "Введите текст", QLineEdit::Normal, "", &ok);
    if (ok)
    {
        paragraph = name;
    }

    QFile file(FILENAME);
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Невозможно открыть файл для записи!\n";
        file.close();
        return;
    }
    QTextStream out(&file);
    for (int i = 0; i < paragraph.size(); ++i)
    {
        out << paragraph.at(i);
    }
    file.close();
}


void MainWindow::on_pushButton_10_clicked()
{
    QFile file(FILENAME);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Невозможно открыть файл для чтения!\n";
        file.close();
        return;
    }
    QTextStream in(&file);
    QString info = in.readAll();
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setPlainText(info);
    qDebug() << "Содержимое: " << qPrintable(info);
}
