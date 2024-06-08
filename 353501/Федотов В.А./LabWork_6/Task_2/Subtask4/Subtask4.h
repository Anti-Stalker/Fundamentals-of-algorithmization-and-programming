#pragma once

#include <qtconfigmacros.h>
#include <qtmetamacros.h>
#include <qwidget.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Subtask4;
}
QT_END_NAMESPACE


class Subtask4 : public QWidget {
    Q_OBJECT
public:
    Subtask4(QWidget *parent = nullptr);
    ~Subtask4();

signals:

private slots:
    void save();
    void read();

protected:
    QString filename = "/home/marahetters/OAIP-Labs/Sem 2/Lab6/Subtask4.txt";

    Ui::Subtask4 *ui;
};
