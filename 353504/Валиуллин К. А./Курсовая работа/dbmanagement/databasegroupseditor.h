#ifndef DATABASEGROUPSEDITOR_H
#define DATABASEGROUPSEDITOR_H

#include "dbmanagement/databasecontroller.h"

class DatabaseGroupsEditor : public DatabaseController
{
public:
    explicit DatabaseGroupsEditor(QObject *parent = nullptr);
    void selectGroupData(GroupData &groupData, const int id);
    void updateGroup(GroupData &groupData);
};

#endif // DATABASEGROUPSEDITOR_H
