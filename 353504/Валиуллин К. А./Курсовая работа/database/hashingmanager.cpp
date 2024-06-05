#include "hashingmanager.h"

void HashingManager::savePasswordHash(const QString& dbName, const QString& password)
{
    QByteArray passwordHash = hashNewPassword(password);
    QString hashKey = dbName + "_hash";
    settings.setValue(hashKey, passwordHash);
}

bool HashingManager::comparePasswordHash(const QString& filePath, const QString& enteredPassword)
{
    QString hashKey = creatingNewRecordName(filePath);
    QByteArray savedHash = settings.value(hashKey).toByteArray();
    QByteArray savedSalt = savedHash.left(kSaltLength);
    QByteArray enteredHash = hashPasswordEntry(enteredPassword, savedSalt);
    return savedHash == enteredHash;
}

QByteArray HashingManager::hashNewPassword(const QString& password)
{
    QByteArray salt = generateSalt();
    QByteArray passwordData = salt + password.toUtf8();
    QByteArray hash = QCryptographicHash::hash(passwordData, QCryptographicHash::Sha256);
    QByteArray hashedPassword = salt + hash;
    return hashedPassword;
}

QByteArray HashingManager::generateSalt()
{
    QByteArray salt(kSaltLength, 0);
    QRandomGenerator randomGenerator(QDateTime::currentMSecsSinceEpoch());
    for (int i = 0; i < kSaltLength; ++i) {
        salt[i] = static_cast<char>(randomGenerator.generate() % 256);
    }
    return salt;
}

QByteArray HashingManager::hashPasswordEntry(const QString& password, const QByteArray& salt)
{
    QByteArray passwordData = salt + password.toUtf8();
    QByteArray hash = QCryptographicHash::hash(passwordData, QCryptographicHash::Sha256);
    QByteArray hashedPassword = salt + hash;
    return hashedPassword;
}

QString HashingManager::creatingNewRecordName(const QString &oldFilePath)
{
    QFileInfo fileInfo(oldFilePath);
    QString dbName = fileInfo.baseName();
    QString oldHashKey = dbName + "_hash";
    return oldHashKey;
}

void HashingManager::removeOldHashRecord(const QString &oldFilePath, const QString &newName)
{
    QString oldHashKey = creatingNewRecordName(oldFilePath);
    if (oldHashKey == newName) {
        return;
    }
    settings.remove(oldHashKey);
}
