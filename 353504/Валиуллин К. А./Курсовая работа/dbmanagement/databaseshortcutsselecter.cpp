#include "databaseshortcutsselecter.h"

DatabaseShortcutsSelecter::DatabaseShortcutsSelecter(QObject *parent)
    : DatabaseController{parent}
{}

void DatabaseShortcutsSelecter::copyPasswordToClipboard(int noteId)
{
    openDatabase();
    QSqlQuery query;
    QString passwordToCopy;
    QString queryRequest = "SELECT password FROM notes WHERE id = :id";
    query.prepare(queryRequest);
    query.bindValue(":id", noteId);
    query.exec();
    if (query.next()) {
        passwordToCopy = query.value(0).toString();
        clipboard->setText(passwordToCopy);
    }
    closeDatabase();
}

void DatabaseShortcutsSelecter::copyUsernameToClipboard(int noteId)
{
    openDatabase();
    QSqlQuery query;
    QString UsernameToCopy;
    QString queryRequest = "SELECT login FROM notes WHERE id = :id";
    query.prepare(queryRequest);
    query.bindValue(":id", noteId);
    query.exec();
    if (query.next()) {
        UsernameToCopy = query.value(0).toString();
        clipboard->setText(UsernameToCopy);
    }
    closeDatabase();
}
