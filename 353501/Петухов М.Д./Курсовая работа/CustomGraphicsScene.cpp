#include "CustomGraphicsScene.h" 
#include "globals.h"

CustomGraphicsScene::CustomGraphicsScene(QObject* parent)
    : QGraphicsScene(parent){
        drawWaterInWell();
    }

void CustomGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent* event) 
{
    if(!isMouseOnProduct && !isMouseOnBear && !isMouseOnEgg && waterToGrowGrass > 0){
        grassWasGrowed = true;
        pos = event->scenePos();

        if(pos.x() > 270 && pos.x() < 940 && pos.y() < 620 && pos.y() > 340){
            if(!checkIfSuchGrassAlreadyExist()){
                Grass* grass = new Grass();
                grass->setPos(pos.x() - grass->m_width / 2, pos.y() - grass->m_height / 2);
                addItem(grass);
                grassVec.push_back(grass);
                waterToGrowGrass--;
            }
        }
            
        drawWaterInWell();
        QGraphicsScene::mousePressEvent(event);
    }
}

bool CustomGraphicsScene::checkIfSuchGrassAlreadyExist(){
    for(int i = 0; i < grassVec.size(); i++){
        if((pos.x() == grassVec[i]->pos().x() + (grassVec[i]->m_width) / 2) && (pos.y() == grassVec[i]->pos().y() + (grassVec[i]->m_height) / 2)){
            return true;
        }
    }
    return false;
}

void CustomGraphicsScene::drawWaterInWell(){
    if((pos.x() > 270 && pos.x() < 940 && pos.y() < 620 && pos.y() > 340) || !grassWasGrowed){
        for(int i = 0; i < rectVector.size(); i++){
            this->removeItem(rectVector[i]);
        }
        rectVector.clear();
        for(int i = 0; i < waterToGrowGrass; i++){
            QGraphicsRectItem* rect = new QGraphicsRectItem(590 - 20, 140 + (121 / 6) * i, 15, 15);
            rect->setBrush(Qt::blue);
            rectVector.push_back(rect);
            this->addItem(rect);
        }
    }
}