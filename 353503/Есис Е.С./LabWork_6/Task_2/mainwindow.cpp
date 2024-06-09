#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , stream_in(&text_in)//чтение
    , stream_out(&text_out)//запись
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->lineEdit->setEnabled(false);
   // ui->lineEdit->setUtf8(true);
}

void MainWindow::ShowMenu()
{
    stream_out << menu;//поток вывода, меню отправляется в поток
    ui->textEdit->setText(text_out);
    while (true) {
        QCoreApplication::processEvents();//обработка событий

       // ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()) {
            QCoreApplication::processEvents();
        }
        int choice;
        stream_in >> choice;
        if (stream_in.status() != QTextStream::Ok) {
            text_in.clear();
            stream_in.resetStatus();
        } else {
            text_in.remove(0, stream_in.pos());
            stream_out << choice << '\n';
        }
        stream_in.seek(0);
        ui->lineEdit->setText(text_in);
        PrintMenu(choice);
    }
}

void MainWindow::PrintMenu(int choice)
{
    switch (choice) {
    case 1:
        SaveTextToFile();
        break;
    case 2:
        GetFileContents();
        break;
    case 3:
        SaveArrayToFile();
        break;
    case 4:
        GetArrayContents();
        break;
    case 5:
        SaveAirplaneToFile();
        break;
    case 6:
        GetAirplaneContents();
        break;
    case 7:
        SaveAirplaneToBinaryFile();
        break;
    case 8:
        GetAirplaneFromBinaryFileContents();
        break;
    case 9:
        AddTextToFile();
        break;
    case 10:
        GetStringToFile();
        break;
    case 11:
        //stream_out << "Выход из программы.\n";
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        close();
        break;
    default:
        stream_out <<QString ( "Некорректный ввод. Пожалуйста, выберите пункт меню от 1 до 11.\n");
        ui->textEdit->setText(text_out);
        //ui->textEdit->moveCursor(QTextCursor::End);
    }
    stream_out << "\n";
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
    ui->lineEdit->setReadOnly(true);
}

void MainWindow::SaveTextToFile()
{
    QString fileName = "ЕсисЛаб20.txt";
    QFile file(fileName);
    QTextStream file_stream(&file);
    stream_out <<QString ( "Вы выбрали пункт 1\nВведите абзац текста");
    ui->lineEdit->clear();
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
    text_in.clear();
    ui->lineEdit->setReadOnly(false);

    while (text_in.isEmpty()) {
        QCoreApplication::processEvents();
    }
    ui->lineEdit->setReadOnly(true);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {

        stream_out << QString ("\nНе удалось открыть файл") << fileName << QString ("для записи\n");
    } else {

        for (int i = 0; i < text_in.length(); ++i) {
            file_stream << text_in.at(i);
        }
        text_in.clear();
        ui->lineEdit->setText(text_in);
        stream_in.readAll();
        file_stream << QString ("\nТекст был добавлен в файл\n");
        file.close();
    }
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::GetFileContents()
{
    QString fileName = "ЕсисЛаб20.txt";
    QFile file(fileName);
    QTextStream file_stream(&file);
    stream_out << QString ("Вы выбрали пункт 2 (отображение содержимого файла: ") << fileName<< QString (")\n");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {

        stream_out <<QString ( "\nНе удалось открыть файл") << fileName << QString ("для чтения\n");
    } else {

        while (!file_stream.atEnd()) {
            QChar ch;
            file_stream >> ch;
            stream_out << ch;
        }
        file.close();
    }
    ui->textEdit->setText(text_in);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::SaveArrayToFile()
{
    QString fileName = "ЕсисЛаб20_0.txt";
    QFile file(fileName);
    QTextStream file_stream(&file);
    stream_out <<QString ( "Вы выбрали пункт 3\nВведите размер массива и массив типа short int, разделяя элементы символом пробела\n");
    ui->lineEdit->clear();
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        stream_out <<QString ( "\nНе удалось открыть файл") << fileName << QString ("для запси\n");
    } else {
        stream_out << QString ("Введте размер массива: ");
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        int n;
        stream_in >> n;
        if (stream_in.status() != QTextStream::Ok || n < 0) {
            stream_out << QString ("\nНеверный ввод размера массива\n");
            ui->textEdit->setText(text_out);
            stream_in.resetStatus();
            text_in.clear();
            file.close();
            stream_in.seek(0);
            return;
        }
        else {
            text_in.remove(0, stream_in.pos());
            stream_in.seek(0);
            stream_out << n << '\n';
        }
        ui->lineEdit->setText(text_in);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            short int c;
            stream_out << "Введите " << i+1 << "-й из " << n << " символа(ов) желаемого: ";
            ui->textEdit->setText(text_out);
            ui->textEdit->moveCursor(QTextCursor::End);
            while (text_in.isEmpty()) {
                QCoreApplication::processEvents();
            }
            stream_in >> c;
            if (stream_in.status() != QTextStream::Ok) {
                stream_out << "\nНеверный ввод символа\n";
                stream_in.seek(0);
                stream_in.resetStatus();
                text_in.clear();
                ok = false;
                return;
            }
            else {
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                stream_out << c << '\n';
            }
            ui->lineEdit->setText(text_in);
            file_stream << c << '|';
        }
        file.close();
        if (ok) stream_out << "\nМассив записан в файл " << fileName << "\n";
    }
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::GetArrayContents()
{
    QString fileName = "ЕсисЛаб20_0.txt";
    QFile file(fileName);
    QTextStream file_stream(&file);
    stream_out <<QString ( "Вы выбрали пункт 4 (отображение содержимого файла: ") << fileName << QString (")\n");
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
    QTextStream in(&file);
    in.setCodec("UTF-8");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        stream_out << QString ("\nНе удалось открыть файл") << fileName << QString ("для чтения\n");
    } else {
        while (!file_stream.atEnd()) {
            QString line = file_stream.readLine();
            QStringList charArray = line.split("|", Qt::SkipEmptyParts);
            for (const QString &ch : charArray) {
                stream_out << ch << " ";
            }
            stream_out << "\n";
        }
        file.close();
    }
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::SaveAirplaneToFile()
{
    QString fileName = "ЕсисЛаб20_1.txt";
    QFile file(fileName);
    QTextStream file_stream(&file);
    stream_out <<QString ( "Вы выбрали пункт 5\nВведите данные о рейсе: кол-во пассажиров, кол-во багажа, класс рейса, в данный момент на земле? (0 — нет, 1 — да)\n");
    ui->lineEdit->clear();
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
    ui->lineEdit->setReadOnly(false);
    QTextStream in(&file);
    in.setCodec("UTF-8");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        stream_out << QString ("\nНе удалось открыть файл") << fileName << QString ("для запси\n");
    } else {
        Airplane flight1;
        stream_out << QString ("Введите кол-во пассажиров (int): ");
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        stream_in >> flight1.pasengers;
        if (stream_in.status() != QTextStream::Ok || flight1.pasengers < 0) {
            stream_out << QString ("\nНеверный ввод\n");
            stream_in.resetStatus();
            text_in.clear();
            file.close();
            stream_in.seek(0);
            return;
        } else {
            text_in.remove(0, stream_in.pos());
            stream_in.seek(0);
            stream_out << flight1.pasengers << '\n';
        }
        ui->lineEdit->setText(text_in);
        ui->lineEdit->clear();
        stream_out << QString ("Введите кол-во багажа: ");
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        stream_in >> flight1.bags;
        if (stream_in.status() != QTextStream::Ok || flight1.bags < 0) {
            stream_out <<QString ( "\nНеверный ввод\n");
            stream_in.resetStatus();
            text_in.clear();
            file.close();
            stream_in.seek(0);
            return;
        } else {
            text_in.remove(0, stream_in.pos());
            stream_in.seek(0);
            stream_out << flight1.bags << QString ("$\n");
        }
        ui->lineEdit->setText(text_in);
        ui->lineEdit->clear();
        stream_out << QString ("Введите класс перелёта (например B или C): ");
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        stream_in >> flight1.typeFlight;
        if (stream_in.status() != QTextStream::Ok ) {
            stream_out <<QString ( "\nНеверный ввод\n");
            stream_in.resetStatus();
            text_in.clear();
            file.close();
            stream_in.seek(0);
            return;
        } else {
            text_in.remove(0, stream_in.pos());
            stream_in.seek(0);
            stream_out << flight1.typeFlight << '\n';
        }
        ui->lineEdit->setText(text_in);
        ui->lineEdit->clear();
        stream_out << QString ("Введите самолёт на земле? (0 — нет, 1 — да): ");
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        int consist;
        stream_in >> consist;
        if (stream_in.status() != QTextStream::Ok || (consist != 0 && consist != 1)) {
            stream_out << QString ("\nНеверный ввод\n");
            stream_in.resetStatus();
            text_in.clear();
            file.close();
            stream_in.seek(0);
            return;
        } else {
            flight1.flight = (consist == 1);
            text_in.remove(0, stream_in.pos());
            stream_in.seek(0);
            stream_out << QString (flight1.flight ? "на земле" : "в небе") << '\n';
        }
        ui->lineEdit->setText(text_in);
        file_stream << flight1.pasengers << " " << flight1.bags<< " " << flight1.typeFlight << " " << (flight1.flight ? "1" : "0") << "\n";
        file.close();
    }
    stream_out << QString ("\nДанные о рейсе успешно записаны в файл ") << fileName << "\n";
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::GetAirplaneContents()
{
    QString fileName = "ЕсисЛаб20_1.txt";
    QFile file(fileName);
    QTextStream file_stream(&file);

    stream_out << QString ("Вы выбрали пункт 6\nСодержимое файла ") << fileName << ":\n";
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
    QTextStream in(&file);
    in.setCodec("UTF-8");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        stream_out << "\nНе удалось открыть файл" << fileName << "для чтения\n";
    } else {
        while (!file_stream.atEnd()) {
            QString line = file_stream.readLine();
            QStringList AirplaneData = line.split(" ", Qt::SkipEmptyParts);
            if (AirplaneData.size() != 4) {
                stream_out << "\nНеверный формат строки в файле.\n";
                continue;
            }
            Airplane flight1;
            flight1.pasengers = AirplaneData[0].toInt();
            flight1.bags = AirplaneData[1].toDouble();
            flight1.typeFlight = AirplaneData[2][0].toLatin1();
            flight1.flight = (AirplaneData[3].toInt() != 0);

            stream_out << "Pasengers: " << flight1.pasengers << " | ";
            stream_out << "Bags: " << flight1.bags << " | ";
            stream_out << "Type of flight: " << flight1.typeFlight << " | ";
            stream_out << "on the ground: " << (flight1.flight ? "Да" : "Нет") << "\n";
        }
        file.close();
    }
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
}
/////////////////////////////////////////////////////////////////////////////////////
void MainWindow::SaveAirplaneToBinaryFile()
{
    QString fileName = "ЕсисЛаб20_2.bin";
    std::ofstream file(fileName.toStdString(), std::ios::binary | std::ios::app);

    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
    stream_out << QString ("Вы выбрали пункт 7\nВведите данные о рейсе: кол-во пассажиров, кол-во багажа, класс рейса, в данный момент на земле? (0 — нет, 1 — да)\n");
    ui->lineEdit->clear();
    if (!file.is_open()) {
        stream_out << QString ("\nНе удалось открыть файл") << fileName << "для запси\n";
    } else {
        Airplane plane;
        stream_out << QString ("кол-во пассажиров (int): ");
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        stream_in >> plane.pasengers;
        if (stream_in.status() != QTextStream::Ok || plane.pasengers < 0) {
            stream_out << "\nНеверный ввод\n";
            stream_in.resetStatus();
            text_in.clear();
            file.close();
            stream_in.seek(0);
            return;
        } else {
            text_in.remove(0, stream_in.pos());
            stream_in.seek(0);
            stream_out << plane.pasengers << '\n';
        }
        ui->lineEdit->setText(text_in);
        ui->lineEdit->clear();


        stream_out << QString ("Введите кол-во багажа(int): ");
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        stream_in >> plane.bags;
        if (stream_in.status() != QTextStream::Ok || plane.bags < 0) {
            stream_out << "Неверный ввод\n";
            stream_in.resetStatus();
            text_in.clear();
            file.close();
            stream_in.seek(0);
            return;
        } else {
            text_in.remove(0, stream_in.pos());
            stream_in.seek(0);
            stream_out << plane.bags << "$\n";
        }
        ui->lineEdit->setText(text_in);
        ui->lineEdit->clear();
        stream_out <<QString ( "Введите класс полёта (например B или C): ");
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        stream_in >> plane.typeFlight;
        if (stream_in.status() != QTextStream::Ok ) {
            stream_out << "\nНеверный ввод\n";
            stream_in.resetStatus();
            text_in.clear();
            file.close();
            stream_in.seek(0);
            return;
        } else {
            text_in.remove(0, stream_in.pos());
            stream_in.seek(0);
            stream_out << plane.typeFlight << '\n';
        }
        ui->lineEdit->setText(text_in);
        ui->lineEdit->clear();
        stream_out << QString ("Введите является ли новым (0 — нет, 1 — да): ");
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        int condition;
        stream_in >> condition;
        if (stream_in.status() != QTextStream::Ok || (condition != 0 && condition != 1)) {
            stream_out << "\nНеверный ввод\n";
            stream_in.resetStatus();
            text_in.clear();
            file.close();
            stream_in.seek(0);
            return;
        } else {
            plane.flight = (condition == 1);
            text_in.remove(0, stream_in.pos());
            stream_in.seek(0);
            stream_out << (plane.flight ? "на земле" : "в небе") << '\n';
        }
        ui->lineEdit->setText(text_in);

        file.write(reinterpret_cast<const char*>(&plane), sizeof(plane));
        file.close();
    }
    ui->textEdit->setText(text_out);
    stream_out << QString ("Данные о рейсе успешно записаны в бинарный файл ") << fileName << "\n";
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::GetAirplaneFromBinaryFileContents()
{
    QString fileName = "ЕсисЛаб20_2.bin";
    std::ifstream file(fileName.toStdString(), std::ios::binary);
    stream_out << QString ("Вы выбрали пункт 8\nСодержимое файла ") << fileName << ":\n";
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);

    if (!file.is_open()) {
        stream_out << "\nНе удалось открыть файл" << fileName << "для чтения\n";
    } else {
        Airplane plane;
        while (!file.eof()) {
            file.read(reinterpret_cast<char*>(&plane), sizeof(plane));
            QString fileName = "StasiukLab6_2.bin";
            std::ifstream file(fileName.toStdString(), std::ios::binary);
            stream_out << QString ("Вы выбрали пункт 8\nСодержимое файла ") << fileName << ":\n";
            ui->textEdit->setText(text_out);
            ui->textEdit->moveCursor(QTextCursor::End);

            if (!file.is_open()) {
                stream_out << QString ("\nНе удалось открыть файл") << fileName <<QString ( "для чтения\n");
            } else {
                Airplane plane;
                while (!file.eof()) {
                    file.read(reinterpret_cast<char*>(&plane), sizeof(plane));//оператор позволяет преобразовывать указатели одного типа в указатели другого типа
                    if (file.eof()) break;
                    stream_out << QString ("кол-во пассажиров: ") << plane.pasengers << "; ";
                    stream_out << QString ("кол-во багажа : ") << plane.bags << "$; ";
                    stream_out << QString ("Класс рейса: ") << plane.typeFlight << "; ";
                    stream_out << QString ("На земле?: ") <<QString  (plane.flight ? "Да" : "Нет") << "\n";
                }
                file.close();
            }

            ui->textEdit->setText(text_out);
            ui->textEdit->moveCursor(QTextCursor::End);
        }
    }
}

void MainWindow::AddTextToFile()
{
    QString fileName = "ЕсисЛаб20_3.txt";
    QFile file(fileName);
    QTextStream file_stream(&file);
    stream_out <<QString ( "Вы выбрали пункт 9\nВведите текст для добавления в файл ") << fileName << "\n";
    ui->lineEdit->clear();
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
    ui->lineEdit->setReadOnly(false);
    while (text_in.isEmpty()) {
        QCoreApplication::processEvents();
    }
    ui->lineEdit->setReadOnly(true);

    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        stream_out << "\nНе удалось открыть файл" << fileName << "для записи\n";
    } else {
        file_stream << text_in << "\n";
        file.close();
        text_in.clear();
        ui->lineEdit->setText(text_in);
        stream_in.readAll();
        stream_out << QString ("Текст успешно добавлен в файл ") << fileName << "\n";
    }

    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::GetStringToFile()
{
    QString fileName = "ЕсисЛаб20_3.txt";
    QFile file(fileName);
    QTextStream file_stream(&file);
    stream_out << QString ("Вы выбрали пункт 10 (построчно считать из текстового файла ") << fileName << QString (" все предложения и вывести их на экран)\n");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        stream_out << "\nНе удалось открыть файл" << fileName << "для чтения\n";
    } else {
        while (!file_stream.atEnd()) {
            QChar ch;
            file_stream >> ch;
            stream_out << ch;
        }
        file.close();
    }
    ui->textEdit->setText(text_in);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::on_lineEdit_returnPressed()
{
    if (!ui->lineEdit->isReadOnly())
        text_in += ui->lineEdit->text();
}


void MainWindow::on_menu_clicked()
{
    ui->lineEdit->setEnabled(true);
    ShowMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}
