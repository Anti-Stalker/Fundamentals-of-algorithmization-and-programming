#ifndef DATABASEEDITOR_H
#define DATABASEEDITOR_H

#include "other/checkifdatabaseexistwarning.h"

#include "databasecontroller.h"

class DatabaseEditor : public DatabaseController
{
public:
    explicit DatabaseEditor(QObject *parent = nullptr);
    void updateDatabaseName(CheckIfDatabaseExistWarning *checkIfDatabaseExistWarning, QString newBaseName, bool deleleAndRename);
    void updateDatabasePassword(QString newBasePassword);

private:
    QWidget widget;
};

#endif // DATABASEEDITOR_H
