#include "mainwindow.h"
#include "worker.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QTextStream>
#include <QFile>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , stream_in(&text_in)
    , stream_out(&text_out)
{
    ui->setupUi(this);
    auto timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::aaa);
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_returnPressed()
{
    if (!ui->lineEdit->isReadOnly())
        text_in += ui->lineEdit->text();
}

void MainWindow::aaa()
{
    auto& out = *ui->textEdit;
    auto& in = *ui->lineEdit;

    while (true) {
        QCoreApplication::processEvents();

        stream_out << "Меню:\n1. Записать абзац в файл.\n"
                             "2. Читать абзац из файла.\n"
                             "3. Записать массив в файл.\n"
                             "4. Читать массив из файла.\n"
                             "5. Записать структуру в файл.\n"
                             "6. Читать структуру из файла.\n"
                             "7. Записать структуру в бинарный файл.»\n"
                             "8. Читать структуру из бинарного файла.\n"
                             "9. Записать предложение в файл.\n"
                             "10. Читать предложение из файла.\n"
                             "11. Выход\n"
                             "Выберите пункт меню: ";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        in.setReadOnly(false);
        while (text_in.isEmpty()){
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
        in.setText(text_in);
        processMenuChoice(choice);
    }
}

void MainWindow::processMenuChoice(int choice) {
    auto& out = *ui->textEdit;
    auto& in = *ui->lineEdit;
    switch (choice) {
    case 1:
    {
        QString fileName = "ЛебедеваЛаб20.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        stream_out << "Введите абзац текста\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        text_in.clear();
        in.setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        in.setReadOnly(true);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            stream_out << "Не удалось открыть файл" << fileName << "для записи\n";
        } else {
            for (int i = 0; i < text_in.length(); ++i) {
                file_stream << text_in.at(i);
            }
            file.close();
            text_in.clear();
            in.setText(text_in);
            stream_in.readAll();
            stream_out << "Текст успешно записан в файл\n";
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 2:
    {
        QString fileName = "ЛебедеваЛаб20.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        stream_out << "Содержимое файла:\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            stream_out << "Не удалось открыть файл" << fileName << "для чтения\n";
        } else {
            while (!file_stream.atEnd()) {
                QChar character;
                file_stream >> character;
                stream_out << character;
            }
            file.close();
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 3:
    {
        QString fileName = "ЛебедеваЛаб20_0.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        stream_out << "Вы выбрали пункт 3\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            stream_out << "Не удалось открыть файл" << fileName << "для запси\n";
        } else {
            stream_out << "Введите размер массива\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            int n;
            stream_in >> n;
            if (stream_in.status() != QTextStream::Ok || n < 0) {
                stream_out << "Неверный ввод\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            } else {
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                stream_out << n << '\n';
            }
            in.setText(text_in);

            char c;
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                stream_out << "Введте символ (" << i+1 << "/" << n << ")\n";
                out.setText(text_out);
                out.moveCursor(QTextCursor::End);
                while (text_in.isEmpty()){
                    QCoreApplication::processEvents();
                }
                stream_in >> c;
                if (stream_in.status() != QTextStream::Ok) {
                    stream_out << "Неверный ввод\n";
                    stream_in.seek(0);
                    stream_in.resetStatus();
                    text_in.clear();
                    ok = false;
                    break;
                } else {
                    text_in.remove(0, stream_in.pos());
                    stream_in.seek(0);
                    stream_out << c << '\n';
                }
                in.setText(text_in);
                file_stream << c << ' ';
            }

            file.close();
            if (ok) stream_out << "Текст успешно записан в файл\n";
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 4:
    {
        stream_out << "Содержимое файла:\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        QString fileName = "ЛебедеваЛаб20_0.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            stream_out << "Не удалось открыть файл" << fileName << "для чтения\n";
        } else {
            while (!file_stream.atEnd()) {
                QChar character;
                file_stream >> character;
                if (character != ' ')
                    stream_out << character << ' ';
            }
            file.close();
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 5:
    {
        stream_out << "Вы выбрали пункт 5\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        QString fileName = "ЛебедеваЛаб20_1.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        if (!file.open(QIODevice::Append | QIODevice::Text)) {
            stream_out << "Не удалось открыть файл" << fileName << "для запси\n";
        } else {
            Worker worker;
            stream_out << "Введите возраст работника(int)\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            stream_in >> worker.age;
            if (stream_in.status() != QTextStream::Ok || worker.age < 0) {
                stream_out << "Неверный ввод\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            } else {
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                stream_out << worker.age << '\n';
            }
            in.setText(text_in);

            stream_out << "Введте зарплату работника(double)\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            stream_in >> worker.salary;
            if (stream_in.status() != QTextStream::Ok || worker.salary < 0) {
                stream_out << "Неверный ввод\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            } else {
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                stream_out << worker.salary << '\n';
            }
            in.setText(text_in);

            stream_out << "Работает ли в настоящее время?(bool)\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            int t;
            stream_in >> t;
            if (stream_in.status() != QTextStream::Ok) {
                stream_out << "Неверный ввод\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            } else {
                worker.works = t;
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                stream_out << worker.works << '\n';
            }
            in.setText(text_in);

            stream_out << "Введите пол(char)\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            stream_in >> worker.gender;
            if (stream_in.status() != QTextStream::Ok ) {
                stream_out << "Неверный ввод\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            } else {
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                stream_out << worker.gender << '\n';
            }
            in.setText(text_in);

            file_stream << worker.gender << '\n' << QString::number(worker.gender, 'g', 100) << '\n' << worker.gender << '\n' << worker.gender << '\n';

            file.close();
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 6:
    {
        stream_out << "Содержимое файла:\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        QString fileName = "ЛебедеваЛаб20_1.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            stream_out << "Не удалось открыть файл" << fileName << "для чтения\n";
        } else {
            int i = 0;
            QString line;
            QVector<QString> vec(4);
            while (!file_stream.atEnd()) {
                line = file_stream.readLine();
                vec[i] = line;
                ++i;
                if (i == 4) {
                    for (int j = 0; j < i; ++j){
                        if (j != 0) stream_out << " | ";
                        stream_out << vec[j];
                    }
                    stream_out << '\n';
                    i = 0;
                }
            }
            for (int j = 0; j < i; ++j){
                if (j != 0) stream_out << " | ";
                stream_out << vec[j];
            }
            file.close();
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 7:
    {
        stream_out << "Вы выбрали пункт 7\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        QString fileName = "ЛебедеваЛаб20_2.bin";
        std::ofstream file(fileName.toStdString(), std::ios::binary | std::ios::app);
        if (!file.is_open()) {
            stream_out << "Не удалось открыть файл" << fileName << "для запси\n";
        } else {
            Worker worker;
            stream_out << "Введите возраст работника(int)\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            stream_in >> worker.age;
            if (stream_in.status() != QTextStream::Ok || worker.age < 0) {
                stream_out << "Неверный ввод\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            } else {
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                stream_out << worker.age << '\n';
            }
            in.setText(text_in);

            stream_out << "Введите зарплату работника(double)\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            stream_in >> worker.salary;
            if (stream_in.status() != QTextStream::Ok || worker.salary < 0) {
                stream_out << "Неверный ввод\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            } else {
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                stream_out << worker.salary << '\n';
            }
            in.setText(text_in);

            stream_out << "Работает ли в настоящее время?(bool)\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            int t;
            stream_in >> t;
            if (stream_in.status() != QTextStream::Ok) {
                stream_out << "Неверный ввод\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            } else {
                worker.works = t;
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                stream_out << worker.works << '\n';
            }
            in.setText(text_in);

            stream_out << "Введте пол работника(char)\n";
            out.setText(text_out);
            out.moveCursor(QTextCursor::End);
            in.setReadOnly(false);
            while (text_in.isEmpty()){
                QCoreApplication::processEvents();
            }
            stream_in >> worker.gender;
            if (stream_in.status() != QTextStream::Ok ) {
                stream_out << "Неверный ввод\n";
                stream_in.resetStatus();
                text_in.clear();
                file.close();
                stream_in.seek(0);
                break;
            } else {
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                stream_out << worker.gender << '\n';
            }
            in.setText(text_in);

            file.write(reinterpret_cast<const char*>(&worker), sizeof(worker));

            file.close();
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 8:
    {
        stream_out << "Содержимое файла:\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        QString fileName = "ЛебедеваЛаб20_2.bin";
        std::ifstream file(fileName.toStdString(), std::ios::binary);
        if (!file.is_open()) {
            stream_out << "Не удалось открыть файл" << fileName << "для чтения\n";
        } else {
            Worker worker;
            while (!file.eof()) {
                file.read(reinterpret_cast<char*>(&worker), sizeof(worker));
                if (file.eof()) break;
                stream_out << "Возраст: " << worker.age << " ; ";
                stream_out << "Зарплата: " << worker.salary << " ; ";
                stream_out << "Пол: " << worker.gender << " ; ";
                stream_out << "Работает ли: " << (worker.works ? "Да" : "Нет") << '\n';
            }
            file.close();
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 9:
    {
        QString fileName = "ЛебедеваЛаб20_3.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        stream_out << "Введите абзац текста\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        text_in.clear();
        in.setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        in.setReadOnly(true);
        if (!file.open(QIODevice::Append | QIODevice::Text)) {
            stream_out << "Не удалось открыть файл" << fileName << "для записи\n";
        } else {
            file_stream << text_in << '\n';
            file.close();
            text_in.clear();
            in.setText(text_in);
            stream_in.readAll();
            stream_out << "Текст успешно записан в файл\n";
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 10:
    {
        stream_out << "Содержимое файла:\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        QString fileName = "ЛебедеваЛаб20_3.txt";
        QFile file(fileName);
        QTextStream file_stream(&file);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            stream_out << "Не удалось открыть файл" << fileName << "для чтения\n";
        } else {
            QString line;
            while (!file_stream.atEnd()) {
                line = file_stream.readLine();
                stream_out << line << '\n';
            }
            file.close();
        }
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
        break;
    }
    case 11:
        stream_out << "Выход из программы.\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);

        exit(0);
        break;
    default:
        stream_out << "Некорректный ввод. Пожалуйста, выберите пункт меню от 1 до 11.\n";
        out.setText(text_out);
        out.moveCursor(QTextCursor::End);
    }
    stream_out << "\n";
    out.setText(text_out);
    out.moveCursor(QTextCursor::End);
    in.setReadOnly(true);
}

