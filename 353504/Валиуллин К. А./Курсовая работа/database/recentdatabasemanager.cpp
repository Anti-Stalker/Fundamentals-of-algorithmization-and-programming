#include "recentdatabasemanager.h"

QString RecentDatabaseManager::recentDatabasesKey = "recentDatabases";

QString RecentDatabaseManager::getRecentDatabasesKey()
{
    return recentDatabasesKey;
}

QStringList RecentDatabaseManager::loadRecentDatabases()
{
    return settings.value(getRecentDatabasesKey()).toStringList();
}

void RecentDatabaseManager::saveRecentDatabases(const QStringList &databases)
{
    settings.setValue(getRecentDatabasesKey(), databases);
}

QStringList RecentDatabaseManager::deleteOneListItem(const QString &fp)
{
    QStringList recentDatabases = RecentDatabaseManager::loadRecentDatabases();
    recentDatabases.removeOne(fp);
    RecentDatabaseManager::saveRecentDatabases(recentDatabases);
    return loadRecentDatabases();
}
