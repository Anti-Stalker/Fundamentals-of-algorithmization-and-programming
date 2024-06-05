#include "widget.h"
#include "ui_widget.h"
#include <QFile>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->coin->setText(QString::number(coins));
    ui->hp->setText(QString::number(baseTower->hp));

    QPixmap pixmap("://cursor.png");
    QPixmap scaled = pixmap.scaled(26, 26, Qt::KeepAspectRatio);
    QCursor cursor(scaled, 0, 0);
    this->setCursor(cursor);

    QImage back("://map.jpg");
    scene->setBackgroundBrush(back);

    ui->graphicsView->setTransform(QTransform::fromScale(1.0735, 1.195));

    for (int i = 0; i < 48; ++i)
    {
        map[i] = new int [24];
    }

    for (int x = 0; x <= 1200; x += 25)
        scene->addLine(x, 0, x, 600, QPen(Qt::black));

    for (int y = 0; y <= 600; y += 25)
        scene->addLine(0, y, 1200, y, QPen(Qt::black));

    QPixmap bush("://09.png");
    QPixmap resizeBush = bush.scaled(50, 50,Qt::KeepAspectRatio);
    QGraphicsPixmapItem *bush1 = scene->addPixmap(resizeBush);
    QGraphicsPixmapItem *bush2 = scene->addPixmap(resizeBush);
    QGraphicsPixmapItem *bush3 = scene->addPixmap(resizeBush);
    bush1->setPos(150, 160);
    bush2->setPos(950, 110);
    bush3->setPos(850, 460);
    map[6][6] = 1;
    map[6][7] = 1;
    map[7][6] = 1;
    map[7][7] = 1;
    map[38][4] = 1;
    map[38][5] = 1;
    map[39][4] = 1;
    map[39][5] = 1;
    map[34][18] = 1;
    map[34][19] = 1;
    map[35][18] = 1;
    map[35][19] = 1;

    QPixmap rock("://06.png");
    QPixmap resizeRock = rock.scaled(50, 50,Qt::KeepAspectRatio);
    QPixmap resizeRock2 = rock.scaled(75, 75,Qt::KeepAspectRatio);
    QGraphicsPixmapItem *rock1 = scene->addPixmap(resizeRock);
    QGraphicsPixmapItem *rock2 = scene->addPixmap(resizeRock);
    rock3 = scene->addPixmap(resizeRock2);
    rock4 = scene->addPixmap(resizeRock2);
    QGraphicsPixmapItem *rock5 = scene->addPixmap(resizeRock);
    QGraphicsPixmapItem *rock6 = scene->addPixmap(resizeRock);
    rock1->setPos(200, 510);
    rock2->setPos(900, 260);
    rock3->setPos(300, 85);
    rock4->setPos(700, 510);
    rock5->setPos(300, 310);
    rock6->setPos(750, 110);
    map[8][20] = 1;
    map[8][21] = 1;
    map[9][20] = 1;
    map[9][21] = 1;
    map[36][10] = 1;
    map[36][11] = 1;
    map[37][10] = 1;
    map[37][11] = 1;
    map[12][3] = 1;
    map[12][4] = 1;
    map[12][5] = 1;
    map[13][3] = 1;
    map[13][4] = 1;
    map[13][5] = 1;
    map[14][3] = 1;
    map[14][4] = 1;
    map[14][5] = 1;
    map[28][20] = 1;
    map[28][21] = 1;
    map[28][22] = 1;
    map[29][20] = 1;
    map[29][21] = 1;
    map[29][22] = 1;
    map[30][20] = 1;
    map[30][21] = 1;
    map[30][22] = 1;
    map[30][4] = 1;
    map[30][5] = 1;
    map[31][4] = 1;
    map[31][5] = 1;
    map[12][12] = 1;
    map[12][13] = 1;
    map[13][12] = 1;
    map[13][13] = 1;


    scene->addItem(baseTower);
    baseTower->setPos(525, 225);

    for (int i = 525; i < 675; ++i)
    {
        for (int j = 225; j < 375; ++j)
        {
            map[i / 25][j / 25] = 1;
        }
    }

    for (int i = 500; i < 700; i += 25)
    {
        baseCoordinates.append(QPointF(i / 25, 200 / 25));
        baseCoordinates.append(QPointF(i / 25, 400 / 25));
    }
    for (int i = 225; i < 375; i += 25)
    {
        baseCoordinates.append(QPointF(500 / 25, i / 25));
        baseCoordinates.append(QPointF(700 / 25, i / 25));
    }

    Swordsman *sw1 = new Swordsman;
    sw1->isEnemy = false;
    swordsmans.append(sw1);
    sw1->setPos(450, 300);
    scene->addItem(sw1);
    sw1->from = QPointF(450 / 25, 300 / 25);
    map[450 / 25][300 / 25] = 1;

    Swordsman *sw2 = new Swordsman;
    swordsmans.append(sw2);
    sw2->isEnemy = false;
    sw2->setPos(725, 275);
    scene->addItem(sw2);
    sw2->from = QPointF(725 / 25, 275 / 25);
    map[725 / 25][275 / 25] = 1;

    Swordsman *sw3 = new Swordsman;
    swordsmans.append(sw3);
    sw3->isEnemy = false;
    sw3->setPos(600, 425);
    scene->addItem(sw3);
    sw3->from = QPointF(600 / 25, 425 / 25);
    map[600 / 25][425 / 25] = 1;

    Swordsman *sw4 = new Swordsman;
    swordsmans.append(sw4);
    sw4->isEnemy = false;
    sw4->setPos(575, 150);
    scene->addItem(sw4);
    sw4->from = QPointF(575 / 25, 150 / 25);
    map[575 / 25][150 / 25] = 1;

    Archer *arch1 = new Archer();
    archers.append(arch1);
    arch1->isEnemy = false;
    arch1->setPos(475, 175);
    scene->addItem(arch1);
    arch1->from = QPointF(475 / 25, 175 / 25);
    map[475 / 25][175 / 25] = 1;

    Archer *arch2 = new Archer();
    archers.append(arch2);
    arch2->isEnemy = false;
    arch2->setPos(700, 400);
    scene->addItem(arch2);
    arch2->from = QPointF(700 / 25, 400 / 25);
    map[700 / 25][400 / 25] = 1;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    QPointF to = event->pos();
    to.setX(to.x() / 1.0735 - 10);
    to.setY(to.y() / 1.195 - 10);
    to.setX((int)(to.x() / 25));
    to.setY((int)(to.y() / 25));
    if (to.y() >= 24 || to.y() >= 48) return;
    foreach (Archer *archer, archers)
    {
        if (archerForDelete.contains(archer)) continue;
        if (archer->selected)
        {
            archer->selected = false;
            archer->update();
            if (map[(int)to.x()][(int)to.y()] == 1) return;
            archer->move(find->aStar(map, archer->from.x(), archer->from.y(), to.x(), to.y()));
            map[(int)archer->from.x()][(int)archer->from.y()] = 0;
            map[(int)archer->to.x()][(int)archer->to.y()] = 1;
            return;
        }

        else if (to == archer->from)
        {
            archer->selected = true;
            archer->update();
        }
    }
    foreach (Swordsman *sword, swordsmans)
    {
        if (swordForDelete.contains(sword)) continue;
        if (sword->selected)
        {
            sword->selected = false;
            sword->update();
            if (map[(int)to.x()][(int)to.y()] == 1) return;
            sword->move(find->aStar(map, sword->from.x(), sword->from.y(), to.x(), to.y()));
            map[(int)sword->from.x()][(int)sword->from.y()] = 0;
            map[(int)sword->to.x()][(int)sword->to.y()] = 1;
            return;
        }

        else if (to == sword->from)
        {
            sword->selected = true;
            sword->update();
        }
    }
}

void Widget::on_AddSword_clicked()
{
    if (coins >= 20)
    {
        Swordsman *sw = new Swordsman();
        sw->isEnemy = false;
        QPair<int, int> pos = generatePos();
        swordsmans.append(sw);
        sw->setPos(pos.first * 25, pos.second * 25);
        map[pos.first][pos.second] = 1;
        sw->from = QPoint(pos.first, pos.second);
        scene->addItem(sw);
        coins -= 20;
        ui->coin->setText(QString::number(coins));
    }
}

double Widget::getDistance(QPointF point1, QPointF point2)
{
    return sqrt((point1.x() - point2.x()) * (point1.x() - point2.x()) + (point1.y() - point2.y()) * (point1.y() - point2.y()));
}

QPair<int, int> Widget::generateEmemyPos()
{
    int x = 0, y = 0;
    do
    {
        int edge = QRandomGenerator::global()->bounded(4);
        switch (edge) {
        case 0: // верхняя граница
            x = 0;
            y = QRandomGenerator::global()->bounded(24);
            break;
        case 1: // правая граница
            x = QRandomGenerator::global()->bounded(47);
            y = 23;
            break;
        case 2: // нижняя граница
            x = 47;
            y = QRandomGenerator::global()->bounded(23);
            break;
        case 3: // левая граница
            x = QRandomGenerator::global()->bounded(47);
            y = 0;
            break;
        }
    } while (map[x][y] == 1);

    QPair<int, int> t;
    t.first = x;
    t.second = y;
    return t;
}

QPair<int, int> Widget::generatePos()
{
    int x = 0, y = 0;
    do
    {
        int edge = QRandomGenerator::global()->bounded(4);
        switch (edge) {
        case 0: // верхняя граница
            x = QRandomGenerator::global()->bounded(10, 38);
            y = QRandomGenerator::global()->bounded(5, 8);
            break;
        case 1: // правая граница
            x = QRandomGenerator::global()->bounded(28, 38);
            y = QRandomGenerator::global()->bounded(5, 19);
            break;
        case 2: // нижняя граница
            x = QRandomGenerator::global()->bounded(10, 38);
            y = QRandomGenerator::global()->bounded(16, 19);
            break;
        case 3: // левая граница
            x = QRandomGenerator::global()->bounded(10, 20);
            y = QRandomGenerator::global()->bounded(5, 19);
            break;
        }
    } while (map[x][y] == 1);

    QPair<int, int> t;
    t.first = x;
    t.second = y;
    return t;
}

void Widget::findNear()
{
    foreach (Archer *archerE, archersE)
    {
        if (archerForDelete.contains(archerE) || archerE->inMove) continue;
        int minWay = 100;
        std::vector<std::pair<int, int>> path;

        foreach (Archer *archer, archers)
        {
            if (archerForDelete.contains(archer) /*|| archer->inMove*/) continue;
            map[(int)archer->from.x()][(int)archer->from.y()] = 0;
            int way = find->aStar(map, archerE->from.x(), archerE->from.y(), archer->from.x(), archer->from.y()).size();
            if (way < minWay)
            {
                minWay = way;
                path = find->aStar(map, archerE->from.x(), archerE->from.y(), archer->from.x(), archer->from.y());
            }
            map[(int)archer->from.x()][(int)archer->from.y()] = 1;
        }
        foreach (Swordsman *sword, swordsmans)
        {
            if (swordForDelete.contains(sword) /*|| sword->inMove*/) continue;
            map[(int)sword->from.x()][(int)sword->from.y()] = 0;
            int way = find->aStar(map, archerE->from.x(), archerE->from.y(), sword->from.x(), sword->from.y()).size();
            if (way < minWay)
            {
                minWay = way;
                path = find->aStar(map, archerE->from.x(), archerE->from.y(), sword->from.x(), sword->from.y());
            }
            map[(int)sword->from.x()][(int)sword->from.y()] = 1;
        }
        for (int i = 0; i < baseCoordinates.size(); ++i)
        {
            int way = find->aStar(map, archerE->from.x(), archerE->from.y(), baseCoordinates[i].x(), baseCoordinates[i].y()).size();
            if (way < minWay)
            {
                minWay = way;
                path = find->aStar(map, archerE->from.x(), archerE->from.y(), baseCoordinates[i].x(), baseCoordinates[i].y());
            }
        }
        if(path.size() > 4)
        {
            path.erase(path.end() - 3, path.end());
        }
        else
        {
            continue;
        }
        archerE->move(path);
        map[path.back().first][path.back().second] = 1;
    }

    foreach (Swordsman *swordE, swordsmansE)
    {
        if (swordForDelete.contains(swordE) || swordE->inMove) continue;
        int minWay = 100;
        std::vector<std::pair<int, int>> path;
        foreach (Swordsman *sword, swordsmans)
        {
            if (swordForDelete.contains(sword) || sword->inMove) continue;
            map[(int)sword->from.x()][(int)sword->from.y()] = 0;
            int way = find->aStar(map, swordE->from.x(), swordE->from.y(), sword->from.x(), sword->from.y()).size();
            if (way < minWay)
            {
                minWay = way;
                path = find->aStar(map, swordE->from.x(), swordE->from.y(), sword->from.x(), sword->from.y());
            }
            map[(int)sword->from.x()][(int)sword->from.y()] = 1;
        }
        foreach (Archer *archer, archers)
        {
            if (archerForDelete.contains(archer) || archer->inMove) continue;
            map[(int)archer->from.x()][(int)archer->from.y()] = 0;
            int way = find->aStar(map, swordE->from.x(), swordE->from.y(), archer->from.x(), archer->from.y()).size();
            if (way < minWay)
            {
                minWay = way;
                path = find->aStar(map, swordE->from.x(), swordE->from.y(), archer->from.x(), archer->from.y());
            }
            map[(int)archer->from.x()][(int)archer->from.y()] = 1;
        }
        for (int i = 0; i < baseCoordinates.size(); ++i)
        {
            int way = find->aStar(map, swordE->from.x(), swordE->from.y(), baseCoordinates[i].x(), baseCoordinates[i].y()).size();
            if (way < minWay)
            {
                minWay = way;
                path = find->aStar(map, swordE->from.x(), swordE->from.y(), baseCoordinates[i].x(), baseCoordinates[i].y());
            }
        }
        if (path.size() == 0) continue;
        path.pop_back();
        swordE->move(path);
        map[path.back().first][path.back().second] = 1;
    }
}

void Widget::ending()
{
    if (baseTower->hp <= 0)
    {
        disconnect(archerFightTimer, &QTimer::timeout, this, &Widget::archerFight);
        disconnect(archerEfightTimer, &QTimer::timeout, this, &Widget::archerEnemyFight);
        disconnect(swordFightTimer, &QTimer::timeout, this, &Widget::swordFight);
        disconnect(swordEfightTimer, &QTimer::timeout, this, &Widget::swordEnemyFight);
        disconnect(finder, &QTimer::timeout, this, &Widget::findNear);
        disconnect(endT, &QTimer::timeout, this, &Widget::ending);
        disconnect(checkEnemyNum, &QTimer::timeout, this, &Widget::checkEnemy);
        disconnect(addMoney, &QTimer::timeout, this, &Widget::coinAdd);
        QEventLoop loop;
        QTimer::singleShot(3000, &loop, SLOT(quit()));
        loop.exec();
        update();
        foreach(Mine *mine, mines)
        {
            mine->hp = 0;
        }
        End *end = new End();
        end->finalScore = coins;
        end->openFile(coins);
        end->shellSort(end->scores, end->scores.size());
        end->printFinal();
        end->show();
        this->close();
    }
}

void Widget::start()
{
    this->showMaximized();
    archerEfightTimer->start(3000);
    archerFightTimer->start(3000);
    swordFightTimer->start(1000);
    swordEfightTimer->start(1000);
    connect(archerFightTimer, &QTimer::timeout, this, &Widget::archerFight);
    connect(archerEfightTimer, &QTimer::timeout, this, &Widget::archerEnemyFight);
    connect(swordFightTimer, &QTimer::timeout, this, &Widget::swordFight);
    connect(swordEfightTimer, &QTimer::timeout, this, &Widget::swordEnemyFight);
    finder->start(1000);
    connect(finder, &QTimer::timeout, this, &Widget::findNear);
    endT->start(1000);
    connect(endT, &QTimer::timeout, this, &Widget::ending);
    addMoney->start(3000);
    connect(addMoney, &QTimer::timeout, this, &Widget::coinAdd);

    generateEnemySword();
    generateEnemyArcher();
    checkEnemy();
    checkEnemyNum->start(30000);
    connect(checkEnemyNum, &QTimer::timeout, this, &Widget::checkEnemy);
}

void Widget::coinAdd()
{
    coins += 10 * mines.size();
    ui->coin->setText(QString::number(coins));
}

void Widget::checkEnemy()
{
    generateEnemyArcher();
    generateEnemySword();
    numOfEnemy += 1;
}

void Widget::archerFight()
{
    foreach (Archer *archer, archers)
    {
        if (archerForDelete.contains(archer)) continue;
        bool hit = false;
        foreach (Archer *archerE, archersE)
        {
            if (getDistance(archer->from, archerE->from) <= archerE->range)
            {
                if (archerForDelete.contains(archerE)) continue;
                hit = true;
                archerE->getDamage();
                archerE->health -= 30;
                if (archerE->health < 0)
                {
                    if (scene->items().contains(archerE))
                    {
                        scene->removeItem(archerE);
                        archerForDelete.push_back(archerE);
                        map[(int)archerE->from.x()][(int)archerE->from.y()] = 0;
                        coins += 50;
                        ui->coin->setText(QString::number(coins));
                    }
                }
                break;
            }
        }
        if (!hit)
        {
            foreach (Swordsman *swordsmanE, swordsmansE)
            {
                if (swordForDelete.contains(swordsmanE)) continue;
                if (getDistance(archer->from, swordsmanE->from) <= archer->range)
                {
                    hit = true;
                    swordsmanE->getDamage();
                    swordsmanE->health -= 30;
                    if (swordsmanE->health < 0)
                    {
                        if (scene->items().contains(swordsmanE))
                        {
                            scene->removeItem(swordsmanE);
                            swordForDelete.append(swordsmanE);
                            map[(int)swordsmanE->from.x()][(int)swordsmanE->from.y()] = 0;
                            coins += 50;
                            ui->coin->setText(QString::number(coins));
                        }
                    }
                    break;
                }
            }
        }
    }
}

void Widget::archerEnemyFight()
{
    foreach (Archer *archerE, archersE)
    {
        if (archerForDelete.contains(archerE)) continue;
        bool hit = false;
        foreach (Archer *archer, archers)
        {
            if (archerForDelete.contains(archer)) continue;
            if (getDistance(archer->from, archerE->from) <= archerE->range)
            {
                hit = true;
                archer->getDamage();
                archer->health -= 30;
                if (archer->health < 0)
                {
                    if (scene->items().contains(archer))
                    {
                        map[(int)archer->from.x()][(int)archer->from.y()] = 0;
                        scene->removeItem(archer);
                        archerForDelete.append(archer);
                    }
                }
                break;
            }
        }
        if (!hit)
        {
            foreach (Swordsman *swordsman, swordsmans)
            {
                if (getDistance(swordsman->from, archerE->from) <= archerE->range)
                {
                    if (swordForDelete.contains(swordsman)) continue;
                    hit = true;
                    swordsman->getDamage();
                    swordsman->health -= 30;
                    if (swordsman->health < 0)
                    {
                        if (scene->items().contains(swordsman))
                        {
                            map[(int)swordsman->from.x()][(int)swordsman->from.y()] = 0;
                            scene->removeItem(swordsman);
                            swordForDelete.append(swordsman);
                        }
                    }
                    break;
                }
            }
        }
        if (!hit)
        {
            for(int i = 0; i < baseCoordinates.size(); ++i)
            {
                if (getDistance(baseCoordinates[i], archerE->from) <= archerE->range)
                {
                    baseTower->getDamage();
                    baseTower->hp -= 30;
                    if (baseTower->hp <= 0)
                    {
                        ui->hp->setText(QString::number(0));
                        return;
                    }
                    else
                    {
                        ui->hp->setText(QString::number(baseTower->hp));
                    }
                    break;
                }
            }
        }
    }
}

void Widget::swordFight()
{
    foreach (Swordsman *swordsman, swordsmans)
    {
        if (swordForDelete.contains(swordsman)) continue;
        bool hit = false;
        foreach (Swordsman *swordsmanE, swordsmansE)
        {
            if (getDistance(swordsman->from, swordsmanE->from) <= swordsmanE->range)
            {
                if (swordForDelete.contains(swordsmanE)) continue;
                hit = true;
                swordsmanE->getDamage();
                swordsmanE->health -= 30;
                if (swordsmanE->health < 0)
                {
                    if (scene->items().contains(swordsmanE))
                    {
                        scene->removeItem(swordsmanE);
                        swordForDelete.append(swordsmanE);
                        map[(int)swordsmanE->from.x()][(int)swordsmanE->from.y()] = 0;
                        coins += 50;
                        ui->coin->setText(QString::number(coins));
                    }
                }
                break;
            }
        }
        if (!hit)
        {
            foreach (Archer *archerE, archersE)
            {
                if (archerForDelete.contains(archerE)) continue;
                if (getDistance(archerE->from, swordsman->from) <= swordsman->range)
                {
                    archerE->getDamage();
                    archerE->health -= 30;
                    if (archerE->health < 0)
                    {
                        if (scene->items().contains(archerE))
                        {
                            scene->removeItem(archerE);
                            archerForDelete.append(archerE);
                            map[(int)archerE->from.x()][(int)archerE->from.y()] = 0;
                            coins += 50;
                            ui->coin->setText(QString::number(coins));
                        }
                    }
                    break;
                }
            }
        }
    }
}

void Widget::swordEnemyFight()
{
    foreach (Swordsman *swordsmanE, swordsmansE)
    {
        if (swordForDelete.contains(swordsmanE)) continue;
        bool hit = false;
        foreach (Swordsman *swordsman, swordsmans)
        {
            if (swordForDelete.contains(swordsman)) continue;
            if (getDistance(swordsman->from, swordsmanE->from) <= swordsmanE->range)
            {
                hit = true;
                swordsman->getDamage();
                swordsman->health -= 30;
                if (swordsman->health < 0)
                {
                    if (scene->items().contains(swordsman))
                    {
                        map[(int)swordsman->from.x()][(int)swordsman->from.y()] = 0;
                        scene->removeItem(swordsman);
                        swordForDelete.append(swordsman);
                    }
                }
                break;
            }
        }
        if (!hit)
        {
            foreach (Archer *archer, archers)
            {
                if (archerForDelete.contains(archer)) continue;
                if (getDistance(archer->from, swordsmanE->from) <= swordsmanE->range)
                {
                    hit = true;
                    archer->getDamage();
                    archer->health -= 30;
                    if (archer->health < 0)
                    {
                        if (scene->items().contains(archer))
                        {
                            map[(int)archer->from.x()][(int)archer->from.y()] = 0;
                            scene->removeItem(archer);
                            archerForDelete.append(archer);
                        }
                    }
                    break;
                }
            }
        }
        if (!hit)
        {
            for(int i = 0; i < baseCoordinates.size(); ++i)
            {
                if (getDistance(baseCoordinates[i], swordsmanE->from) <= swordsmanE->range)
                {
                    baseTower->getDamage();
                    baseTower->hp -= 30;
                    if (baseTower->hp <= 0)
                    {
                        ui->hp->setText(QString::number(0));
                        return;
                    }
                    else
                    {
                        ui->hp->setText(QString::number(baseTower->hp));
                    }
                    break;
                }
            }
        }
    }
}

void Widget::generateEnemyArcher()
{
    for (int i = 0; i < numOfEnemy / 2; ++i)
    {
        Archer *ar = new Archer();
        QPair<int, int> pos = generateEmemyPos();
        archersE.append(ar);
        ar->setPos(pos.first * 25, pos.second * 25);
        map[pos.first][pos.second] = 1;
        ar->from = QPoint(pos.first, pos.second);
        scene->addItem(ar);
    }
}

void Widget::generateEnemySword()
{
    for (int i = 0; i < numOfEnemy; ++i)
    {
        Swordsman *sw = new Swordsman();
        QPair<int, int> pos = generateEmemyPos();
        sw->setPos(pos.first * 25, pos.second * 25);
        map[pos.first][pos.second] = 1;
        sw->from = QPoint(pos.first, pos.second);
        scene->addItem(sw);
        swordsmansE.push_back(sw);
    }
}

void Widget::on_AddArcher_clicked()
{
    if (coins >= 30)
    {
        Archer *ar = new Archer();
        QPair<int, int> pos = generatePos();
        ar->isEnemy = false;
        archers.append(ar);
        ar->setPos(pos.first * 25, pos.second * 25);
        map[pos.first][pos.second] = 1;
        ar->from = QPoint(pos.first, pos.second);
        scene->addItem(ar);
        coins -= 30;
        ui->coin->setText(QString::number(coins));
    }
}

void Widget::on_Heal_clicked()
{
    if (coins >= 100)
    {
        if (baseTower->hp == 2000) return;
        coins -= 100;
        if (baseTower->hp < 1500)
            baseTower->hp += 500;
        else baseTower->hp = 2000;

        ui->coin->setText(QString::number(coins));
        ui->hp->setText(QString::number(baseTower->hp));
    }
}


void Widget::on_AddMine_clicked()
{
    if (mines.size() <= 2 && coins >= 50)
    {
        coins -= 50;
        ui->coin->setText(QString::number(coins));
        Mine *mine = new Mine();
        mines.append(mine);
        scene->addItem(mine);
        if (mines.size() == 1)
        {
            mine->setPos(300, 85);
            scene->removeItem(rock3);
        }
        else if (mines.size() == 2)
        {
            mine->setPos(700, 510);
            scene->removeItem(rock4);
            ui->AddMine->setEnabled(false);
        }
    }

}
