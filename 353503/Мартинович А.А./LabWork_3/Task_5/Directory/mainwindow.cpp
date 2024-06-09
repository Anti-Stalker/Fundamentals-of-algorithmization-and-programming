#include "mainwindow.h"
#include "QDebug"

const int8_t MAX_HEIGHT = 15;
const int8_t START = 1;
const int8_t FINISH = 2;
const int8_t TMP_NUMBER = 6;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , converterWidget(new QWidget(this))
    , hLayout(new QVBoxLayout())
    , openDirButton(new QPushButton("Выбрать директорию", this))
    , resultTextEdit(new QTextEdit(this))
    , calculateButton(new QPushButton("Рассчитать", this))
    , openedFolderPath("")
{
    setCentralWidget(converterWidget);
    converterWidget->setLayout(hLayout);

    resultTextEdit->setReadOnly(true);

    hLayout->addWidget(openDirButton);
    hLayout->addWidget(resultTextEdit);
    hLayout->addWidget(calculateButton);


    connect(openDirButton, &QPushButton::clicked, this, &MainWindow::OpenDirectory);
    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::Calculate);
}

void MainWindow::OpenDirectory()
{
    openedFolderPath = QFileDialog::getExistingDirectory(nullptr, "Выберите папку", QDir::homePath());
    if (!openedFolderPath.isEmpty()) {
        resultTextEdit->setText("Выбраная директория: " + openedFolderPath);
    } else {
        qDebug() << "Директория не выбрана не выбрана.";
    }
}

void MainWindow::Calculate()
{
    if (!openedFolderPath.isEmpty()) {
        int8_t fileCount = 0;
        int8_t folderCount = 0;
        CalculateFolders(openedFolderPath, folderCount, fileCount);
        resultTextEdit->append("Количество папок: " + QString::number(folderCount) + "\n");
        resultTextEdit->append("Количество файлов: " + QString::number(fileCount) + "\n");
    }
}

void MainWindow::CalculateFolders(const QString &path, int8_t &folderCount, int8_t &fileCount)
{
    QDir dir(path);
    const QFileInfoList& entries = dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);

    for (const QFileInfo& entry : entries) {
        if (entry.isDir()) {
            ++folderCount;
            resultTextEdit->append("Папка: " + entry.filePath() + entry.fileName() + "\n");
            CalculateFolders(entry.filePath(), folderCount, fileCount);
        } else {
            ++fileCount;
            resultTextEdit->append("Файл: " + entry.filePath() + entry.fileName() + "\n");
        }

    }
}




