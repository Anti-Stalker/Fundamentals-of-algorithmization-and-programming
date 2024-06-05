#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtMultimedia>
#include <QListWidgetItem>
#include <QMediaPlayer>

#include <QMessageBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QGraphicsColorizeEffect>
#include <keypressbutton.h>
#include <soundanalyzer.h>
#include <QAudioOutput>
#include <QPainter>
#include <QTimer>
#include <QAudioDecoder>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <sort.h>
#include <QAudioSource>

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
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status,int iterator);
    void autoPlayProc(int iterator);
    double* loadAudioData(const QString& filePath) {
        QFile audioFile(filePath);
        if (audioFile.open(QIODevice::ReadOnly)) {
            // Загрузка аудиоданных из файла

                QByteArray audioDatta = audioFile.readAll();

            // Выделяем память для массива
            double* audioData = new double[512];
                memcpy(audioData, audioDatta.constData(), 512);

                // Теперь вы можете работать с массивом double
                for (int i = 0; i < 512; ++i) {
                    qDebug() << "Double value at index" << i << ":" << audioData[i];
                }


            return audioData;
        }
        return nullptr;
    }
    void updateSpectrogramInGraphicsView(QGraphicsView* graphicsView, double* audioData, std::size_t numSamples) {
        QGraphicsScene* scene = graphicsView->scene();
        if (!scene) {
            scene = new QGraphicsScene(graphicsView);
            graphicsView->setScene(scene);
        } else {
            scene->clear();
        }

        int width = graphicsView->width();
        int height = graphicsView->height();
        int columnWidth = 5; // Уменьшаем ширину столбца
        int columnSpacing = 2; // Добавляем пространство между столбцами

        // Найдем минимальное и максимальное значения в массиве
        double minValue = *std::min_element(audioData, audioData + numSamples);
        double maxValue = *std::max_element(audioData, audioData + numSamples);

        // Нормализуем значения в массиве audioData
        double maxAbsValue = std::max(std::fabs(minValue), std::fabs(maxValue));
        for (std::size_t i = 0; i < numSamples; ++i) {
            audioData[i] /= maxAbsValue;
        }

        // Отображаем данные в виде столбцов
        for (std::size_t i = 0; i < numSamples; ++i) {
            int columnHeight = static_cast<int>(height * std::fabs(audioData[i]));
            columnHeight = std::max(columnHeight, 1); // Гарантируем, что высота столбца будет как минимум 1 пиксель
            QGraphicsRectItem* item = scene->addRect(i * (columnWidth + columnSpacing), height - columnHeight, columnWidth, columnHeight, QPen(), QBrush(Qt::blue));
        }

        graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }
    void heapify(double* nums, int n, int i){
        int largest = i; // Инициализируем largest как корень
        int left = 2 * i + 1; // Левый потомок
        int right = 2 * i + 2; // Правый потомок

        // Если левый потомок больше корня
        if (left < n && nums[left] > nums[largest])
            largest = left;

        // Если правый потомок больше, чем largest
        if (right < n && nums[right] > nums[largest])
            largest = right;

        // Если largest не является корнем
        if (largest != i) {
            double temp = nums[i];
            nums[i] = nums[largest];
            nums[largest] = temp;
            // Рекурсивно heapify затронутое поддерево
            heapify(nums, n, largest);
        }
    }
    void heapsort(double* nums, int n){
        // Построение кучи (переставляем элементы в порядке убывания)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(nums, n, i);

        // Один за другим извлекаем элементы из кучи
        for (int i = n - 1; i > 0; i--) {
            // Перемещаем текущий корень в конец
            double temp = nums[0];
            nums[0] = nums[i];
            nums[i] = temp;
            // Вызываем heapify на уменьшенной куче
            heapify(nums, i, 0);
        }
    }
    QByteArray xorAudioData(const QByteArray& data, const QByteArray& key) {
        QByteArray result(data.size(), 0);
        for (int i = 0; i < data.size(); i++) {
            result[i] = data[i] ^ key[i % key.size()];
        }
        return result;
    }
    void saveTemporaryFileToDisk(const QString& filePath, const QByteArray& data) {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly)) {
            file.write(data);
            file.flush();
            file.close();
            qDebug() << "Temporary file saved to disk:" << filePath;
        } else {
            qDebug() << "Failed to save temporary file to disk:" << file.errorString();
        }
    }
    int binarySearchByteCount(const QByteArray& bytes, const QString& targetByte) {
        int left = 0;
        int right = bytes.size() - 1;
        int count = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (bytes.mid(mid, 1) == targetByte) {
                count++;
                int leftIndex = mid;
                int rightIndex = mid;

                // Найти левую границу вхождений
                while (leftIndex >= 0 && bytes.mid(leftIndex, 1) == targetByte) {
                    count++;
                    leftIndex--;
                }

                // Найти правую границу вхождений
                while (rightIndex < bytes.size() && bytes.mid(rightIndex, 1) == targetByte) {
                    count++;
                    rightIndex++;
                }

                return count;
            } else if (bytes.mid(mid, 1) < targetByte) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return count;
    }
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_comboBox_3_activated(int index);

    void on_comboBox_4_activated(int index);

    void on_comboBox_5_activated(int index);

    void on_comboBox_6_activated(int index);

    void on_comboBox_7_activated(int index);

    void on_comboBox_8_activated(int index);

    void on_comboBox_9_activated(int index);

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *m_player1;
    QMediaPlayer *m_player2;
    QMediaPlayer *m_player3;
    QMediaPlayer *m_player4;
    QMediaPlayer *m_player5;
    QMediaPlayer *m_player6;
    QMediaPlayer *m_player7;
    QMediaPlayer *m_player8;
    QMediaPlayer *m_player9;
    QAudioOutput *audioOutput1;
    QAudioOutput *audioOutput2;
    QAudioOutput *audioOutput3;
    QAudioOutput *audioOutput4;
    QAudioOutput *audioOutput5;
    QAudioOutput *audioOutput6;
    QAudioOutput *audioOutput7;
    QAudioOutput *audioOutput8;
    QAudioOutput *audioOutput9;
    KeyPressButton* keyButton1;
    KeyPressButton* keyButton2;
    KeyPressButton* keyButton3;
    KeyPressButton* keyButton4;
    KeyPressButton* keyButton5;
    KeyPressButton* keyButton6;
    KeyPressButton* keyButton7;
    KeyPressButton* keyButton8;
    KeyPressButton* keyButton9;
    KeyPressButton* keyButton10;

    QGraphicsColorizeEffect *buttonEffect;

    SoundAnalyzer* soundAnalyzer;
    QByteArray arrdata;
    Sort* sort;


};
#endif // MAINWINDOW_H
