#pragma once

#include "Song.h"
#include <QMainWindow>
#include <qgraphicsscene.h>

using std::string;

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
    void initWithInitializerList();
    void initWithVariables();
    void initWithPointer();
    void initWithReference();


protected:
    QString getTitle();
    void print(const Song &song);
    Ui::MainWindow *ui;
};
