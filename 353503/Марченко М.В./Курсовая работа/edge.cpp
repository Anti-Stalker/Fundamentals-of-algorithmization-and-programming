#include "edge.h"
#include <QPainter>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>

Edge::Edge(Vertex *startVertex, Vertex *endVertex, bool isDirect, QGraphicsItem *parent)
    : QGraphicsPathItem(parent)
{
    start = startVertex;
    end = endVertex;
    directed = isDirect;

    QRectF rectStart = start->boundingRect();
    QPointF localCenterStart = rectStart.center();
    QPointF startPos = start->mapToScene(localCenterStart);

    QRectF rectEnd = end->boundingRect();
    QPointF localCenterEnd = rectEnd.center();
    QPointF endPos = end->mapToScene(localCenterEnd);

    qreal radiusStart = rectStart.width() / 2.0;
    qreal radiusEnd = rectEnd.width() / 2.0;

    qreal angle = atan2(endPos.y() - startPos.y(), endPos.x() - startPos.x());

    QPointF newStartPos = startPos + QPointF(cos(angle) * radiusStart, sin(angle) * radiusStart);
    QPointF newEndPos = endPos - QPointF(cos(angle) * radiusEnd, sin(angle) * radiusEnd);

    if (start == end) {
        QPainterPath path;
        qreal startAngle = 0;
        qreal spanAngle = 270;

        QPointF squareCenter = QPointF(newEndPos.x(), newEndPos.y()-radiusStart);

        QRectF rect(squareCenter.x() - radiusStart, squareCenter.y() - radiusStart, 2*radiusStart, 2*radiusStart);
        path.arcMoveTo(rect, startAngle);
        path.arcTo(rect, startAngle, spanAngle);
        setPath(path);

    } else  {
        QPainterPath path;
        path.moveTo(newStartPos);
        path.lineTo(newEndPos);
        setPath(path);
        if (directed) {
            qreal arrowSize = 6;
            QPointF startPoint = path.pointAtPercent(0);
            QPointF endPoint = path.pointAtPercent(1);

            qreal dx = endPoint.x() - startPoint.x();
            qreal dy = endPoint.y() - startPoint.y();

            double angle = ::acos(dx / sqrt(dx * dx + dy * dy));
            if (dy>= 0)
                angle = (M_PI * 2) - angle;

            QPointF arrowP1 = newEndPos + QPointF(sin(angle - M_PI / 3) * arrowSize,
                                                  cos(angle - M_PI / 3) * arrowSize);
            QPointF arrowP2 = newEndPos + QPointF(sin(angle - M_PI + M_PI / 3) * arrowSize,
                                                  cos(angle - M_PI + M_PI / 3) * arrowSize);

            arrowHead << path.pointAtPercent(1.0) << arrowP1 << arrowP2;
        }

    }

    QPen newPen = pen();
    newPen.setWidthF(2.5);
    setPen(newPen);
    setFlags(QGraphicsItem::ItemIsSelectable);

    QFont font;
    font.setPointSize(13);
    textItem = new QGraphicsTextItem(this);

    textItem->setFont(font); // Примените шрифт к textItem
    textItem->setTextInteractionFlags(Qt::TextEditable);
    textItem->setPlainText("0");
   // connect(textItem->document(), &QTextDocument::contentsChanged, this, &Edge::centerText);
    connect(textItem->document(), &QTextDocument::contentsChanged, this, &Edge::updateWeight);
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    QPen myPen = pen();
    if (isSelected()) {
        myPen.setStyle(Qt::DashLine);
    } else {
        myPen.setStyle(Qt::SolidLine);
    }
    painter->setPen(myPen);

    if (start == end) {
        painter->drawPath(path());
    } else if (directed) {
        painter->setBrush(Qt::black);
        painter->drawPath(path());
        painter->drawPolygon(arrowHead);
    } else {
        painter->drawPath(path());
    }

}

void Edge::updateWeight()
{
    qreal number = textItem->toPlainText().toDouble();
    setWeight(number);
}

Vertex *Edge::startVertex() const
{
    return start;
}

Vertex *Edge::endVertex() const
{
    return end;
}

int Edge::getStart()
{
    return start->vertexNumber();
}

int Edge::getEnd()
{
    return end->vertexNumber();
}

void Edge::setWeight(qreal number)
{

    m_weight = number;
   // textItem->setPlainText(QString::number(number));

   // textItem->setPos(boundingRect().center() - textItem->boundingRect().center());
    centerText();
}

void Edge::setHighlighted(bool highlighted) {
    QPen myPen = pen();
    if (highlighted) {
        myPen.setColor(Qt::red);  // Изменяем цвет на красный
    } else {
        myPen.setColor(Qt::black);  // Изменяем цвет на черный
    }
    setPen(myPen);
}

void Edge::centerText()
{
    QRectF rectStart = start->boundingRect();
    QPointF localCenterStart = rectStart.center();
    QPointF startPos = start->mapToScene(localCenterStart);

    QRectF rectEnd = end->boundingRect();
    QPointF localCenterEnd = rectEnd.center();
    QPointF endPos = end->mapToScene(localCenterEnd);

    QPointF center = boundingRect().center();
    QPointF textOffset(0, -10);
    qreal angle = atan2(endPos.y() - startPos.y(), endPos.x() - startPos.x());

    qreal dx = textOffset.y() * qSin(angle);
    qreal dy = -textOffset.y() * qCos(angle);

    QPointF textPos = center + QPointF(dx, dy) - textItem->boundingRect().center();
    textItem->setPos(textPos);
}

void Edge::updatePosition() {
    QRectF rectStart = start->boundingRect();
    QPointF localCenterStart = rectStart.center();
    QPointF startPos = start->mapToScene(localCenterStart);

    QRectF rectEnd = end->boundingRect();
    QPointF localCenterEnd = rectEnd.center();
    QPointF endPos = end->mapToScene(localCenterEnd);

    qreal radius = rectStart.width() / 2.0;

    qreal angle = atan2(endPos.y() - startPos.y(), endPos.x() - startPos.x());

    QPointF newStartPos = startPos + QPointF(cos(angle) * radius, sin(angle) * radius);
    QPointF newEndPos = endPos - QPointF(cos(angle) * radius, sin(angle) * radius);

    if (textItem != nullptr) {
        centerText();
    }

    if (start == end) {
        QPainterPath path;
        qreal startAngle = 0;
        qreal spanAngle = 270;

        QPointF squareCenter = QPointF(newEndPos.x(), newEndPos.y() - radius);

        QRectF rect(squareCenter.x() - radius, squareCenter.y() - radius, 2 * radius, 2 * radius);
        path.arcMoveTo(rect, startAngle);
        path.arcTo(rect, startAngle, spanAngle);
        setPath(path);
    } else {
        QPainterPath path;
        path.moveTo(newStartPos);
        path.lineTo(newEndPos);
        setPath(path);

        if (directed) {
            qreal arrowSize = 6;
            QPointF startPoint = path.pointAtPercent(0);
            QPointF endPoint = path.pointAtPercent(1);

            qreal dx = endPoint.x() - startPoint.x();
            qreal dy = endPoint.y() - startPoint.y();

            double arrowAngle = ::acos(dx / sqrt(dx * dx + dy * dy));
            if (dy >= 0)
                arrowAngle = (M_PI * 2) - arrowAngle;

            QPointF arrowP1 = newEndPos + QPointF(sin(arrowAngle - M_PI / 3) * arrowSize,
                                                  cos(arrowAngle - M_PI / 3) * arrowSize);
            QPointF arrowP2 = newEndPos + QPointF(sin(arrowAngle - M_PI + M_PI / 3) * arrowSize,
                                                  cos(arrowAngle - M_PI + M_PI / 3) * arrowSize);

            arrowHead.clear();
            arrowHead << path.pointAtPercent(1.0) << arrowP1 << arrowP2;
        }
    }
}

void Edge::updateSize() {

    QRectF rectStart = start->boundingRect();
    QPointF localCenterStart = rectStart.center();
    QPointF startPos = start->mapToScene(localCenterStart);
    qreal radiusStart = rectStart.width() / 2.0;

    QRectF rectEnd = end->boundingRect();
    QPointF localCenterEnd = rectEnd.center();
    QPointF endPos = end->mapToScene(localCenterEnd);
    qreal radiusEnd = rectEnd.width() / 2.0;

    qreal angle = atan2(endPos.y() - startPos.y(), endPos.x() - startPos.x());

    QPointF newStartPos = startPos + QPointF(cos(angle) * radiusStart, sin(angle) * radiusStart);
    QPointF newEndPos = endPos - QPointF(cos(angle) * radiusEnd, sin(angle) * radiusEnd);

    if (textItem != nullptr) {
        centerText();
    }

    if (start == end) {
        QPainterPath path;
        qreal startAngle = 0;
        qreal spanAngle = 270;
        QPointF squareCenter = QPointF(newEndPos.x(), newEndPos.y() - radiusStart);
        QRectF rect(squareCenter.x() - radiusStart, squareCenter.y() - radiusStart, 2 * radiusStart, 2 * radiusStart);
        path.arcMoveTo(rect, startAngle);
        path.arcTo(rect, startAngle, spanAngle);
        setPath(path);
    } else {
        QPainterPath path;
        path.moveTo(newStartPos);
        path.lineTo(newEndPos);
        setPath(path);

        if (directed) {
            qreal arrowSize = 6;
            QPointF startPoint = path.pointAtPercent(0);
            QPointF endPoint = path.pointAtPercent(1);

            qreal dx = endPoint.x() - startPoint.x();
            qreal dy = endPoint.y() - startPoint.y();

            double arrowAngle = ::acos(dx / sqrt(dx * dx + dy * dy));
            if (dy >= 0)
                arrowAngle = (M_PI * 2) - arrowAngle;

            QPointF arrowP1 = newEndPos + QPointF(sin(arrowAngle - M_PI / 3) * arrowSize,
                                                  cos(arrowAngle - M_PI / 3) * arrowSize);
            QPointF arrowP2 = newEndPos + QPointF(sin(arrowAngle - M_PI + M_PI / 3) * arrowSize,
                                                  cos(arrowAngle - M_PI + M_PI / 3) * arrowSize);
            arrowHead.clear();
            arrowHead << path.pointAtPercent(1.0) << arrowP1 << arrowP2;
        }
    }
}


void Edge::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
//        qDebug() << "edge left clicked.";
        setSelected(true);
    }
    else  {
        QGraphicsItem::mousePressEvent(event);
        event->accept();
    }
}


