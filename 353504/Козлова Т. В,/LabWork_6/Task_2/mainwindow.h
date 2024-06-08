#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>
#include <FileInputOutput.h>

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
    ~MainWindow();

private:

private slots:

    void on_inputButton_clicked();

    void on_outputButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_clearButton_clicked();

    void on_addButton_clicked();

    void on_addButtonBin_clicked();

    void on_countInput_valueChanged(int arg1);

    void on_addArray_clicked();

private:
    Ui::MainWindow *ui;
    Plant plant;
    QVector<float> array;
};
#endif // MAINWINDOW_H
