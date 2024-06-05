#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <unit.h>
#include <QVector>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QList>
#include <QEventLoop>
#include <QTimer>
#include <QRandomGenerator>
#include <QImage>
#include <QMessageBox>
#include <QGraphicsProxyWidget>
#include <QScrollBar>
#include "mine.h"
#include "end.h"
#include "swordsman.h"
#include "find.h"
#include "archer.h"
#include "basetower.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    double getDistance(QPointF point1, QPointF point2);

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    QList<Unit*> units;
    QList<Unit*> enemies;
    QList<Archer*> archers;
    QList<Archer*> archersE;
    QList<Swordsman*> swordsmans;
    QList<Swordsman*> swordsmansE;
    QList<QPointF> baseCoordinates;
    QList<Archer*> archerForDelete;
    QList<Swordsman*> swordForDelete;
    QList<Mine*> mines;
    QTimer *archerFightTimer = new QTimer();
    QTimer *archerEfightTimer = new QTimer();
    QTimer *swordFightTimer = new QTimer();
    QTimer *swordEfightTimer = new QTimer();
    QTimer *checkEnemyNum = new QTimer();
    QTimer *finder = new QTimer();
    QTimer *endT = new QTimer();
    QTimer *addMoney = new QTimer();

    BaseTower *baseTower = new BaseTower();
    int **map = new int*[48];

    int coins = 100;
    QPair<int, int> generateEmemyPos();
    QPair<int, int> generatePos();
    void checkEnemy();
    int numOfEnemy = 2;
    Find *find = new Find();

    QGraphicsPixmapItem *rock3;
    QGraphicsPixmapItem *rock4;

public slots:
    void archerFight();
    void archerEnemyFight();
    void swordFight();
    void swordEnemyFight();
    void generateEnemyArcher();
    void generateEnemySword();
    void findNear();
    void ending();
    void start();
    void coinAdd();

protected:
    void mousePressEvent(QMouseEvent *event) override;
private slots:
    void on_AddSword_clicked();
    void on_AddArcher_clicked();
    void on_Heal_clicked();
    void on_AddMine_clicked();
};
#endif // WIDGET_H
