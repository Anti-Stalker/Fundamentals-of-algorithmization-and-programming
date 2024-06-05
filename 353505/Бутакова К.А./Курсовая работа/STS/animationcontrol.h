#ifndef ANIMATIONCONTROL_H
#define ANIMATIONCONTROL_H

#include <QPropertyAnimation>
#include <QMovie>
#include <QPixmap>
#include <QEventLoop>

class CharacterUnit;
class QMovie;

class AnimationControl : public QObject{
    Q_OBJECT

private:
    QEventLoop* waiter;
    QMovie* gif_container;
    CharacterUnit* RoleInteracting;
    QPixmap* currentPixmap;
    QString InteractingStatus;

    void loadGif(QString address);

public:
    AnimationControl(QObject* parent = 0);
    ~AnimationControl();


signals:
    void sendUpdatePng(CharacterUnit*, QString);
    void sendUpdateGif(CharacterUnit*, QPixmap);

public slots:
    void StatusRequest(CharacterUnit* role, QString status);
    void StopGif(CharacterUnit* role);

};

#endif
