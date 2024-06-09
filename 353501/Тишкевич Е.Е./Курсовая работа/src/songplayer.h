#ifndef SONGPLAYER_H
#define SONGPLAYER_H

#include <QJsonArray>
#include <QPushButton>
#include <QCoreApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTableWidget>
#include <QDebug>
#include <QLabel>

namespace Songplayer
{
    void find_spotify_preview(const QString& access_token, const QString& songTitle, const QString& artistName, QPushButton* playButton,
                QNetworkAccessManager*, QPushButton*);
};

#endif // SONGPLAYER_H
