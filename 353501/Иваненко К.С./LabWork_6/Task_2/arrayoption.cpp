#include "arrayoption.h"
#include "choosedialog.h"
#include <QFile>
#include <QMessageBox>

void ArrayOption::initInput()
{
  ChooseDialog chooseOption(MENU, 10);

  if (chooseOption.exec() == QDialog::Accepted)
  {
    size = chooseOption.getOption();
  }
  array = new int[size];

  connect(input, &QTextEdit::textChanged, [=]
          {auto s = input->toPlainText(); if (!s.isEmpty() && s.back() == '\n') {onEnterInput();} });
}

void ArrayOption::initOutput() {}

QString ArrayOption::getInstructions()
{
  return QString("Введите %1 элементов массива типа int, разделяя значения символом \'%2\'.\n"
                 "В результате массив будет записан в файл %3,\n"
                 "который затем будет прочитан и выведется на экран через пробел.")
      .arg(size)
      .arg(SEPARATOR)
      .arg(FNAME);
}

ArrayOption::~ArrayOption()
{
  if (array)
    delete[] array;
}

void ArrayOption::onEnterInput()
{

  auto lst = input->toPlainText().split(SEPARATOR);

  if (lst.size() > size)
  {
    QMessageBox::warning(input, "Предупреждение",
                         "Было введено больше данных, чем необходимо.");
    clear();
    return;
  }

  int i = 0;
  bool ok;
  foreach (auto s, lst)
  {
    array[i] = s.toInt(&ok);
    if (!ok)
    {
      QMessageBox::warning(input, "Предупреждение",
                           "Не удалось считать все данные. Убедитесь в "
                           "корректности их формата.");
      clear();
      return;
    }
    ++i;
  }
  for (int j = i; j < size; ++j)
  {
    array[j] = 0.0;
  }

  QFile f(FNAME);
  f.open(QFile::WriteOnly);
  QTextStream ts(&f);
  for (int i = 0; i < size; ++i)
  {
    ts << array[i] << ' ';
  }
  f.close();

  processOutput();
  clear();
}

void ArrayOption::processOutput()
{
  QFile f(FNAME);
  f.open(QFile::ReadOnly);
  QTextStream ts(&f);
  output->setText("Запись в файл произедена.\nПометка: " + ts.readAll());
  f.close();
}
