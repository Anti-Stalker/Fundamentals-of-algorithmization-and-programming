#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include<QProcess>
#include <qgraphicsscene.h>
#include "drawer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum class BlockType {
    Start, Input, Process, Decision, Output, End
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QMap<BlockType, QString> blocks;
    QMap<BlockType, std::vector<BlockType>> exampleFlowchart;

private slots:
    void openFile();
    void displayCode(const QString &filePath);
    void analysis(QString code);
    int analysisCount(QString code);
    void loadRandomCode(const QString directory);
    void saveImage();
    int generateRandomNumber(QString code);
    void calculateDeterminant(QString code);
    int calculateMatrixDeterminant();

    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    int matrixLabels[3][3];
    Drawer draw;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
