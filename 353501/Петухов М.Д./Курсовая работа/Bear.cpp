#include "Bear.h"
#include "globals.h"

Bear::Bear(CustomGraphicsScene* sceneArg, QGraphicsItem* parent) : QGraphicsObject(parent)
{
    scene = sceneArg;

    rng = new XORShiftPlusPlus(XORShiftPlusPlus::Rand(), XORShiftPlusPlus::Rand(), XORShiftPlusPlus::Rand());

    animationTimer = new QTimer();
    connect(animationTimer, &QTimer::timeout, this, &Bear::changeAnimationFrame);
    animationTimer->start(500);

    timerToCheckCollidingHens = new QTimer();
    connect(timerToCheckCollidingHens, &QTimer::timeout, this, &Bear::checkCollidingHens);
    timerToCheckCollidingHens->start(100);

    timerToChangeDirection = new QTimer();
    connect(timerToChangeDirection, &QTimer::timeout, this, &Bear::changeDirection);
    timerToChangeDirection->start(100);

    pathes.push_back("../resources/Bear1.png");
    pathes.push_back("../resources/Bear2.png");
    pathes.push_back("../resources/Bear1.png");
    pathes.push_back("../resources/Bear3.png");

    pathesToCagePictures.push_back("../resources/Cage-4RemovedBack.png");
    pathesToCagePictures.push_back("../resources/Cage-3RemovedBack.png");
    pathesToCagePictures.push_back("../resources/Cage-2RemovedBack.png");
    pathesToCagePictures.push_back("../resources/Cage-1RemovedBack.png");
    pathesToCagePictures.push_back("../resources/CageFinalRemovedBack.png");

    isMouseOnBear = false;
    isMouseOnThisBear = false;
    setAcceptHoverEvents(true);
    setFlag(ItemIsSelectable, true);
    setFlag(ItemIsFocusable, true);
}


void Bear::hoverEnterEvent(QGraphicsSceneHoverEvent*) 
{
    isMouseOnBear = true;
    isMouseOnThisBear = true;
    QGraphicsItem::update();
}
//------------------------------------------------------------------------------
void Bear::hoverLeaveEvent(QGraphicsSceneHoverEvent*) 
{
    isMouseOnBear = false;
    isMouseOnThisBear = false;
    QGraphicsItem::update();
}
//------------------------------------------------------------------------------
void Bear::mousePressEvent(QGraphicsSceneMouseEvent *aEvent) 
{   
    damage++;
    coefSlowdown *= 1.2;
    if(damage == health){
        emit bearWasRemoved();
        scene->removeItem(this);
        delete this;
        isMouseOnBear = false;
    }
    QGraphicsItem::update();
}
void Bear::changeDirection(){
    timerToChangeDirection->stop();

    // std::random_device rd;
    // std::mt19937 gen(rd());
    // std::uniform_int_distribution<int> distGeneratorX(270, 940);
    // std::uniform_int_distribution<int> distGeneratorY(340, 620);
    int distX = rng->getRandomXPos();
    int distY = rng->getRandomYPos();
    qreal distance = this->findDist(this->pos().x(), this->pos().y(), distX, distY);

    QPropertyAnimation* animation = new QPropertyAnimation(this, "pos");
    animation->setDuration(distance * 23 * coefSlowdown); 
    animation->setStartValue(QPoint(this->pos().x(), this->pos().y()));
    animation->setEndValue(QPoint(distX, distY));
    animation->start();    

    connect(animation, &QPropertyAnimation::finished, this, &Bear::startTimerToChangeDirection);
}

qreal Bear::findDist(qreal animPosX, qreal animPosY, qreal posX, qreal posY){
    return sqrt((animPosX - posX) * (animPosX - posX) + (animPosY - posY) * (animPosY - posY));
}

void Bear::startTimerToChangeDirection(){
  timerToChangeDirection->start(100);
}

void Bear::checkCollidingHens(){
    QList<QGraphicsItem*> collidingItems = this->collidingItems();
    foreach (QGraphicsItem* item, collidingItems) {
        Animal* hen = dynamic_cast<Animal*>(item);
        if (hen) {        
            scene->removeItem(hen);
            delete hen;
        }
    }
}

void Bear::setImage(int frameNumber){
    QPixmap image(pathes[frameNumber]);
    if (image.isNull()) {
        qDebug() << "no picture found";
    }
    m_image = image.scaled(90, 90);
    update();
}

void Bear::changeAnimationFrame(){
    if(frameNumber < 3){
        frameNumber++;
    }
    else{
        frameNumber = 0;
    }
    setImage(frameNumber);
}

QRectF Bear::boundingRect() const 
{
    return QRectF(0, 0, m_image.width() - 20, m_image.height() - 20);
}

void Bear::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) 
{   
    painter->drawPixmap(0, 0, m_image);
    if(damage != -1){
        QPixmap image(pathesToCagePictures[damage]);
        if (image.isNull()) {
            qDebug() << "no picture found";
        }
        painter->drawPixmap(-20, -20, image.scaled(m_image.width() + 50, m_image.height() + 40));
    }
}


