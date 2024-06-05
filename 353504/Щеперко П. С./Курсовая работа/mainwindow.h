#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QComboBox>
#include <QGraphicsScene>
#include <QGraphicsPathItem>
#include <QMainWindow>
#include <QPainterPath>
#include <QTableWidget>
#include <QMap>
#include "bullet/bullet_cartridges_enums/_366TKM_cartridge.h"
#include "bullet/bullet_cartridges_enums/_545x39mm_cartridge.h"
#include "bullet/bullet_cartridges_enums/_762x54RmmR_cartridge.h"
#include "bullet/bullet_cartridges_enums/_9x18mm_cartridge.h"
#include "bullet/bullet_cartridges_enums/_9x19mm_cartridge.h"
#include "bullet/calibr.h"
#include "calculator.h"
#include "integration_method.h"
#include "qcustomplot.h"

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

private slots:
    void on_caliberComboBox_activated(int index);

    void on_caliber_366TKM_CartridgeComboBox_activated(int index);

    void on_caliber_9x19mm_CartridgeComboBox_activated(int index);

    void on_caliber_9x18mm_CartridgeComboBox_activated(int index);

    void on_caliber_545x39mm_CartridgeComboBox_activated(int index);

    void on_caliber_762x54mmR_CartridgeComboBox_activated(int index);

    void on_gunsightComboBox_currentIndexChanged(int index);

    void on_windSpeedVerticalSlider_valueChanged(int value);

    void on_comparisonCheckBox_stateChanged(int arg1);

    void on_caliberComboBox_2_activated(int index);

    void on_caliber_545x39mm_CartridgeComboBox_2_activated(int index);

    void on_caliber_762x54mmR_CartridgeComboBox_2_activated(int index);

    void on_caliber_366TKM_CartridgeComboBox_2_activated(int index);

    void on_caliber_9x18mm_CartridgeComboBox_2_activated(int index);

    void on_caliber_9x19mm_CartridgeComboBox_2_activated(int index);

    void on_calculatePushButton_clicked();

private:
    Ui::MainWindow *ui;


    QVector<QComboBox *> comboBoxes;
    QVector<QComboBox *> comboBoxes_2;
    QMap<QString, QVector<QComboBox *>> comboBoxesMap;
    QVector<QRadioButton *> methods;
    QVector<QRadioButton *> methods_2;
    QMap<QString, QVector<QRadioButton *>> methodsMap;

    Calculator *calculator;
    QGraphicsScene *scene;
    QPair<QCPGraph*, QCPGraph*> graph;
    QGraphicsPixmapItem *reticleItem;
    QPixmap *acogPixmap;
    QPixmap *psoPixmap;
    QPair<QGraphicsEllipseItem*, QGraphicsEllipseItem*> shotPoint;
    QVector<QWidget *> comparedWidgets;

    inline IntegrationMethod ClickedMethod(QString suffix = 0);

    inline void SetComparedWidgetsStatus(Qt::CheckState status);

    inline void ShowComboBox(Calibr calibr, QString suffix = 0);

    inline void SetPropertiesText(double muzzleVelocity,
                           double ballisticCoefficient,
                           double diameter,
                           double weight,
                           QString suffix = 0);
    inline void SetTableRowHeight(QTableWidget *table);
    inline void SetTableWidgets(QTableWidget *table);

    inline void SetCalculatorValues(QString suffix = 0);
    inline void SetTableValues(QTableWidget *table);
    inline void SetTableAlignCenter(QTableWidget *table);
    inline void SetTrajectory(QCPGraph *&graph, QColor color);
    inline void DrawPoint(QColor color, QGraphicsEllipseItem *&ellipse);
};
#endif // MAINWINDOW_H
