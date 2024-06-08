#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qrcode.h>
#include <QVector>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QFileDialog>

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
    void printQrCode(QrCode&);
private:
    void SetStyleSheet();
private slots:
    void on_radioButtonLow_clicked();
    void on_radioButtonMedium_clicked();
    void on_radioButtonQuartile_clicked();
    void on_radioButtonHigh_clicked();
    void on_checkBox_stateChanged(int);
    void on_checkBox_clicked();
    void on_pushButton_clicked();
    void on_spinBoxMax_valueChanged(int);
    void on_spinBoxMin_valueChanged(int);
    void on_spinBoxMask_valueChanged(int);
    void on_save_triggered();
private:
    QrCode* qr;
    QrCode::Ecc ecc;
    QBrush brush;
    QPen pen;
    QColor background;
    QColor qrColor;
    uint8_t maxVersion;
    uint8_t minVersion;
    int mask;
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
