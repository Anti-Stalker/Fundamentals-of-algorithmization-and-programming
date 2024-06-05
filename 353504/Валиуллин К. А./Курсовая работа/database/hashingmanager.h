#ifndef HASHINGMANAGER_H
#define HASHINGMANAGER_H

#include "settingsmanager.h"

class HashingManager : public SettingsManager
{
public:
    static void removeOldHashRecord(const QString &oldFilePath, const QString &newName);
    static bool comparePasswordHash(const QString& dbName, const QString& enteredPassword);
    static void savePasswordHash(const QString &dbName, const QString &password);

private slots:
    static QByteArray hashNewPassword(const QString &password);
    static QString creatingNewRecordName(const QString &oldFilePath);
    static QByteArray generateSalt();
    static QByteArray hashPasswordEntry(const QString& password, const QByteArray& salt);

private:
    static const int kSaltLength = 16;

};

#endif // HASHINGMANAGER_H
