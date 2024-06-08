#include "binstructoption.h"
#include "town.h"
#include <QFile>
#include <QMessageBox>

QString BinStructOption::getInstructions()
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

void BinStructOption::initInput()
{
  connect(input, &QTextEdit::textChanged, [=]{auto s = input->toPlainText(); if (!s.isEmpty() && s.back() == '\n') {enterInput();}});
}

void BinStructOption::initOutput()
{
  QFile f(FNAME);
  if (!f.open(QFile::ReadOnly))
  {
    QMessageBox::warning(input, "Предупреждение", "Не удалось прочитать файл. Возможно, вы еще ни разу не записали туда структуру.");
    return;
  }

  QDataStream ds(&f);
  QString res;

  while (!ds.atEnd())
  {
    Town town;
    ds.readRawData(reinterpret_cast<char *>(&town), sizeof(Town));
    res += town.to_string(';') + '\n';
  }

  f.close();

  output->setText(res);
}

void BinStructOption::enterInput()
{
  QString s = input->toPlainText();
  s.chop(1);

  Town town;
  try
  {
    town = Town(s.toStdString());
  }
  catch (const std::invalid_argument &ex)
  {
    QMessageBox::warning(input, "Предупреждение", "Не удалось считать все поля структуры.");
    clear();
    return;
  }

  QFile f(FNAME);
  f.open(QFile::Append);
  QDataStream ds(&f);
  ds.writeRawData(reinterpret_cast<char *>(&town), sizeof(Town));
  f.close();

  clear();
  processOutput();
}

void BinStructOption::processOutput()
{
  output->setText("Запись в файл произедена.\nПометка: Файл обновлен.");
}