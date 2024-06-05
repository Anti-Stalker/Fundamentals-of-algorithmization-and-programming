#include "databasedecryptor.h"

DatabaseDecryptor::DatabaseDecryptor(QObject *parent)
    : DatabaseController{parent}
{}

bool DatabaseDecryptor::decryptDatabase()
{
    QFile databaseFile(filePath);
    if (databaseFile.open(QIODevice::ReadOnly))
    {
        QByteArray encryptedDataWithIV = databaseFile.readAll();
        databaseFile.close();
        QByteArray iv = encryptedDataWithIV.left(16);
        AES256 aes(tryPassword.toStdString(), iv.toStdString());
        QByteArray encryptedData = encryptedDataWithIV.mid(16);
        std::string decryptedData;
        try {
            decryptedData = aes.decrypt(encryptedData.toStdString());
        } catch (const std::invalid_argument& e) {
            return false;
        }
        QByteArray decryptedDataArray = QByteArray::fromStdString(decryptedData);
        if (databaseFile.open(QIODevice::WriteOnly))
        {
            databaseFile.write(decryptedDataArray);
            databaseFile.close();
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
