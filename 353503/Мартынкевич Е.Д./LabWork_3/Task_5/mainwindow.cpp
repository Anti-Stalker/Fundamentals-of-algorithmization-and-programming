#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileInfo>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QApplication>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QGridLayout>
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->scrollArea->setWidgetResizable(true);
    label_2 = new QLabel("");
    ui->scrollArea->setWidget(label_2);
    ui->scrollArea->setWidgetResizable(true);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::OpenFile);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenFile()
{
    main_task = "";

    open_file_string = QFileDialog::getExistingDirectory(nullptr, "Directory Dialog", "");

    int fileCount = 0;
    int dirCount = 0;

    countFilesAndDirs(open_file_string, fileCount, dirCount);

    ui->label->setText("файлов: " + QString::number(fileCount) + "\nпапок: " + QString::number(dirCount));
    label_2->setText(main_task);
}

void MainWindow::countFilesAndDirs(const QString &dirPath, int &fileCount, int &dirCount) {
    QDir dir(dirPath);
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

    for (const QFileInfo &fileInfo : list) {
        if (fileInfo.isDir()) {
            dirCount++;
            main_task.append(fileInfo.absoluteFilePath() + "\n{\n");
            countFilesAndDirs(fileInfo.absoluteFilePath(), fileCount, dirCount);
            main_task.append("}\n");
        } else if (fileInfo.isFile()) {
            fileCount++;
            main_task.append(fileInfo.absoluteFilePath() + '\n');
        }
    }
}

