#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "QVBoxLayout"
#include "QTextEdit"
#include "QSpinBox"
#include "QPushButton"
#include "QFileDialog"
#include "QDebug"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent);
    ~MainWindow() override = default;

private:
    QString openedFolderPath;

    QWidget* converterWidget;
    QVBoxLayout *hLayout;

    QTextEdit *resultTextEdit;
    QPushButton *openDirButton;
    QPushButton *calculateButton;

    void OpenDirectory();
    void Calculate();
    void CalculateFolders(const QString& path, int8_t& folderCount, int8_t& fileCount);
};
#endif // MAINWINDOW_H
