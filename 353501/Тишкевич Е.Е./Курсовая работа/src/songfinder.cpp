#include "songfinder.h"
#include "songplayer.h"
#include <QDesktopServices>

QAudioOutput* audioOutput = new QAudioOutput();
QMediaPlayer* mediaPlayer = new QMediaPlayer();

bool isBeingSorted = false;
bool wasEnabled = false;
QString currentUrl="";
QString currentSpotik = "";

QString playIconPath = "/Users/egortishkevic/Qt/FixedShazam/play.svg";
QString pauseIconPath = "/Users/egortishkevic/Qt/FixedShazam/pause.svg";
QString geniusIconPath = "/Users/egortishkevic/Qt/FixedShazam/Genius.png";
QString spotifyIconPath = "/Users/egortishkevic/Qt/FixedShazam/spotik.png";
quint64 pausedPosition = 0;

// Добавление свойства для отслеживания состояния воспроизведения
bool isPlaying = false;
QPushButton* currentPlayButton = nullptr;
QLabel* loadingLabel;

QVector<QString> urls {};

class Spotik {
public:
    int views;
    QString url;
    Spotik(int a, QString b) {views=a; url=b;}
};
QVector<Spotik>songs;




void Songfinder::find_song_by_lyrics(const QString& lyrics, const QVector<QString>& artists, const QString& access_token, QTableWidget* table, QString&error) {

    urls.clear();
    mediaPlayer->stop();
    currentPlayButton=nullptr;
    mediaPlayer->setAudioOutput(audioOutput);
    QNetworkAccessManager manager;
    QNetworkRequest request;

    // Проверяем, не пустой ли массив исполнителей
    if (artists.isEmpty()) {
        // Поиск песен только по тексту, если нет исполнителей
        QUrlQuery params;
        params.addQueryItem("q", lyrics);
        params.addQueryItem("per_page", "10");

        QUrl url("https://api.genius.com/search");
        url.setQuery(params);

        request.setUrl(url);
    } else {
        // Поиск песен по тексту и исполнителям
        for (const QString& artist : artists) {
            QUrlQuery params;
            // Строим запрос, включающий в себя и текст песни, и имя исполнителя
            QString searchQuery = lyrics + " " + artist;
            params.addQueryItem("q", searchQuery);
            params.addQueryItem("per_page", "7");

            QUrl url("https://api.genius.com/search");
            url.setQuery(params);

            request.setUrl(url);

            request.setRawHeader("Authorization", ("Bearer " + access_token).toUtf8());

            QNetworkReply* reply = manager.get(request);
            QEventLoop loop;
            QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

            loop.exec();

            if (reply->error() == QNetworkReply::NoError) {
                QByteArray data = reply->readAll();
                QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
                QJsonObject jsonObject = jsonDoc.object();
                QJsonArray hits = jsonObject["response"].toObject()["hits"].toArray();



                for (const auto& hit : hits) {
                    QJsonObject result = hit.toObject()["result"].toObject();
                    QString artistName = result["primary_artist"].toObject()["name"].toString();
                    if (artistName.toLower() == artist.toLower()) { // Check if the artist matches
                        QVector<QString> song_data;

                        song_data.push_back(result["title"].toString());
                        song_data.push_back(artistName);
                        song_data.push_back(result["url"].toString());

                        int pageviews = result["stats"].toObject()["pageviews"].toInt();
                        QString pageviewsStr = QString::number(pageviews);
                        song_data.push_back(pageviewsStr);

                        QString logo_url = result["song_art_image_thumbnail_url"].toString();
                        song_data.push_back(logo_url);
                         urls.push_back(logo_url);

                        fillTable(table, song_data);
                    }
                }
            } else {
                error = "Check your internet connection";

            }

            reply->deleteLater();
        }
        return;
    }

    // Выполнение запроса, если массив исполнителей пуст
    request.setRawHeader("Authorization", ("Bearer " + access_token).toUtf8());
    QNetworkReply* reply = manager.get(request);
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
        QJsonObject jsonObject = jsonDoc.object();
        QJsonArray hits = jsonObject["response"].toObject()["hits"].toArray();


        for (const auto& hit : hits) {
            QJsonObject result = hit.toObject()["result"].toObject();


            QString artistName = result["primary_artist"].toObject()["name"].toString();
            QVector<QString> song_data;

            song_data.push_back(result["title"].toString());
            song_data.push_back(artistName);
            song_data.push_back(result["url"].toString());

            int pageviews = result["stats"].toObject()["pageviews"].toInt();
            QString pageviewsStr = QString::number(pageviews);
            song_data.push_back(pageviewsStr);

            QString logo_url = result["song_art_image_thumbnail_url"].toString();
            song_data.push_back(logo_url);
            urls.push_back(logo_url);

            fillTable(table, song_data);
        }
    }
    else {
        error = "Check your internet connection";

    }

    reply->deleteLater();
    return;
}

QString Songfinder::getSpotifyAccessToken() {
    QNetworkAccessManager manager;
    QEventLoop loop;

    QUrl tokenUrl("https://accounts.spotify.com/api/token");
    QNetworkRequest request(tokenUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QByteArray body;
    QUrlQuery params;
    params.addQueryItem("grant_type", "client_credentials");
    params.addQueryItem("client_id", "366a52fa33a744358455f5fd812230d1");
    params.addQueryItem("client_secret", "693ce6d041624e63b7cee299d0c61fb3");
    body = params.query().toUtf8();

    QNetworkReply* reply = manager.post(request, body);
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QString accessToken;
    if (reply->error() == QNetworkReply::NoError) {
        auto jsonDoc = QJsonDocument::fromJson(reply->readAll());
        auto jsonObj = jsonDoc.object();
        accessToken = jsonObj["access_token"].toString();
    } else {
        qDebug()<<"Token error";
    }

    reply->deleteLater();
    return accessToken;
}

void Songfinder::fillTable (QTableWidget*table, QVector<QString>data)
{
    enum Songs{
        TITLE,
        ARTIST,
        URL,
        STREAMS,
        LOGO_URL
    };

    table->insertRow(table->rowCount());

    int row = table->rowCount()-1;

    table->setRowHeight(row, 65);


    QLabel* logoLabel = new QLabel();
    logoLabel->setAlignment(Qt::AlignCenter);
    table->setCellWidget(row, 0, logoLabel);

    QString logoUrl = data[LOGO_URL];
    QNetworkAccessManager* manager = new QNetworkAccessManager();
    QObject::connect(manager, &QNetworkAccessManager::finished,  [=](QNetworkReply* reply) {
        if (reply->error() == QNetworkReply::NoError) {
            QPixmap logo;
            logo.loadFromData(reply->readAll());
            logoLabel->setPixmap(logo.scaled(62, 62, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        reply->deleteLater();
    });
    manager->get(QNetworkRequest(QUrl(logoUrl)));

    QTableWidgetItem* title = new QTableWidgetItem();
    title->setText(data[TITLE]);
    QFont titleFont("Roboto", 20, QFont::Medium);
    title->setFont(titleFont);
    table->setItem(row, 1, title);

    QTableWidgetItem* artist = new QTableWidgetItem();
    artist->setText(data[ARTIST]);
    QFont artistFont("Roboto", 19, QFont::Light);
    artist->setFont(artistFont);
    table->setItem(row, 2, artist);

    QPushButton* lyrics = new QPushButton();
    lyrics->setProperty("url", data[URL]);
    QFont lyricsFont("Roboto", 17);
    lyrics->setFont(lyricsFont);
    table->setCellWidget(table->rowCount() - 1, 3, lyrics);
    lyrics->setIcon(QIcon(geniusIconPath));
    lyrics->setIconSize(QSize(58, 58));
    lyrics->setStyleSheet(
        "QPushButton { border: none; }"
        "QPushButton:hover { background-color: lightgray; }"
        );

    QObject::connect(lyrics, &QPushButton::clicked, [=](){
        QString link = lyrics->property("url").toString();;
        QDesktopServices::openUrl(QUrl(link));
    });


    QPushButton* playButton = new QPushButton();
    playButton->setIcon(QIcon(playIconPath));
    playButton->setIconSize(QSize(58, 58));
    playButton->setStyleSheet(
        "QPushButton { border: none; }"
        "QPushButton:hover { background-color: lightgray; }"
        );
    playButton->setEnabled(false);
    table->setCellWidget(row, 5, playButton);

    QPushButton* spotify = new QPushButton();
    spotify->setIcon(QIcon(spotifyIconPath));
    spotify->setIconSize(QSize(96, 96));
    spotify->setStyleSheet(
        "QPushButton { border: none; }"
        "QPushButton:hover { background-color: lightgray; }"
        );
    spotify->setEnabled(true);
    table->setCellWidget(row, 6, spotify);




    if (!isBeingSorted) {
        QNetworkAccessManager* manager2 = new QNetworkAccessManager();
        Songplayer::find_spotify_preview(getSpotifyAccessToken(), data[TITLE], data[ARTIST], playButton, manager2, spotify);
    }
    else {
        if (wasEnabled)
        {
            playButton->setProperty("preview_url", currentUrl);
            spotify->setProperty("url", currentSpotik);
            playButton->setEnabled(true);
            spotify->setEnabled(true);
        }
        else {
            playButton->setEnabled(false);
        }
    }

    QObject::connect(spotify, &QPushButton::clicked, [=](){
        QString link = spotify->property("url").toString();
        if (link!="") QDesktopServices::openUrl(QUrl(link));
        else spotify->setEnabled(false);
    });

    QTableWidgetItem* streams = new QTableWidgetItem();
    streams->setText(data[STREAMS]);
    QFont streamsFont("Roboto", 18);
    streams->setFont(streamsFont);
    table->setItem(table->rowCount() - 1, 4, streams);


    QObject::connect(playButton, &QPushButton::clicked, [=]() {
        QString previewUrl = playButton->property("preview_url").toString();
        if (!previewUrl.isEmpty()) {
            // Если уже воспроизводится другая песня, остановим её и сменим иконку на play
            if (currentPlayButton && currentPlayButton != playButton) {
                isPlaying = false;
                currentPlayButton->setIcon(QIcon(playIconPath));
            }

            // Если текущая кнопка playButton, то изменяем её состояние
            if (isPlaying && currentPlayButton == playButton) {
                pausedPosition = mediaPlayer->position();
                mediaPlayer->pause();
                playButton->setIcon(QIcon(playIconPath));
            } else {
                if (mediaPlayer->source().toString() != previewUrl) {
                    mediaPlayer->setSource(QUrl(previewUrl));
                    pausedPosition = 0; // Reset position if new song
                }
                mediaPlayer->setPosition(pausedPosition);
                mediaPlayer->play();
                playButton->setIcon(QIcon(pauseIconPath));
            }

            // Обновляем текущее состояние
            isPlaying = !isPlaying;
            currentPlayButton = isPlaying ? playButton : nullptr;
        }
    });
}

void Songfinder::sortTableByViews(QTableWidget*table) {
    isBeingSorted = true;
    currentPlayButton=nullptr;
    mediaPlayer->stop();
    int rowCount = table->rowCount();

    QVector<SongData> songs;

    // Извлекаем данные из таблицы
    for (int i = 0; i < rowCount; ++i) {
        SongData song;
        song.title = table->item(i, 1)->text();
        song.artist = table->item(i, 2)->text();
        song.url = "";
        QWidget* cellWidget = table->cellWidget(i, 3);
        if (cellWidget) {
            QPushButton* button = qobject_cast<QPushButton*>(cellWidget);
            if (button) {
                song.url = button->property("url").toString();
            }
        }
        song.views = table->item(i, 4)->text().toInt();
        song.logoUrl = urls[i];
        song.wasEnabled =  table->cellWidget(i,5)->isEnabled();
        song.buttonUrl= table->cellWidget(i,5)->property("preview_url").toString();
        song.spotikUrl= table->cellWidget(i,6)->property("url").toString();

        songs.append(song);
    }

    // Сортируем данные
    quicksort(songs, 0, songs.size() - 1);

    // Очищаем таблицу и заполняем отсортированными данными
    table->setRowCount(0);
    for (const auto& song : songs) {
        QVector<QString> song_data = { song.title, song.artist, song.url, QString::number(song.views), song.logoUrl};
        currentUrl= song.buttonUrl;
        currentSpotik = song.spotikUrl;
        wasEnabled = song.wasEnabled;
        qDebug()<<wasEnabled;
        fillTable(table, song_data);
    }
    isBeingSorted = false;
}

void Songfinder::quicksort(QVector<SongData>& data, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(data, left, right);
        quicksort(data, left, pivotIndex - 1);
        quicksort(data, pivotIndex + 1, right);
    }
}

int Songfinder::partition(QVector<SongData>& data, int left, int right) {
    int pivotValue = data[right].views;
    int i = left - 1;

    for (int j = left; j < right; ++j) {
        if (data[j].views >= pivotValue) { // Сортируем по убыванию
            ++i;
            qSwap(data[i], data[j]);
        }
    }
    qSwap(data[i + 1], data[right]);
    return i + 1;
}



