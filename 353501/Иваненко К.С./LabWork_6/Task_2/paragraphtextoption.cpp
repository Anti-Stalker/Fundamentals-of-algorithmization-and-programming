#include "paragraphtextoption.h"
#include <QFile>
#include <QMessageBox>

QString ParagraphTextOption::getInstructions()
{
    Q_ASSERT(type != BOTH);
    if (type == INP)
    {
        return QString("Введите абзац текста (до нажатия Enter), который будет записан (дозаписан) в файл %1.").arg(FNAME);
    }
    else if (type == OUT)
    {
        return "Все введенные вами ранее абзацы будут выведены на экран.";
    }
}

void ParagraphTextOption::initInput()
{
    connect(input, &QTextEdit::textChanged, [=] {auto s = input->toPlainText(); if(!s.isEmpty() &&s.back() == '\n'){enterInput();} });
}

void ParagraphTextOption::initOutput()
{
    QFile f(FNAME);
    if (!f.open(QFile::ReadOnly))
    {
        QMessageBox::warning(input, "Предупреждение", "Не удалось прочитать файл. Возможно, вы еще ни разу не выбрали опцию ввод.");
        output->setText("");
        return;
    }
    output->setText(f.readAll());
    f.close();
}

void ParagraphTextOption::processOutput()
{
    output->setText("Запись в файл произведена.");
}

void ParagraphTextOption::enterInput()
{
    QFile f(FNAME);
    f.open(QFile::Append);
    QTextStream ts(&f);
    auto s = input->toPlainText();
    ts << s;
    f.close();
    clear();
    processOutput();
}