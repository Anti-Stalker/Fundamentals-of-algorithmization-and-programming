#pragma once

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
#include <QMovie>
#include <QPushButton>
#include <QtMultimedia/QMediaPlayer>
#include <QAudioOutput>
#include <QMediaDevices>

namespace Songfinder {

struct SongData {
    QString title;
    QString artist;
    QString url;
    int views;
    QString logoUrl;
    bool wasEnabled;
    QString buttonUrl;
    QString spotikUrl;
};

    void fillTable (QTableWidget*, QVector<QString>);
    void find_song_by_lyrics(const QString&, const QVector<QString>&, const QString&, QTableWidget*, QString&);
    QString getSpotifyAccessToken();
    void quicksort(QVector<SongData>& data, int left, int right);
    int partition(QVector<SongData>& data, int left, int right);
    void sortTableByViews(QTableWidget*);
    void showLoadingAnimation();
    void hideLoadingAnimation();
}
