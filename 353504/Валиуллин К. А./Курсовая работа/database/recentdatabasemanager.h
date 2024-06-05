#ifndef RECENTDATABASEMANAGER_H
#define RECENTDATABASEMANAGER_H

#include "settingsmanager.h"

class RecentDatabaseManager : public SettingsManager
{

public:
    static QString getRecentDatabasesKey();
    static QStringList loadRecentDatabases();
    static void saveRecentDatabases(const QStringList& databases);
    static QStringList deleteOneListItem(const QString &fp);

private:
    static QString recentDatabasesKey;
};

#endif // RECENTDATABASEMANAGER_H
