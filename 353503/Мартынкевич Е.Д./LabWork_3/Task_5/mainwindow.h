#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void OpenFile();
    void countFilesAndDirs(const QString &dirPath, int &fileCount, int &dirCount);

private:
    Ui::MainWindow *ui;
    QString open_file_string;
    QString main_task;
    QLabel* label_2;
};
#endif // MAINWINDOW_H
