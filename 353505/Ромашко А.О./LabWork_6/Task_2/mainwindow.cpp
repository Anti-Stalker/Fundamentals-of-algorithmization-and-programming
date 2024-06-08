#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->lineEdit, &QLineEdit::returnPressed, &loop, &QEventLoop::quit);

    QTimer::singleShot(50, [&]{
        printMenu();
    });

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);

    scrollArea->setWidget(ui->label);

    ui->gridLayout->removeWidget(ui->label);
    ui->gridLayout->addWidget(scrollArea, 0, 0);

    Qt::WindowFlags flags = Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::CustomizeWindowHint;
    setWindowFlags(flags);

    setFixedSize(size());
    setWindowTitle("");
}

struct Skin
{
    int cost;
    double floatSkin;
    char wear;
    bool unique;
    char name [10];
    int playerId[3];
};

MainWindow::~MainWindow()
{
    delete ui;
    QApplication::quit();
}

QString MainWindow::input()
{
    loop.exec();
    QString ret = ui->lineEdit->text();
    ui->lineEdit->clear();
    ui->label->setText(ui->label->text() + "\n");
    return ret;
}

void MainWindow::print(QString newStr)
{
    ui->label->setText(ui->label->text() + newStr);
}

void MainWindow::printMenu()
{
    bool isRunning = true;
    while (isRunning) {
        print("\nМеню:\n"
              "1. Записать параграф в файл\n"
              "2. Прочитать и распечатать параграф из файла\n"
              "3. Записать массив в файл\n"
              "4. Прочитать и распечатать массив из файла\n"
              "5. Записать структуру в файл\n"
              "6. Прочитать и распечатать структуры из файла\n"
              "7. Записать предложение в файл\n"
              "8. Прочитать и распечатать предложения из файла\n"
              "9. Записать структуру в бинарный файл\n"
              "10. Прочитать и распечатать структуры из бинарного файла\n"
              "11. Выход\n"
              "Введите ваш выбор:\n");
        switch (input().toInt()) {
        case 1:
            writeParagraphToFile(paragraphFile);
            break;
        case 2:
            readAndPrintParagraphFromFile(paragraphFile);
            break;
        case 3:
            writeArrayToFile(arrayFile, ',');
            break;
        case 4:
            readAndPrintArrayFromFile(arrayFile, ',');
            break;
        case 5:
            writeStructToFile(structFile);
            break;
        case 6:
            readAndPrintStructsFromFile(structFile);
            break;
        case 7:
            writeSentenceToFile(sentenceFile);
            break;
        case 8:
            readAndPrintSentencesFromFile(sentenceFile);
            break;
        case 11:
            print("Завершение программы...\n");
            isRunning = false;
            break;
        case 9:
            saveShipToBinaryFile(binaryFile);
            break;
        case 10:
            printShipsFromBinaryFile(binaryFile);
            break;
        default:
            print("Неверный выбор. Пожалуйста, введите число от 1 до 9.\n");
        }
    }
    QApplication::quit();
}

void MainWindow::writeParagraphToFile(const std::string &filename)
{
    std::wofstream file(filename, std::ios::out);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }
    print("Введите параграф (нажмите Enter для завершения):\n");
    QString paragraph = input();
    file << paragraph.toStdWString();
    print("Параграф введён!\n");
    file.close();
}

void MainWindow::readAndPrintParagraphFromFile(const std::string &filename)
{
    std::wifstream file(filename, std::ios::in);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }
    QString fileName(filename.c_str());
    print(QString("Параграф из файла " + fileName + ":" + "\n"));
    wchar_t ch;
    while (file.get(ch)) {
        print(QString(QChar(ch)));
    }
    file.close();
}

void MainWindow::writeArrayToFile(const std::string &filename, char delimiter)
{
    int size;
    print("Введите размер массива:\n");
    size = input().toInt();

    std::ofstream file(filename, std::ios::out);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }

    print("Введите элементы массива, разделенные '" + QString(delimiter) + "': ");
    qint64 value;
    QString inp = input();
    for (int i = 0; i < size; ++i) {
        value = inp.section(delimiter, i, i).toLongLong();
        file << value;
        if (i != size - 1) {
            file << delimiter;
        }
    }

    file.close();

    print("Массив введён!");
}

void MainWindow::readAndPrintArrayFromFile(const std::string &filename, char delimiter)
{
    std::ifstream file(filename, std::ios::in);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }
    QString fileName(filename.c_str());
    print(QString("Массив из файла " + fileName + ":" + "\n"));

    int value;
    while (file >> value) {
        print(QString::number(value) + " ");
        file.ignore(std::numeric_limits<std::streamsize>::max(), delimiter);
    }

    file.close();
}

void MainWindow::writeStructToFile(const std::string &filename)
{
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }

    Skin obj;
    print("Введите цену скина: ");
    obj.cost = input().toInt();
    print("Введите float корабля: ");
    obj.floatSkin = input().toDouble();
    print("Введите тип потертостей: ");
    obj.wear = input()[0].toLatin1();
    print("Является ли скин уникальным? (1 - да, 0 - нет): ");
    obj.unique = input().toInt();
    print("Введите название скина (не более 10 символов): ");
    std::string temp;
    temp = input().toStdString();
    for(int i =0 ; i<10;i++)
    {
        obj.name[i]=temp[i];
    }
    print("Введите id игрока экипажа: ");
    obj.playerId[0] = input().toInt();

    file << obj.cost << " | " << obj.floatSkin << " | " << obj.wear << " | "
         << obj.unique << " | " << obj.name << " | " << obj.playerId << std::endl;

    file.close();
}

void MainWindow::readAndPrintStructsFromFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::in);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }
    QString fileName(filename.c_str());
    print("Структуры из файла " + fileName + ":" + "\n");
    Skin skin;
    char delimiter;
    while (file >> skin.cost >> delimiter && delimiter == '|' &&
           file >> skin.floatSkin >> delimiter && delimiter == '|' &&
           file >> skin.wear >> delimiter && delimiter == '|' &&
           file >> skin.unique >> delimiter && delimiter == '|' &&
           file >> skin.name >> delimiter && delimiter == '|' &&
           file >> skin.playerId[0]) {
        print(QString::number(skin.cost) + "|" +
              QString::number(skin.floatSkin) + "|" + skin.wear + "|" + QString::number(skin.unique)
              + "|" + QString::fromUtf8(skin.name) + "|" + QString::number(skin.playerId[0]) + " ;\n");
    }

    file.close();
}

void MainWindow::writeSentenceToFile(const std::string &filename)
{
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }

    QString sentence;
    print("Введите предложение: ");
    sentence = input();

    file << sentence.toStdString() << '\n';

    file.close();

    print("Предложение записано!\n");
}

void MainWindow::readAndPrintSentencesFromFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::in);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }

    QString fileName(filename.c_str());
    print("Предложения из файла " + fileName + ":" + "\n");
    std::string sentence;
    while (std::getline(file, sentence)) {
        print(QString(sentence.c_str()) +"\n");
    }

    file.close();
}

void MainWindow::saveShipToBinaryFile(const std::string &filename)
{
    std::ofstream file(filename, std::ios::app | std::ios::binary);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }

    Skin obj;
    print("Введите цену скина: ");
    obj.cost = input().toInt();
    print("Введите float корабля: ");
    obj.floatSkin = input().toDouble();
    print("Введите тип потертостей: ");
    obj.wear = input()[0].toLatin1();
    print("Является ли скин уникальным? (1 - да, 0 - нет): ");
    obj.unique = input().toInt();
    // print("Введите название скина (не более 10 символов): ");
    //obj.name = input().toStdString();
    print("Введите id игрока: ");
    obj.playerId[0] = input().toInt();
    wchar_t name[10];
    input().toWCharArray(name);
    print("Введите название скина (не более 10 символов): ");
    for (int i = 0; i < 10; ++i) obj.name[i] = name[i];

    file.write(reinterpret_cast<const char*>(&obj), sizeof(Skin) + 1);

    file.close();
}

void MainWindow::printShipsFromBinaryFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        QMessageBox::critical(this, "Ошибка!", "Ошибка открытия файла!");
        return;
    }

    Skin skin;
    while (file.read(reinterpret_cast<char*>(&skin), sizeof(Skin))) {
        print(QString::number(skin.cost) + "|" +
              QString::number(skin.floatSkin) + "|" + skin.wear + "|" + QString::number(skin.unique)
              + "|" + QString::fromUtf8(skin.name) + "|" + QString::number(skin.playerId[0]) + " ;\n");
    }

    file.close();
}
