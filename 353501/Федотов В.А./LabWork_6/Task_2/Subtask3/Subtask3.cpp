#include "Subtask3.h"
#include "ui_Subtask3.h"
#include <cstddef>
#include <cstring>
#include <iostream>

#include <QFile>
#include <ostream>
#include <qlabel.h>
#include <qlayoutitem.h>


Subtask3::Subtask3(QWidget *parent) : QWidget(parent), ui(new Ui::Subtask3){
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    ui->setupUi(this);

    connect(ui->saveButton, &QPushButton::pressed, this, &Subtask3::initializeStruct);
    connect(ui->readButton, &QPushButton::pressed, this, &Subtask3::readTxt);
    connect(ui->readButton, &QPushButton::pressed, this, &Subtask3::readBin);
}

Subtask3::~Subtask3() {}

void Subtask3::initializeStruct() {
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

    QString qtitle = ui->titleEdit->text();
    for (int i = 0; i < MAX_TITLE_LENGTH && i < qtitle.size(); ++i) {
        song.title[i] = qtitle.at(i).toLatin1();
    }

    saveTxt(song);
    saveBin(song);
}

void Subtask3::saveTxt(Song song) {
    QFile file(filenameTxt);
    if (!file.open( QIODevice::WriteOnly | 
                    QIODevice::Text | 
                    QIODevice::Append)) {
        return;
    }

    QString printString =   QString::fromLatin1(song.title) + " | " + 
                            QString::number(song.releaseYear) + " | " +
                            QString::number(song.duration) + " | " +
                            (song.isInstrumental ? "Instrumental" : "Non-Instrumental") + " | " +
                            QString::number(song.ratingValues[0]) + " | " +
                            QString::number(song.ratingValues[1]) + " | " +
                            QString::number(song.ratingValues[2]);


    QTextStream out(&file);
    out << printString << '\n';

    file.close();
}

void Subtask3::saveBin(Song song) {
    QFile file(filenameBin);
    if (!file.open(QFile::Append)) {
        return;
    }
    
    size_t size = sizeof(Song);
    QByteArray binary((const char*)&song, size);

    file.write(binary);
    file.close();
}

void Subtask3::readTxt() {
    QString text;
    QFile file(filenameTxt);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // ui->resLabel->setText("Unable to read file");
        return;
    }

    QTextStream in(&file);
    ui->txtEdit->clear();
    while (!in.atEnd()){
        QString line = in.readLine();
        ui->txtEdit->append(line + "\n");
    }

    file.close();
}

void Subtask3::readBin() {
    QString text;
    QFile file(filenameBin);
    if (!file.open(QFile::ReadOnly)) {
        // ui->resLabel->setText("Unable to read file");
        return;
    }

    size_t structSize = sizeof(Song);
    songs.clear();
    while (!file.atEnd()) {
        Song song;
        memcpy(&song, file.read(structSize), structSize);
        songs.append(song);
    }

    ui->binEdit->clear();
    for (auto &song : songs) {
        QString printString =   QString::fromLatin1(song.title) + " ; " + 
                                QString::number(song.releaseYear) + " ; " +
                                QString::number(song.duration) + " ; " +
                                (song.isInstrumental ? "Instrumental" : "Non-Instrumental") + " ; " +
                                QString::number(song.ratingValues[0]) + " ; " +
                                QString::number(song.ratingValues[1]) + " ; " +
                                QString::number(song.ratingValues[2]) + " ! ";

        ui->binEdit->append(printString + "\n");
    }

    file.close();
}