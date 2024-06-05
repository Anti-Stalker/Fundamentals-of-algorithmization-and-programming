#include "Animal.h"

Animal::Animal(CustomGraphicsScene* sceneArg, QVector<Egg*>* _myEggVector,
                  QGraphicsItem* parent) : QGraphicsObject(parent)
{
    rng = new XORShiftPlusPlus(XORShiftPlusPlus::Rand(), XORShiftPlusPlus::Rand(), XORShiftPlusPlus::Rand());

    scene = sceneArg;
    _ptrToEggVec = _myEggVector;

    pathes.push_back("../resources/Hen-removebg-preview.png");
    pathes.push_back("../resources/Hen-removebg-preview-angled-transformed (1).png");

    QPixmap image(pathes[0]);
    if (image.isNull()) {
        qDebug() << "no picture found";
    }

    m_image = image.scaled(50, 50); 

    timerToRandomMoving = new QTimer();
    connect(timerToRandomMoving, &QTimer::timeout, this, &Animal::startRandomMoving);
    timerToRandomMoving->start(100);

    timerToFindGrass = new QTimer();
    connect(timerToFindGrass, &QTimer::timeout, this, &Animal::findGrass);
    timerToFindGrass->start(1000);

    timerChangeAnimationPictures = new QTimer();
    connect(timerChangeAnimationPictures, &QTimer::timeout, this, &Animal::startEatingAnimation); 
    
    timeForDurationAnimation = new QTimer();

    timerForMinusEatenGrass = new QTimer();
    connect(timerForMinusEatenGrass, &QTimer::timeout, this, &Animal::minusEatenGrass); 
    timerForMinusEatenGrass->start(2000);
    startTimeToMakeEgg();

    
}

Animal::~Animal(){
    delete timerToRandomMoving;
    delete timerToFindGrass;
    delete timerChangeAnimationPictures;
    delete timeForDurationAnimation;
}

void Animal::collectedEggsIncrement(Egg* eggToRemoveFromScene){
    scene->removeItem(eggToRemoveFromScene);
    emit updateCollectedEggsLabelSignal();
}

void Animal::makeEgg(){
    if(countEatenGrass > 4 && wasAnyGrassEaten){
        Egg* egg = new Egg();
        _ptrToEggVec->push_back(egg);
        scene->addItem(egg);
        egg->setZValue(0.5);
        egg->setPos(pos().x() + 25, pos().y() + 50);
        connect(egg, &Egg::eggWasCollected, this, &Animal::collectedEggsIncrement);
    }
    timerToMakeEgg->stop();
    delete timerToMakeEgg;
    startTimeToMakeEgg();
}

void Animal::startTimeToMakeEgg(){
    timerToMakeEgg = new QTimer();
    connect(timerToMakeEgg, &QTimer::timeout, this, &Animal::makeEgg);
    
    // std::random_device rd;
    // std::mt19937 gen(rd());
    // std::uniform_int_distribution<> dis(10000, 20000);
    int randomTimeToMakeEgg = rng->getRandomValue(10000, 20000);

    timerToMakeEgg->start(randomTimeToMakeEgg);
}

void Animal::startRandomMoving(){
    timerToRandomMoving->stop();
    QPropertyAnimation* animation = new QPropertyAnimation(this, "pos");
    // std::random_device rd;
    // std::mt19937 gen(rd());
    // std::uniform_int_distribution<int> distGeneratorX(270, 940);
    // std::uniform_int_distribution<int> distGeneratorY(340, 620);
    int x = rng->getRandomXPos();
    int y = rng->getRandomYPos();

    qreal distance = this->findDist(this->pos().x(), this->pos().y(), x, y);

    animation->setDuration(distance * 15); 
    animation->setStartValue(this->pos());
    animation->setEndValue(QPoint(x, y));

    animation->start();
    connect(animation, &QPropertyAnimation::finished, this, &Animal::startRandomTimer);
}

void Animal::startRandomTimer(){
  timerToRandomMoving->start(100);
}

void Animal::findGrass(){
    if(!scene->grassVec.isEmpty() && this->countEatenGrass < 6){
        findClosestGrass(QPointF(this->pos().x(), this->pos().y()));
        QPropertyAnimation* animation = new QPropertyAnimation(this, "pos");
        connect(animation, &QPropertyAnimation::finished, this, &Animal::finishedFindingGrass);

        animation->setDuration(this->closestDistance * 6); 
        animation->setStartValue(QPoint(this->pos().x(), this->pos().y()));
        animation->setEndValue(QPoint(this->distX, this->distY));

        animation->start();
    }
}


void Animal::finishedFindingGrass(){
      this->timerChangeAnimationPictures->start(70);
      connect(this->timeForDurationAnimation, &QTimer::timeout, this, &Animal::stopAnimation);
      this->timeForDurationAnimation->start(700);
}

int Animal::detectGrassIndexByPos(qreal posXOfCollidingGrass, qreal posYOfCollidingGrass){
    for(int i = 0; i < scene->grassVec.size(); i++) {
        if(scene->grassVec[i]->pos().x() == posXOfCollidingGrass && scene->grassVec[i]->pos().y() == posYOfCollidingGrass){
            return i;
        }
    }
    return NO_SUCH_GRASS_INDEX;
}

void Animal::stopAnimation(){
    if(!scene->grassVec.empty()){
        indexOfGrassToRemove = NO_SUCH_GRASS_INDEX;
        qreal posXOfCollidingGrass;
        qreal posYOfCollidingGrass;
        QList<QGraphicsItem*> collidingItems = this->collidingItems();
        foreach (QGraphicsItem* item, collidingItems) {
            Grass* grass = dynamic_cast<Grass*>(item);
            if (grass) {    
                posXOfCollidingGrass = grass->pos().x();
                posYOfCollidingGrass = grass->pos().y();
                indexOfGrassToRemove = detectGrassIndexByPos(posXOfCollidingGrass, posYOfCollidingGrass);
                if(grass->amount == 1){
                    if(indexOfGrassToRemove != NO_SUCH_GRASS_INDEX){
                        scene->removeItem(scene->grassVec[indexOfGrassToRemove]);
                        scene->grassVec[indexOfGrassToRemove]->amount--;
                    }
                }
                else{
                    if(indexOfGrassToRemove != NO_SUCH_GRASS_INDEX){   
                        scene->grassVec[indexOfGrassToRemove]->amount--;
                    }
                }
                scene->update(); 
                break;
            }
        }
        if(indexOfGrassToRemove != NO_SUCH_GRASS_INDEX){
            qDebug() << "no such grass" << "\n";
            if(scene->grassVec[indexOfGrassToRemove]->amount == 0){
                scene->grassVec.erase(scene->grassVec.begin() + indexOfGrassToRemove);   
            }
            if(this->countEatenGrass + 6 <= 10){
                this->countEatenGrass += 6;
                wasAnyGrassEaten = true;
            }
            else{
                this->countEatenGrass = 10;
                wasAnyGrassEaten = true;
            }
        }
    }
    else {
        qDebug() << "deleting or removing grass that doesnt exist, thouth the animation finished";
    }

    timerToRandomMoving->start(100);
    this->stopEatingAnimation();
}

void Animal::findClosestGrass(QPointF animPos){
    closestDistance = std::numeric_limits<qreal>::max();
    for(int i = 0; i < scene->grassVec.size(); i++){
            qreal tempDist = findDist(animPos.x(), animPos.y(), scene->grassVec[i]->pos().x(), scene->grassVec[i]->pos().y());
            qreal tempX = scene->grassVec[i]->pos().x();
            qreal tempY = scene->grassVec[i]->pos().y();
            if(tempDist < closestDistance){
                closestDistance = tempDist;
                distX = tempX;
                distY = tempY;
            }
    }
}

qreal Animal::findDist(qreal animPosX, qreal animPosY, qreal posX, qreal posY){
    return sqrt((animPosX - posX) * (animPosX - posX) + (animPosY - posY) * (animPosY - posY));
}

void Animal::minusEatenGrass(){
    if(this->countEatenGrass > 0){
      this->countEatenGrass--;
    }
    else{
        scene->removeItem(this);
        timerForMinusEatenGrass->stop();
        disconnect(timerForMinusEatenGrass, &QTimer::timeout, this, &Animal::minusEatenGrass); 
        delete timerForMinusEatenGrass;
        emit deleteHenSignal(this);
    }
}

void Animal::startEatingAnimation(){
    QList<QGraphicsItem*> collidingItems = this->collidingItems();
            if(currentPath == pathes[0]){
                currentPath = pathes[1];
            }
            else{
                currentPath = pathes[0];
            }

            QPixmap image(currentPath);

            m_image = image.scaled(50, 50); 
            update();
}

void Animal::stopEatingAnimation(){
    QPixmap image(pathes[0]);
    m_image = image.scaled(50, 50); 
    update();
    timerChangeAnimationPictures->stop();
    disconnect(this->timeForDurationAnimation, &QTimer::timeout, this, &Animal::stopAnimation);
    timeForDurationAnimation->stop();
}

QRectF Animal::boundingRect() const 
{
    return QRectF(0, 0, m_image.width(), m_image.height() + 15);
}

void Animal::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) 
{
    painter->setBrush(Qt::blue);
    painter->drawRect(0, m_image.height() + 5, m_image.width() / 10 * countEatenGrass, 10);
    painter->setPen(Qt::white);
    for(int i = 0; i < countEatenGrass; i++){
        painter->drawLine(0 + m_image.width() / 10 * i, m_image.height() + 5, 0 + m_image.width() / 10 * i, m_image.height() + 15);
    }
    painter->drawPixmap(0, 0, m_image);
}


