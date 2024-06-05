#include "databaseencryptor.h"

DatabaseEncryptor::DatabaseEncryptor(QObject *parent)
    : DatabaseController{parent}
{}

void DatabaseEncryptor::encryptDatabase()
{
    QFile databaseFile(filePath);
    if (databaseFile.open(QIODevice::ReadOnly))
    {
        QByteArray databaseContent = databaseFile.readAll();
        databaseFile.close();
        QByteArray iv = generateIV();
        AES256 aes(password.toStdString(), iv.toStdString());
        std::string encryptedData = aes.encrypt(databaseContent.toStdString());
        QByteArray encryptedDataArray = QByteArray::fromStdString(encryptedData);
        QByteArray encryptedDataWithIV;
        encryptedDataWithIV.append(iv);
        encryptedDataWithIV.append(encryptedDataArray);
        if (databaseFile.open(QIODevice::WriteOnly))
        {
            databaseFile.write(encryptedDataWithIV);
            databaseFile.close();
        }
        else
        {
            throw std::runtime_error("ERRORENCRYPTOR");
        }
    }
    else
    {
        throw std::runtime_error("ERRORENCRYPTOR");
    }
}

QByteArray DatabaseEncryptor::generateIV()
{
    QByteArray iv(kIvLength, 0);
    QRandomGenerator randomGenerator(QDateTime::currentMSecsSinceEpoch());
    for (int i = 0; i < kIvLength; ++i) {
        iv[i] = static_cast<char>(randomGenerator.generate() % 256);
    }
    return iv;
}

