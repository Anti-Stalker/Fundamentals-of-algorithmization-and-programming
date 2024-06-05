#ifndef NODEDATA_H
#define NODEDATA_H

#include <QString>

struct NoteData {
    QString noteName;
    QString userName;
    QString url;
    QString passwordEntry;
    QString otherNotes;
    int group_id;
    int id;
};

#endif // NODEDATA_H
