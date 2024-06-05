#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lineEdit->setMaxLength(1);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked(){
    if(!ui->lineEdit->text().isEmpty() &&
        !ui->lineEdit_5->text().isEmpty() & !ui->plainTextEdit->toPlainText().isEmpty()){
        int runwayCount = ui->spinBox->value();

        double area = ui->doubleSpinBox->value();

        QString textChar = ui->lineEdit->text();
        char inputChar = textChar[0].toLatin1();

        bool hasControlTower = ui->checkBox->isChecked();

        std::string text = ui->lineEdit_5->text().toStdString();

        QString text2 = ui->plainTextEdit->toPlainText();
        QStringList numberStrings = text2.split(' ');
        QVector<int> numbers;
        for (const QString& numberString : numberStrings) {
            bool ok;
            int number = numberString.toInt(&ok);
            if (ok) {
                numbers.append(number);
            }
            else{
                QMessageBox::information(this, "Неправильный ввод", "Вводите целочисленные значения");
            }
        }
        emit textEntered(runwayCount, area, inputChar, hasControlTower, text, numbers);
        close();
    }
    else{
        QMessageBox::information(this, "Неправильный ввод", "Введите значения");
    }
}