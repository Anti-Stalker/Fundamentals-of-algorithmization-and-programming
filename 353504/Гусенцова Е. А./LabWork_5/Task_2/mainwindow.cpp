#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cstring = new CString();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete cstring;
}

void MainWindow::on_pushButton_clicked()
{
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
    size_t n = ui->spb_N->value();
    QString selectedFunction = ui->comboBox->currentText();

    if (selectedFunction == "memcpy") {
        char* str1 = new char[n + 1];
        cstring->memcpy(str1, byteArray1.constData(), n);
        str1[n] = '\0';
        ui->ln_ans->setText(str1);
        delete[] str1;
        QMessageBox::information(nullptr, "Результат", "С помощью метода memcpy n символов было скопировано из String1 в QLineEdit");

    } else if (selectedFunction == "memmove") {
        char* str1 = new char[byteArray1.size() + 1];
        cstring->memmove(str1, byteArray1.constData(), byteArray1.size());
        str1[byteArray1.size()] = '\0';
        ui->ln_ans->setText(str1);
        delete[] str1;
        QMessageBox::information(nullptr, "Результат", "С помощью метода memmove данные были перемещены из String1 в QLineEdit");

    } else if (selectedFunction == "strcpy") {
        char* src = new char[byteArray1.size() + 1];
        cstring->memcpy(src, byteArray1.constData(), byteArray1.size());
        src[byteArray1.size()] = '\0';
        char dest[100];
        cstring->strcpy(dest, src);
        ui->ln_ans->setText(dest);
        delete[] src;
        QMessageBox::information(nullptr, "Результат", "С помощью метода strcpy данные были перемещены из String1 в QLineEdit");

    } else if (selectedFunction == "strncpy") {
        char* src = new char[byteArray1.size() + 1];
        cstring->memcpy(src, byteArray1.constData(), byteArray1.size());
        src[byteArray1.size()] = '\0';
        char dest[n + 1];
        cstring->strncpy(dest, src, n);
        dest[n] = '\0';
        ui->ln_ans->setText(dest);
        delete[] src;
        QMessageBox::information(nullptr, "Результат", "С помощью метода strncpy n символов было скопировано из String1 в QLineEdit");

    } else if (selectedFunction == "strcat") {
        char* str = new char[byteArray1.size() + byteArray2.size() + 1];
        cstring->memcpy(str, byteArray1.constData(), byteArray1.size());
        str[byteArray1.size()] = '\0';
        cstring->strcat(str, byteArray2.constData());
        ui->ln_ans->setText(str);
        delete[] str;
        QMessageBox::information(nullptr, "Результат", "Строки были успешно объединены");

    } else if (selectedFunction == "memset") {
        if (ui->ln_str2->text().isEmpty() || ui->ln_str1->text().isEmpty()) {
            QMessageBox::warning(nullptr, "Результат", "Заполните поля String!!!");
            return;
        }
        char value = ui->ln_str2->text().toUtf8().at(0);
        char* str = new char[byteArray1.size() + 1];
        cstring->memcpy(str, byteArray1.constData(), byteArray1.size());
        cstring->memset(str + byteArray1.size(), value, n);
        str[byteArray1.size() + n] = '\0';
        ui->ln_ans->setText(str);
        delete[] str;
        QMessageBox::information(nullptr, "Результат", "Строка была успешно заполнена первым символом String 2");

    } else if (selectedFunction == "strtok") {
        if (ui->ln_str2->text().isEmpty() || ui->ln_str1->text().isEmpty()) {
            QMessageBox::warning(nullptr, "Результат", "Заполните поля String!!!");
            return;
        }
        char delimiter = ui->ln_str2->text().toUtf8().at(0);
        char* str = byteArray1.data();
        char* token = strtok(str, &delimiter);
        QString result;
        while (token != nullptr) {
            result.append(token).append("===");
            token = strtok(nullptr, &delimiter);
        }
        ui->ln_ans->setText(result);
        QMessageBox::information(nullptr, "Результат", "Строка была успешно разбита на токены");

    } else if (selectedFunction == "strcoll") {
        int result = cstring->strcoll(byteArray1.constData(), byteArray2.constData());
        QString message;
        if (result == 0) {
            message = "Строки равны";
        } else if (result < 0) {
            message = "Первая строка меньше второй";
        } else {
            message = "Первая строка больше второй";
        }
        QMessageBox::information(nullptr, "Результат", message);

    } else if (selectedFunction == "strxfrm") {
        char* dest = new char[n + 1];
        size_t result = cstring->strxfrm(dest, byteArray1.constData(), n);
        if (result < n) {
            ui->ln_ans->setText(dest);
        } else {
            ui->ln_ans->setText("Строка не умещается в заданный буфер");
        }
        delete[] dest;
        QMessageBox::information(nullptr, "Результат", "Строка была успешно преобразована");

    } else if (selectedFunction == "strlen") {
        size_t length = cstring->strlen(byteArray1.constData());
        ui->ln_ans->setText(QString::number(length));
        QMessageBox::information(nullptr, "Результат", QString("Длина строки: %1").arg(length));

    } else if (selectedFunction == "strcmp") {
        int result = cstring->strcmp(byteArray1.constData(), byteArray2.constData());
        QString message;
        if (result == 0) {
            message = "Строки равны";
        } else if (result < 0) {
            message = "Первая строка меньше второй";
        } else {
            message = "Первая строка больше второй";
        }
        QMessageBox::information(nullptr, "Результат", message);

    } else if (selectedFunction == "strncmp") {
        int result = cstring->strncmp(byteArray1.constData(), byteArray2.constData(), n);
        QString message;
        if (result == 0) {
            message = "Первые " + QString::number(n) + " символов равны";
        } else if (result < 0) {
            message = "Первые " + QString::number(n) + " символов первой строки меньше второй";
        } else {
            message = "Первые " + QString::number(n) + " символов первой строки больше второй";
        }
        QMessageBox::information(nullptr, "Результат", message);

    } else if (selectedFunction == "memcmp") {
        int result = cstring->memcmp(byteArray1.constData(), byteArray2.constData(), n);
        QString message;
        if (result == 0) {
            message = "Первые " + QString::number(n) + " байт равны";
        } else if (result < 0) {
            message = "Первые " + QString::number(n) + " байт первой строки меньше второй";
        } else {
            message = "Первые " + QString::number(n) + " байт первой строки больше второй";
        }
        QMessageBox::information(nullptr, "Результат", message);

    } else if (selectedFunction == "strncat") {
        char* str = new char[byteArray1.size() + n + 1];
        cstring->strncpy(str, byteArray1.constData(), byteArray1.size());
        cstring->strncat(str, byteArray2.constData(), n);
        str[byteArray1.size() + n] = '\0';
        ui->ln_ans->setText(str);
        delete[] str;
        QMessageBox::information(nullptr, "Результат", "Строки были успешно объединены");
    }
}
