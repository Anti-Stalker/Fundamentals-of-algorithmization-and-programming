#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //QTextCodec *russiancodec = QTextCodec::codecForName("Cp1251");//указана кодировка для корректного отображения букв
    //QTextCodec::setCodecForCStrings(russiancodec);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QString enteredText;
    enteredText += event->text();
    ui->label->setText(enteredText);

    if (event->modifiers() &Qt::ShiftModifier)
    {
        qDebug()<< "Shift";
    }

    if (event->modifiers() &Qt::AltModifier)
    {
        qDebug()<< "Alt";
    }

    if (event->modifiers() &Qt::ControlModifier)
    {
        qDebug()<< "Ctrl";
    }

    switch (event->key()) {
    case Qt::Key_Up : {
        qDebug()<< "Ctrl";
        break;
    }

    case Qt::Key_Down: {
        qDebug()<< "Ctrl";
        break;
    }

    case Qt::Key_Left: {
        qDebug()<< "Ctrl";
        break;
    }
    case Qt::Key_Right: {
        qDebug()<< "Ctrl";
        break;
    }
    case Qt::Key_NumLock: {
        qDebug()<< "Ctrl";
        break;
    }

    case Qt::Key_Return: {
        qDebug()<< "Ctrl";
        break;
    }

    /*
     *позволит автоматически определить кодировку ввода на основе локали.
     *Таким образом, если пользователь вводит русский или китайский язык, кодировка будет корректно обработана.
     *Это удобно, так как не требует явного указания кодировки для каждой строки текста.
     *Хотя установка кодировки по умолчанию удобна,
лучше всего всегда явно указывать кодировку для строк в своем коде.
Это поможет избежать потенциальных проблем с символами и
обеспечит более надежное поведение вашего приложения.*/
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString str;
    str = QFileDialog::getOpenFileName(this, "Choose file", "/home/kateryna/textfile/LabWork_5_TextLanguage" );
    //ui->text_Language->setText(str);
    QFile file(str);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString fileContent = in.readAll();
        ui->text_Language->setText(str);
        file.close();
    } else {
        // Обработка ошибки открытия файла
        qDebug() << "Ошибка при открытии файла: " << file.errorString();
    }
}
