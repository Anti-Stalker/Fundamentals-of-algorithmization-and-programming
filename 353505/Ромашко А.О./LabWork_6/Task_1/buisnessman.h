#ifndef BUISNESSMAN_H
#define BUISNESSMAN_H

#include <QDebug>
class Buisnessman
{
public:
    Buisnessman(){
        skin.cost = 100;
        skin.floatSkin = 1.2323423;
        skin.wear='d';
        skin.unique = 0;
        for(int i  =0;i<10;i++)
            skin.name[i] = char(i*10%255);
        for(int i  =0;i<3;i++)
            skin.playerId[i] = i*5;
    }

    int cost(){return skin.cost;}
    double floatSkin(){return skin.floatSkin;}
    char wear(){return skin.wear;}
    bool unique(){return skin.unique;}
    char *name(){return skin.name;}
    int *idPlayer(){return skin.playerId;}

    void cost(int v){ skin.cost=v;}
    void floatSkin(double v){ skin.floatSkin=v;}
    void wear(char v){ skin.wear = v;}
    void unique(bool v){ skin.unique = v;}
    void name(char v[10]){
        for (int i = 0; i < 10; i++) {
            skin.name[i] = v[i];
        }
    }
    void idPlayer(int v[2]){
        for (int i = 0; i < 3; i++) {
            skin.playerId[i] = v[i];
        }
    }
    void idPlayer(int &v){
        for(int i =0; i <3;i++)
        {
            skin.playerId[i] = v*i;
        }
    }
    void initializeSkinptr(){
        Skin localSkin;
        Skin* ptrSkin = &localSkin;
        ptrSkin->cost = 200;
        ptrSkin->floatSkin = 2.4646846;
        ptrSkin->wear = 'b';
        ptrSkin->unique = true;
        for (int i = 0; i < 10; i++) {
            ptrSkin->name[i] = 'A' + i;
        }
        for (int i = 0; i < 3; i++) {
            ptrSkin->playerId[i] = i + 10;
        }
        this->skin=localSkin;

        qDebug() << "Cost:" << ptrSkin->cost;
        qDebug() << "Float Skin:" << ptrSkin->floatSkin;
        qDebug() << "Wear:" << ptrSkin->wear;
        qDebug() << "Unique:" << ptrSkin->unique;
        qDebug() << "Name:" << ptrSkin->name;
        qDebug() << "Player ID:";
        for (int i = 0; i < 3; i++) {
            qDebug() << ptrSkin->playerId[i];
        }}
    void initializeSkinref(){
        Skin localSkin;
        Skin& refSkin = localSkin;
        refSkin.cost = 300;
        refSkin.floatSkin = 3.696927;
        refSkin.wear = 'c';
        refSkin.unique = false;
        for (int i = 0; i < 10; i++) {
            refSkin.name[i] = 'Z' - i;
        }
        for (int i = 0; i < 3; i++) {
            refSkin.playerId[i] = i + 20;
        }
        this->skin=localSkin;

        qDebug() << "Cost:" << refSkin.cost;
        qDebug() << "Float Skin:" << refSkin.floatSkin;
        qDebug() << "Wear:" << refSkin.wear;
        qDebug() << "Unique:" << refSkin.unique;
        qDebug() << "Name:" << refSkin.name;
        qDebug() << "Player ID:";
        for (int i = 0; i < 3; i++) {
            qDebug() << refSkin.playerId[i];
        }}
private:
    struct Skin
    {
        int cost;
        double floatSkin;
        char wear;
        bool unique;
        char name [10];
        int playerId[3];
    };
    Skin skin;
};

#endif // BUISNESSMAN_H
