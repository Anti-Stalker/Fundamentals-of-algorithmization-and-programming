#ifndef DATABASEGROUPSCREATOR_H
#define DATABASEGROUPSCREATOR_H

#include "dbmanagement/databasecontroller.h"

class DatabaseGroupsCreator : public DatabaseController
{
public:
    explicit DatabaseGroupsCreator(QObject *parent = nullptr);
    void createNewGroup(const GroupData &groupData);
    bool isGroupTableEmpty();

private:
    QWidget widget;
};

#endif // DATABASEGROUPSCREATOR_H
