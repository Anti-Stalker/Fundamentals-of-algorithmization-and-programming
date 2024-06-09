#include "towers.h"

towers::towers() {}


void towers::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);



    painter->setPen(Qt::gray);
    painter->setBrush(Qt::gray);
    painter->drawRect(-305, 30, 10, 240);
    painter->drawRect(-5, 30, 10, 240);
    painter->drawRect(295, 30, 10, 240);

    painter->drawRect(-430, 250, 260, 25);
    painter->drawRect(-130, 250, 260, 25);
    painter->drawRect(+170, 250, 260, 25);



    for(int i = 10 - n;i < 10;++i){
        if(diskUnused[i]){
            diskPos[i].setX(towerX[0] - diskWidth[i] / 2);
            diskPos[i].setY(250 - (i + 1) * diskHeight);
            diskUnused[i] = false;
        }
        if(i % 2 == 0){

            painter->setBrush(Qt::blue);
            painter->setPen(Qt::black);



            painter->drawRect(diskPos[i].x(),diskPos[i].y() + posN[n - 1],diskWidth[i],diskHeight);
            continue;
        }


        painter->setBrush(Qt::cyan);
         painter->setPen(Qt::black);

        painter->drawRect(diskPos[i].x(),diskPos[i].y() + posN[n - 1],diskWidth[i],diskHeight);
    }

    if (isChanging) {
        lastEmptyPositionA = 230 - n * diskHeight;
    }
}


QRectF towers::boundingRect() const
{
    return QRectF(0, 0, 10, 10);
}

void towers::changeNumberOfRings(int num)
{
    n = num;
    update();
}

void towers::setN(int num)
{
    n = num;
    update();
}
void towers::animate(int num, char from, char to)
{
    int i = num;

    // Up
    if (!onY[i])
    {
        if (diskPos[i].y() > posMinN[n - 1])
        {
            diskPos[i].setY(diskPos[i].y() - 5);
        }
        else
        {
            onX[i] = true;
        }
    }


    if (from == 'A' && to == 'B')
    {
        if (onX[i])
        {
            if (diskPos[i].x() < 0 - diskWidth[i] / 2)
            {
                diskPos[i].setX(diskPos[i].x() + 5);
            }
            else
            {
                onX[i] = false;
                onY[i] = true;
            }
        }
        // Down
        if (onY[i])
        {
            if (diskPos[i].y() < lastEmptyPositionB)
            {
                diskPos[i].setY(diskPos[i].y() + 5);
            }
            else
            {
                lastEmptyPositionB -= 20;
                onY[i] = false;
                finished = true;
            }
        }
    }


    if (from == 'A' && to == 'C')
    {
        if (onX[i])
        {
            if (diskPos[i].x() < 300 - diskWidth[i] / 2)
            {
                diskPos[i].setX(diskPos[i].x() + 5);
            }
            else
            {
                onX[i] = false;
                onY[i] = true;
            }
        }
        // Down
        if (onY[i])
        {
            if (diskPos[i].y() < lastEmptyPositionC)
            {
                diskPos[i].setY(diskPos[i].y() + 5);
            }
            else
            {
                lastEmptyPositionC -= 20;
                onY[i] = false;
                finished = true;
            }
        }
    }


    if (from == 'B' && to == 'A')
    {
        if (onX[i])
        {
            if (diskPos[i].x() > -300 - diskWidth[i] / 2)
            {
                diskPos[i].setX(diskPos[i].x() - 5);
            }
            else
            {
                onX[i] = false;
                onY[i] = true;
            }
        }
        // Down
        if (onY[i])
        {
            if (diskPos[i].y() < lastEmptyPositionA)
            {
                diskPos[i].setY(diskPos[i].y() + 5);
            }
            else
            {
                lastEmptyPositionA -= 20;
                onY[i] = false;
                finished = true;
            }
        }
    }

    if (from == 'B' && to == 'C')
    {
        if (onX[i])
        {
            if (diskPos[i].x() < 300 - diskWidth[i] / 2)
            {
                diskPos[i].setX(diskPos[i].x() + 5);
            }
            else
            {
                onX[i] = false;
                onY[i] = true;
            }
        }
        // Down
        if (onY[i])
        {
            if (diskPos[i].y() < lastEmptyPositionC)
            {
                diskPos[i].setY(diskPos[i].y() + 5);
            }
            else
            {
                lastEmptyPositionC -= 20;
                onY[i] = false;
                finished = true;
            }
        }
    }

    if (from == 'C' && to == 'A')
    {
        if (onX[i])
        {
            if (diskPos[i].x() > -300 - diskWidth[i] / 2)
            {
                diskPos[i].setX(diskPos[i].x() - 5);
            }
            else
            {
                onX[i] = false;
                onY[i] = true;
            }
        }
        // Down
        if (onY[i])
        {
            if (diskPos[i].y() < lastEmptyPositionA)
            {
                diskPos[i].setY(diskPos[i].y() + 5);
            }
            else
            {
                lastEmptyPositionA -= 20;
                onY[i] = false;
                finished = true;
            }
        }
    }

    if (from == 'C' && to == 'B')
    {
        if (onX[i])
        {
            if (diskPos[i].x() > 0 - diskWidth[i] / 2)
            {
                diskPos[i].setX(diskPos[i].x() - 5);
            }
            else
            {
                onX[i] = false;
                onY[i] = true;
            }
        }
        // Down
        if (onY[i])
        {
            if (diskPos[i].y() < lastEmptyPositionB)
            {
                diskPos[i].setY(diskPos[i].y() + 5);
            }
            else
            {
                lastEmptyPositionB -= 20;
                onY[i] = false;
                finished = true;
            }
        }
    }
    update();
}
