#include "parentoption.h"
#include <qobject.h>
#include <qplaintextedit.h>

ParentOption::ParentOption(QTextEdit *inp, QTextEdit *outp, QLabel *instr, QObject *par, OptionType _type)
    : input(inp), output(outp), instructions(instr), type(_type) {}

ParentOption::~ParentOption()
{
  input->disconnect();
}

void ParentOption::init()
{
  input->setPlainText("");
  output->setText("");

  if (type == BOTH || type == INP)
  {
    initInput();
  }
  if (type == BOTH || type == OUT)
  {
    initOutput();
  }

  if (type == OUT)
  {
    input->setEnabled(false);
  }
  else
  {
    input->setEnabled(true);
  }

  instructions->setText(getInstructions());
}

void ParentOption::clear()
{
  input->setText("");
}
