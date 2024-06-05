#ifndef DATABASEDECRYPTOR_H
#define DATABASEDECRYPTOR_H

#include <QFile>
#include <QDataStream>
#include <QString>
#include <QByteArray>

#include "aes256/AES256.hpp"

#include "databasecontroller.h"

class DatabaseDecryptor : public DatabaseController
{
public:
    explicit DatabaseDecryptor(QObject *parent = nullptr);
    bool decryptDatabase();
};

#endif // DATABASEDECRYPTOR_H
