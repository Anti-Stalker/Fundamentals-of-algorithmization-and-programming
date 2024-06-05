#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "airportStruct.h"
#include "dialog.h"
#include <QPrinter>
#include <QPrintDialog>

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

private:
  Airport airportInitWithString;
  Airport airportInitEachField;
  Airport userInputAirport;
  Airport airportForPointer;
  Airport airportForRef;
  Airport* ptrAirport = &airportForPointer;
  Airport& ref = airportForRef;

  void printFields(const Airport &airportInitEachField, int size, int sizeWeekendYears);
  void printFields(const Airport* airportInitEachField, int sizeStr, int sizeWeekendYears);
private slots:
  void on_init_with_str_clicked();
  void on_init_with_user_input_clicked();
  void on_init_each_filed_clicked();
  void on_init_by_pointer_clicked();
  void on_init_by_ref_clicked();

  void initWithUserInput(const int& runwayCount, const double& area, char inputChar, const bool& hasControlTower, std::string airportName, const QVector<int>& numbers);

  void on_print_clicked();
protected:
  Ui::MainWindow *ui;
};