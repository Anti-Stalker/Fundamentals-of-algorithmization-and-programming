#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QTextBrowser>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
    m_player1(new QMediaPlayer(this)),
    m_player2(new QMediaPlayer(this)),
    m_player3(new QMediaPlayer(this)),
    m_player4(new QMediaPlayer(this)),
    m_player5(new QMediaPlayer(this)),
    m_player6(new QMediaPlayer(this)),
    m_player7(new QMediaPlayer(this)),
    m_player8(new QMediaPlayer(this)),
    m_player9(new QMediaPlayer(this)),

    audioOutput1(new QAudioOutput(this)),
    audioOutput2(new QAudioOutput(this)),
    audioOutput3(new QAudioOutput(this)),
    audioOutput4(new QAudioOutput(this)),
    audioOutput5(new QAudioOutput(this)),
    audioOutput6(new QAudioOutput(this)),
    audioOutput7(new QAudioOutput(this)),
    audioOutput8(new QAudioOutput(this)),
    audioOutput9(new QAudioOutput(this)),

    buttonEffect(new QGraphicsColorizeEffect(this)),
    soundAnalyzer(new SoundAnalyzer(this))


{
    ui->setupUi(this);
    setWindowTitle("Media Launchpad");
    sort = new Sort(this);
    ui->pushButton->setStyleSheet("background-color: grey;");
    ui->pushButton_2->setStyleSheet("background-color: grey;");
    ui->pushButton_3->setStyleSheet("background-color: grey;");
    ui->pushButton_4->setStyleSheet("background-color: grey;");
    ui->pushButton_5->setStyleSheet("background-color: grey;");
    ui->pushButton_6->setStyleSheet("background-color: grey;");
    ui->pushButton_7->setStyleSheet("background-color: grey;");
    ui->pushButton_8->setStyleSheet("background-color: grey;");
    ui->pushButton_9->setStyleSheet("background-color: grey;");

    keyButton1 = new KeyPressButton(NULL, "Q", this);
    connect(keyButton1, &KeyPressButton::keyPressed, this, &MainWindow::on_pushButton_clicked);
    ui->pushButton->setDefault(keyButton1); // Назначение кнопки по умолчанию

    keyButton2 = new KeyPressButton(NULL, "A", this);
    connect(keyButton2, &KeyPressButton::keyPressed, this, &MainWindow::on_pushButton_2_clicked);
    ui->pushButton_2->setDefault(keyButton2); // Назначение кнопки по умолчанию

    keyButton3 = new KeyPressButton(NULL, "Z", this);
    connect(keyButton3, &KeyPressButton::keyPressed, this, &MainWindow::on_pushButton_3_clicked);
    ui->pushButton_3->setDefault(keyButton3); // Назначение кнопки по умолчанию

    keyButton4 = new KeyPressButton(NULL, "W", this);
    connect(keyButton4, &KeyPressButton::keyPressed, this, &MainWindow::on_pushButton_4_clicked);
    ui->pushButton_4->setDefault(keyButton4); // Назначение кнопки по умолчанию

    keyButton5 = new KeyPressButton(NULL, "S", this);
    connect(keyButton5, &KeyPressButton::keyPressed, this, &MainWindow::on_pushButton_5_clicked);
    ui->pushButton_5->setDefault(keyButton5); // Назначение кнопки по умолчанию

    keyButton6 = new KeyPressButton(NULL, "X", this);
    connect(keyButton6, &KeyPressButton::keyPressed, this, &MainWindow::on_pushButton_6_clicked);
    ui->pushButton_6->setDefault(keyButton6); // Назначение кнопки по умолчанию

    keyButton7 = new KeyPressButton(NULL, "E", this);
    connect(keyButton7, &KeyPressButton::keyPressed, this, &MainWindow::on_pushButton_7_clicked);
    ui->pushButton_7->setDefault(keyButton7); // Назначение кнопки по умолчанию

    keyButton8 = new KeyPressButton(NULL, "D", this);
    connect(keyButton8, &KeyPressButton::keyPressed, this, &MainWindow::on_pushButton_8_clicked);
    ui->pushButton_8->setDefault(keyButton8); // Назначение кнопки по умолчанию

    keyButton9 = new KeyPressButton(NULL, "C", this);
    connect(keyButton9, &KeyPressButton::keyPressed, this, &MainWindow::on_pushButton_9_clicked);
    ui->pushButton_9->setDefault(keyButton9); // Назначение кнопки по умолчанию
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::onMediaStatusChanged(QMediaPlayer::MediaStatus status, int iterator)
{
    if (status == QMediaPlayer::EndOfMedia) {
        if (iterator == 1) {
            buttonEffect->setColor(Qt::transparent);
            ui->pushButton->setGraphicsEffect(buttonEffect);
            disconnect(m_player1, &QMediaPlayer::mediaStatusChanged, this, nullptr);
        }
        if (iterator == 2) {
            buttonEffect->setColor(Qt::transparent);
            ui->pushButton_2->setGraphicsEffect(buttonEffect);
            disconnect(m_player2, &QMediaPlayer::mediaStatusChanged, this, nullptr);
        }
        if (iterator == 3) {
            buttonEffect->setColor(Qt::transparent);
            ui->pushButton_3->setGraphicsEffect(buttonEffect);
            disconnect(m_player3, &QMediaPlayer::mediaStatusChanged, this, nullptr);
        }
        if (iterator == 4) {
            buttonEffect->setColor(Qt::transparent);
            ui->pushButton_2->setGraphicsEffect(buttonEffect);
            disconnect(m_player2, &QMediaPlayer::mediaStatusChanged, this, nullptr);
        }
        if (iterator == 5) {
            buttonEffect->setColor(Qt::transparent);
            ui->pushButton_5->setGraphicsEffect(buttonEffect);
            disconnect(m_player5, &QMediaPlayer::mediaStatusChanged, this, nullptr);
        }
        if (iterator == 6) {
            buttonEffect->setColor(Qt::transparent);
            ui->pushButton_6->setGraphicsEffect(buttonEffect);
            disconnect(m_player6, &QMediaPlayer::mediaStatusChanged, this, nullptr);
        }
        if (iterator == 7) {
            buttonEffect->setColor(Qt::transparent);
            ui->pushButton_7->setGraphicsEffect(buttonEffect);
            disconnect(m_player7, &QMediaPlayer::mediaStatusChanged, this, nullptr);
        }
        if (iterator == 8) {
            buttonEffect->setColor(Qt::transparent);
            ui->pushButton_8->setGraphicsEffect(buttonEffect);
            disconnect(m_player8, &QMediaPlayer::mediaStatusChanged, this, nullptr);
        }
        if (iterator == 9) {
            buttonEffect->setColor(Qt::transparent);
            ui->pushButton_9->setGraphicsEffect(buttonEffect);
            disconnect(m_player9, &QMediaPlayer::mediaStatusChanged, this, nullptr);
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    int iterator = 1;
    int selectedIndex = ui->comboBox->currentIndex();
    if (selectedIndex >= 0 && selectedIndex < ui->listWidget->count()) {
        QListWidgetItem* item = ui->listWidget->item(selectedIndex);
        QString filePath = item->data(Qt::UserRole).toString();
        m_player1->setAudioOutput(audioOutput1);
        m_player1->setSource(QUrl::fromLocalFile(filePath));
        audioOutput1->setVolume(80);

        buttonEffect->setColor(Qt::blue);
        ui->pushButton->setGraphicsEffect(buttonEffect);

        connect(m_player1, &QMediaPlayer::mediaStatusChanged, this, [this, iterator](QMediaPlayer::MediaStatus status){
            onMediaStatusChanged(status, iterator);
        });
        m_player1->play();
        double* audioData = loadAudioData(filePath);
        double* fftValues = new double[512];
        soundAnalyzer->FFTAnalysis(audioData,fftValues,512,512);
        ui->listWidget_2->clear();
        for(int i =0;i<512;i++){
            qDebug()<<fftValues[i];
            QListWidgetItem* item = new QListWidgetItem(QString::number(fftValues[i]));
            ui->listWidget_2->addItem(item);
        }
        updateSpectrogramInGraphicsView(ui->graphicsView, audioData, 512);
        heapsort(audioData,512);
        updateSpectrogramInGraphicsView(ui->graphicsView_2, audioData, 512);

        delete[] audioData;
        delete[] fftValues;
        audioData = nullptr;
        fftValues = nullptr;
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    int iterator = 2;
    int selectedIndex = ui->comboBox_2->currentIndex();
    if (selectedIndex >= 0 && selectedIndex < ui->listWidget->count()) {
        QListWidgetItem* item = ui->listWidget->item(selectedIndex);
        QString filePath = item->data(Qt::UserRole).toString();
        m_player2->setAudioOutput(audioOutput2);
        m_player2->setSource(QUrl::fromLocalFile(filePath));
        audioOutput2->setVolume(80);

        buttonEffect->setColor(Qt::blue);
        ui->pushButton_2->setGraphicsEffect(buttonEffect);

        connect(m_player2, &QMediaPlayer::mediaStatusChanged, this, [this, iterator](QMediaPlayer::MediaStatus status){
            onMediaStatusChanged(status, iterator);
        });

        m_player2->play();
        double* audioData = loadAudioData(filePath);
        double* fftValues = new double[512];
        soundAnalyzer->FFTAnalysis(audioData,fftValues,512,512);
        ui->listWidget_2->clear();
        for(int i =0;i<512;i++){
            qDebug()<<fftValues[i];
            QListWidgetItem* item = new QListWidgetItem(QString::number(fftValues[i]));
            ui->listWidget_2->addItem(item);
        }
        updateSpectrogramInGraphicsView(ui->graphicsView, audioData, 512);
        heapsort(audioData,512);
        updateSpectrogramInGraphicsView(ui->graphicsView_2, audioData, 512);

        delete[] audioData;
        delete[] fftValues;
        audioData = nullptr;
        fftValues = nullptr;
    }

}


void MainWindow::on_pushButton_3_clicked()
{
    int iterator = 3;
    int selectedIndex = ui->comboBox_3->currentIndex();
    if (selectedIndex >= 0 && selectedIndex < ui->listWidget->count()) {
        QListWidgetItem* item = ui->listWidget->item(selectedIndex);
        QString filePath = item->data(Qt::UserRole).toString();
        m_player3->setAudioOutput(audioOutput3);
        m_player3->setSource(QUrl::fromLocalFile(filePath));
        audioOutput3->setVolume(80);

        buttonEffect->setColor(Qt::blue);
        ui->pushButton_3->setGraphicsEffect(buttonEffect);

        connect(m_player3, &QMediaPlayer::mediaStatusChanged, this, [this, iterator](QMediaPlayer::MediaStatus status){
            onMediaStatusChanged(status, iterator);
        });

        m_player3->play();
        double* audioData = loadAudioData(filePath);
        double* fftValues = new double[512];
        soundAnalyzer->FFTAnalysis(audioData,fftValues,512,512);
        ui->listWidget_2->clear();
        for(int i =0;i<512;i++){
            qDebug()<<fftValues[i];
            QListWidgetItem* item = new QListWidgetItem(QString::number(fftValues[i]));
            ui->listWidget_2->addItem(item);
        }
        updateSpectrogramInGraphicsView(ui->graphicsView, audioData, 512);
        heapsort(audioData,512);
        updateSpectrogramInGraphicsView(ui->graphicsView_2, audioData, 512);
        delete[] audioData;
        delete[] fftValues;
        audioData = nullptr;
        fftValues = nullptr;
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    int iterator = 4;
    int selectedIndex = ui->comboBox_4->currentIndex();
    if (selectedIndex >= 0 && selectedIndex < ui->listWidget->count()) {
        QListWidgetItem* item = ui->listWidget->item(selectedIndex);
        QString filePath = item->data(Qt::UserRole).toString();
        m_player4->setAudioOutput(audioOutput4);
        m_player4->setSource(QUrl::fromLocalFile(filePath));
        audioOutput4->setVolume(80);

        buttonEffect->setColor(Qt::blue);
        ui->pushButton_4->setGraphicsEffect(buttonEffect);

        connect(m_player4, &QMediaPlayer::mediaStatusChanged, this, [this, iterator](QMediaPlayer::MediaStatus status){
            onMediaStatusChanged(status, iterator);
        });

        m_player4->play();
        double* audioData = loadAudioData(filePath);
        double* fftValues = new double[512];
        soundAnalyzer->FFTAnalysis(audioData,fftValues,512,512);
        ui->listWidget_2->clear();
        for(int i =0;i<512;i++){
            qDebug()<<fftValues[i];
            QListWidgetItem* item = new QListWidgetItem(QString::number(fftValues[i]));
            ui->listWidget_2->addItem(item);
        }
        updateSpectrogramInGraphicsView(ui->graphicsView, audioData, 512);
        heapsort(audioData,512);
        updateSpectrogramInGraphicsView(ui->graphicsView_2, audioData, 512);
        delete[] audioData;
        delete[] fftValues;
        audioData = nullptr;
        fftValues = nullptr;
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    int iterator = 5;
    int selectedIndex = ui->comboBox_5->currentIndex();
    if (selectedIndex >= 0 && selectedIndex < ui->listWidget->count()) {
        QListWidgetItem* item = ui->listWidget->item(selectedIndex);
        QString filePath = item->data(Qt::UserRole).toString();
        m_player5->setAudioOutput(audioOutput5);
        m_player5->setSource(QUrl::fromLocalFile(filePath));
        audioOutput5->setVolume(80);

        buttonEffect->setColor(Qt::blue);
        ui->pushButton_5->setGraphicsEffect(buttonEffect);

        connect(m_player5, &QMediaPlayer::mediaStatusChanged, this, [this, iterator](QMediaPlayer::MediaStatus status){
            onMediaStatusChanged(status, iterator);
        });

        m_player5->play();
        double* audioData = loadAudioData(filePath);
        double* fftValues = new double[512];
        soundAnalyzer->FFTAnalysis(audioData,fftValues,512,512);
        updateSpectrogramInGraphicsView(ui->graphicsView, audioData, 512);
        heapsort(audioData,512);
        updateSpectrogramInGraphicsView(ui->graphicsView_2, audioData, 512);
        ui->listWidget_2->clear();
        for(int i =0;i<512;i++){
            qDebug()<<fftValues[i];
            QListWidgetItem* item = new QListWidgetItem(QString::number(fftValues[i]));
            ui->listWidget_2->addItem(item);
        }
        delete[] audioData;
        delete[] fftValues;
        audioData = nullptr;
        fftValues = nullptr;
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    int iterator = 6;
    int selectedIndex = ui->comboBox_6->currentIndex();
    if (selectedIndex >= 0 && selectedIndex < ui->listWidget->count()) {
        QListWidgetItem* item = ui->listWidget->item(selectedIndex);
        QString filePath = item->data(Qt::UserRole).toString();
        m_player6->setAudioOutput(audioOutput6);
        m_player6->setSource(QUrl::fromLocalFile(filePath));
        audioOutput6->setVolume(80);

        buttonEffect->setColor(Qt::blue);
        ui->pushButton_6->setGraphicsEffect(buttonEffect);

        connect(m_player6, &QMediaPlayer::mediaStatusChanged, this, [this, iterator](QMediaPlayer::MediaStatus status){
            onMediaStatusChanged(status, iterator);
        });

        m_player6->play();
        double* audioData = loadAudioData(filePath);
        double* fftValues = new double[512];
        soundAnalyzer->FFTAnalysis(audioData,fftValues,512,512);
        ui->listWidget_2->clear();
        for(int i =0;i<512;i++){
            qDebug()<<fftValues[i];
            QListWidgetItem* item = new QListWidgetItem(QString::number(fftValues[i]));
            ui->listWidget_2->addItem(item);
        }
        updateSpectrogramInGraphicsView(ui->graphicsView, audioData, 512);
        heapsort(audioData,512);
        updateSpectrogramInGraphicsView(ui->graphicsView_2, audioData, 512);
        delete[] audioData;
        delete[] fftValues;
        audioData = nullptr;
        fftValues = nullptr;
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    int iterator = 7;
    int selectedIndex = ui->comboBox_7->currentIndex();
    if (selectedIndex >= 0 && selectedIndex < ui->listWidget->count()) {
        QListWidgetItem* item = ui->listWidget->item(selectedIndex);
        QString filePath = item->data(Qt::UserRole).toString();
        m_player7->setAudioOutput(audioOutput7);
        m_player7->setSource(QUrl::fromLocalFile(filePath));
        audioOutput7->setVolume(80);

        buttonEffect->setColor(Qt::blue);
        ui->pushButton_7->setGraphicsEffect(buttonEffect);

        connect(m_player7, &QMediaPlayer::mediaStatusChanged, this, [this, iterator](QMediaPlayer::MediaStatus status){
            onMediaStatusChanged(status, iterator);
        });

        m_player7->play();
        double* audioData = loadAudioData(filePath);
        double* fftValues = new double[512];
        soundAnalyzer->FFTAnalysis(audioData,fftValues,512,512);
        ui->listWidget_2->clear();
        for(int i =0;i<512;i++){
            qDebug()<<fftValues[i];
            QListWidgetItem* item = new QListWidgetItem(QString::number(fftValues[i]));
            ui->listWidget_2->addItem(item);
        }
        updateSpectrogramInGraphicsView(ui->graphicsView, audioData, 512);
        heapsort(audioData,512);
        updateSpectrogramInGraphicsView(ui->graphicsView_2, audioData, 512);
        delete[] audioData;
        delete[] fftValues;
        audioData = nullptr;
        fftValues = nullptr;
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    int iterator = 8;
    int selectedIndex = ui->comboBox_8->currentIndex();
    if (selectedIndex >= 0 && selectedIndex < ui->listWidget->count()) {
        QListWidgetItem* item = ui->listWidget->item(selectedIndex);
        QString filePath = item->data(Qt::UserRole).toString();
        m_player8->setAudioOutput(audioOutput8);
        m_player8->setSource(QUrl::fromLocalFile(filePath));
        audioOutput8->setVolume(80);

        buttonEffect->setColor(Qt::blue);
        ui->pushButton_8->setGraphicsEffect(buttonEffect);

        connect(m_player8, &QMediaPlayer::mediaStatusChanged, this, [this, iterator](QMediaPlayer::MediaStatus status){
            onMediaStatusChanged(status, iterator);
        });

        m_player8->play();
        double* audioData = loadAudioData(filePath);
        double* fftValues = new double[512];
        soundAnalyzer->FFTAnalysis(audioData,fftValues,512,512);
        ui->listWidget_2->clear();
        for(int i =0;i<512;i++){
            qDebug()<<fftValues[i];
            QListWidgetItem* item = new QListWidgetItem(QString::number(fftValues[i]));
            ui->listWidget_2->addItem(item);
        }
        updateSpectrogramInGraphicsView(ui->graphicsView, audioData, 512);
        heapsort(audioData,512);
        updateSpectrogramInGraphicsView(ui->graphicsView_2, audioData, 512);
        delete[] audioData;
        delete[] fftValues;
        audioData = nullptr;
        fftValues = nullptr;
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    int iterator = 9;
    int selectedIndex = ui->comboBox_9->currentIndex();
    if (selectedIndex >= 0 && selectedIndex < ui->listWidget->count()) {
        QListWidgetItem* item = ui->listWidget->item(selectedIndex);
        QString filePath = item->data(Qt::UserRole).toString();
        m_player9->setAudioOutput(audioOutput9);
        m_player9->setSource(QUrl::fromLocalFile(filePath));
        audioOutput9->setVolume(80);

        buttonEffect->setColor(Qt::blue);
        ui->pushButton_9->setGraphicsEffect(buttonEffect);

        connect(m_player9, &QMediaPlayer::mediaStatusChanged, this, [this, iterator](QMediaPlayer::MediaStatus status){
            onMediaStatusChanged(status, iterator);
        });

        m_player9->play();
        double* audioData = loadAudioData(filePath);
        double* fftValues = new double[512];
        soundAnalyzer->FFTAnalysis(audioData,fftValues,512,512);
        ui->listWidget_2->clear();
        for(int i =0;i<512;i++){
            qDebug()<<fftValues[i];
            QListWidgetItem* item = new QListWidgetItem(QString::number(fftValues[i]));
            ui->listWidget_2->addItem(item);
        }
        updateSpectrogramInGraphicsView(ui->graphicsView, audioData, 512);
        heapsort(audioData,512);
        updateSpectrogramInGraphicsView(ui->graphicsView_2, audioData, 512);
        delete[] audioData;
        delete[] fftValues;
        audioData = nullptr;
        fftValues = nullptr;
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    QStringList filePaths = QFileDialog::getOpenFileNames(this, tr("Select Audio Files"), QString(), tr("Audio Files (*.mp3 *.wav)"));
    foreach (const QString &filePath, filePaths) {
        QFileInfo fileInfo(filePath);
        QListWidgetItem *item = new QListWidgetItem(fileInfo.fileName());
        item->setData(Qt::UserRole, filePath);
        ui->listWidget->addItem(item);
        ui->comboBox->addItem(fileInfo.fileName());
        ui->comboBox_2->addItem(fileInfo.fileName());
        ui->comboBox_3->addItem(fileInfo.fileName());
        ui->comboBox_4->addItem(fileInfo.fileName());
        ui->comboBox_5->addItem(fileInfo.fileName());
        ui->comboBox_6->addItem(fileInfo.fileName());
        ui->comboBox_7->addItem(fileInfo.fileName());
        ui->comboBox_8->addItem(fileInfo.fileName());
        ui->comboBox_9->addItem(fileInfo.fileName());
    }
}


void MainWindow::on_comboBox_activated(int index)
{
 ui->comboBox->setCurrentIndex(index);
}


void MainWindow::on_comboBox_2_activated(int index)
{
    ui->comboBox_2->setCurrentIndex(index);
}


void MainWindow::on_comboBox_3_activated(int index)
{
    ui->comboBox_3->setCurrentIndex(index);
}


void MainWindow::on_comboBox_4_activated(int index)
{
    ui->comboBox_4->setCurrentIndex(index);
}


void MainWindow::on_comboBox_5_activated(int index)
{
    ui->comboBox_5->setCurrentIndex(index);
}


void MainWindow::on_comboBox_6_activated(int index)
{
    ui->comboBox_6->setCurrentIndex(index);
}


void MainWindow::on_comboBox_7_activated(int index)
{
    ui->comboBox_7->setCurrentIndex(index);
}


void MainWindow::on_comboBox_8_activated(int index)
{
    ui->comboBox_8->setCurrentIndex(index);
}


void MainWindow::on_comboBox_9_activated(int index)
{
    ui->comboBox_9->setCurrentIndex(index);
}


void MainWindow::on_pushButton_11_clicked()
{
    QDialog dialog(this);
    QFormLayout form(&dialog);

    // Добавление полей для ввода
    QLineEdit *buttonInput = new QLineEdit(&dialog);
    QLineEdit *keyInput = new QLineEdit(&dialog);

    form.addRow("Button", buttonInput);
    form.addRow("key", keyInput);


    // Добавление кнопок Ок и Отмена
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Отображение диалогового окна
    if (dialog.exec() == QDialog::Accepted) {
        QString button = buttonInput->text();
        QChar i=button[0];
        QString k = keyInput->text();
        switch(i.toLatin1()){
        case '1':
            if (keyButton1) {
                disconnect(keyButton1, &KeyPressButton::keyPressed, this, &MainWindow::on_pushButton_clicked);
                delete keyButton1;
            }
            keyButton10 = new KeyPressButton("Mama","r", this);
            connect(keyButton10, &KeyPressButton::keyPressed, this, &MainWindow::on_pushButton_clicked);
            ui->pushButton->setDefault(keyButton10);
            break;
        case '2':
            keyButton2 = new KeyPressButton(NULL, keyInput->text(), this);
            connect(keyButton2, &KeyPressButton::keyPressed, this, &MainWindow::on_pushButton_2_clicked);
            ui->pushButton_2->setDefault(keyButton2);
            break;
        case '3':
            keyButton3 = new KeyPressButton(NULL, keyInput->text(), this);
            connect(keyButton3, &KeyPressButton::keyPressed, this, &MainWindow::on_pushButton_3_clicked);
            ui->pushButton_3->setDefault(keyButton3);
            break;
        case '4':
            keyButton4 = new KeyPressButton(NULL, keyInput->text(), this);
            connect(keyButton4, &KeyPressButton::keyPressed, this, &MainWindow::on_pushButton_4_clicked);
            ui->pushButton_4->setDefault(keyButton4);
            break;
        case '5':
            keyButton5 = new KeyPressButton(NULL, keyInput->text(), this);
            connect(keyButton5, &KeyPressButton::keyPressed, this, &MainWindow::on_pushButton_5_clicked);
            ui->pushButton_5->setDefault(keyButton5);
            break;
        case '6':
            keyButton6 = new KeyPressButton(NULL, keyInput->text(), this);
            connect(keyButton6, &KeyPressButton::keyPressed, this, &MainWindow::on_pushButton_6_clicked);
            ui->pushButton_6->setDefault(keyButton6);
            break;
        case '7':
            keyButton7 = new KeyPressButton(NULL, keyInput->text(), this);
            connect(keyButton7, &KeyPressButton::keyPressed, this, &MainWindow::on_pushButton_7_clicked);
            ui->pushButton_7->setDefault(keyButton7);
            break;
        case '8':
            keyButton8 = new KeyPressButton(NULL, keyInput->text(), this);
            connect(keyButton8, &KeyPressButton::keyPressed, this, &MainWindow::on_pushButton_8_clicked);
            ui->pushButton_8->setDefault(keyButton8);
        case '9':
            keyButton9 = new KeyPressButton(NULL, keyInput->text(), this);
            connect(keyButton9, &KeyPressButton::keyPressed, this, &MainWindow::on_pushButton_9_clicked);
            ui->pushButton_9->setDefault(keyButton9);
            break;
        default:break;
        }

    }
}


void MainWindow::on_pushButton_12_clicked()
{

}


void MainWindow::on_pushButton_13_clicked()
{
    int x0 = 123456789;  // начальное значение
    int m = 429496726;
    int a = 16807;
    int c = 2531011;
    int i = 0;
    int* array = new int[100];
    std::unique_ptr<int> iterations = std::make_unique<int>(0);
    while (i <= 90) {
        int next_num = (a * x0 + c) % m;
        next_num = (next_num % 9) + 1; // приводим диапазон к 1-9
        x0 = next_num;
        array[i] = next_num;
        qDebug() <<i<<" - "<<array[i];
        i++;
    }
    QTimer* timer = new QTimer(this);
    timer->setInterval(300);
    timer->setSingleShot(false); // Повторяющийся таймер
    connect(timer, &QTimer::timeout, this, [this, array, iterations = std::move(iterations), timer]()mutable {
        autoPlayProc(array[*iterations]);
        qDebug() <<"array"<<array[*iterations]<<" "<<*iterations;
        (*iterations)++;

        if (*iterations == 90) {
            timer->stop();
            timer->deleteLater(); // Удаляем таймер позже
        }
    });
    timer->start();
}
void MainWindow::autoPlayProc(int iterator){
    if(iterator==1){
        on_pushButton_clicked();
    }
    if(iterator==2){
        on_pushButton_2_clicked();
    }
    if(iterator==3){
        on_pushButton_3_clicked();
    }
    if(iterator==4){
        on_pushButton_4_clicked();
    }
    if(iterator==5){
        on_pushButton_5_clicked();
    }
    if(iterator==6){
        on_pushButton_6_clicked();
    }
    if(iterator==7){
        on_pushButton_7_clicked();
    }
    if(iterator==8){
        on_pushButton_8_clicked();
    }
    if(iterator==9){
        on_pushButton_9_clicked();
    }
}




void MainWindow::on_pushButton_14_clicked()
{
    QAudioDevice outputDevice;
    int selectedIndex = ui->comboBox->currentIndex();
    QListWidgetItem* item = ui->listWidget->item(selectedIndex);
    QString filePath = item->data(Qt::UserRole).toString();
    QFile audioFile(filePath);

    audioFile.open(QIODevice::ReadOnly);

    // Считываем аудио-данные из файла
    QByteArray audioData = audioFile.readAll();

    // Генерируем ключ для XOR шифрования
    QByteArray key = "121212";

    // Шифруем аудио-данные с помощью XOR
    QByteArray encryptedData = xorAudioData(audioData, key);
    saveTemporaryFileToDisk("/home/makar/encrp.wav", encryptedData);
    QByteArray unencrypted = xorAudioData(encryptedData,key);
    saveTemporaryFileToDisk("/home/makar/unencrp.wav", unencrypted);
}


void MainWindow::on_pushButton_15_clicked()
{
    int selectedIndex = ui->comboBox->currentIndex();
    QListWidgetItem* item = ui->listWidget->item(selectedIndex);
    QString filePath = item->data(Qt::UserRole).toString();
    QFile audioFile(filePath);

    audioFile.open(QIODevice::ReadOnly);

    // Считываем аудио-данные из файла
    QByteArray audioData = audioFile.readAll();
    QString targetByte =ui->lineEdit->text();
    int count = binarySearchByteCount(audioData,targetByte);
    ui->label_2->setText(QString::number(count));

}

