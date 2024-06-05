#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include "vertex.h"


Vertex::Vertex(QGraphicsItem *parent)
    : QGraphicsEllipseItem(parent)
{
    QPen p = pen();
    p.setWidth(3);
    p.setColor(QColor(0, 160, 230));
    setPen(p);

    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

    QFont font;
    font.setPointSize(20);
    textItem = new QGraphicsTextItem(this);
    textItem->setFont(font);
    textItem->setTextInteractionFlags(Qt::NoTextInteraction);
    connect(textItem->document(), &QTextDocument::contentsChanged, this, &Vertex::updateNumber);
}

void Vertex::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
//        qDebug() << isButtonClicked;
        if (isButtonClicked) {
//            qDebug() << "Зашло в клик, должен вызваться сигнал";
//            qDebug() << m_vertexNumber;
            emit vertexSelected(m_vertexNumber);
            isButtonClicked = false;  // Сбрасываем флаг после обработки сигнала
        }
        if (event->modifiers() == Qt::ShiftModifier) {
            setSelected(true);
        }
        else if (event->modifiers() == Qt::AltModifier) {
            double radius = boundingRect().width() / 2.0;
            QPointF topLeft = boundingRect().topLeft();
            m_centerPointF = QPointF(topLeft.x() + pos().x() + radius, topLeft.y() + pos().y() + radius);
            QPointF pos = event->scenePos();
            double dist = sqrt(pow(m_centerPointF.x()-pos.x(), 2) + pow(m_centerPointF.y()-pos.y(), 2));
            if (dist / radius > 0.8) {
                m_bResizing = true;
            }
            else {
                m_bResizing = false;
            }
        }
        else {
            QGraphicsItem::mousePressEvent(event);
            event->accept();
        }
    } else if (event->button() == Qt::RightButton) {
         emit rightClicked(this);
    }
}

void Vertex::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if ((event->modifiers() == Qt::AltModifier) && m_bResizing) {

        QPointF pos = event->scenePos();
        double dist = sqrt(pow(m_centerPointF.x()-pos.x(), 2) + pow(m_centerPointF.y()-pos.y(), 2));
        setRect(m_centerPointF.x()-this->pos().x()-dist, m_centerPointF.y()-this->pos().y()-dist, dist*2, dist*2);
        qreal radius = boundingRect().width() / 2.0;
        emit vertexResized( radius);
    }
    else if(event->modifiers() != Qt::AltModifier) {

        QGraphicsItem::mouseMoveEvent(event);
        emit vertexMoved();
        qreal radius = boundingRect().width() / 2.0;
        emit vertexResized( radius);
    }
}

void Vertex::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if ((event->modifiers() == Qt::AltModifier) && m_bResizing) {
        m_bResizing = false;
    } else {
        QGraphicsItem::mouseReleaseEvent(event);
    }
}

void Vertex::setVertexNumber(int number) {

    m_vertexNumber = number;
    textItem->setPlainText(QString::number(number));
    textItem->setPos(boundingRect().center() - textItem->boundingRect().center());
}

void Vertex::updateNumber() {
    qreal number = textItem->toPlainText().toInt();
    setVertexNumber1(number);
}
void Vertex::setVertexNumber1(int number) {

    m_vertexNumber = number;
    textItem->setPos(boundingRect().center() - textItem->boundingRect().center());
}

int Vertex::type() const
{
    return UserType + 1;
}

void Vertex::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    textItem->setTextInteractionFlags(Qt::TextEditable);
}

void Vertex::onEditingFinished() {
    textItem->setTextInteractionFlags(Qt::NoTextInteraction);
}



