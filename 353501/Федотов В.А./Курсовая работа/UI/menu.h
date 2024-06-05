#pragma once

#include <qtconfigmacros.h>
#include <qtmetamacros.h>
#include <qwidget.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Menu;
}
QT_END_NAMESPACE


class Menu : public QWidget {
    Q_OBJECT
public:
    Menu(QWidget *parent = nullptr);
    ~Menu();

signals:
    void startGame(int width, int height, bool hardmode);

private slots:
    void handleStartGame();
    void showRulesBox();

private:
    int size_x = 20;
    int size_y = 20;

protected:
    Ui::Menu *ui;
};
