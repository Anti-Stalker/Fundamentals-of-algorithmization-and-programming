 #include "firstwindow.h"
#include "ui_firstwindow.h"

FirstWindow::FirstWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FirstWindow)
{
    ui->setupUi(this);

    QPalette pal = palette();
    pal.setColor(QPalette::Window, QColor("#E6E6FA")); // Лавандовый цвет
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    setWindowFlags(Qt::FramelessWindowHint);
}

FirstWindow::~FirstWindow()
{
    delete ui;
}

void FirstWindow::on_dialog_1_1_Btn_clicked()
{
    dialog_1_1 okno_1(this);
    okno_1.showFullScreen();
    okno_1.setModal(true);
    okno_1.exec();
}


void FirstWindow::on_dialog_1_2_Btn_clicked()
{
    dialog_1_2  okno_2;
    okno_2.showFullScreen();
    okno_2.setModal(true);
    okno_2.exec();
}


void FirstWindow::on_dailog_1_3_Btn_clicked()
{
    dialog_1_3 okno_3;
    okno_3.showFullScreen();
    okno_3.setModal(true);
    okno_3.exec();
}



void FirstWindow::on_pushButton_clicked()
{
    close();
}

