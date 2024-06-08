#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    menu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::WriteAndSaveText()
{
    bool ok = false;
    QString text;
    QString inputText = QInputDialog::getText(nullptr,
                                         "Введите абзац",
                                         "Введите строку и завершите линию символом конца строки",
                                         QLineEdit::Normal, "", &ok);
    if (ok)
    {
        text = inputText;
    }

    QFile file(FILENAME);
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Не могу открыть файл для записи!\n";
        file.close();
        return;
    }
    QTextStream out(&file);
    for (int i = 0; i < text.size(); ++i)
    {
        out << text.at(i);
    }
    out << "\n";
    file.close();
}

void MainWindow::ReadText()
{
    QFile file(FILENAME);
    QTextStream in(&file);

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString text;
    while(!in.atEnd()){
        QChar symbol;
        in >> symbol;
        text += symbol;
    }
    file.close();
    QMessageBox::information(this, "Текст в файле", text);
}

void MainWindow::WriteAndSaveArray()
{
    bool pushed = false;

    QFile file(FILEFORARRAY);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(nullptr, "Ошибка", "Не удалось открыть файл для записи");
        return;
    }

    QTextStream out(&file);

    int size = QInputDialog::getInt(nullptr, "Размер массива", "Введите размер массива", 0, 1, INT_MAX, 1, &pushed);

    if (!pushed)
    {
        file.close();
        return;
    }

    for (int i = 0; i < size; ++i)
    {
        bool ok;
        long int number = QInputDialog::getInt(nullptr, "Элемент массива",
                                               "Введите элемент массива (число должно быть long int)", 0, INT_MIN, INT_MAX, 1, &ok);

        if (!ok)
        {
            QMessageBox::warning(nullptr, "Ошибка", "Некорректный ввод. Попробуйте снова");
            --i;
            continue;
        }

        out << number;

        if (i < size - 1)
        {
            out << separator;
        }
    }

    file.close();
}

void MainWindow::ReadArray()
{
    QFile file(FILEFORARRAY);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для чтения");
        return;
    }

    QTextStream in(&file);

    QString text;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        text += line.replace(separator, ' ');
    }

    file.close();
    QMessageBox::information(this, "Числа в файле", text);
}

void MainWindow::WriteAndSaveStructTXT()
{
    // D - Дорожные мотоциклы (Street Bikes)
    // S - Спортивные мотоциклы (Sport Bikes)
    // C - Круизеры (Cruisers)
    // E - Эндуро и Кроссовые мотоциклы (Enduro/Motocross)
    // T - Туристические мотоциклы (Touring)
    // M - Минибайки (Mini-bikes)

    QFile file(FILEFORSTRUCTS);
    QTextStream in(&file);
    file.open(QIODevice::Append | QIODevice::Text);

    std::string s = QInputDialog::getText(nullptr, "Заполнение структуры [1/6]", "Введите бренд мотоцикла").toStdString();
    while (s.size() >= 20 || s.empty())
    {
        QMessageBox::warning(nullptr, "Ошибка", "Некорректный ввод. Введите заново");
        s = QInputDialog::getText(nullptr, "Заполнение структуры [1/6]", "Введите бренд мотоцикла").toStdString();
    }

    strncpy(motorcycle.brand, s.c_str(), 19);
    motorcycle.brand[19] = '\0';

    s = QInputDialog::getText(nullptr, "Заполнение структуры [2/6]", motoTypesDiscription).toStdString();
    while (s.size() != 1 || (s[0] != 'D' && s[0] != 'S' && s[0] != 'C' && s[0] != 'E'))
    {
        QMessageBox::warning(nullptr, "Ошибка", "Некорректный ввод. Введите заново");
        s = QInputDialog::getText(nullptr, "Заполнение структуры [2/6]", motoTypesDiscription).toStdString();
    }
    motorcycle.category = s[0];

    s = QInputDialog::getText(nullptr, "Заполнение структуры [3/6]", "Введите объем двигателя (>0)").toStdString();
    while (s.empty() || !std::all_of(s.begin(), s.end(), ::isdigit))
    {
        QMessageBox::warning(nullptr, "Ошибка", "Некорректный ввод. Введите заново");
        s = QInputDialog::getText(nullptr, "Заполнение структуры [3/6]", "Введите объем двигателя (>0)").toStdString();
    }
    motorcycle.engineCapacity = std::stoi(s);

    s = QInputDialog::getText(nullptr, "Заполнение структуры [4/6]", "Введите расход топлива (>0)").toStdString();
    while (s.empty() || !std::all_of(s.begin(), s.end(), ::isdigit))
    {
        QMessageBox::warning(nullptr, "Ошибка", "Некорректный ввод. Введите заново");
        s = QInputDialog::getText(nullptr, "Заполнение структуры [4/6]", "Введите расход топлива (>0)").toStdString();
    }
    motorcycle.fuelConsumption = std::stod(s);

    s = QInputDialog::getText(nullptr, "Заполнение структуры [5/6]", "Является ли мотоцикл электрическим? (1 - да, 0 - нет)").toStdString();
    while (s != "0" && s != "1")
    {
        QMessageBox::warning(nullptr, "Ошибка", "Некорректный ввод. Введите заново");
        s = QInputDialog::getText(nullptr, "Заполнение структуры [5/6]", "Является ли мотоцикл электрическим? (1 - да, 0 - нет)").toStdString();
    }
    motorcycle.is_electric = std::stoi(s);

    for (int i = 2023; i > 2018; --i)
    {
        s = QInputDialog::getText(nullptr, "Заполнение структуры [6/6]", "Введите пробег за год " + QString::number(i)).toStdString();
        while (s.empty() || !std::all_of(s.begin(), s.end(), ::isdigit))
        {
            QMessageBox::warning(nullptr, "Ошибка", "Некорректный ввод. Введите заново");
            s = QInputDialog::getText(nullptr, "Заполнение структуры [6/6]", "Введите пробег за год " + QString::number(i)).toStdString();
        }
        motorcycle.mileageByYear[2023 - i] = std::stoi(s);
    }

    QString text = "\n";
    text += motorcycle.brand;
    text += " " + QString(motorcycle.category);
    text += " " + QString::number(motorcycle.engineCapacity);
    text += " " + QString::number(motorcycle.fuelConsumption);
    if (motorcycle.is_electric) {
        text += "Да";
        text += ';';
    }
    else {
        text += "Нет";
        text += ';';
    }

    for (int i = 0; i < 5; ++i)
    {
        text += " " + QString::number(motorcycle.mileageByYear[i]);
    }

    in << text;
    file.close();
    QMessageBox::information(this, "Файл сохранен", "Данные успешно сохранены");
}

void MainWindow::ReadStructTXT()
{
    QFile file(FILEFORSTRUCTS);
    QTextStream in(&file);

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QString text;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList data = line.split(" ", Qt::SkipEmptyParts);

        if (data.size() == 0)
            continue;

        if (data.size() != 10 || data[0].size() > 19 || !(data[1] == "D" || data[1] == "S" || data[1] == "C" || data[1] == "E") ||
            !data[2].toInt() || !data[3].toDouble() || (data[4] != "0" && data[4] != "1") ||
            !data[5].toInt() || !data[6].toInt() || !data[7].toInt() || !data[8].toInt() || !data[9].toInt())
        {
            QMessageBox::warning(nullptr, "Ошибка", "Некорректный формат данных");
            return;
        }

        strncpy(motorcycle.brand, data[0].toStdString().c_str(), 19);
        motorcycle.brand[19] = '\0';

        motorcycle.category = data[1][0].toLatin1();
        motorcycle.engineCapacity = data[2].toInt();
        motorcycle.fuelConsumption = data[3].toDouble();
        motorcycle.is_electric = data[4].toInt();
        for (int i = 0; i < 5; ++i)
        {
            motorcycle.mileageByYear[i] = data[5 + i].toInt();
        }

        text += data[0] + "|" + data[1] + "|" + data[2] + "|" + data[3] + "|" + data[4] + "|";
        for (int i = 0; i < 5; ++i)
        {
            text += data[5 + i] + (i < 4 ? "|" : "\n");
        }
    }
    file.close();
    QMessageBox::information(this, "Text in file", text);
}

void MainWindow::WriteAndSaveStructBIN()
{
    QFile file(FILEBIN);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для записи");
        return;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_15);

    std::string s = QInputDialog::getText(nullptr, "Заполнение структуры [1/7]", "Введите бренд мотоцикла").toStdString();
    while (s.size() >= 20 || s.empty())
    {
        QMessageBox::warning(nullptr, "Ошибка", "Некорректный ввод. Введите заново");
        s = QInputDialog::getText(nullptr, "Заполнение структуры [1/7]", "Введите бренд мотоцикла").toStdString();
    }
    strncpy(motorcycle.brand, s.c_str(), 19);
    motorcycle.brand[19] = '\0';

    QString motoTypesDescription = "Введите категорию мотоцикла (D - дорожный, S - спортивный, C - кроссовый, E - эндуро)";
    s = QInputDialog::getText(nullptr, "Заполнение структуры [2/7]", motoTypesDescription).toStdString();
    while (!(s == "D" || s == "S" || s == "C" || s == "E"))
    {
        QMessageBox::warning(nullptr, "Ошибка", "Некорректный ввод. Введите заново");
        s = QInputDialog::getText(nullptr, "Заполнение структуры [2/7]", motoTypesDescription).toStdString();
    }
    motorcycle.category = s[0];

    s = QInputDialog::getText(nullptr, "Заполнение структуры [3/7]", "Введите объем двигателя").toStdString();
    while (s.empty() || !std::all_of(s.begin(), s.end(), ::isdigit))
    {
        QMessageBox::warning(nullptr, "Ошибка", "Некорректный ввод. Введите заново");
        s = QInputDialog::getText(nullptr, "Заполнение структуры [3/7]", "Введите объем двигателя").toStdString();
    }
    motorcycle.engineCapacity = std::stoi(s);

    s = QInputDialog::getText(nullptr, "Заполнение структуры [4/7]", "Введите расход топлива").toStdString();
    while (s.empty() || !(std::all_of(s.begin(), s.end(), ::isdigit) || s.find('.') != std::string::npos))
    {
        QMessageBox::warning(nullptr, "Ошибка", "Некорректный ввод. Введите заново");
        s = QInputDialog::getText(nullptr, "Заполнение структуры [4/7]", "Введите расход топлива").toStdString();
    }
    motorcycle.fuelConsumption = std::stod(s);

    s = QInputDialog::getText(nullptr, "Заполнение структуры [5/7]", "Является ли мотоцикл электрическим? (1 - да, 0 - нет)").toStdString();
    while (!(s == "0" || s == "1"))
    {
        QMessageBox::warning(nullptr, "Ошибка", "Некорректный ввод. Введите заново");
        s = QInputDialog::getText(nullptr, "Заполнение структуры [5/7]", "Является ли мотоцикл электрическим? (1 - да, 0 - нет)").toStdString();
    }
    motorcycle.is_electric = std::stoi(s);

    for (int i = 2023; i > 2018; --i)
    {
        s = QInputDialog::getText(nullptr, "Заполнение структуры [6/7]", "Введите пробег за год " + QString::number(i)).toStdString();
        while (s.empty() || !std::all_of(s.begin(), s.end(), ::isdigit))
        {
            QMessageBox::warning(nullptr, "Ошибка", "Некорректный ввод. Введите заново");
            s = QInputDialog::getText(nullptr, "Заполнение структуры [6/7]", "Введите пробег за год " + QString::number(i)).toStdString();
        }
        motorcycle.mileageByYear[2023 - i] = std::stoi(s);
    }

    out.writeRawData(reinterpret_cast<const char*>(&motorcycle), sizeof(Motorcycle));
    file.close();
    QMessageBox::information(this, "Файл сохранен", "Данные успешно сохранены");
}

void MainWindow::ReadStructBIN()
{
    QFile file(FILEBIN);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл");
        return;
    }

    QDataStream in(&file);

    QString text;

    while (!in.atEnd()) {
        in.readRawData(reinterpret_cast<char*>(&motorcycle), sizeof(Motorcycle));

        text += QString(motorcycle.brand) + ';';
        text += QChar(motorcycle.category) + ';';
        text += QString::number(motorcycle.engineCapacity) + ";";
        text += QString::number(motorcycle.fuelConsumption) + ";";
        if (motorcycle.is_electric) {
            text += "Да";
            text += ';';
        }
        else {
            text += "Нет";
            text += ';';
        }

        for (int i = 0; i < 5; ++i) {
            text += QString::number(motorcycle.mileageByYear[i]);
            if (i != 4) text += ",";
        }
        text += "\n";
    }

    file.close();
    QMessageBox::information(this, "Содержимое файла", text);
}

void MainWindow::WriteAndSaveSentences()
{
    QString text = QInputDialog::getText(nullptr, "Ввод текста", "Напишите текст. Для завершения ввода нажмите Enter");
    QFile file(FILESENTENSES);
    QTextStream in(&file);
    file.open(QIODevice::Append | QIODevice::Text);

    in << text << '\n';
    file.close();
    QMessageBox::information(this, "Файл сохранен", "Данные успешно сохранены");
}

void MainWindow::ReadSentences()
{
    QFile file(FILESENTENSES);
    QTextStream in(&file);

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString text;
    while(!in.atEnd()){
        QString line = in.readLine();
        text += line;
    }
    file.close();
    QMessageBox::information(this, "Текст в файле", text);
}

void MainWindow::menu()
{
    int choosedFunction;
    while(true)
    {
        bool pushed = false;
        choosedFunction = QInputDialog::getInt(nullptr, "Выберите функцию",   "1. Напишите и сохраните текст\n"
                                                              "2. Чтение текста из файла\n"
                                                              "3. Напишите и сохраните массив символов\n"
                                                              "4. Читать массив из файла\n"
                                                              "5. Напишите и сохраните структуру в текстовом файле.\n"
                                                              "6. Чтение структуры текстового файла\n"
                                                              "7. Запишите и сохраните структуру в двоичный файл.\n"
                                                              "8. Чтение структуры из двоичного файла\n"
                                                              "9. Напишите и сохраните новое предложение\n"
                                                              "10. Прочитать все предложения из файла\n"
                                                              "11. Выход\n\n Напишите номер функции:", 0, 1, 11, 1, &pushed);
        switch(choosedFunction)
        {
        case 1:
            WriteAndSaveText();
            break;
        case 2:
            ReadText();
            break;
        case 3:
            WriteAndSaveArray();
            break;
        case 4:
            ReadArray();
            break;
        case 5:
            WriteAndSaveStructTXT();
            break;
        case 6:
            ReadStructTXT();
            break;
        case 7:
            WriteAndSaveStructBIN();
            break;
        case 8:
            ReadStructBIN();
            break;
        case 9:
            WriteAndSaveSentences();
            break;
        case 10:
            ReadSentences();
            break;
        case 11:
            exit(0);
            break;
        default:
            break;
        }
    }
}
