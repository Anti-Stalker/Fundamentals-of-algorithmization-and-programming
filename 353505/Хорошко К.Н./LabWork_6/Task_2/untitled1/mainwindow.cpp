#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->input->setFocus();
    connect(ui->input, &QLineEdit::returnPressed, this, &MainWindow::Enter);
    QTimer* timer = new QTimer(this);
    timer->setInterval(20);
    timer->start();
    connect(timer, &QTimer::timeout, this, &MainWindow::Exec);
}


void MainWindow::Exec(){
    QFile file("ХорошкоЛаб20.txt");
    QFile file1("ХорошкоЛаб20_0.txt");
    QFile file2("ХорошкоЛаб20_1.txt");
    std::ifstream file3("ХорошкоЛаб20_2.bin", std::ios::binary);
    QFile file4("ХорошкоЛаб20_3.txt");
    enemy Enemy;
    if (Press){
        ui->input->clear();
        switch (k) {
        case 1:
            ui->output->appendPlainText("Введите абзац\n");
            Press = false;
            break;
        case 2:
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                // Создаем объект QTextStream для чтения текста из файла
                QTextStream in(&file);

                ui->output->appendPlainText(in.readAll() + "\n");


                k = 0;

                // Закрываем файл после чтения
                file.close();
            } else {
                // Если не удалось открыть файл, вы можете обработать это соответствующим образом
                qDebug() << "Ошибка при открытии файла для чтения:" << file.errorString();
            }

            break;
        case 4:
            if (file1.open(QIODevice::ReadOnly | QIODevice::Text)) {
                // Создаем объект QTextStream для чтения текста из файла
                QTextStream in(&file1);

                ui->output->appendPlainText(in.readAll() + "\n");


                k = 0;

                // Закрываем файл после чтения
                file1.close();
            } else {
                // Если не уда    QFile file3("ХорошкоЛаб20_2.bin");лось открыть файл, вы можете обработать это соответствующим образом
                qDebug() << "Ошибка при открытии файла для чтения:" << file.errorString();
            }
            break;
        case 6:
            if (file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
                // Создаем объект QTextStream для чтения текста из файла
                QTextStream in(&file2);

                ui->output->appendPlainText(in.readAll() + "\n");


                k = 0;

                // Закрываем файл после чтения
                file2.close();
            } else {
                // Если не удалось открыть файл, вы можете обработать это соответствующим образом
                qDebug() << "Ошибка при открытии файла для чтения:" << file.errorString();
            }
            break;
        case 8:
if (!file3.is_open()) {
                qDebug() << "Ошибка при открытии файла для чтения:";
    return;

}


while (file3.read(reinterpret_cast<char*>(&Enemy), sizeof(enemy))) {
    // Считываем данные из файла



    // Выводим данные
    ui->output->appendPlainText("Ноги : " + QString::number(Enemy.paws) +
                                " | Вес : " + QString::number(Enemy.weight) +
                                " | Первая буква вида: " + QChar(Enemy.firstNameSymbol) +
                                " | Домашнее: " + (Enemy.isHouse ? "Да" : "Нет") + "\n");
}
file3.close();
k = 0;
            break;

        case 9:
ui->output->appendPlainText("Введите текст\n");
Press = false;
break;

        case 10:
if (file4.open(QIODevice::ReadOnly | QIODevice::Text)) {
    // Создаем объект QTextStream для чтения текста из файла
    QTextStream in(&file4);

    ui->output->appendPlainText(in.readAll() + "\n");


    k = 0;

    // Закрываем файл после чтения
    file4.close();
} else {
    // Если не удалось открыть файл, вы можете обработать это соответствующим образом
    qDebug() << "Ошибка при открытии файла для чтения:" << file.errorString();
}

        case 11:
        QCoreApplication::exit();
break;

break;
        default:
            ui->output->appendPlainText("1.Ввести абзац\n"
                                        "2.Вывести абзац\n"
                                        "3.Ввести массив\n"
                                        "4.Вывести массив\n"
                                        "5.Ввести структуру в txt\n"
                                        "6.Вывести структуру из txt\n"
                                        "7.Ввести структуру в бинарный файл\n"
                                        "8.Вывести структуру из бинарного файла\n"
                                        "9.Дабавить текст к файлу\n"
                                        "10.Вывести текст\n"
                                        "11.Выйти\n");
            Press = false;
            break;
        }
    }
}

void MainWindow::Enter(){
    if (k == 1){
        QFile file("ХорошкоЛаб20.txt");


        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            // Создаем объект QTextStream для записи текста в файл
            QTextStream stream(&file);

            // Очищаем содержимое файла
            file.resize(0);

            // Записываем текст в файл
            stream << ui->input->text();

            // Закрываем файл после записи
            file.close();

            k = 0;
        } else {
            // Если не удалось открыть файл, вы можете обработать это соответствующим образом
            qDebug() << "Ошибка при открытии файла для записи:" << file.errorString();
        }
    }


    if (k != 3 && k != 5 && k != 7){
    Press = true;
    }

    if (k == 3){
    if (l == -1){
        ui->output->appendPlainText("Введите колличество элементов \n");
            l = 0;
    }
    else
    {
            if (can){
                l = ui->input->text().toInt();
                can = false;
                QFile file("ХорошкоЛаб20_0.txt");

                if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    // Создаем объект QTextStream для записи текста в файл
                    file.resize(0);
                    // Закрываем файл после записи
                    file.close();

                } else {
                    // Если не удалось открыть файл, вы можете обработать это соответствующим образом
                    qDebug() << "Ошибка при открытии файла для записи:" << file.errorString();
                }
            }
            m++;
            if (m != l+1){
                ui->output->appendPlainText("Введите элемент " + QString::number(m) + "\n");
}
            if (m <= l+1 && m != 1){
                QFile file("ХорошкоЛаб20_0.txt");

                if (file.open(QIODevice::Append | QIODevice::Text)) {
                    // Создаем объект QTextStream для записи текста в файл
                    QTextStream stream(&file);

                    // Записываем текст в файл
                    stream << ui->input->text() + '~';

                    // Закрываем файл после записи
                    file.close();


                } else {
                    // Если не удалось открыть файл, вы можете обработать это соответствующим образом
                    qDebug() << "Ошибка при открытии файла для записи:" << file.errorString();
                }
                }

            if (m == l+1){
                k = 0;
                can = true;
                l = -1;
                Press = true;
                m = 0;
                }
    }
    }

    if (k == 5){
    if (m == 0){
        ui->output->appendPlainText("Введите количество лап\n");
    }
    if (m == 1){
        ui->output->appendPlainText("Введите вес\n");
        Enemy.paws = ui->input->text().toInt();
    }
    if (m == 2){
        ui->output->appendPlainText("Введите первую букву вида\n");
        Enemy.weight = ui->input->text().toDouble();
    }
    if (m == 3){
        ui->output->appendPlainText("Это домашнее животное?\n");
        Enemy.firstNameSymbol = ui->input->text().at(0);
    }
    if (m == 4){
        if (ui->input->text() == "Да"){
        Enemy.isHouse = true;
        }
        else
        {
        Enemy.isHouse = false;
        }

QFile file("ХорошкоЛаб20_1.txt");

if (file.open(QIODevice::Append | QIODevice::Text)) {
        // Создаем объект QTextStream для записи текста в файл
        QTextStream stream(&file);

        // Записываем текст в файл
        stream << "Ноги : " + QString::number(Enemy.paws) + " | Вес : " + QString::number(Enemy.weight) + " | Первая буква вида: " + Enemy.firstNameSymbol + " | Домашнее: " + (Enemy.isHouse ? "Да" : "Нет") + "\n";

        // Закрываем файл после записи
        file.close();


} else {
        // Если не удалось открыть файл, вы можете обработать это соответствующим образом
        qDebug() << "Ошибка при открытии файла для записи:" << file.errorString();
}
k = 0;
m = 0;
Press = true;
    }
    m++;
    }

    if (k == 7){
    if (m == 0){
        ui->output->appendPlainText("Введите количество лап\n");
    }
    if (m == 1){
        ui->output->appendPlainText("Введите вес\n");
        Enemy.paws = ui->input->text().toInt();
    }
    if (m == 2){
        ui->output->appendPlainText("Введите первую букву вида\n");
        Enemy.weight = ui->input->text().toDouble();
    }
    if (m == 3){
        ui->output->appendPlainText("Это домашнее животное?\n");
        Enemy.firstNameSymbol = ui->input->text().at(0);
    }
    if (m == 4){
        if (ui->input->text() == "Да"){
        Enemy.isHouse = true;
        }
        else
        {
        Enemy.isHouse = false;
        }



        QFile file("ХорошкоЛаб20_2.bin");

        if (file.open(QIODevice::Append | QIODevice::WriteOnly)) {
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_5_0); // Устанавливаем версию QDataStream (опционально)

        // Записываем данные
        out.writeRawData(reinterpret_cast<const char*>(&Enemy), sizeof(Enemy));
file.resize(0);
        // Закрываем файл после записи
        file.close();
        } else {
        // Если не удалось открыть файл, обработайте это соответствующим образом
        qDebug() << "Ошибка при открытии файла для записи:" << file.errorString();
        }


k = 0;
m = 0;
Press = true;
    }
    m++;
    }


    if (k == 9){

    QFile file("ХорошкоЛаб20_3.txt");


    if (file.open(QIODevice::Append | QIODevice::Text)) {
// Создаем объект QTextStream для записи текста в файл
QTextStream stream(&file);

// Очищаем содержимое файла

// Записываем текст в файл
stream << ui->input->text();

// Закрываем файл после записи
file.close();

k = 0;
    } else {
// Если не удалось открыть файл, вы можете обработать это соответствующим образом
qDebug() << "Ошибка при открытии файла для записи:" << file.errorString();
    }
    }

    if (k == 0){
    k = ui->input->text().toInt();
    }
    ui->input->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

