#include "keyboardlayouts.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "QFile"
#include <QJsonDocument>
#include "iostream"

QMap<int, QRectF> KeyboardLayouts::getKeyRects()
{
    QRectF r;
    QMap<int, QRectF> rects;

    QFile file("../KeyBoard/keyboard_rect.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file";
    }

    QTextStream in(&file);
    QString strJson = in.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(strJson.toUtf8());
    QJsonObject obj = doc.object();

    for (int i = 0; i <= 54; ++i) {
        QString id = QString::number(i);
        if (obj.contains(id)) {
            QJsonArray params = obj.value(id).toArray();

            int x = params[0].toInt();
            int y = params[1].toInt();
            int width = params[2].toInt();
            int height = params[3].toInt();

            r = QRectF(x, y, width, height);
            rects.insert(i, r);
        }
    }

    return rects;
}

QMap<int, QPair<QString, QString> > KeyboardLayouts::getLayout(QString lang){
    QMap<int, QPair<QString, QString>> lay;

    QFile file("../KeyBoard/" + lang + "_symb.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file";
    }

    QTextStream in(&file);
    QString strJson = in.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(strJson.toUtf8());
    QJsonObject obj = doc.object();

    for (int i = 0; i <= 54; ++i) {
        QString id = QString::number(i);
        if (obj.contains(id)) {
            QJsonArray params = obj.value(id).toArray();

            QString symb = params[0].toString();
            QString symb_shift = params[1].toString();

            lay.insert(i, QPair<QString,QString>(symb, symb_shift));
        }
    }
    return lay;
    }
