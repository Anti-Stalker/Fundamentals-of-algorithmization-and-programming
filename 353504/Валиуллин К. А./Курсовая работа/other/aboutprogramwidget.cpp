#include "aboutprogramwidget.h"
#include "ui_aboutprogramwidget.h"

AboutProgramWidget::AboutProgramWidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AboutProgramWidget)
{
    ui->setupUi(this);
    connect(ui->linkLabel, &QLabel::linkActivated, [](const QString &link) {
        QDesktopServices::openUrl(QUrl(link));
    });
}

AboutProgramWidget::~AboutProgramWidget()
{
    delete ui;
}

void AboutProgramWidget::on_pushButton_clicked()
{
    close();
}
