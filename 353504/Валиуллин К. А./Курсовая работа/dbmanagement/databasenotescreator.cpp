    #include "dbmanagement/databasenotescreator.h"

DatabaseNotesCreator::DatabaseNotesCreator(QObject *parent)
    : DatabaseController{parent}
{}

void DatabaseNotesCreator::createNewNote(const NoteData &noteData)
{
    openDatabase();

    QSqlQuery query;
    QString insertQuery = "INSERT INTO notes (note_name, login, url, password, other_notes, group_id, updated_at) "
                          "VALUES (:noteName, :login, :url, :password, :otherNotes, :groupid, :updatedAt)";
    query.prepare(insertQuery);
    query.bindValue(":noteName", noteData.noteName);
    query.bindValue(":login", noteData.userName);
    query.bindValue(":url", noteData.url);
    query.bindValue(":password", noteData.passwordEntry);
    query.bindValue(":otherNotes", noteData.otherNotes);
    query.bindValue(":groupid", noteData.group_id);
    QDateTime currentDateTime = QDateTime::currentDateTimeUtc();
    currentDateTime = currentDateTime.addSecs(3 * 3600);
    QString formattedDateTime = currentDateTime.toString("yyyy-MM-dd HH:mm:ss");
    query.bindValue(":updatedAt", formattedDateTime);

    if (!query.exec())
    {
        qDebug() << "Error executing query:" << query.lastError().text();
    }
    else
    {
        qDebug() << "Record created successfully.";
    }

    closeDatabase();
}
