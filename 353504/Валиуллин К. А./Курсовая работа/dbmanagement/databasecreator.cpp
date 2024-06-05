#include "DatabaseCreator.h"

DatabaseCreator::DatabaseCreator(DatabaseGroupsCreator *databaseGroupsCreator,
    QObject *parent) : DatabaseController(parent),
    databaseGroupsCreator(databaseGroupsCreator) {}

void DatabaseCreator::createDatabase() {
    if (!filePath.isEmpty()) {
        if (openDatabase()) {
            createQueryNotesTable();
            createQueryGroupsTable();
            GroupData gd = creatingStandartGroup();
            databaseGroupsCreator->createNewGroup(gd);
            emit transmitFilePath(filePath);
            emit transmitChangeToMainWindow(IndexMainWindow);
            closeDatabase();
        } else {
            QMessageBox::warning(parentWidget, "Ошибка", "Ошибка при открытии базы данных");
        }
    } else {
        QMessageBox::warning(parentWidget, "Ошибка", "Ошибка при создании базы данных: ");
    }
}

void DatabaseCreator::createQueryNotesTable() {
    QSqlQuery query;
    QString queryRequest = "CREATE TABLE notes ("
                           "id INTEGER PRIMARY KEY,"
                           "group_id INTEGER,"
                           "note_name VARCHAR(64) NOT NULL,"
                           "login VARCHAR(64),"
                           "url VARCHAR(64),"
                           "password VARCHAR(64) NOT NULL,"
                           "other_notes VARCHAR(500),"
                           "updated_at TIMESTAMP,"
                           "FOREIGN KEY (group_id) REFERENCES groups(id)"
                           ")";
    query.exec(queryRequest);
}

void DatabaseCreator::createQueryGroupsTable()
{
    QSqlQuery query;
    QString queryRequest = "CREATE TABLE groups ("
                           "id INTEGER PRIMARY KEY,"
                           "group_name VARCHAR(64) NOT NULL,"
                           "other_notes VARCHAR(500)"
                           ")";
    query.exec(queryRequest);
}

GroupData DatabaseCreator::creatingStandartGroup()
{
    GroupData gd;
    gd.groupName = "PasswordManager";
    gd.otherNotes = "Группа по умолчанию.";
    return gd;
}
