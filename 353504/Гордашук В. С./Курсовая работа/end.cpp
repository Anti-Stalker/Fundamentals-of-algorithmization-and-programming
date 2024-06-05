#include "end.h"
#include "ui_end.h"

End::End(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::End)
{
    ui->setupUi(this);

    QPixmap pixmap("://cursor.png");
    QPixmap scaled = pixmap.scaled(26, 26, Qt::KeepAspectRatio);
    QCursor cursor(scaled, 0, 0);
    this->setCursor(cursor);
    ui->label->setCursor(cursor);
    ui->label_2->setCursor(cursor);
    ui->pushButton->setStyleSheet(
        "QPushButton {"
        "    border: none;"
        "    border-radius: 5px;"
        "    background: url(:/back.png) no-repeat center center;"
        "    min-width: 50px;"
        "    min-height: 25px;"
        "}"
        );
    ui->label->setStyleSheet("QLabel { color : black; }");
    ui->label_2->setStyleSheet("QLabel { color : black; }");
}

End::~End()
{
    delete ui;
}

void End::printFinal()
{
    ui->label_2->setText("Финальный результат - " + QString::number(finalScore) + ", это " +
                         QString::number(interpolationSearch(scores, scores.size(), finalScore)) + " место за всю историю игры");
}

void End::openFile(int a)
{
    QFile file("score.txt");
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        out << "\n" << a;
        file.close();
    }
    file.open(QIODevice::ReadWrite);
    fileText = file.readAll();
    QStringList numberList = fileText.split("\n");


    for (const QString &number : numberList)
    {
        scores.append(number.toInt());
    }
}

void End::shellSort(QVector<int> &a, int n)
{
    int k = n / 2;
    while (k > 0)
    {
        for (int i = k; i < n; i += k)
        {
            for (int j = i; j > 0 && a[j - k] < a[j]; j -= k)
            {
                std::swap(a[j - k], a[j]);
            }
        }
        k /= 2;
    }
}

int End::interpolationSearch(QVector<int> &a, int n, int x)
{
    int first = 0, last = (n - 1);

    while (first <= last && x <= a[first] && x >= a[last])
    {
        if (first == last)
        {
            if (a[first] == x) return first;
            return -1;
        }
        int pos = first + (((double)(last - first) / (a[first] - a[last])) * (a[first] - x));

        if (a[pos] == x) return pos;

        if (a[pos] > x) first = pos + 1;

        else last = pos - 1;
    }
    return -1;
}

void End::paintEvent(QPaintEvent *event)
{
    QPixmap px("://endPr.png");
    QPainter painter(this);
    painter.drawPixmap(rect(), px);
}

void End::on_pushButton_clicked()
{
    this->close();
}

