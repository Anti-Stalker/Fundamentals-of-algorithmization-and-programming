#ifndef DATABASECREATOR_H
#define DATABASECREATOR_H

#include "dbmanagement/databasecontroller.h"
#include "dbmanagement/databasegroupscreator.h"

#include <QDateTime>

class DatabaseCreator : public DatabaseController
{
public:
    DatabaseCreator(DatabaseGroupsCreator *databaseGroupsCreator, QObject *parent = nullptr);
    void createDatabase();

private slots:
    GroupData creatingStandartGroup();
    void createQueryNotesTable();
    void createQueryGroupsTable();

private:
    DatabaseGroupsCreator *databaseGroupsCreator;
};

#endif // DATABASECREATOR_H
