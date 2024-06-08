#include "Subtask4.h"
#include "ui_Subtask4.h"
#include <QFileDialog>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qsizepolicy.h>
#include <qtmetamacros.h>
#include <qwidget.h>

Subtask4::Subtask4(QWidget *parent) : QWidget(parent), ui(new Ui::Subtask4){
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    ui->setupUi(this);

    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &Subtask4::save);
    connect(ui->pushButton, &QPushButton::pressed, this, &Subtask4::read);
}

Subtask4::~Subtask4() {}

void Subtask4::save() {
    QFile file(filename);
    if (!file.open( QIODevice::WriteOnly | 
                    QIODevice::Text |
                    QIODevice::Append)) {
        ui->label->setText("Unable to save file");
        return;
    }

    QString text = ui->lineEdit->text();
    ui->lineEdit->clear();
    if (text.at(text.length()-1) != '.') 
        text.append(". ");
    
    QTextStream out(&file);
    for (int i = 0; i < text.length(); ++i)    {
        out << text[i];
    }

    file.close();
}

void Subtask4::read() {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->label->setText("Unable to read file");
        return;
    }

    QString text;
    QTextStream in(&file);
    while (!in.atEnd()){
        QString line = in.readLine();
        text += line;
    }

    ui->label->setText(text);
    file.close();
}