#include "databasegroupscreator.h"

DatabaseGroupsCreator::DatabaseGroupsCreator(QObject *parent)
    : DatabaseController{parent}
{}

void DatabaseGroupsCreator::createNewGroup(const GroupData &groupData)
{
    openDatabase();
    QSqlQuery query;
    query.prepare("INSERT INTO groups (group_name, other_notes)"
                  " VALUES (:groupName, :otherNotes)");
    query.bindValue(":groupName", groupData.groupName);
    query.bindValue(":otherNotes", groupData.otherNotes);
    query.exec();
    closeDatabase();
}

bool DatabaseGroupsCreator::isGroupTableEmpty()
{
    openDatabase();
    bool isEmpty = true;
    int count = 0;
    QSqlQuery query;
    QString isEmptyQuery = "SELECT COUNT(*) FROM groups";
    query.prepare(isEmptyQuery);
    if (query.exec())
    {
        if (query.next())
        {
            count = query.value(0).toInt();
            if (count != 0) {
                isEmpty = false;
            }
        }
    }
    closeDatabase();
    return isEmpty;
}

