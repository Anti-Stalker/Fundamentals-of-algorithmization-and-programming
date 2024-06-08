#include "paragraphoption.h"
#include <QFile>

QString ParagraphOption::getInstructions()  {
    return QString("Введите абзац текста (до нажатия Enter), который затем будет сохранен в файл с именем %1,\nи выведен на экран из этого файла.").arg(FNAME);
}

void ParagraphOption::initInput()  {
        connect(input, &QTextEdit::textChanged, [=]{auto s = input->toPlainText(); if(!s.isEmpty() && s.back() == '\n'){textChanged();}});
}

void ParagraphOption::initOutput()  {}

void ParagraphOption::processOutput() {
    QFile file(FNAME);
    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }

    
    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_6_0);

    QByteArray data;
    while (!stream.atEnd()) {
        char ch;
        stream.readRawData(&ch, sizeof(char));
        data.append(ch);
    }
    output->setText("Запись в файл произедена.\nПометка: " + QString::fromUtf8(data));
    file.close();
}   

void ParagraphOption::textChanged() {
    QFile file(FNAME);
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }

    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_6_0);

    QByteArray data = input->toPlainText().toUtf8();
    stream.writeRawData(data.constData(), data.size());

    file.close();

    clear();
    processOutput();
}
