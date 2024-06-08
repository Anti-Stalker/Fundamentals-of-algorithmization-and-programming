#include "Widget.h"
#include "ui_Widget.h"


Widget::Widget(QWidget *parent) :
        QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    mode = 0;
    ui->lineEdit->installEventFilter(this);

    connect(ui->comboBox, QOverload<int>::of(&QComboBox::activated), this, &Widget::execution);
}

Widget::~Widget() {
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event) {
    switch (mode) {
        case 0:
            firstTask();
        case 1:
            secondTask();
        case 2:
            thirdTask();
        case 3:
            fourthTask();
        case 4:
            fifthTask();
    }
}

void Widget::execution(int mode) {
    switch (mode) {
        case 0:
            this->mode = 0;
            break;
        case 1:
            this->mode = 1;
            break;
        case 2:
            this->mode = 2;
            break;
        case 3:
            this->mode = 3;
            break;
        case 4:
            this->mode = 4;
            break;
        default:
            close();
            break;
    }
}

bool Widget::eventFilter(QObject *object, QEvent *event) {
    if (object == ui->lineEdit && event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return) {
            keyPressEvent(keyEvent);
            return true;
        }
    }
    return QWidget::eventFilter(object, event);
}

void Widget::firstTask() {
    QFile file("../files/БурчукЛаб20.txt");
    if (!file.open(QIODevice::Truncate | QIODevice::ReadWrite)) {
        return;
    }
    QString data = ui->lineEdit->text();
    std::string str = data.trimmed().toStdString();
    for (wchar_t ch: str) {
        file.putChar(ch);
        file.flush();
    }
    this->firstTaskPrint();
    file.close();
}

void Widget::firstTaskPrint() {
    QFile file("../files/БурчукЛаб20.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QString data = file.readLine();
    for (QChar ch: data) {
        ui->textEdit->setText(ui->textEdit->toPlainText() + ch);
    }
    file.close();
}

void Widget::secondTask() {
    QString str = ui->lineEdit->text();
    QStringList list = str.split(" ");
    if (list[0].toInt() == 0) {
        return;
    }
    QFile file("../files/БурчукЛаб20_0.txt");
    if (!file.open(QIODevice::Truncate | QIODevice::ReadWrite)) {
        return;
    }
    QTextStream stream(&file);
    for (int i = 1; i <= list[0].toInt() || i < list.size(); ++i) {
        stream << list[i].toInt() << SPLITTER;
    }
    file.close();
    this->secondTaskPrint();
}

void Widget::secondTaskPrint() {
    QFile file("../files/БурчукЛаб20_0.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << file.errorString();
        return;
    }
    ui->lineEdit->clear();
    QTextStream stream(&file);
    QString str;
    stream >> str;
    ui->textEdit->clear();
    QStringList nums = str.split(SPLITTER);
    for (QString num: nums) {
        ui->textEdit->setText(ui->textEdit->toPlainText() + " " + num);
    }
    file.close();
}

void Widget::thirdTask() {
    QRegExp regex = QRegExp(R"((\d+)\s(\d+\.\d+)\s([A-Za-z])\s(\d+)\s(\S+)\s(\d+))");
    QRegExpValidator validator(regex);
    QString str = ui->lineEdit->text();
    int pos = 0;
    if (validator.validate(str, pos) != QValidator::Acceptable) {
        return;
    }
    QFile file("../files/БурчукЛаб20_1.txt");
    if (!file.open(QIODevice::Append | QIODevice::ReadWrite)) {
        return;
    }
    QTextStream stream(&file);
    Motorbike motorbike = Motorbike(str);
    stream << motorbike.mileage << SPLITTER << motorbike.max_speed << SPLITTER
           << motorbike.type << SPLITTER << motorbike.isWoundUp << SPLITTER
           << motorbike.brand << SPLITTER << motorbike.lastModelNumber;
    stream << '\n';
    thirdTaskPrint();
    file.close();
}

void Widget::thirdTaskPrint() {
    QFile file("../files/БурчукЛаб20_1.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QTextStream in(&file);
    ui->textEdit->clear();
    file.close();
    while (!in.atEnd()) {
        QString bike = in.readLine();
        ui->textEdit->setPlainText(ui->textEdit->toPlainText() +
                                   bike + '\n');
    }
}

void Widget::fourthTask() {
    QRegExp regex = QRegExp(R"((\d+)\s(\d+\.\d+)\s([A-Za-z])\s(\d+)\s(\S+)\s(\d+))");
    QRegExpValidator validator(regex);
    QString str = ui->lineEdit->text();
    int pos = 0;
    if (validator.validate(str, pos) != QValidator::Acceptable) {
        return;
    }

    std::ofstream file(
            "../files/БурчукЛаб20_2.bin",
            std::ofstream::out | std::ofstream::binary | std::ofstream::app);

    Motorbike motorbike(str);

    file.write(reinterpret_cast<char *>(&motorbike.mileage), sizeof(motorbike.mileage));
    file.write(reinterpret_cast<char *>(&motorbike.max_speed), sizeof(motorbike.max_speed));
    file.write(reinterpret_cast<char *>(&motorbike.type), sizeof(motorbike.type));
    file.write(reinterpret_cast<char *>(&motorbike.isWoundUp), sizeof(motorbike.isWoundUp));
    file.write(reinterpret_cast<char *>(&motorbike.lastModelNumber), sizeof(motorbike.lastModelNumber));

    size_t brandLength = strlen(motorbike.brand);
    file.write(reinterpret_cast<char *>(&brandLength), sizeof(brandLength));
    file.write(motorbike.brand, brandLength);

    file.close();
    fourthTaskPrint();
}

void Widget::fourthTaskPrint() {
    std::ifstream file(
            "../files/БурчукЛаб20_2.bin",
            std::ifstream::in | std::ifstream::binary);

    ui->textEdit->clear();

    while (!file.eof()) {
        Motorbike temp;
        file.read(reinterpret_cast<char *>(&temp.mileage), sizeof(temp.mileage));
        file.read(reinterpret_cast<char *>(&temp.max_speed), sizeof(temp.max_speed));
        file.read(reinterpret_cast<char *>(&temp.type), sizeof(temp.type));
        file.read(reinterpret_cast<char *>(&temp.isWoundUp), sizeof(temp.isWoundUp));
        file.read(reinterpret_cast<char *>(&temp.lastModelNumber), sizeof(temp.lastModelNumber));

        size_t brandLength;
        file.read(reinterpret_cast<char *>(&brandLength), sizeof(brandLength));
        temp.brand = new char[brandLength + 1];
        file.read(temp.brand, brandLength);
        temp.brand[brandLength] = '\0';

        if (file.gcount() > 0) {
            ui->textEdit->setText(ui->textEdit->toPlainText() + temp.print() + "\n");
        }

        delete[] temp.brand;
    }

    file.close();
}


void Widget::fifthTask() {
    QFile file("../files/БурчукЛаб20_3.txt");
    if (!file.open(QIODevice::Append | QIODevice::ReadWrite)) {
        return;
    }
    ui->lineEdit->removeEventFilter(this);
    QTextStream stream(&file);
    stream << ui->lineEdit->text().trimmed() << "\n";
    stream.flush();
    this->fifthTaskPrint();
    file.close();
}

void Widget::fifthTaskPrint() {
    QFile file("../files/БурчукЛаб20_3.txt");
    ui->textEdit->clear();
    ui->lineEdit->clear();
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << file.errorString();
        return;
    }
    QTextStream stream(&file);
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        ui->textEdit->append(line);
    }
    file.close();
}
