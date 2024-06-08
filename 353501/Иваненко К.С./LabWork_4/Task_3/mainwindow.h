#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
  class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow();
  ~MainWindow();

  QVector<int> convertQStringToIntArray(const QString &inputString);
  QVector<int> processVector(const QVector<int> &inputVector);

  QString input;
  QVector<int> intArray;

protected:
  Ui::MainWindow *ui;

private slots:
  void on_lineEdit_textChanged(const QString &arg1);
  void on_pushButton_clicked();
};
