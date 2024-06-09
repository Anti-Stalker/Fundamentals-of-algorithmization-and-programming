

#include "searchworker.h"
#include "songfinder.h"

SearchWorker::SearchWorker(QObject *parent) : QObject(parent), m_table(nullptr)
{
}

void SearchWorker::setData(const QString &lyrics, const QVector<QString> &artists, const QString &accessToken, QTableWidget *table)
{
    m_lyrics = lyrics;
    m_artists = artists;
    m_accessToken = accessToken;
    m_table = table;
}

void SearchWorker::setSortData(QTableWidget *table)
{
    m_table = table;
}

void SearchWorker::performSearch()
{
    QString errors;
    Songfinder::find_song_by_lyrics(m_lyrics, m_artists, m_accessToken, m_table, errors);
    if (!errors.isEmpty()) {
        emit errorOccurred(errors);
    }
    emit searchFinished();
}

void SearchWorker::performSort()
{
    Songfinder::sortTableByViews(m_table);
    emit sortFinished();
}
