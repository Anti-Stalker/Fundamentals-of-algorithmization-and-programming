#ifndef BINSTRUCTOPTION_H
#define BINSTRUCTOPTION_H
#include "parentoption.h"

class BinStructOption : public ParentOption
{
  const QString FNAME = FILENAME + "_2.bin";

  using ParentOption::ParentOption;
  virtual QString getInstructions();

  virtual void initInput();
  virtual void initOutput();
  void enterInput();

protected slots:
  virtual void processOutput();
};

#endif // BINSTRUCTOPTION_H
