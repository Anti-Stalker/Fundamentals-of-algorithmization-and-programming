#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->text, &QLineEdit::returnPressed, this, &MainWindow::stop);
    QObject::connect(this, &MainWindow::operationChanged, this, &MainWindow::menu);

    QRegularExpression regExp("(10|[0-9])");
    ui->input->setValidator(new QRegularExpressionValidator(regExp, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fileRead()
{
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QString text;
    QTextStream in(file);
    while (!in.atEnd()) {
        QChar ch;
        in >> ch;
        text.push_back(ch);
    }
    if (text.size() == 0)
    {
        ui->fileText->setText("Файл пуст");
        file->close();
        return;
    }
    ui->fileText->setText(text);
    file->close();
}

void MainWindow::arrayFile()
{
    bool ok;
    int n = QInputDialog::getInt(this, "Ввод размера", "Размер массива:", 0, 0, INT_MAX, 1, &ok);
    if (!ok)
    {
        return;
    }
    float arr[n];
    file2->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    for (int i = 0; i < n; ++i)
    {
        arr[i] = QInputDialog::getDouble(this, "Ввод 'элемента", "Элемент " + QString::number(i), 0, 0, INT_MAX, 1, &ok);
        if (!ok)
        {
            --i;
            break;
        }
        QTextStream out(file2);
        QString text = QString::number(arr[i]);
        out << text + '$';
        if (i == (n - 1)) return;
    }
    file2->close();
    ui->operate->setEnabled(true);
}

void MainWindow::readArray()
{
    if (!file2->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QString text;
    QTextStream in(file2);
    while (!in.atEnd()) {
        QChar ch;
        in >> ch;
        if (ch == '$')
        {
            ch = ' ';
        }
        text.push_back(ch);
    }
    if (text.size() == 0)
    {
        ui->fileText->setText("Файл пуст");
        file2->close();
        return;
    }
    ui->fileText->setText(text);
    file2->close();
}

void MainWindow::createStruct()
{
    State *state = new State;
    bool ok = false;
    while (!ok)
    {
        state->population = QInputDialog::getInt(this, "Население", "Введите население:", 0, 0, INT_MAX, 1, &ok);
    }
    ok = false;
    while (!ok)
    {
        state->area = QInputDialog::getDouble(this, "Площадь", "Введите площадь:", 0, 0, INT_MAX, 1, &ok);
    }
    ok = false;
    while (!ok)
    {
        QString text = QInputDialog::getText(this, "Название", "Введите название:");
        if (text.size() < 20)
        {
            strncpy(state->name, text.toStdString().c_str(), sizeof(state->name));
            ok = true;
        }
    }
    ok = false;
    while (!ok)
    {
        state->population = QInputDialog::getInt(this, "Независимость", "0 - зависимое, все остальные числа - независимое:", 0, 0, INT_MAX, 1, &ok);
    }
    ok = false;
    while (!ok)
    {
        QString text = QInputDialog::getText(this, "Валюта", "Введите валюту(до 3 символов):");
        if (text.size() < 4)
        {
            strncpy(state->currency, text.toStdString().c_str(), sizeof(state->currency));
            ok = true;
        }
    }

    file3->open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream in(file3);
    in << printState(state);
    in << " | ";
    file3->close();
    ui->operate->setEnabled(true);
}

void MainWindow::readStruct()
{
    if (!file3->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QString text;
    QTextStream in(file3);
    while (!in.atEnd()) {
        QChar ch;
        in >> ch;
        text.push_back(ch);
    }
    if (text.size() == 0)
    {
        ui->fileText->setText("Файл пуст");
        file3->close();
        return;
    }
    ui->fileText->setText(text);
    file3->close();
}

void MainWindow::createBinStruct()
{
    State *state = new State;
    bool ok = false;
    while (!ok)
    {
        state->population = QInputDialog::getInt(this, "Население", "Введите население:", 0, 0, INT_MAX, 1, &ok);
    }
    ok = false;
    while (!ok)
    {
        state->area = QInputDialog::getDouble(this, "Площадь", "Введите площадь:", 0, 0, INT_MAX, 1, &ok);
    }
    ok = false;
    while (!ok)
    {
        QString text = QInputDialog::getText(this, "Название", "Введите название:");
        if (text.size() < 20)
        {
            strncpy(state->name, text.toStdString().c_str(), sizeof(state->name));
            ok = true;
        }
    }
    ok = false;
    while (!ok)
    {
        int a = QInputDialog::getInt(this, "Независимость", "0 - зависимое, все остальные числа - независимое:", 0, 0, INT_MAX, 1, &ok);
        if (a == 0) state->independent = false;
        else state->independent = true;
    }
    ok = false;
    while (!ok)
    {
        QString text = QInputDialog::getText(this, "Валюта", "Введите валюту(до 3 символов):");
        if (text.size() < 4)
        {
            strncpy(state->currency, text.toStdString().c_str(), sizeof(state->currency));
            ok = true;
        }
    }
    ui->operate->setEnabled(true);
    if (file4->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        QDataStream in(file4);
        in << printState(state);
        in << " | ";
        file4->close();
    }
    else qDebug() << "File not open";
}

void MainWindow::readBinStruct()
{
    file4->open(QIODevice::ReadOnly | QIODevice::Text);
    QDataStream out(file4);
    QString line;
    out >> line;
    line.replace('|', ';');
    if (line.size() == 0)
    {
        ui->fileText->setText("Файл пуст");
        file4->close();
        return;
    }
    ui->fileText->setText(line);
    file4->close();
}

void MainWindow::sentRead()
{
    if (!file5->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QString text;
    QTextStream in(file5);
    while (!in.atEnd()) {
        QChar ch;
        in >> ch;
        text.push_back(ch);
    }
    if (text.size() == 0)
    {
        ui->fileText->setText("Файл пуст");
        file2->close();
        return;
    }
    ui->fileText->setText(text);
    file5->close();
}

void MainWindow::textWrite()
{
    QTextStream out(file);
    QString text = ui->text->text();
    out << text.right(1);
}

void MainWindow::sentencesWrite()
{
    file5->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    QString text = QInputDialog::getText(this, "Текст", "Введите текст:", QLineEdit::Normal);
    QTextStream in(file5);
    in << text;
    file5->close();
    ui->operate->setEnabled(true);
}

void MainWindow::menu()
{
    switch (operation) {
    case 1:
        ui->operate->setEnabled(false);
        ui->text->clear();
        ui->text->setEnabled(true);
        file->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
        QObject::connect(ui->text, &QLineEdit::textChanged, this, &MainWindow::textWrite);
        break;
    case 2:
        fileRead();
        break;
    case 3:
        ui->operate->setEnabled(false);
        arrayFile();
        break;
    case 4:
        readArray();
        break;
    case 5:
        ui->operate->setEnabled(false);
        createStruct();
        break;
    case 6:
        readStruct();
        break;
    case 7:
        ui->operate->setEnabled(false);
        createBinStruct();
        break;
    case 8:
        readBinStruct();
        break;
    case 9:
        ui->operate->setEnabled(false);
        sentencesWrite();
        break;
    case 10:
        sentRead();
        break;
    case 0:
        this->close();
    }
}

void MainWindow::stop()
{
    QObject::disconnect(ui->text, &QLineEdit::textChanged, this, &MainWindow::textWrite);
    file->close();
    ui->text->setEnabled(false);
    ui->operate->setEnabled(true);
}

void MainWindow::on_operate_clicked()
{
    operation = ui->input->text().toInt();
    emit operationChanged();
}

QString MainWindow::printState(State *state)
{
    QString independ = "true";
    if (state->independent == 0) independ = "false";
    return QString::number(state->population) + " | " + QString::number(state->area) + " | " + state->name + " | " + independ + " | " + state->currency;
}
