#ifndef TASK1_MAINWINDOW_H
#define TASK1_MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QPushButton>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QMainWindow {
Q_OBJECT

public:
    mainwindow();

protected:
    Ui::mainwindow *ui;

private:
    QVector<QPushButton*> buttons;
    QVector<int> connect_keyboard_buttons;
    void keyPressEvent(QKeyEvent *e) override;
    void keyReleaseEvent(QKeyEvent *e) override;
    int current_language = 0;
    bool caps = false;
    bool shift = false;
    bool is_training = false;
    void setLayout();
    void resetWidgets();
    void setText();
    QString training_text;
    QString green;
    QString black;
    int cur_pos = 0;
    QTimer *timer;
    void increase_mistake();
    void increase_words();
    void show_end_game();
    QString Convert();

    struct data
    {
        int time = 0;
        int mistakes = 0;
        int words = 0;
        int all_symbols = 0;
    };
    data information;

private slots:
    void change_language_clicked(int type);
    void update_data();
    void increase_timer();
    void start_game_clicked();
    void open_file_clicked();
};

#endif //TASK1_MAINWINDOW_H