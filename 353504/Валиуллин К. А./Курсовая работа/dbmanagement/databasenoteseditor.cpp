#include "dbmanagement/databasenoteseditor.h"

DatabaseNotesEditor::DatabaseNotesEditor(QObject *parent)
    : DatabaseController{parent}
{}

void DatabaseNotesEditor::selectNoteData(NoteData &noteData, const int id)
{
    openDatabase();

    QSqlQuery query;
    QString queryRequest = "SELECT id, note_name, login, url, password, other_notes, group_id "
                           "FROM notes "
                           "WHERE id = :id";
    query.prepare(queryRequest);
    query.bindValue(":id", id);

    if (query.exec())
    {
        if (query.next())
        {
            noteData.id = query.value("id").toInt();
            noteData.noteName = query.value("note_name").toString();
            noteData.userName = query.value("login").toString();
            noteData.url = query.value("url").toString();
            noteData.passwordEntry = query.value("password").toString();
            noteData.otherNotes = query.value("other_notes").toString();
            noteData.group_id = query.value("group_id").toInt();
        }
        else
        {
            qDebug() << "Record not found.";
        }
    }
    else
    {
        qDebug() << "Error executing query:" << query.lastError().text();
    }

    closeDatabase();
}

void DatabaseNotesEditor::updateNote(NoteData &noteData)
{
    openDatabase();

    QSqlQuery query;
    QString queryRequest = "UPDATE notes SET note_name = :noteName, group_id = :groupId,"
                           " login = :login, url = :url, password = :password,"
                           " other_notes = :otherNotes, updated_at = :updatedAt"
                           " WHERE id = :noteId";
    query.prepare(queryRequest);
    query.bindValue(":noteName", noteData.noteName);
    query.bindValue(":groupId", noteData.group_id);
    query.bindValue(":login", noteData.userName);
    query.bindValue(":url", noteData.url);
    query.bindValue(":password", noteData.passwordEntry);
    query.bindValue(":otherNotes", noteData.otherNotes);
    query.bindValue(":noteId", noteData.id);
    QDateTime currentDateTime = QDateTime::currentDateTimeUtc();
    currentDateTime = currentDateTime.addSecs(3 * 3600);
    QString formattedDateTime = currentDateTime.toString("yyyy-MM-dd HH:mm:ss");
    query.bindValue(":updatedAt", formattedDateTime);

    if (query.exec())
    {
        qDebug() << "Record updated successfully.";
    }
    else
    {
        qDebug() << "Error executing query:" << query.lastError().text();
    }

    closeDatabase();
}
