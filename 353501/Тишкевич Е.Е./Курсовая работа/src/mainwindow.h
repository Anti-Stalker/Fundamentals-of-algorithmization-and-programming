#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QtWidgets>
#include <searchworker.h>

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

public slots:
    void search_slot();
    void sort_slot();
    QVector<QString>getArtists();

    void handleLineEditClick();
    void handleTextEditClick();

private:
    Ui::MainWindow *ui;
    QString access_token = "ZSTxNoxeMvBzg3qUmFqB2FOl-hPMGQJtHRNSnU7zaMYtvXmHqswm_fyb2zBYukFl";
    QString entered_lyrics;
    int curr_clicks = 0;
    QString errors = "";
    QMovie* loadingMovie;
    QLabel* label;


};
#endif // MAINWINDOW_H
