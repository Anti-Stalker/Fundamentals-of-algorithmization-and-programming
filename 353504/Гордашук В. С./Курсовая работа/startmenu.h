#ifndef STARTMENU_H
#define STARTMENU_H

#include <QWidget>
#include <widget.h>
#include <QPainter>
#include <QPixmap>

namespace Ui {
class StartMenu;
}

class StartMenu : public QWidget
{
    Q_OBJECT

public:
    explicit StartMenu(QWidget *parent = nullptr);
    ~StartMenu();

private slots:
    void on_start_clicked();

signals:
    void start();


private:
    Ui::StartMenu *ui;
protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // STARTMENU_H
