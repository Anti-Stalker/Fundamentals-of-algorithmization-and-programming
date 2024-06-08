#pragma once

#include <qtconfigmacros.h>
#include <qtmetamacros.h>
#include <qwidget.h>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Subtask2;
}
QT_END_NAMESPACE


class Subtask2 : public QWidget {
    Q_OBJECT
public:
    Subtask2(QWidget *parent = nullptr);
    ~Subtask2();

signals:

private slots:
    void setSize();
    void save();
    void read();

protected:
    QTableWidget *table;
    QString filename = "/home/marahetters/OAIP-Labs/Sem 2/Lab6/Subtask2.txt";

    Ui::Subtask2 *ui;
};
