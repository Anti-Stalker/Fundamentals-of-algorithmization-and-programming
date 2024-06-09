#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "songfinder.h"
#include <QMessageBox>
#include <customlineedit.h>
#include <customtextedit.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRadialGradient gradient(756, 850, 1000);
    gradient.setColorAt(0, QColor("black"));
    gradient.setColorAt(1, QColor("gray"));

    QPalette pal = this->palette();
    pal.setBrush(QPalette::Window, QBrush(gradient));
    this->setPalette(pal);;

    ui->table->setStyleSheet("QFrame { background: #fdfd96; }");

    ui->frame->setStyleSheet("QFrame { background: #fdfd96; }");
    ui->table->setColumnCount(7);
    ui->table->setHorizontalHeaderLabels(QStringList() << "Logo" << "Name" << "Artist" << "Lyrics" << "Views"<<"Play"<<"Spotify");

    ui->table->setColumnWidth(0, 65);
    ui->table->setColumnWidth(1, 450);
    ui->table->setColumnWidth(2, 395);
    ui->table->setColumnWidth(3, 150);
    ui->table->setColumnWidth(4, 150);
    ui->table->setColumnWidth(5, 150);
    ui->table->setColumnWidth(6, 150);

    ui->frame->hide();


    ui->table->verticalHeader()->setVisible(false);


    ui->input->setStyleSheet("QLineEdit { background: lightgray; border: 2px solid #fdfd96; }");
    ui->artists->setStyleSheet("QTextEdit { background: lightgray; border: 2px solid #fdfd96; }");

    ui->input->setPlaceholderText("Enter search text...");
    ui->artists->setPlaceholderText("Enter possible artists...");

    QPixmap logo("/Users/egortishkevic/Qt/FixedShazam/logo.png");
    ui->logo->setPixmap(logo.scaled(500, 500, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    connect(ui->searchB, &QPushButton::pressed, this, &MainWindow::search_slot);
    connect(ui->sortB, &QPushButton::pressed, this, &MainWindow::sort_slot);


    label = new QLabel(this);
    loadingMovie = new QMovie("/Users/egortishkevic/Qt/FixedShazam/loading.gif");
    label->setMovie(loadingMovie);
    label->setAlignment(Qt::AlignCenter);
    label->setGeometry(500,350, 450, 400);
    label->hide();
    ui->label_2->hide();
    loadingMovie->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::search_slot()
{
    curr_clicks=0;
    ui->table->setRowCount(0);

    ui->table->hide();
    ui->searchB->hide();
    ui->sortB->hide();
    ui->frame->show();

    label->show();
    ui->label_2->show();


    Songfinder::find_song_by_lyrics(ui->input->text(), getArtists(), access_token, ui->table, errors);

    label->hide();
    ui->label_2->hide();

    ui->table->show();
    ui->searchB->show();
    ui->sortB->show();
    ui->frame->hide();

    if (errors!="") QMessageBox::warning(this, "Error", errors);
}

void MainWindow::sort_slot()
{
    curr_clicks++;
    if (ui->table->rowCount()==0) {QMessageBox::warning(this, "warning", "Nothing to be sorted");
        return;
    }
    if (curr_clicks>1) return;

    ui->table->hide();
    ui->searchB->hide();
    ui->sortB->hide();
    ui->frame->show();

    Songfinder::sortTableByViews(ui->table);

    ui->table->show();
    ui->searchB->show();
    ui->sortB->show();
     ui->frame->hide();
}

QVector<QString> MainWindow::getArtists()
{
    QVector<QString> artists;
    QString text = ui->artists->toPlainText();
    QStringList lines = text.split("\n");

    for (const QString& line : lines) {
        QString artist = line.trimmed();
        if (!artist.isEmpty()) {
            artists.append(artist);
        }
    }
    return artists;
}

void MainWindow::handleLineEditClick()
{
    if (ui->input->text() == "Enter search text...") {
        ui->input->clear();
    }
}

void MainWindow::handleTextEditClick()
{
    if (ui->artists->toPlainText() == "Enter possible artists (1 per line)...") {
        ui->artists->clear();
    }
}

