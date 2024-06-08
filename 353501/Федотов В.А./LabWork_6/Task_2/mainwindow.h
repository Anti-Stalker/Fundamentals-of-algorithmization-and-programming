#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
  
public:
    MainWindow();

private slots:
    void subtaskChanged(int index);

protected:
    QWidget *currentSubtask = nullptr;
    Ui::MainWindow *ui;
};
