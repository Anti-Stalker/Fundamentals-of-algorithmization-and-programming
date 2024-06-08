#ifndef PARAGRAPHTEXTOPTION_H
#define PARAGRAPHTEXTOPTION_H

#include "paragraphoption.h"
#include "parentoption.h"

class ParagraphTextOption : public ParentOption {
  Q_OBJECT

public:
  using ParentOption::ParentOption;

  const QString FNAME = FILENAME + "_3.txt";

  virtual QString getInstructions() override;

  virtual void initInput() override;
  virtual void initOutput() override;

  void enterInput();

protected slots:
  virtual void processOutput() override;
};

#endif // PARAGRAPHTEXTOPTION_H
