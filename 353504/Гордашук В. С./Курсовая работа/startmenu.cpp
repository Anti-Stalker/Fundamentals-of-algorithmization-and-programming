#include "startmenu.h"
#include "ui_startmenu.h"

StartMenu::StartMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartMenu)
{
    ui->setupUi(this);
    QPixmap pixmap("://cursor.png");
    QPixmap scaled = pixmap.scaled(26, 26, Qt::KeepAspectRatio);
    QCursor cursor(scaled, 0, 0);
    this->setCursor(cursor);
    ui->label->setCursor(cursor);
    ui->start->setStyleSheet(
        "QPushButton {"
        "    border: none;"
        "    border-radius: 5px;"
        "    background: url(:/back.png) no-repeat center center;"
        "    min-width: 50px;"
        "    min-height: 25px;"
        "}"
        );
    ui->label->setStyleSheet("QLabel { color : black; }");
}

StartMenu::~StartMenu()
{
    delete ui;
}

void StartMenu::on_start_clicked()
{
    emit start();
    this->close();
}

void StartMenu::paintEvent(QPaintEvent *event)
{
    QPixmap px("://endPr.png");
    QPainter painter(this);
    painter.drawPixmap(rect(), px);
}
