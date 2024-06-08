#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class StartWindow; }
QT_END_NAMESPACE

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

signals:
    void startGame();
    void closeApplication();

private slots:
    void onStartButtonClicked();
    void onCloseButtonClicked();

private:
    Ui::StartWindow *ui;
};

#endif // STARTWINDOW_H
