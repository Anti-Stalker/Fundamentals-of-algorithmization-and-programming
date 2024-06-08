//
// Created by u on 30.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include "main_window.h"
#include "ui_main_window.h"


main_window::main_window(QWidget *parent) :
        QWidget(parent), ui(new Ui::main_window) {
    ui->setupUi(this);

    connect(ui->lineEdit, &QLineEdit::returnPressed, &loop, &QEventLoop::quit);

    QTimer::singleShot(50, [&]{printMenu();});

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);

    scrollArea->setWidget(ui->label);

    ui->gridLayout->removeWidget(ui->label);
    ui->gridLayout->addWidget(scrollArea, 0, 0);

    Qt::WindowFlags flags = Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::CustomizeWindowHint;
    setWindowFlags(flags);

    setFixedSize(size());
}

main_window::~main_window()
{
    delete ui;
}

QString main_window::input()
{
    loop.exec();
    QString res = ui->lineEdit->text();
    ui->lineEdit->clear();
    ui->label->setText(ui->label->text() + "\n");
    return res;
}

void main_window::print(QString newStr)
{
    ui->label->setText(ui->label->text() + newStr);
}

struct athlete {
    int footSize;
    double height;
    char eyeColor;
    bool isFast;
    static const int maxNameLength = 20;
    std::string name;
    static const int maxMedalsSize = 100;
    int medals;
};

void main_window::printMenu()
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
                writeArrayToFile(arrayFile, '\\');
                break;
            case 4:
                readAndPrintArrayFromFile(arrayFile, '\\');
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
            case 9:
                saveShipToBinaryFile(binaryFile);
                break;
            case 10:
                printShipsFromBinaryFile(binaryFile);
                break;
            case 11:
                print("Завершение программы...\n");
                isRunning = false;
                break;
            default:
                print("Неверный выбор. Пожалуйста, введите число от 1 до 11.\n");
        }
    }
    QApplication::quit();
}

void main_window::writeParagraphToFile(const std::string &filename)
{
    std::wofstream file(filename, std::ios::out);
    if (!file.is_open())
        throw std::runtime_error("");

    print("Введите параграф:\n");
    QString paragraph = input();
    file << paragraph.toStdWString();
    print("Параграф введён!\n");
    file.close();
}

void main_window::readAndPrintParagraphFromFile(const std::string &filename)
{
    std::wifstream file(filename, std::ios::in);
    if (!file)
        throw std::runtime_error("");

    QString fileName(filename.c_str());
    print(QString("Параграф из файла " + fileName + ":" + "\n"));
    wchar_t ch;
    while (file.get(ch))
        print(QString(QChar(ch)));

    file.close();
}

void main_window::writeArrayToFile(const std::string &filename, char delimiter)
{
    int size;
    print("Введите размер массива:\n");
    size = input().toInt();

    std::ofstream file(filename, std::ios::out);
    if (!file)
        throw std::runtime_error("");

    file << size << "\n";

    print("Введите элементы массива: ");
    QString inp = input();
    int value = 0;
    for (int i = 0; i < inp.size() && size > 0; ++i)
    {
        if (inp[i] >= '0' && inp[i] <= '9')
        {
            value = value * 10 + (inp.toStdString()[i] - '0');
            continue;
        }
        file << value << delimiter;
        size--;
        value = 0;
    }

    file << value;

    file.close();

    print("Массив введён!");
}

void main_window::readAndPrintArrayFromFile(const std::string &filename, char delimiter)
{
    std::ifstream file(filename, std::ios::in);
    if (!file)
        throw std::runtime_error("");

    QString fileName(filename.c_str());
    print(QString("Массив из файла " + fileName + ":" + "\n"));
    int sz;
    file >> sz;
    for (int i = 1; i < sz; i++)
    {
        int value;
        char c;
        file >> value >> c;
        print(QString::number(value) + " ");
    }

    int value;
    file >> value;
    print(QString::number(value) + "\n");

    file.close();
}

void main_window::writeStructToFile(const std::string &filename)
{
    std::ofstream file(filename, std::ios::app);
    if (!file)
        throw std::runtime_error("");

    athlete obj;
    print("Введите размер ноги: ");
    obj.footSize = input().toInt();
    print("Введите высоту: ");
    obj.height = input().toDouble();
    print("Введите цвет глаз: ");
    obj.eyeColor = input()[0].toLatin1();
    print("Быстрый ли спортсмен (1 - да, 0 - нет): ");
    obj.isFast = input().toInt();
    print("Введите имя (не более " + QString::number(athlete::maxNameLength) + " символов): ");
    obj.name = input().toStdString();
    print("Введите число медалей: ");
    obj.medals = input().toInt();

    file << obj.footSize << " | " << obj.height << " | " << obj.eyeColor << " | "
         << obj.isFast << " | " << obj.name << " | " << obj.medals << std::endl;

    file.close();
}

void main_window::readAndPrintStructsFromFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::in);
    if (!file)
        throw std::runtime_error("");

    QString fileName(filename.c_str());
    print("Структуры из файла " + fileName + ":" + "\n");
    athlete obj;
    char delimiter;
    while (file >> obj.footSize >> delimiter && delimiter == '|' &&
           file >> obj.height >> delimiter && delimiter == '|' &&
           file >> obj.eyeColor >> delimiter && delimiter == '|' &&
           file >> obj.isFast >> delimiter && delimiter == '|' &&
           file >> obj.name >> delimiter && delimiter == '|' &&
           file >> obj.medals)
    {
        print(QString::number(obj.footSize) + "|" +
              QString::number(obj.height) + "|" + obj.eyeColor + "|" + QString::number(obj.isFast)
              + "|" + QString::fromStdString(obj.name) + "|" + QString::number(obj.medals) + " ;\n");
    }

    file.close();
}

void main_window::writeSentenceToFile(const std::string &filename)
{
    std::ofstream file(filename, std::ios::app);
    if (!file)
        throw std::runtime_error("");

    QString sentence;
    print("Введите предложение: ");
    sentence = input();

    file << sentence.toStdString() << '\n';

    file.close();

    print("Предложение записано!\n");
}

void main_window::readAndPrintSentencesFromFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::in);
    if (!file)
        throw std::runtime_error("");

    QString fileName(filename.c_str());
    print("Предложения из файла " + fileName + ":" + "\n");
    std::string sentence;
    while (getline(file, sentence))
        print(QString(sentence.c_str()) +"\n");

    file.close();
}

void main_window::saveShipToBinaryFile(const std::string &filename)
{
    std::ofstream file(filename, std::ios::app | std::ios::binary);
    if (!file)
        throw std::runtime_error("");

    athlete obj;
    print("Введите размер ноги: ");
    obj.footSize = input().toInt();
    print("Введите высоту: ");
    obj.height = input().toDouble();
    print("Введите цвет глаз: ");
    obj.eyeColor = input()[0].toLatin1();
    print("Быстрый ли спортсмен (1 - да, 0 - нет): ");
    obj.isFast = input().toInt();
    print("Введите имя (не более " + QString::number(athlete::maxNameLength) + " символов): ");
    obj.name = input().toStdString();
    print("Введите число медалей: ");
    obj.medals = input().toInt();

    file.write(reinterpret_cast<const char*>(&obj), sizeof(athlete) + 1);

    file.close();
}

void main_window::printShipsFromBinaryFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file)
        throw std::runtime_error("");

    athlete ship;
    while (file.read(reinterpret_cast<char*>(&ship), sizeof(athlete))) {
        print(QString::number(ship.footSize) + "|" +
              QString::number(ship.height) + "|" + ship.eyeColor + "|" + QString::number(ship.isFast)
              + "|" + QString::fromStdString(ship.name) + "|" + QString::number(ship.medals) + " ;\n");
    }

    file.close();
}