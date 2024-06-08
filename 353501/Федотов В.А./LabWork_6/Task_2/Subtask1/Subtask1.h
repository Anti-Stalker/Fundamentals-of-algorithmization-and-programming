#pragma once

#include <qtconfigmacros.h>
#include <qtmetamacros.h>
#include <qwidget.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Subtask1;
}
QT_END_NAMESPACE


class Subtask1 : public QWidget {
    Q_OBJECT
public:
    Subtask1(QWidget *parent = nullptr);
    ~Subtask1();

signals:

private slots:
    void save();
    void read();

protected:
    QString filename = "/home/marahetters/OAIP-Labs/Sem 2/Lab6/Subtask1.txt";

    Ui::Subtask1 *ui;
};
