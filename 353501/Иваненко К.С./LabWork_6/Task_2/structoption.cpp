#include "structoption.h"
#include "town.h"
#include "parentoption.h"
#include <QFile>
#include <QMessageBox>

QString StructOption::getInstructions()
{
  Q_ASSERT(type != BOTH);

  if (type == INP)
  {
    return "Введите поля структуры Город в виде НАЗАНИЕ(строка) | ПОПУЛЯЦИЯ(число) | РЕГИОН(один символ) | СТОЛИЦА(+/-)\n"
           "Структура затем будет добавлена в файл.";
  }
  else if (type == OUT)
  {
    return "Выведется содержание файла с полями структур";
  }
  return "";
}

void StructOption::initInput()
{
  connect(input, &QTextEdit::textChanged, [=]{auto s = input->toPlainText(); if (!s.isEmpty() && s.back() == '\n') {enterInput();} });
}

void StructOption::initOutput()
{
  QFile f(FNAME);
  if (!f.open(QFile::ReadOnly))
  {
    QMessageBox::warning(input, "Предупреждение", "Не удалось прочитать файл. Возможно, вы еще ни разу не записали туда структуру. ");
    return;
  }

  QTextStream ts(&f);
  output->setText(ts.readAll());
  f.close();
}

void StructOption::processOutput()
{
  output->setText("Запись в файл произедена.\nПометка: Файл обновлен.");
}

void StructOption::enterInput()
{

  QString s = input->toPlainText();
  s.chop(1);

  try
  {
    Town town(s.toStdString());
  }
  catch (const std::invalid_argument &ex)
  {
    QMessageBox::warning(input, "Предупреждение!", "Не удалось считать все поля структурыы.");
    clear();
    return;
  }

  QFile f(FNAME);
  f.open(QFile::Append);
  QTextStream ts(&f);
  ts << s << '\n';
  f.close();

  clear();

  processOutput();
}
