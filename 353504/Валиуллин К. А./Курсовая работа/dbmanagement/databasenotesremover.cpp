#include "databasenotesremover.h"

DatabaseNotesRemover::DatabaseNotesRemover(QObject *parent)
    : DatabaseController{parent}
{}

void DatabaseNotesRemover::deleteNote(const int noteId)
{
    openDatabase();
    QSqlQuery query;
    query.prepare("DELETE FROM notes WHERE id = :id");
    query.bindValue(":id", noteId);
    if (query.exec()) {
    } else {
        closeDatabase();
        throw std::runtime_error("Ошибка при удалении записи");
    }
    closeDatabase();
}
