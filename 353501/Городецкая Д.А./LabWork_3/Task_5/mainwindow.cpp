#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDirIterator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::on_openButton_clicked()
{
    QString folderPath = QFileDialog::getExistingDirectory(this, "Выберите папку", QDir::homePath());

    if (!folderPath.isEmpty()) {
        QDir dir(folderPath);
        if (dir.exists()) {
            int subfolderCount = countSubfolders(folderPath);
            int fileCount = countFiles(folderPath);

            QMessageBox::information(this, "Статистика", QString("Количество подпапок: %1\nКоличество файлов: %2")
                                                             .arg(subfolderCount).arg(fileCount));
        } else {
            QMessageBox::critical(this, "Ошибка", "Выбранная папка не существует");
        }
    } else {
        QMessageBox::warning(this, "Предупреждение", "Папка не выбрана");
    }
}

int MainWindow::countSubfolders(const QString &folderPath)
{
    int count = 0;

    QDirIterator it(folderPath, QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        count++;
    }

    return count;
}

int MainWindow::countFiles(const QString &folderPath)
{
    int count = 0;

    QDirIterator it(folderPath, QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        count++;
    }

    return count;
}

MainWindow::~MainWindow()
{
    delete ui;
}
