#pragma once

#ifndef PARENTOPTION_H
#define PARENTOPTION_H

#include <QLabel>
#include <QObject>
#include <QTextEdit>

enum OptionType
{
  BOTH = 0,
  INP = 1,
  OUT = 2
};

class ParentOption : public QObject
{

  Q_OBJECT

protected:
  OptionType type = BOTH;

  QLabel *instructions;
  QTextEdit *input;
  QTextEdit *output;

  const QString FILENAME = "ИваненкоЛаб20";

public:
  ParentOption(QTextEdit *inp, QTextEdit *outp, QLabel *instr, QObject *par = nullptr, OptionType = BOTH);
  virtual ~ParentOption();

  void init();
  virtual QString getInstructions() = 0;
  virtual void initInput() = 0;
  virtual void initOutput() = 0;
  void clear();

protected slots:
  virtual void processOutput() = 0;
};

#endif // PARENTOPTION_H
