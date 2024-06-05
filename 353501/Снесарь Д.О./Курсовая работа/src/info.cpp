#include "info.h"
#include "ui_info.h"

Info::Info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Info)
{
    ui->setupUi(this);
    QPalette palette;
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor("#F7ADA9"));
    gradient.setColorAt(1, QColor("#F9DEC1"));
    this->setAutoFillBackground(true);
    palette.setBrush(QPalette::Window, gradient);
    this->setPalette(palette);

    QString styleSheet = QString("QPushButton { background-color: white; color: black; border-radius: %1%; border-style: none; } QPushButton:pressed { background-color: lightgray; color: white; }").arg(ui->pushButton->size().rwidth() * 0.9);
    ui->pushButton->setStyleSheet(styleSheet);
    QPixmap exitButtonIcon(":/img/exitIcon.png");
    int bSize = ui->pushButton->size().height();
    exitButtonIcon = exitButtonIcon.scaled(QSize(bSize * 0.9, bSize * 0.9), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->pushButton->setIcon(exitButtonIcon);
    ui->pushButton->setIconSize(exitButtonIcon.size() * 2);
    ui->textBrowser->setStyleSheet("background-color: white; color: black; border-radius: 30px;");

}

Info::~Info()
{
    delete ui;
}

void Info::setPaletteW(QPalette palette)
{
    Palette = palette;
    this->setPalette(Palette);
}

void Info::on_pushButton_clicked()
{
    emit backMenu();
}

