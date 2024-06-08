#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SetStyleSheet();
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    on_checkBox_clicked();
    ecc = QrCode::Ecc::LOW;
    background = "#FFFFFF";
    qrColor = "#000000";
    maxVersion = 40;
    minVersion = 1;
    mask = -1;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::SetStyleSheet() {
    this->setStyleSheet("background-color: #FADADD;"
                        "color: #EB5284;"
                         "font: 600 19px Times New Roman;"
                         );
    ui->pushButton->setStyleSheet("QPushButton {"
                                  "border-style: outset;"
                                  "border-width: 2px;"
                                  "border-radius: 10px;"
                                  "border-color: #C08081;"
                                  "background-color: #F19CBB;"
                                  "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                                  "color: #EB5284;"
                                  "font: 900 20px Times New Roman;"
                                  "font-style: normal;"
                                  "min-width: 10em;"
                                  "padding: 6px; "
                                  "}"
                                  "QPushButton:pressed {"
                                  "background-color: #FB607F;"\
                                  "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop: 0.4 rgba(222, 93, 131, 40), stop:1 rgba(215, 24, 104, 100));"
                                  "color: #D71868;"
                                  "}"
                                  );
    ui->textEdit->setStyleSheet("QTextEdit {border-style: ridge;"
                                "border-width: 2px;"
                                "border-color: #C08081;"
                                "color: #EB5284;"
                                "font: 500 18px;"
                                "font-style: normal;"
                                "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop: 0 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));}"
                                );
    ui->lineEditBackground->setStyleSheet("QLineEdit {border-style: ridge;"
                                          "border-width: 3px;"
                                          "border-color: #C08081;"
                                          "color: #EB5284;"
                                          "font: 500 18px;"
                                          "font-style: normal;"
                                          "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop: 0 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));}"
                                          );
    ui->lineEditQRColor->setStyleSheet("QLineEdit {border-style: ridge;"
                                       "border-width: 3px;"
                                       "border-color: #C08081;"
                                       "color: #EB5284;"
                                       "font: 500 18px;"
                                       "font-style: normal;"
                                       "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop: 0 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));}"
                                       );
    ui->spinBoxMask->setStyleSheet("QSpinBox {"
                                   "border-color: #C08081;"
                                   "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop: 0 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                                   );
    ui->spinBoxMax->setStyleSheet("QSpinBox {"
                                  "border-color: #C08081;"
                                  "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop: 0 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                                   );
    ui->spinBoxMin->setStyleSheet("QSpinBox {"
                                  "border-color: #C08081;"
                                  "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop: 0 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                                  );
    ui->graphicsView->setStyleSheet("QGraphicsView {border-style: groove;"
                                    "border-width: 3px;"
                                    "border-color: #C08081;"
                                    "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop: 0 rgba(241, 156, 187, 40), stop:1 rgba(235, 82, 132, 100));"
                                    "}"
                                    );

}


void MainWindow::on_radioButtonLow_clicked()
{
    ecc = QrCode::Ecc::LOW;
}


void MainWindow::on_radioButtonMedium_clicked()
{
    ecc = QrCode::Ecc::MEDIUM;
}


void MainWindow::on_radioButtonQuartile_clicked()
{
    ecc = QrCode::Ecc::QUARTILE;
}


void MainWindow::on_radioButtonHigh_clicked()
{
    ecc = QrCode::Ecc::HIGH;
}



void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (ui->checkBox->isChecked()) {
        ui->spinBoxMask->setDisabled(true);
        mask = -1;
    }
    else {
        ui->spinBoxMask->setDisabled(false);
        mask = ui->spinBoxMask->value();
    }

}


void MainWindow::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked()) {
        ui->spinBoxMask->setDisabled(true);
    }
    else {
        ui->spinBoxMask->setDisabled(false);
    }
}


void MainWindow::on_pushButton_clicked()
{
    background = static_cast<QColor>(ui->lineEditBackground->text());
    qrColor = static_cast<QColor>(ui->lineEditQRColor->text());
    QString text = ui->textEdit->toPlainText();
    QVector<QrSegment> segs = QrSegment::buildSegments(text.begin());
    qr = new QrCode(QrCode::encodeSegments(segs, ecc, minVersion, maxVersion, mask));
    printQrCode(*qr);
}


void MainWindow::on_spinBoxMax_valueChanged(int arg1)
{
    ui->spinBoxMax->setMinimum(ui->spinBoxMin->value());
    maxVersion = arg1;
}


void MainWindow::on_spinBoxMin_valueChanged(int arg1)
{
    ui->spinBoxMin->setMaximum(ui->spinBoxMax->value());
    minVersion = arg1;
}


void MainWindow::on_spinBoxMask_valueChanged(int arg1)
{
    mask = arg1;
}

void MainWindow::on_save_triggered() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save image"), "/home/lklls1/Документы/", tr("PNG (*.png)") );
    if (!fileName.isNull()) {
        QPixmap pixMap = this->ui->graphicsView->grab();
        pixMap.save(fileName);
    }
}


void MainWindow::printQrCode(QrCode &qr) {
    scene->clear();
    scene->update();
    const int BORDER = 4;
    int size = 2 * BORDER + qr.getSize();
    double width = static_cast<double>(540 / size);
    QRectF *rect;
    for (int y = -BORDER; y < qr.getSize() + BORDER; y++) {
        for (int x = -BORDER; x < qr.getSize() + BORDER; x++) {
            if (qr.getModule(x, y)) {
                rect = new QRectF(static_cast<double>(x * width), static_cast<double>(y * width),
                                  static_cast<double>(width), static_cast<double>(width));
                scene->addRect(*rect, QPen(qrColor), QBrush(qrColor));
            }
            else {
                rect = new QRectF(static_cast<double>(x * width), static_cast<double>(y * width),
                                  static_cast<double>(width), static_cast<double>(width));
                scene->addRect(*rect, QPen(background), QBrush(background));
            }
        }
    }
}
