#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QKeyEvent>
#include <QTimer>

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
    QVector<QPushButton*> getButtons();
    void setNewKeyBoard();
    QVector<QVector<QString>> getGermanKeyboard();
    QVector<QVector<QString>> getFranchKeyboard();
    QVector<QVector<QString>> getArabicKeyboard();
    QVector<QVector<QString>> getEnglishKeyboard();
    QVector<QVector<QString>> getBelarussianKeyboard();
    QVector<QVector<QString>> getHerbewKeyboard();
    QVector<QVector<QString>> getChinaseKeyboard();
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void changeColorAtIndex(int index, const QString& color);
    void checkIsCorrectSymbol(QString ch);

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_fileButton_clicked();

    void on_startButton_clicked();

    void on_endButton_clicked();
    void startTimer();
    void stopTimer();
    void updateLabels();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    qint64 startTime;
    bool isCaps = false;
    bool isShift = false;
    int indexOfLanguage = 0;
    int currIndOfText = -1;
    int cntAllStmbol = -1;
    int cntCorrectSymbol = -1;
    QString testString = "";
    QString oldStr = "";
    bool isActiveTrain = false;
    QVector<QVector<QString>> currKeyboard;
};
#endif // MAINWINDOW_H
