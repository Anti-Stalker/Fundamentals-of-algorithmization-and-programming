#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "computer.h"
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , inputStream(&textInput)
    , outputStream(&textOutput)
{
    ui->setupUi(this);
    checkFilesAvailable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mainMenu()
{
    while (true) {
        QCoreApplication::processEvents();
        outputStream << menu;
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()) {
            QCoreApplication::processEvents();
        }
        int func;
        inputStream >> func;
        if (inputStream.status() != QTextStream::Ok) {
            textInput.clear();
            inputStream.resetStatus();
        } else {
            textInput.remove(0, inputStream.pos());
            outputStream << func << '\n';
        }
        inputStream.seek(0);
        ui->lineEdit->setText(textInput);

        QString fileName;
        switch (func) {
        case 1:
            fileName = "BorovikovLab6.txt";
            saveData(fileName);
            break;
        case 2:
            fileName = "BorovikovLab6.txt";
            streamFileData(fileName);
            break;
        case 3:
            fileName = "BorovikovLab6_0.txt";
            saveShortIntArray(fileName);
            break;
        case 4:
            fileName = "BorovikovLab6_0.txt";
            streamFileDataCharArray(fileName);
            break;
        case 5:
            fileName = "BorovikovLab6_1.txt";
            saveStructData(fileName);
            break;
        case 6:
            fileName = "BorovikovLab6_1.txt";
            streamFileDataStruct(fileName);
            break;
        case 7:
            fileName = "BorovikovLab6_2.bin";
            saveStructBin(fileName);
            break;
        case 8:
            fileName = "BorovikovLab6_2.bin";
            streamBinFileDataStruct(fileName);
            break;
        case 9:
            fileName = "BorovikovLab6_3.txt";
            textFile(fileName);
            break;
        case 10:
            fileName = "BorovikovLab6_3.txt";
            streamFileData(fileName);
            break;
        case 11:
            outputStream << "Выход из программы.\n";
            ui->textEdit->setText(textOutput);
            ui->textEdit->moveCursor(QTextCursor::End);
            close();
            break;
        default:
            outputStream << "Некорректный ввод. Пожалуйста, выберите пункт меню от 1 до 11.\n";
            ui->textEdit->setText(textOutput);
            ui->textEdit->moveCursor(QTextCursor::End);
        }
        outputStream << "\n";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(true);
    }
}

void MainWindow::checkFilesAvailable()
{
    QStringList filesToCreate = {"BorovikovLab6.txt", "BorovikovLab6_0.txt", "BorovikovLab6_1.txt", "BorovikovLab6_2.bin", "BorovikovLab6_3.txt"};
    for (const QString &fileName : filesToCreate) {
        QFile file(fileName);
        if (!file.exists()) {
            if (!file.open(QIODevice::WriteOnly)) {
                qDebug() << "\nНе удалось создать файл" << fileName;
            }
            file.close();
        }
    }
}

void MainWindow::saveData(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);
    outputStream << "Вы выбрали пункт 1\nВведите абзац текста";
    ui->lineEdit->clear();
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
    textInput.clear();
    ui->lineEdit->setReadOnly(false);
    while (textInput.isEmpty()) {
        QCoreApplication::processEvents();
    }
    ui->lineEdit->setReadOnly(true);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для записи\n";
    } else {
        for (int i = 0; i < textInput.length(); ++i) {
            fileStream << textInput.at(i);
        }
        textInput.clear();
        ui->lineEdit->setText(textInput);
        inputStream.readAll();
        outputStream << "\nТекст был добавлен в файл\n";
        file.close();
    }
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::streamFileData(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);
    outputStream << "Вы выбрали пункт для отображения содержимого файла: " << fileName << "\n";
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для чтения\n";
    } else {
        while (!fileStream.atEnd()) {
            QChar ch;
            fileStream >> ch;
            outputStream << ch;
        }
        file.close();
    }
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::saveShortIntArray(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);
    outputStream << "Вы выбрали пункт 3\nВведите размер массива и массив типа short int, разделяя элементы символом ?\n";
    ui->lineEdit->clear();
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для запси\n";
    } else {
        outputStream << "Введте размер массива";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        int n;
        inputStream >> n;
        if (inputStream.status() != QTextStream::Ok || n < 0) {
            outputStream << "\nНеверный ввод размера массива\n";
            ui->textEdit->setText(textOutput);
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        }
        else {
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << n << '\n';
        }
        ui->lineEdit->setText(textInput);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            int c;
            outputStream << "Введите " << i+1 << "-й из " << n << " элементов";
            ui->textEdit->setText(textOutput);
            ui->textEdit->moveCursor(QTextCursor::End);
            while (textInput.isEmpty()) {
                QCoreApplication::processEvents();
            }
            inputStream >> c;
            if (inputStream.status() != QTextStream::Ok) {
                outputStream << "\nНеверный ввод символа\n";
                inputStream.seek(0);
                inputStream.resetStatus();
                textInput.clear();
                ok = false;
                return;
            }
            else {
                textInput.remove(0, inputStream.pos());
                inputStream.seek(0);
                outputStream << c << '\n';
            }
            ui->lineEdit->setText(textInput);
            fileStream << c << '?';
        }
        file.close();
        if (ok) outputStream << "\nМассив записан в файл " << fileName << "\n";
    }
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::streamFileDataCharArray(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);
    outputStream << "Вы выбрали пункт 4\nСодержимое файла " << fileName << ":\n";
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для чтения\n";
    } else {
        while (!fileStream.atEnd()) {
            QString line = fileStream.readLine();
            QStringList charArray = line.split(":", Qt::SkipEmptyParts);
            for (const QString &ch : charArray) {
                outputStream << ch << " ";
            }
            outputStream << "\n";
        }
        file.close();
    }
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::saveStructData(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);
    outputStream << "Вы выбрали пункт 5\nВведите данные об компьютере: объем оперативной памяти,скорость процессора, начальную букву бренда, является ли компьютер ноутбуком  (0 или 1)\n";
    ui->lineEdit->clear();
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
    ui->lineEdit->setReadOnly(false);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для запси\n";
    } else {
        Computer computer;
        outputStream << "Введте объем оперативной памяти(int)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        inputStream >> computer.ramSizeGB;
        if (inputStream.status() != QTextStream::Ok || computer.ramSizeGB < 0) {
            outputStream << "\nНеверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << computer.ramSizeGB << '\n';
        }
        ui->lineEdit->setText(textInput);
        ui->lineEdit->clear();
        outputStream << "Введте скорость процессора(double)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        inputStream >> computer.cpuSpeedGHz;
        if (inputStream.status() != QTextStream::Ok || computer.cpuSpeedGHz < 0) {
            outputStream << "\nНеверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << computer.cpuSpeedGHz << '\n';
        }
        ui->lineEdit->setText(textInput);
        ui->lineEdit->clear();
        outputStream << "Введите начальную букву бренда (Char)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        inputStream >> computer.brandInitial;
        if (inputStream.status() != QTextStream::Ok ) {
            outputStream << "\nНеверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << computer.brandInitial << '\n';
        }
        ui->lineEdit->setText(textInput);
        ui->lineEdit->clear();
        outputStream << "Является ли ноутбуком(0 или 1)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        int b;
        inputStream >> b;
        if (inputStream.status() != QTextStream::Ok || (b != 0 && b != 1)) {
            outputStream << "\nНеверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            computer.isLaptop = (b == 1);
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << (computer.isLaptop ? "Есть" : "Нет") << '\n';
        }
        ui->lineEdit->setText(textInput);
        fileStream << computer.ramSizeGB << " " << computer.cpuSpeedGHz << " " << computer.brandInitial << " " << (computer.isLaptop ? "1" : "0") << "\n";
        file.close();
    }
    outputStream << "\nДанные успешно записаны в файл " << fileName << "\n";
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::streamFileDataStruct(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);
    outputStream << "Вы выбрали пункт 6\nСодержимое файла " << fileName << ":\n";
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для чтения\n";
    } else {
        while (!fileStream.atEnd()) {
            QString line = fileStream.readLine();
            QStringList carShopData = line.split(" ", Qt::SkipEmptyParts);
            if (carShopData.size() != 4) {
                outputStream << "\nНеверный формат строки в файле.\n";
                continue;
            }
            Computer computer_1;
            computer_1.ramSizeGB = carShopData[0].toInt();
            computer_1.cpuSpeedGHz = carShopData[1].toDouble();
            computer_1.brandInitial = carShopData[2][0].toLatin1();
            computer_1.isLaptop = (carShopData[3].toInt() != 0);

            outputStream << "Объем оперативной памяти: " << computer_1.ramSizeGB << " ; ";
            outputStream << "Скорость процессора: " << computer_1.cpuSpeedGHz << " ; ";
            outputStream << "Начальная буква бренда: " << computer_1.brandInitial << " ; ";
            outputStream << "Является ли компьютер ноутбуком: " << (computer_1.isLaptop ? "Да" : "Нет") << "\n";
        }
        file.close();
    }
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::saveStructBin(const QString &fileName)
{
    std::ofstream file(fileName.toStdString(), std::ios::binary | std::ios::app);
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
    outputStream << "Вы выбрали пункт 5\nВведите данные об Введите данные об компьютере: объем оперативной памяти,скорость процессора, начальную букву бренда, является ли компьютер ноутбуком  (0 или 1)\n";
    ui->lineEdit->clear();
    if (!file.is_open()) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для запси\n";
    } else {
        Computer computer_2;
        outputStream << "Введите объем оперативной памяти(int)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        inputStream >> computer_2.ramSizeGB;
        if (inputStream.status() != QTextStream::Ok || computer_2.ramSizeGB < 0) {
            outputStream << "\nНеверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << computer_2.ramSizeGB << '\n';
        }
        ui->lineEdit->setText(textInput);
        ui->lineEdit->clear();
        outputStream << "Введите скорость процессора(double)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        inputStream >> computer_2.cpuSpeedGHz;
        if (inputStream.status() != QTextStream::Ok || computer_2.cpuSpeedGHz < 0) {
            outputStream << "Неверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << computer_2.cpuSpeedGHz << '\n';
        }
        ui->lineEdit->setText(textInput);
        ui->lineEdit->clear();
        outputStream << "Введите начальную букву бренда(Char)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        inputStream >> computer_2.brandInitial;
        if (inputStream.status() != QTextStream::Ok ) {
            outputStream << "\nНеверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << computer_2.brandInitial << '\n';
        }
        ui->lineEdit->setText(textInput);
        ui->lineEdit->clear();
        outputStream << "Введте является ли ноутбуком(0 или 1)";
        ui->textEdit->setText(textOutput);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (textInput.isEmpty()){
            QCoreApplication::processEvents();
        }
        int b;
        inputStream >> b;
        if (inputStream.status() != QTextStream::Ok || (b != 0 && b != 1)) {
            outputStream << "\nНеверный ввод\n";
            inputStream.resetStatus();
            textInput.clear();
            file.close();
            inputStream.seek(0);
            return;
        } else {
            computer_2.isLaptop = (b == 1);
            textInput.remove(0, inputStream.pos());
            inputStream.seek(0);
            outputStream << (computer_2.isLaptop ? "Да" : "Нет") << '\n';
        }
        ui->lineEdit->setText(textInput);

        file.write(reinterpret_cast<const char*>(&computer_2), sizeof(computer_2));
        file.close();
    }
    ui->textEdit->setText(textOutput);
    outputStream << "Данные о компьютере успешно записаны в бинарный файл " << fileName << "\n";
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::streamBinFileDataStruct(const QString &fileName)
{
    std::ifstream file(fileName.toStdString(), std::ios::binary);
    outputStream << "Вы выбрали пункт 8\nСодержимое файла " << fileName << ":\n";
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);

    if (!file.is_open()) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для чтения\n";
    } else {
        Computer computer_3;
        while (!file.eof()) {
            file.read(reinterpret_cast<char*>(&computer_3), sizeof(computer_3));
            if (file.eof()) break;
            outputStream << "Объем оперативной памяти: " << computer_3.ramSizeGB << " ; ";
            outputStream << "Скорость процессора: " << computer_3.cpuSpeedGHz << " ; ";
            outputStream << "Начальная буква бренда: " << computer_3.brandInitial << " ; ";
            outputStream << "Является ли компьютер ноутбуком: " << (computer_3.isLaptop ? "Да" : "Нет") << "\n";
        }
        file.close();
    }

    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::textFile   (const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);
    outputStream << "Вы выбрали пункт 9\nВведите текст для добавления в файл " << fileName;
    ui->lineEdit->clear();
    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
    ui->lineEdit->setReadOnly(false);
    while (textInput.isEmpty()) {
        QCoreApplication::processEvents();
    }
    ui->lineEdit->setReadOnly(true);

    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        outputStream << "\nНе удалось открыть файл" << fileName << "для записи\n";
    } else {
        fileStream << textInput << "\n";
        file.close();
        textInput.clear();
        ui->lineEdit->setText(textInput);
        inputStream.readAll();
        outputStream << "Текст успешно добавлен в файл " << fileName << "\n";
    }

    ui->textEdit->setText(textOutput);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::on_lineEdit_returnPressed()
{
    if (!ui->lineEdit->isReadOnly()) {
        textInput += ui->lineEdit->text();
    }
}

