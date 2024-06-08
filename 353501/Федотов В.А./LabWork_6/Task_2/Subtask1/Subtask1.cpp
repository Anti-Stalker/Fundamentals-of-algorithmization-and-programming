#include "Subtask1.h"
#include "ui_Subtask1.h"
#include <QFileDialog>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qsizepolicy.h>
#include <qtmetamacros.h>
#include <qwidget.h>

Subtask1::Subtask1(QWidget *parent) : QWidget(parent), ui(new Ui::Subtask1){
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    ui->setupUi(this);

    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &Subtask1::save);
    connect(ui->pushButton, &QPushButton::pressed, this, &Subtask1::read);
}

Subtask1::~Subtask1() {}

void Subtask1::save() {
    QString text = ui->lineEdit->text();
    QFile file(filename);
    if (!file.open( QIODevice::WriteOnly | 
                    QIODevice::Text)) {
        ui->label->setText("Unable to save file");
        return;
    }

    QTextStream out(&file);
    for (int i = 0; i < text.length(); ++i)    {
        out << text[i];
    }

    file.close();
}

void Subtask1::read() {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->label->setText("Unable to read file");
        return;
    }

    QTextStream in(&file);
    QString text;
    while (!in.atEnd()){
        QString character = in.read(1);
        text += character;
    }

    ui->label->setText(text);
    file.close();
}