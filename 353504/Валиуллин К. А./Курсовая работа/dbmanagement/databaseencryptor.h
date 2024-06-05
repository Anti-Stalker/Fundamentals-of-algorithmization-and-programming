#ifndef DATABASEENCRYPTOR_H
#define DATABASEENCRYPTOR_H

#include <QFile>
#include <QDataStream>
#include <QString>
#include <QByteArray>
#include <QRandomGenerator>

#include "aes256/AES256.hpp"

#include "databasecontroller.h"

class DatabaseEncryptor : public DatabaseController
{
public:
    explicit DatabaseEncryptor(QObject *parent = nullptr);
    void encryptDatabase();
    QByteArray generateIV();

private:
    const int kIvLength = 16;
};

#endif // DATABASEENCRYPTOR_H
