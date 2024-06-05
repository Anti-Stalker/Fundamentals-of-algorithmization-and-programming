#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->volume_bttn->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
    m_player = new QMediaPlayer();
    audioOutput = new QAudioOutput;
    ui->volumeSlider->setRange(0,100);
    ui->volumeSlider->setValue(20);
    m_player->setAudioOutput(audioOutput);
    connect(m_player,&QMediaPlayer::durationChanged,this, &MainWindow::durationChanged);
    connect(m_player,&QMediaPlayer::positionChanged,this, &MainWindow::positionChanged);
    connect(ui->playlistView->selectionModel(), &QItemSelectionModel::currentRowChanged, this, &MainWindow::playlistSelectionChanged);
    connect(ui->searchResultListView->selectionModel(), &QItemSelectionModel::currentRowChanged, this, &MainWindow::playlistSelectionChanged2);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::search);
    connect(m_player, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::mediaStatusChanged);
    ui->horizontalSlider->setRange(0,m_player->duration() / 1000);
    m_playListModel = new QStandardItemModel(0, 1, this);
    m_playListModel->setHeaderData(0, Qt::Horizontal, "PLaylist");
    ui->playlistView->setModel(m_playListModel);
    ui->playlistView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->playlistView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->playlistView->setSelectionMode(QAbstractItemView::SingleSelection);
    currentTrackIndex = QModelIndex();
    searchResultModel = new QStringListModel(this);
    ui->searchResultListView->setModel(searchResultModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDuration(qint64 duration)
{
    QString timestr;
    if(duration || m_duration)
    {
        QTime CurrentTime((duration / 3600) % 60, (duration / 60) % 60, duration % 60, (duration * 1000) % 1000);
        QTime allTime((m_duration / 3600) % 60, (m_duration / 60) % 60, m_duration % 60, (m_duration * 1000) % 1000);
        QString format = "mm:ss";
        if(m_duration > 3600)
            format = "hh:mm:ss";
        ui->label_2->setText(CurrentTime.toString(format));
        ui->label_3->setText(allTime.toString(format));

    }
}

void MainWindow::durationChanged(qint64 duration)
{
    m_duration = duration / 1000;
    ui->horizontalSlider->setMaximum(m_duration);
}

void MainWindow::positionChanged(qint64 position)
{
    if(!ui->horizontalSlider->isSliderDown())
    {
        ui->horizontalSlider->setValue(position / 1000);
    }
    updateDuration(position / 1000);
}

void MainWindow::on_volume_bttn_clicked()
{
    if(Is_Muted == false)
    {
        ui->volume_bttn->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
        Is_Muted = true;
        audioOutput->setMuted(true);
    }else{
        ui->volume_bttn->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
        Is_Muted = false;
        audioOutput->setMuted(false);
    }
}

void MainWindow::on_pushBack_bttn_clicked()
{
    QModelIndex currentIndex = ui->playlistView->currentIndex();
    int rowCount = m_playListModel->rowCount();
    if (rowCount > 0) {
        int prevRow = (currentIndex.row() - 1 + rowCount) % rowCount;
        QModelIndex prevIndex = m_playListModel->index(prevRow, 0);
        ui->playlistView->setCurrentIndex(prevIndex);
        setTrack(prevIndex);
        m_player->play();
    }
}

void MainWindow::on_play_bttn_clicked()
{
    if (ui->playlistView->currentIndex().isValid()) {
        currentTrackIndex = ui->playlistView->currentIndex();
        setTrack(currentTrackIndex);
    }

    if (!m_player->source().isEmpty()) {
        m_player->play();
    }
}

void MainWindow::on_pause_bttn_clicked()
{
    m_player->pause();
}


void MainWindow::on_stop_bttn_clicked()
{
    m_player->stop();
}

void MainWindow::on_pushFront_bttn_clicked()
{
    QModelIndex currentIndex = ui->playlistView->currentIndex();
    int rowCount = m_playListModel->rowCount();
    if (rowCount > 0) {
        int nextRow = (currentIndex.row() + 1) % rowCount;
        QModelIndex nextIndex = m_playListModel->index(nextRow, 0);
        ui->playlistView->setCurrentIndex(nextIndex);
        setTrack(nextIndex);
        m_player->play();
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    m_player->setPosition(value * 1000);
}


void MainWindow::on_volumeSlider_valueChanged(int value)
{
    double volume = value / 100.0;
    audioOutput->setVolume(volume);

}

void MainWindow::on_add_bttn_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Add Track", "", "Audio Files (*.mp3 *.wav *.ogg)");
    if (!filePath.isEmpty()) {
        QFileInfo fileInfo(filePath);
        QStandardItem *item = new QStandardItem(fileInfo.fileName());
        item->setData(filePath, Qt::UserRole);
        m_playListModel->appendRow(item);
    }
}

void MainWindow::playlistSelectionChanged(const QModelIndex &current, const QModelIndex &previous)
{
    if (current.isValid()) {
        currentTrackIndex = current;
        setTrack(current);
        m_player->play();
    }
}

void MainWindow::setTrack(const QModelIndex &index)
{
    QString filePath = m_playListModel->data(index, Qt::UserRole).toString();
    m_player->setSource(QUrl::fromLocalFile(filePath));
}

void MainWindow::mergeSort(QList<QStandardItem*>& items)
{
    if (items.size() <= 1) {
        return;
    }

    int mid = items.size() / 2;
    QList<QStandardItem*> left(items.mid(0, mid));
    QList<QStandardItem*> right(items.mid(mid));

    mergeSort(left);
    mergeSort(right);

    merge(left, right, items);
}

void MainWindow::merge(QList<QStandardItem*>& left, QList<QStandardItem*>& right, QList<QStandardItem*>& result)
{
    result.clear();
    while (!left.isEmpty() && !right.isEmpty()) {
        if (left.first()->text().toLower() <= right.first()->text().toLower()) {
            result.append(left.takeFirst());
        } else {
            result.append(right.takeFirst());
        }
    }
    result.append(left);
    result.append(right);
}
void MainWindow::on_sort_bttn_clicked()
{
    QList<QStandardItem*> items;
    for (int row = 0; row < m_playListModel->rowCount(); ++row) {
        items.append(m_playListModel->takeItem(row));
    }

    mergeSort(items);

    m_playListModel->clear();
    m_playListModel->setHorizontalHeaderItem(0, new QStandardItem("Playlist"));

    for (QStandardItem* item : items) {
        m_playListModel->appendRow(item);
    }
    currentTrackIndex = m_playListModel->index(0, 0);
    ui->playlistView->setCurrentIndex(currentTrackIndex);
    setTrack(currentTrackIndex);
    m_player->play();
}

void MainWindow::fisherYatesShuffle(QList<QStandardItem*>& items)
{
    int n = items.size();
    for (int i = n - 1; i > 0; --i) {
        int j = QRandomGenerator::global()->bounded(i + 1);
        items.swapItemsAt(i, j);
    }
}

void MainWindow::on_rand_bttn_clicked()
{
    int rowCount = m_playListModel->rowCount();
    if (rowCount > 0) {
        // Перемешиваем плейлист
        QList<QStandardItem*> items;
        for (int row = 0; row < rowCount; ++row) {
            items.append(m_playListModel->takeItem(row));
        }

        fisherYatesShuffle(items);

        m_playListModel->clear();
        m_playListModel->setHorizontalHeaderItem(0, new QStandardItem("Playlist"));

        for (QStandardItem* item : items) {
            m_playListModel->appendRow(item);
        }

        // Выбираем первый трек из перемешанного списка
        currentTrackIndex = m_playListModel->index(0, 0);
        ui->playlistView->setCurrentIndex(currentTrackIndex);
        setTrack(currentTrackIndex);
        m_player->play();
    }
}

void MainWindow::mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia) {
        int rowCount = m_playListModel->rowCount();
        if (rowCount > 0) {
            int nextRow = (currentTrackIndex.row() + 1) % rowCount;
            currentTrackIndex = m_playListModel->index(nextRow, 0);
            ui->playlistView->setCurrentIndex(currentTrackIndex);
            setTrack(currentTrackIndex);
            m_player->play();
        }
    }
}

void MainWindow::search(const QString &text)
{
    QStringList results;

    for (int i = 0; i < m_playListModel->rowCount(); ++i) {
        QModelIndex index = m_playListModel->index(i, 0);
        QString trackName = index.data(Qt::DisplayRole).toString();

        if (boyerMooreSearch(trackName, text)) {
            results << trackName;
        }
    }

    searchResultModel->setStringList(results);
}

bool MainWindow::boyerMooreSearch(const QString &text, const QString &pattern)
{
    QMap<QChar, int> shiftTable;

    int patternLength = pattern.length();
    int textLength = text.length();

    for (int i = 0; i < patternLength - 1; ++i) {
        shiftTable[pattern.at(i)] = patternLength - i - 1;
    }

    int i = patternLength - 1;
    while (i < textLength) {
        int j = patternLength - 1;
        int k = i;

        while (j >= 0 && text.at(k) == pattern.at(j)) {
            --k;
            --j;
        }

        if (j < 0) {
            return true;
        }

        i += shiftTable.value(text.at(i), patternLength);
    }

    return false;
}

void MainWindow::playlistSelectionChanged2(const QModelIndex &current, const QModelIndex &previous)
{
    if (current.isValid()) {
        currentTrackIndex = current;
        setTrack(current);
        m_player->play();
    }
}
