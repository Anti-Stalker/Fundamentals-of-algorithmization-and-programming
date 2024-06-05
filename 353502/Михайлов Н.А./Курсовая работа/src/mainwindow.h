#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtCore>
#include<QtWidgets>
#include<QAudioOutput>
#include <QStandardItemModel>
#include<QFileDialog>
#include<QFileInfo>
#include <QModelIndex>
#include <QRandomGenerator>
#include <QStringListModel>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void playlistSelectionChanged(const QModelIndex &current, const QModelIndex &previous);

    void playlistSelectionChanged2(const QModelIndex &current, const QModelIndex &previous);

    void durationChanged(qint64 duration);

    void positionChanged(qint64 position);

    void on_volume_bttn_clicked();

    void on_pushBack_bttn_clicked();

    void on_play_bttn_clicked();

    void on_pause_bttn_clicked();

    void on_stop_bttn_clicked();

    void on_pushFront_bttn_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_volumeSlider_valueChanged(int value);

    void on_add_bttn_clicked();

    void on_sort_bttn_clicked();

    void on_rand_bttn_clicked();

    void mediaStatusChanged(QMediaPlayer::MediaStatus status);

    void search(const QString &text);


private:
    bool boyerMooreSearch(const QString &text, const QString &pattern);
    void fisherYatesShuffle(QList<QStandardItem*>& items);
    void mergeSort(QList<QStandardItem*>& items);
    void merge(QList<QStandardItem*>& left, QList<QStandardItem*>& right, QList<QStandardItem*>& result);
    void setTrack(const QModelIndex &index);
    void updateDuration(qint64 duration);
    Ui::MainWindow *ui;
    bool Is_Muted = false;
    QMediaPlayer *m_player;
    QAudioOutput *audioOutput;
    qint64 m_duration;
    qint64 m_position;
    QStandardItemModel *m_playListModel;
    QModelIndex currentTrackIndex;
    QStringListModel *searchResultModel;

};
#endif // MAINWINDOW_H
