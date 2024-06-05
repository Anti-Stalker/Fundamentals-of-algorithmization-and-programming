#ifndef QMESSAGEQUESTION_H
#define QMESSAGEQUESTION_H
#pragma once

#include <QMessageBox>

class QMessageQuestion
{
public:
    static QMessageBox *setQuestion(QString setTitle, QString setText);
};

#endif // QMESSAGEQUESTION_H
