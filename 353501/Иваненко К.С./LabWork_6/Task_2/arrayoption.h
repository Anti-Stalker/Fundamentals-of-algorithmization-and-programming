#pragma once

#ifndef ARRAYOPTION_H
#define ARRAYOPTION_H

#include "parentoption.h"
#include <qtmetamacros.h>
class ArrayOption : public ParentOption {
  Q_OBJECT
public:
  using ParentOption::ParentOption;
  ~ArrayOption() override;

  static const char SEPARATOR = '^';
  const QString FNAME = FILENAME + "_0.txt";

  int size = 0;
  int *array = nullptr;

  const QString MENU = "Введите размер запрашиваемого массива";

protected:
  void initInput() override;
  void initOutput() override;
  QString getInstructions() override;


protected:
  void onEnterInput();

protected slots:
  void processOutput() override;
};

#endif // ARRAYOPTION_H
