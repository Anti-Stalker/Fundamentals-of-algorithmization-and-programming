#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtPrintSupport/qprinter.h>
#include <qpagesize.h>
#include <qpushbutton.h>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <qtextdocument.h>
#include <qtextoption.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->initListButton, &QPushButton::pressed, this, &MainWindow::initWithInitializerList);
    connect(ui->variablesButton, &QPushButton::pressed, this, &MainWindow::initWithVariables);
    connect(ui->pointerButton, &QPushButton::pressed, this, &MainWindow::initWithPointer);
    connect(ui->referenceButton, &QPushButton::pressed, this, &MainWindow::initWithReference);
}

QString MainWindow::getTitle() {
    QString qtitle = ui->titleEdit->text();
    if (qtitle.length() > MAX_TITLE_LENGTH) {
        qtitle = qtitle.left(MAX_TITLE_LENGTH);
    }
    qDebug() << qtitle;
    return qtitle;
}

void MainWindow::initWithInitializerList() {
    Song song = {
        ui->releaseBox->value(),
        ui->durationBox->value(),
        (bool)ui->instrumentalCBox->currentIndex(),
        "",
        {
            ui->ratingBox1->value(), 
            ui->ratingBox2->value(),
            ui->ratingBox3->value()
        }
    };
    
    const char *songTitle = getTitle().toUtf8().constData();
    qstrncpy(song.title, songTitle, MAX_TITLE_LENGTH);
    song.title[MAX_TITLE_LENGTH - 1] = '\0'; 

    print(song);
}

void MainWindow::initWithVariables() {
    Song song;
    song.duration = ui->durationBox->value();
    song.releaseYear = ui->releaseBox->value();
    song.isInstrumental = ui->instrumentalCBox->currentIndex();
    song.ratingValues[0] = ui->ratingBox1->value();
    song.ratingValues[1] = ui->ratingBox2->value();
    song.ratingValues[2] = ui->ratingBox3->value();

    const char *songTitle = getTitle().toUtf8().constData();
    qstrncpy(song.title, songTitle, MAX_TITLE_LENGTH);
    song.title[MAX_TITLE_LENGTH - 1] = '\0';

    print(song);
}

void MainWindow::initWithPointer() {
    Song song;
    Song *ptr = &song; 

    ptr->duration = ui->durationBox->value();
    ptr->releaseYear = ui->releaseBox->value();
    ptr->isInstrumental = ui->instrumentalCBox->currentIndex();
    ptr->ratingValues[0] = ui->ratingBox1->value();
    ptr->ratingValues[1] = ui->ratingBox2->value();
    ptr->ratingValues[2] = ui->ratingBox3->value();

    const char *songTitle = getTitle().toUtf8().constData();
    qstrncpy(song.title, songTitle, MAX_TITLE_LENGTH);
    song.title[MAX_TITLE_LENGTH - 1] = '\0'; 

    print(*ptr);
}
void MainWindow::initWithReference() {
    Song song;
    Song &ref = song; 

    ref.duration = ui->durationBox->value();
    ref.releaseYear = ui->releaseBox->value();
    ref.isInstrumental = ui->instrumentalCBox->currentIndex();
    ref.ratingValues[0] = ui->ratingBox1->value();
    ref.ratingValues[1] = ui->ratingBox2->value();
    ref.ratingValues[2] = ui->ratingBox3->value();

    const char *songTitle = getTitle().toUtf8().constData();
    qstrncpy(song.title, songTitle, MAX_TITLE_LENGTH);
    song.title[MAX_TITLE_LENGTH - 1] = '\0'; 

    print(ref);
}

void MainWindow::print(const Song &song) {
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize::A4);
    printer.setOutputFileName(fileName);

    QString printString =   QString::fromUtf8(song.title) + " | " + 
                            QString::number(song.releaseYear) + " | " +
                            QString::number(song.duration) + " | " +
                            (song.isInstrumental ? "Instrumental" : "Non-Instrumental") + " | " +
                            QString::number(song.ratingValues[0]) + " | " +
                            QString::number(song.ratingValues[1]) + " | " +
                            QString::number(song.ratingValues[2]);

    QTextDocument doc;
    QFont font;
    font.setPointSize(14);
    doc.setHtml(printString.toHtmlEscaped());
    doc.setDefaultFont(font);
    doc.print(&printer);
}