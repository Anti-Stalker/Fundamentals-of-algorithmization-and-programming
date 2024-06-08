#pragma once

#ifndef STRUCTOPTION_H
#define STRUCTOPTION_H
#include "parentoption.h"

class StructOption : public ParentOption
{
  Q_OBJECT
public:
  using ParentOption::ParentOption;

  const QString FNAME = FILENAME + "_1.txt";

protected:
  virtual QString getInstructions();
  virtual void initInput();
  virtual void initOutput();
  void enterInput();
protected slots:
  virtual void processOutput();
};

#endif // STRUCTOPTION_H
