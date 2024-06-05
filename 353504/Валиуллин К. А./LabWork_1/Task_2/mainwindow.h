#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "figure.h"
#include "figuretriangle.h"
#include "figurecircle.h"
#include "figurerhombus.h"
#include "figuresquare.h"
#include "figurerectangle.h"
#include "figurestar5.h"
#include "figurestar6.h"
#include "figurestar8.h"
#include "figurehexagon.h"
#include "figureoval.h"

#include "dialogtriangle.h"
#include "dialogcircle.h"
#include "dialogrhombus.h"
#include "dialogsquare.h"
#include "dialogrectangle.h"
#include "dialogstar.h"
#include "dialoghexagon.h"
#include "dialogoval.h"
#include "dialogsetxy.h"

#include <QMainWindow>
#include <QGraphicsItem>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>

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

signals:
    void transmitSideOfStar(int sideOfStar);

public slots:
    void ReceiveValuesOfStar(valuesOfStar &values);

private slots:
    void on_chooseFigure_currentIndexChanged(int index);
    void clearPreviosFigure();
    void moveUpSlot();
    void moveDownSlot();
    void moveRightSlot();
    void moveLeftSlot();
    void downScaleSlot();
    void upScaleSlot();
    void on_buttonClearAll_clicked();
    void setProperties();
    void on_buttonUpScale_pressed();
    void on_buttonUpScale_released();
    void on_buttonDownScale_pressed();
    void on_buttonDownScale_released();
    void on_buttonRight_pressed();
    void on_buttonRight_released();
    void on_buttonUp_pressed();
    void on_buttonUp_released();
    void on_buttonLeft_pressed();
    void on_buttonLeft_released();
    void on_buttonDown_released();
    void on_buttonDown_pressed();
    void on_setXY_clicked();
    void on_focusButton_clicked();
    void on_buttonRightRotation_clicked();
    void on_buttonLeftRotation_clicked();
    void on_buttonLeftRotation_pressed();
    void on_buttonLeftRotation_released();
    void on_buttonRightRotation_pressed();
    void on_buttonRightRotation_released();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Figure *figure = nullptr;
    QTimer *timer;
    DialogTriangle *formTriangle;
    DialogCircle *formCircle;
    DialogRhombus *formRhombus;
    DialogSquare *formSquare;
    DialogRectangle *formRectangle;
    DialogStar *formStar;
    DialogHexagon *formHexagon;
    DialogOval *formOval;
    DialogSetXY *formSetXY;
    int typeOfStar, sideOfStar, dialogStatus;
    QPointF previousPoint;
};

#endif // MAINWINDOW_H
