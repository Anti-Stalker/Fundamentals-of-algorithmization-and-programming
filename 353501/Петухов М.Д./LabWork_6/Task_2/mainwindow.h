#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "dialog.h"
#include "airportStruct.h"

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

public:
  

public:
  void getAndSaveTextToFile();
  void outputTextFromFile();
  void getArrayAndSaveToFile();
  void readArrayFromFileAndPrint();
  void initWithUserInputTxtFile(const int& runwayCount, const double& area, char inputChar, const bool& hasControlTower,
                                    std::string airportName, const QVector<int>& numbers);
  void readAirportFromFile();
  void initWithUserInputBinFile(const int& runwayCount, const double& area, char inputChar, const bool& hasControlTower,
                                    std::string airportName, const QVector<int>& numbers);
  void readStructuresFromBinaryFile();
  void appendSentencesToTextFile();
  void readSentencesFromTextFile();

public slots:
  void on_select_case_clicked();
  void on_open_struct_dialog_clicked();
  void on_open_struct_dialog_for_bin_clicked();

protected:
  Ui::MainWindow *ui;
};