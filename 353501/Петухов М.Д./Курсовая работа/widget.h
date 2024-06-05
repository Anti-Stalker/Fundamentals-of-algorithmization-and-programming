#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMainWindow>
#include "rulesDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QMainWindow* mainGameWindowPtr = nullptr;

private:
    Ui::Widget *ui;
public slots:
    void execute();
private slots:
    void on_startGameButton_clicked();
    void on_rulesDialogButton_clicked();
};
#endif // WIDGET_H
