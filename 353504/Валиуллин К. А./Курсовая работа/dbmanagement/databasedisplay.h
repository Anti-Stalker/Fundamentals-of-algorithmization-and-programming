#ifndef DATABASEDISPLAY_H
#define DATABASEDISPLAY_H

#include "databasecontroller.h"

class DatabaseDisplay : public DatabaseController
{
public:
    explicit DatabaseDisplay(QObject *parent = nullptr);
    void showDatabasesGroups(QListWidget *list);
    void showNotesByGroupId(QTableWidget *table, const int groupId);
};

#endif // DATABASEDISPLAY_H
