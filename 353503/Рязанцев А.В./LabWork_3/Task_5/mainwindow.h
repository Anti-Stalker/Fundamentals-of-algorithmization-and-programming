#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void setPath();
    void FilesCounter(QString);

private slots:
    void on_openButton_clicked();

private:
    Ui::MainWindow *ui;

    int total_dirs = 0;
    int total_files = 0;
    int depth = 1;

    QString output = "";

    QDir Directory;
};
#endif // MAINWINDOW_H
