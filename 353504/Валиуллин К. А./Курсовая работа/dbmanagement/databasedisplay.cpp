#include "databasedisplay.h"

DatabaseDisplay::DatabaseDisplay(QObject *parent)
    : DatabaseController{parent}
{}

void DatabaseDisplay::showDatabasesGroups(QListWidget* list)
{
    openDatabase();
    list->clear();
    QSqlQuery query;
    query.exec("SELECT id, group_name FROM groups");
    while (query.next()) {
        int idValue = query.value(0).toInt();
        QString groupName = query.value(1).toString();
        QListWidgetItem *item = new QListWidgetItem(groupName);
        item->setData(Qt::UserRole, idValue);
        list->addItem(item);
    }
    closeDatabase();
}

void DatabaseDisplay::showNotesByGroupId(QTableWidget *table, const int groupId)
{
    openDatabase();
    QSqlQuery query;
    QString queryRequest = "SELECT notes.id, notes.note_name, notes.login, notes.url, notes.other_notes, notes.updated_at "
                           "FROM notes "
                           "JOIN groups ON notes.group_id = groups.id "
                           "WHERE groups.id = :groupId";
    query.prepare(queryRequest);
    query.bindValue(":groupId", groupId);

    if (query.exec())
    {
        table->clearContents();
        table->setRowCount(0);
        int row = 0;
        while (query.next())
        {
            table->insertRow(row);
            for (int col = 0; col < 5; ++col)
            {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col + 1).toString());
                table->setItem(row, col, item);
            }

            int idValue = query.value(0).toInt();
            table->item(row, 0)->setData(Qt::UserRole, idValue);
            ++row;
        }
    }
    closeDatabase();
}
