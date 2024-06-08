#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qgraphicsscene.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
  input = arg1;
}

void MainWindow::on_pushButton_clicked()
{
  intArray = convertQStringToIntArray(input);

  QString content;
  for (int value : intArray)
  {
    content += QString::number(value) + " ";
  }

  if (!content.isEmpty())
    ui->lineEdit_2->setText(content.trimmed());
  else
    ui->lineEdit_2->setText("Error");

  intArray = processVector(intArray);

  content.clear();
  for (int value : intArray)
  {
    content += QString::number(value) + " ";
  }

  if (!content.isEmpty())
    ui->lineEdit_3->setText(content.trimmed());
  else
    ui->lineEdit_3->setText("Error");
}

QVector<int> MainWindow::convertQStringToIntArray(const QString &inputString)
{
  QVector<int> resultArray;
  QStringList stringList = inputString.split(" ", Qt::SkipEmptyParts);

  for (const QString &str : stringList)
  {
    bool ok;
    int intValue = str.toInt(&ok);
    if (ok)
    {
      resultArray.append(intValue);
    }
    else
    {
      resultArray.clear();
      return resultArray;
      qDebug() << "Не удалось преобразовать:" << str;
    }
  }

  return resultArray;
}

QVector<int> MainWindow::processVector(const QVector<int> &inputVector)
{
  QVector<int> resultVector;

  for (int i = 0; i < inputVector.size(); i += 3)
  {
    int sum = 0;
    int count = 0;

    QVector<int> subArray;
    for (int j = i; j < i + 3 && j < inputVector.size(); ++j)
    {
      subArray.push_back(inputVector[j]);
      sum += inputVector[j];
      ++count;
    }
    std::sort(subArray.begin(), subArray.end());

    if (count == 3)
    {
      resultVector.push_back(subArray[1]);
    }
    else if (count > 0)
    {
      resultVector.push_back(sum / count);
    }
  }

  return resultVector;
}