#include "Subtask2.h"
#include "ui_Subtask2.h"
#include <QFileDialog>
#include <qline.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qsize.h>
#include <qsizepolicy.h>
#include <qtmetamacros.h>
#include <qwidget.h>

Subtask2::Subtask2(QWidget *parent) : QWidget(parent), ui(new Ui::Subtask2){
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    ui->setupUi(this);
    table = ui->tableWidget;

    connect(ui->setSizeButton, &QPushButton::pressed, this, &Subtask2::setSize);
    connect(ui->saveButton, &QPushButton::pressed, this, &Subtask2::save);
    connect(ui->resultButton, &QPushButton::pressed, this, &Subtask2::read);
}

Subtask2::~Subtask2() {}

void Subtask2::setSize() {
    int colCount = ui->spinBox->value();
    table->setColumnCount(colCount);
    table->setRowCount(1);

    for (int i = 0; i < colCount; ++i) {
        auto lineEdit = new QLineEdit;
        table->setColumnWidth(i, 20);
        lineEdit->setFixedWidth(table->columnWidth(i));
        lineEdit->setMaxLength(1);
        table->setCellWidget(0, i, lineEdit);
    }
}

void Subtask2::save() {
    QFile file(filename);
    if (!file.open( QIODevice::WriteOnly | 
                    QIODevice::Text)) {
        return;
    }

    QTextStream out(&file);
    for (int i = 0; i < table->columnCount(); ++i)    {
        QLineEdit *lineEdit = (QLineEdit*)table->cellWidget(0, i);

        out << lineEdit->text() + "/";
    }

    file.close();
}

void Subtask2::read() {
    QString text;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->resLabel->setText("Unable to read file");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()){
        QString character = in.read(1);
        text += character;
    }

    ui->resLabel->setText(text);
    file.close();
}