#include "songplayer.h"
#include <QMessageBox>


void Songplayer::find_spotify_preview(const QString& access_token, const QString& songTitle, const QString& artistName, QPushButton* playButton,
        QNetworkAccessManager* manager, QPushButton*spotify) {
    QUrlQuery params;
    params.addQueryItem("q", songTitle + " " + artistName);
    params.addQueryItem("type", "track");
    params.addQueryItem("limit", "1");

    QUrl url("https://api.spotify.com/v1/search");
    url.setQuery(params);

    QNetworkRequest request(url);
    request.setRawHeader("Authorization", ("Bearer " + access_token).toUtf8());

    QNetworkReply* reply = manager->get(request);
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
            QJsonObject jsonObject = jsonDoc.object();
            QJsonArray tracks = jsonObject["tracks"].toObject()["items"].toArray();

            if (!tracks.isEmpty()) {
                QString previewUrl = tracks[0].toObject()["preview_url"].toString();


                QJsonObject trackObject = tracks[0].toObject();

                // Проверяем совпадение имени артиста
                QJsonArray artists = trackObject["artists"].toArray();
                if (!((artists[0].toObject()["name"].toString().contains(artistName) ||
                     artistName.contains(artists[0].toObject()["name"].toString()))
                     &&   (trackObject["name"].toString().contains(songTitle) || songTitle.contains(trackObject["name"].toString()))))
                {
                    spotify->setProperty("url", "");
                    playButton->setEnabled(false);

                    return;
                }

                if (!previewUrl.isEmpty()) {
                    playButton->setProperty("preview_url", previewUrl);
                    spotify->setProperty("url", tracks[0].toObject()["external_urls"].toObject()["spotify"].toString());
                    playButton->setEnabled(true);
                } else {
                    playButton->setEnabled(false);
                   spotify->setProperty("url", "");
                }
            } else {
                 spotify->setProperty("url", "");

            }
        } else {
            qDebug() << "Ошибка при выполнении запроса к Spotify:" << reply->errorString();
            playButton->setEnabled(false);

        }
        reply->deleteLater();
    });
}
