#include "animationcontrol.h"
#include "chatacterunit.h"

AnimationControl::AnimationControl(QObject* parent) : QObject(parent)
{
    gif_container = new QMovie;
    currentPixmap = new QPixmap;
    waiter = new QEventLoop;
    connect(gif_container, &QMovie::finished, [=](){ StopGif(RoleInteracting); });
}

AnimationControl::~AnimationControl()
{
    delete gif_container;
    delete currentPixmap;
}
void AnimationControl::StatusRequest(CharacterUnit* role, QString status)
{
    RoleInteracting = role;
    QString s;
    QString roleClass = role->getClass();
    s += ":/characters/";
    s += roleClass;
    currentPixmap->load(s + "/stand.png");

    InteractingStatus = status;
    if(status == "MOVE")
    {
        s += "/move.gif";
        gif_container->setSpeed(150);
    }
    else if(status == "ATTACK")
    {
        s += "/attack.gif";
        gif_container->setSpeed(100);
    }
    else if(status == "DIE")
    {
        s += "/die.gif";
        gif_container->setSpeed(100);
    }
    loadGif(s);
}

void AnimationControl::loadGif(QString address)
{
    gif_container->setFileName(address);
    connect(gif_container, &QMovie::updated, [=](){ emit sendUpdateGif(RoleInteracting, gif_container->currentPixmap()); });
    gif_container->start();

}

void AnimationControl::StopGif(CharacterUnit* role)
{
    gif_container->stop();
    disconnect(gif_container, &QMovie::updated, nullptr, nullptr);
    QString s;
    s += ":/characters/";
    s += role->getClass();
    if(InteractingStatus != "DIE")
    {
        s += "/stand.png";
    }
    else
    {
        s += "/dead.png";
    }
    emit sendUpdatePng(RoleInteracting, s);
    RoleInteracting = nullptr;
}
