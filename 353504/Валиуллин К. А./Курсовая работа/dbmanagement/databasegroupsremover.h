#ifndef DATABASEGROUPSREMOVER_H
#define DATABASEGROUPSREMOVER_H

#include "databasecontroller.h"

class DatabaseGroupsRemover : public DatabaseController
{
public:
    explicit DatabaseGroupsRemover(QObject *parent = nullptr);
    void deleteGroup(const int groupId);
    void deleteNotesByGroupId(int groupId);

};

#endif // DATABASEGROUPSREMOVER_H
