#include "drawer.h"

Drawer::Drawer()
{
    image = QImage(2000, 2000, QImage::Format_RGB32);
    image.fill(Qt::white);

    painter.begin(&image);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    x = 100;
    y = 100;
}

void Drawer::drawStart(){
    //painter.setBrush(startColor);
    painter.drawEllipse(x, y, blockWidth, blockHeight);
    painter.drawText(x, y, blockWidth, blockHeight, Qt::AlignCenter, "Start");
    y = y + blockHeight;
}

void Drawer::drawInput(){
    //painter.setBrush(inputColor);
    painter.drawPolygon(QVector<QPoint>() << QPoint(x, y + blockHeight)
                                          << QPoint(x + blockWidth/4, y)
                                          << QPoint(x + blockWidth, y)
                                          << QPoint(x +blockWidth * 3/4, y + blockHeight));
    painter.drawText(x, y, blockWidth, blockHeight, Qt::AlignCenter, "Input");
    y = y + blockHeight;
}

void Drawer::drawProcess(){
    //painter.setBrush(processColor);
    painter.drawRoundedRect(x, y, blockWidth, blockHeight, 10, 10);
    painter.drawText(x, y, blockWidth, blockHeight, Qt::AlignCenter, "Action");
    y = y + blockHeight;
}

void Drawer::drawDecision(){
    //painter.setBrush(decisionColor);
    int halfWidth = blockWidth / 2;
    int halfHeight = blockHeight / 2;
    QVector<QPointF> points = {
        QPointF(x, y + halfHeight),    // Верхняя вершина
        QPointF(x + halfWidth, y),     // Правая вершина
        QPointF(x + blockWidth, y + halfHeight),    // Нижняя вершина
        QPointF(x + halfWidth, y + blockHeight)      // Левая вершина
    };

    painter.drawPolygon(points);
    painter.drawText(x, y, blockWidth, blockHeight, Qt::AlignCenter, "Condition");
    y = y + blockHeight;
}

void Drawer::drawOutput(){
    //painter.setBrush(outputColor);
    painter.drawPolygon(QVector<QPoint>() << QPoint(x, y + blockHeight)
                                          << QPoint(x + blockWidth/4, y)
                                          << QPoint(x + blockWidth, y)
                                          << QPoint(x +blockWidth * 3/4, y + blockHeight));

    painter.drawText(x, y, blockWidth, blockHeight, Qt::AlignCenter, "Output");
    y = y + blockHeight;
}

void Drawer::drawEnd(){
    //painter.setBrush(endColor);
    painter.drawEllipse(x, y, blockWidth, blockHeight);
    painter.drawText(x, y, blockWidth, blockHeight, Qt::AlignCenter, "Stop");
    painter.end();
}

void Drawer::drawLine(){
    int arrowX = x + blockWidth/ 2;
    int arrowY = y;
    painter.drawLine(arrowX, arrowY, arrowX, arrowY + blockSpacing);
    y = y + blockSpacing;
}

void Drawer::drawLoop(){
    QPolygon polygon;
    polygon << QPoint(x, y + blockHeight/2);
    polygon << QPoint(x + blockWidth/3, y);
    polygon << QPoint(x + blockWidth * 2/3, y);
    polygon << QPoint(x + blockWidth, y + blockHeight/2);
    polygon << QPoint(x + blockWidth * 2/3, y + blockHeight);
    polygon << QPoint(x + blockWidth/3, y + blockHeight);

    painter.drawPolygon(polygon);
    y = y + blockHeight;
}

QImage Drawer::returnImage(){
    return image;
}
