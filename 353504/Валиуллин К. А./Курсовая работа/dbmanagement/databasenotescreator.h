#ifndef DATABASENOTESCREATOR_H
#define DATABASENOTESCREATOR_H

#include "dbmanagement/databasecontroller.h"

class DatabaseNotesCreator : public DatabaseController
{
public:
    explicit DatabaseNotesCreator(QObject *parent = nullptr);
    void createNewNote(const NoteData &noteData);
};

#endif // DATABASENOTESCREATOR_H
