#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->open_struct_dialog->setEnabled(false);
    ui->open_struct_dialog_for_bin->setEnabled(false);
}

void MainWindow::on_select_case_clicked(){
    int x = ui->comboBox->currentIndex() + 1;

    switch(x)
    {
        case 1: 
            ui->open_struct_dialog_for_bin->setEnabled(false);
            ui->open_struct_dialog->setEnabled(false);
            getAndSaveTextToFile();
            break;
        case 2: 
            ui->open_struct_dialog_for_bin->setEnabled(false);
            ui->open_struct_dialog->setEnabled(false);
            outputTextFromFile();
            break;
        case 3:
            ui->open_struct_dialog_for_bin->setEnabled(false);
            ui->open_struct_dialog->setEnabled(false);
            getArrayAndSaveToFile();
            break;
        case 4:
            ui->open_struct_dialog_for_bin->setEnabled(false);
            ui->open_struct_dialog->setEnabled(false);
            readArrayFromFileAndPrint();
            break;
        case 5:
            ui->open_struct_dialog_for_bin->setEnabled(false);
            ui->open_struct_dialog->setEnabled(true);
            break;
        case 6:
            ui->open_struct_dialog_for_bin->setEnabled(false);
            ui->open_struct_dialog->setEnabled(false);
            readAirportFromFile();
            break;
        case 7:
            ui->open_struct_dialog->setEnabled(false);
            ui->open_struct_dialog_for_bin->setEnabled(true);
            break;
        case 8:
            ui->open_struct_dialog->setEnabled(false);
            ui->open_struct_dialog_for_bin->setEnabled(false);
            readStructuresFromBinaryFile();
            break;
        case 9:
            ui->open_struct_dialog->setEnabled(false);
            ui->open_struct_dialog_for_bin->setEnabled(false);
            appendSentencesToTextFile();
            break;
        case 10:
            ui->open_struct_dialog->setEnabled(false);
            ui->open_struct_dialog_for_bin->setEnabled(false);
            readSentencesFromTextFile();
            break;
        default: 
            qDebug() << "x is undefined" << "\n";
            break;
    }   
}

void MainWindow::getAndSaveTextToFile(){
    QString text = QInputDialog::getText(nullptr, "Ввод текста", "Введите текст:", QLineEdit::Normal);

    QString fileName = "../txtFiles/PetuhovLab60.txt";

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл для записи.";
    }

    QTextStream out(&file);

    for (int i = 0; i < text.length(); ++i) {
        out << text.at(i).unicode();
    }

    file.close();
}

void MainWindow::outputTextFromFile(){
    QString fileName = "../txtFiles/PetuhovLab60.txt";

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось открыть файл для чтения.");
    }

    QTextStream in(&file);

    QString text;
    while (!in.atEnd()) {
        QString character = in.read(1);
        text += character;
    }

    file.close();

    QMessageBox::information(nullptr, "Текст из файла", text);
}

void MainWindow::getArrayAndSaveToFile(){
    QString fileName = "../txtFiles/PetuhovLab60_0.txt";

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось открыть файл для записи.");
    }

    QTextStream out(&file);

    bool ok;
    int size = QInputDialog::getInt(nullptr, "Размер массива", "Введите размер массива:", 0, 0, 20, 1, &ok);
    if (!ok){
      size = QInputDialog::getInt(nullptr, "Размер массива", "Введите размер массива:", 0, 0, 20, 1, &ok);
    }

    QVector<long> array;
    for (int i = 0; i < size; ++i) {
        bool ok;
        int value = QInputDialog::getInt(nullptr, "Значение элемента", QString("Введите значение элемента %1:").arg(i), 0, -1000, 1000, 1, &ok);
        if (!ok)
            return;
        array.append(value);
    }

    for (int i = 0; i < size; ++i) {
        out << array[i];
        if (i != size - 1) {
            out << "~";
        }
    }

    file.close();
}

void MainWindow::readArrayFromFileAndPrint()
{
    QString fileName = "../txtFiles/PetuhovLab60_0.txt";

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось открыть файл для чтения.");
    }

    QTextStream in(&file);

    QVector<long> array;
    while (!in.atEnd()) {
        QString line = in.readLine(); 
        QStringList values = line.split("~");
        for (const QString& value : values) {
            bool ok;
            long intValue = value.toLong(&ok); 
            if (ok) {
                array.append(intValue);
            }
        }
    }

    file.close();

    QString arrayString;
    for (int i = 0; i < array.size(); ++i) {
        arrayString += QString::number(array[i]);
        if (i != array.size() - 1) {
            arrayString += " ";
        }
    }

    QMessageBox::information(nullptr, "Считанный массив", arrayString);
}

void MainWindow::initWithUserInputTxtFile(const int& runwayCount, const double& area, char inputChar, const bool& hasControlTower,
                                    std::string airportName, const QVector<int>& numbers)
{
  
    Airport userInputAirport;

    QString fileName = "../txtFiles/PetuhovLab60_1.txt";

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось открыть файл для записи.");
        return;
    }
    QTextStream out(&file);

    userInputAirport.runwayCount = runwayCount;
    userInputAirport.area = area;
    userInputAirport.airportCode = inputChar;
    userInputAirport.hasControlTower = hasControlTower;

    for(auto i = 0; i < airportName.size(); i++){
        userInputAirport.airportName[i] = airportName[i];
    }

    int sizeWeekYear = 0;
    for(auto i = 0; i < numbers.size(); i++){
        userInputAirport.weekendYears[i] = numbers[i];
        sizeWeekYear++;
    }   

    out << userInputAirport.runwayCount << " ";
    out << userInputAirport.area << " ";
    out << userInputAirport.airportCode << " ";
    out << userInputAirport.hasControlTower << " ";
    for (int i = 0; i < airportName.size(); ++i) {
        out << userInputAirport.airportName[i];
    }
    out << " ";
    for (int i = 0; i < numbers.size(); ++i) {
        out << userInputAirport.weekendYears[i] << " ";
    }
    out << Qt::endl;

    file.close();

}

void MainWindow::readAirportFromFile()
{
    QString fileName = "../txtFiles/PetuhovLab60_1.txt";

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось открыть файл для чтения.");
        return;
    }

    QTextStream in(&file);

    QString messege;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList values = line.split(' ');

        Airport airport;

        if (values.size() < 6) {
            continue; 
        }

        bool ok;
        airport.runwayCount = values[0].toInt(&ok); 
        if (!ok) {
            continue; 
        }

        airport.area = values[1].toDouble(&ok);
        if (!ok) {
            continue;
        }

        airport.airportCode = values[2][0].toLatin1(); 

        airport.hasControlTower = values[3].toInt(&ok); 
        if (!ok) {
            continue; 
        }

        strncpy(airport.airportName, values[4].toUtf8().constData(), sizeof(airport.airportName)); 

        for (int i = 0; i < values.size() - 6; i++) {
            airport.weekendYears[i] = values[5 + i].toInt(&ok);
            if (!ok) {
                continue; 
            }
        }

     messege += QString::number(airport.runwayCount) + " | " + 
                            QString::number(airport.area) + " | " +
                            airport.airportCode + " | "  + 
                            (airport.hasControlTower ? "true" : "false") + "|" +
                            airport.airportName + "|";

        for (int i = 0; i < values.size() - 6; i++) {
            messege += (QString::number(airport.weekendYears[i]) + " ");
        }

        messege += '\n';
    }

    QMessageBox::information(nullptr, "Текст из файла", messege);

    file.close();
}

void MainWindow::initWithUserInputBinFile(const int& runwayCount, const double& area, char inputChar, const bool& hasControlTower,
                                    std::string airportName, const QVector<int>& numbers)
{
    Airport binAirport;

    QString fileName = "../txtFiles/PetuhovLab60_2.bin";

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось открыть файл для записи.");
        return;
    }
    QDataStream out(&file);

    binAirport.runwayCount = runwayCount;
    binAirport.area = area;
    binAirport.airportCode = inputChar;
    binAirport.hasControlTower = hasControlTower;

    auto i = 0;
    for(i = 0; i < airportName.size(); i++){
        binAirport.airportName[i] = airportName[i];
    }
    binAirport.airportName[i] = '\0';

    int sizeWeekYear = 0;
    for(auto i = 0; i < numbers.size(); i++){
        binAirport.weekendYears[i] = numbers[i];
        sizeWeekYear++;
    }   

    out.writeRawData(reinterpret_cast<const char*>(&binAirport), sizeof(Airport));

    file.close();
}

void MainWindow::readStructuresFromBinaryFile()
{
    QString fileName = "../txtFiles/PetuhovLab60_2.bin";

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось открыть файл для чтения.");
        return;
    }

    QDataStream in(&file);

    QString messege;

    while (!in.atEnd()) {
            Airport airport;

        in.readRawData(reinterpret_cast<char*>(&airport), sizeof(Airport));

        messege += QString::number(airport.runwayCount) + " ; " + 
                            QString::number(airport.area) + " ; " +
                            QString(airport.airportCode) + " ; "  + 
                            (airport.hasControlTower ? "true" : "false") + " ; " + 
                            QString(airport.airportName) + " ; ";
        for (int i = 0; i < 10; ++i) {
            messege += QString::number(airport.weekendYears[i]) + " ; ";
        }
        messege += " ||||||| \n";
    }

    QMessageBox::information(nullptr, "Текст из файла", messege);

    file.close();
}

void MainWindow::appendSentencesToTextFile()
{
    QString fileName = "../txtFiles/PetuhovLab60_3.txt";

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось открыть файл для записи.");
        return;
    }

    QTextStream out(&file);

    qDebug() << "Введите предложение:";
    QString sentence = QInputDialog::getText(this, "Ввод", "Предложение:");

    out << sentence << Qt::endl;

    file.close();
}

void MainWindow::readSentencesFromTextFile()
{
    QString fileName = "../txtFiles/PetuhovLab60_3.txt";

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось открыть файл для чтения.");
        return;
    }

    QTextStream in(&file);

    qDebug() << "Содержимое файла " << fileName << ":";

    QString sentences;

    while (!in.atEnd()) {
        sentences += in.readLine() + "\n";
    }

    QMessageBox::information(nullptr, "Предложения из файла", sentences);

    file.close();
}

void MainWindow::on_open_struct_dialog_clicked(){
    Dialog* dialog = new Dialog();
    connect(dialog, &Dialog::textEntered, this, &MainWindow::initWithUserInputTxtFile);
    dialog->exec();
}

void MainWindow::on_open_struct_dialog_for_bin_clicked(){
    Dialog* dialog = new Dialog();
    connect(dialog, &Dialog::textEntered, this, &MainWindow::initWithUserInputBinFile);
    dialog->exec();
}