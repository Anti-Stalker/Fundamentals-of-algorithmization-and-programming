#include "Widget.h"
#include "ui_Widget.h"


Widget::Widget(QWidget *parent) :
        QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    srand(time(nullptr));
    //int size = rand() % 30 + 20;
    int size = 10;
    for (int i = 0; i < size; ++i) {
        d.push(rand() % 1001 - 500);
    }
}


void Widget::doTask() {
    int min, max = min = d.front();
    int min_i, max_i = min_i = 0;
    int i = 0;

    for (i = 0; i < d.size(); ++i) {
        std::cout << d.front() << ' ';
        d.push(d.front());
        d.pop();
    }
    std::cout << std::endl;

    for (i = 0; i < d.size(); ++i) {
        if (d.front() > max) {
            max = d.front();
            max_i = i;
        }
        if (d.front() < min) {
            min = d.front();
            min_i = i;
        }
        d.push(d.front());
        d.pop();
    }
    if (max_i < min_i) { std::swap(min_i, max_i); }
    for (int j = 0; j <= min_i; ++j) {
        d.push(d.front());
        d.pop();
    }
    for (int j = min_i + 1; j < max_i; ++j) {
        d.pop();
    }
    for (int j = max_i; j < i; ++j) {
        d.push(d.front());
        d.pop();
    }

    std::cout << "Max: " << max << " " << max_i << std::endl << "Min: " << min << " " << min_i << std::endl;

    for (i = 0; i < d.size(); ++i) {
        std::cout << d.front() << ' ';
        d.push(d.front());
        d.pop();
    }
    std::cout << std::endl;
}


Widget::~Widget() {
    delete ui;
}

void Widget::showList() {
    ui->listWidget->clear();
    for (int i = 0; i < d.size(); ++i) {
        ui->listWidget->addItem(new QListWidgetItem((QString::number(d.front()))));
        d.push(d.front());
        d.pop();
    }
}

void Widget::on_frontPushButton_clicked() {
    if (d.size() > 0) {
        ui->listWidget->clear();
        ui->listWidget->addItem(new QListWidgetItem((QString::number(d.front()))));
    }
}

void Widget::on_backPushButton_clicked() {
    if (d.size() > 0) {
        ui->listWidget->clear();
        ui->listWidget->addItem(new QListWidgetItem((QString::number(d.back()))));
    }
}

void Widget::on_popPushButton_clicked() {
    d.pop();
    showList();
    if (d.size() <= 0) {
        ui->frontPushButton->setEnabled(false);
        ui->backPushButton->setEnabled(false);
        ui->doTaskPushButton->setEnabled(false);
        ui->popPushButton->setEnabled(false);
    }
}

void Widget::on_pushPushButton_clicked() {
    bool ok;
    int tmp = ui->pushLineEdit->text().toInt(&ok);
    if(ok) {
        d.push(tmp);
        showList();
        if (d.size() >= 0) {
            ui->frontPushButton->setEnabled(true);
            ui->backPushButton->setEnabled(true);
            ui->doTaskPushButton->setEnabled(true);
            ui->popPushButton->setEnabled(true);
        }
    }
}

void Widget::on_doTaskPushButton_clicked() {
    if (d.size() > 0) { doTask(); }
    showList();
}

void Widget::on_showPushButton_clicked() {
    showList();
}
