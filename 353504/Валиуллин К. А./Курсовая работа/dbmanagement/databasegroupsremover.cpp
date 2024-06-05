#include "databasegroupsremover.h"

DatabaseGroupsRemover::DatabaseGroupsRemover(QObject *parent)
    : DatabaseController{parent}
{}

void DatabaseGroupsRemover::deleteGroup(const int groupId)
{
    openDatabase();
    QSqlQuery query;
    query.prepare("DELETE FROM groups WHERE id = :groupId");
    query.bindValue(":groupId", groupId);
    if (query.exec()) {
    } else {
        closeDatabase();
        throw std::runtime_error("Ошибка при удалении записей группы");
    }
    closeDatabase();
}

void DatabaseGroupsRemover::deleteNotesByGroupId(int groupId) {
    if (openDatabase()) {
        QSqlQuery query;
        query.prepare("DELETE FROM notes WHERE group_id = :groupId");
        query.bindValue(":groupId", groupId);
        if (query.exec()) {
        } else {
            closeDatabase();
            throw std::runtime_error("Ошибка при удалении записей группы");
        }
        closeDatabase();
    } else {
        closeDatabase();
        throw std::runtime_error("Ошибка при удалении записей группы");
    }
}
