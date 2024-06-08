#pragma once

#ifndef PARAGRAPHOPTION_H
#define PARAGRAPHOPTION_H

#include "parentoption.h"

class ParagraphOption : public ParentOption
{
  Q_OBJECT

  const QString FNAME = FILENAME + ".txt";
  virtual QString getInstructions() override;
  virtual void initInput() override;
  virtual void initOutput() override;

public:
  using ParentOption::ParentOption;

private slots:
  void textChanged();

  virtual void processOutput() override;
};

#endif // PARAGRAPHOPTION_H
