#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStringListModel>
#include "dequeue.h"

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

private slots:
    void on_dequeueSizePushButton_clicked();

    void on_enqueuePushButton_clicked();

    void on_dequeuePushButton_clicked();

    void on_inputPlainTextEdit_textChanged();

    void on_isEmptyPushButton_clicked();

    void on_frontPushButton_clicked();

    void on_saveValuesPushButton_clicked();

    void on_moveValuesPushButton_clicked();

private:
    Ui::MainWindow *ui;
    Dequeue<QString> *deque;
    QModelIndexList selectedValues;
    QStringList savedElements;

    void SetListValues();
};
#endif // MAINWINDOW_H
