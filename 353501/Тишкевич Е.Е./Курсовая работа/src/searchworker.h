#ifndef SEARCHWORKER_H
#define SEARCHWORKER_H

#include <QObject>
#include <QTableWidget>
#include <QString>
#include <QVector>

class SearchWorker : public QObject
{
    Q_OBJECT

public:
    explicit SearchWorker(QObject *parent = nullptr);
    void setData(const QString &lyrics, const QVector<QString> &artists, const QString &accessToken, QTableWidget *table);
    void setSortData(QTableWidget *table);

signals:
    void searchFinished();
    void sortFinished();
    void errorOccurred(const QString &errorMessage);

public slots:
    void performSearch();
    void performSort();

private:
    QString m_lyrics;
    QVector<QString> m_artists;
    QString m_accessToken;
    QTableWidget *m_table;
};

#endif // SEARCHWORKER_H
