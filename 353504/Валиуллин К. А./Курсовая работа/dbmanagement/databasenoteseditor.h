#ifndef DATABASENOTESEDITOR_H
#define DATABASENOTESEDITOR_H

#include "dbmanagement/databasecontroller.h"

class DatabaseNotesEditor : public DatabaseController
{
public:
    explicit DatabaseNotesEditor(QObject *parent = nullptr);
    void selectNoteData(NoteData &noteData, const int id);
    void updateNote(NoteData &noteData);
};

#endif // DATABASENOTESEDITOR_H
