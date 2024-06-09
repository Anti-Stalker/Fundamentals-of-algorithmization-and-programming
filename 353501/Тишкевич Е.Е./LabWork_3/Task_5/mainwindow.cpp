#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(): ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->openB, &QPushButton::pressed, this, &MainWindow::openFolder);
    ui->tree->setColumnWidth(0, 400);
}

void MainWindow::openFolder()
{
    QString Path = QFileDialog::getExistingDirectory(
        nullptr, "Select the folder", QDir::homePath());

    if (Path.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Select the folder");
        return;
    }

    ui->tree->clear();
    QTreeWidgetItem *rootDir = new QTreeWidgetItem(ui->tree);
    rootDir->setText(0, Path);

    updTree(Path, rootDir);
}

QPair<long, long> MainWindow::updTree(const QString &folderPath, QTreeWidgetItem *parentTree)
{
    QDir folder(folderPath);
    QFileInfoList entries = folder.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Files);

    int folderCount = 0;
    int fileCount = 0;

    for (const QFileInfo &entry : entries) {

        if (entry.isDir())
        {
            QTreeWidgetItem *subfolderTree = new QTreeWidgetItem(parentTree);
            subfolderTree->setText(0, entry.fileName());

            QPair<long, long> childCount = updTree(entry.filePath(), subfolderTree);
            folderCount += (1 + childCount.first);
            fileCount += childCount.second;
            parentTree->setText(2, QString::number(fileCount));

        }

        else if (entry.isFile())
        {
            QTreeWidgetItem *fileTree = new QTreeWidgetItem(parentTree);
            fileTree->setText(0, entry.fileName());
            ++fileCount;
        }
    }

    parentTree->setText(1, QString::number(folderCount));
    parentTree->setText(2, QString::number(fileCount));

    QPair<long, long> finalInfo {folderCount, fileCount};
    return finalInfo;
}
