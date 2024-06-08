#pragma once

#ifndef XLMSTORAGE_H
#define XLMSTORAGE_H

#include <QString>
#include <vector>

class Note;

class QXmlStreamWriter;
class QXmlStreamReader;

class XlmStorage
{
public:
    XlmStorage();

    std::vector<Note> read();
    bool write(const std::vector<std::reference_wrapper<Note>> &notes);

private:
    void writeNote(QXmlStreamWriter &stream, const Note &note);
    void readNote(QXmlStreamReader &stream, std::vector<Note> &notes);

private:
    QString fullFilePath;

    const QString fileName = "mynotes.xml";
    const QString dateTimeFormat = "dd/MM/yyyy - hh:mm:ss";
    const QString xmlRootToken = "NotesList";
    const QString noteToken = "Note";
    const QString titleToken = "title";
    const QString lastModifiedToken = "modified";
    const QString contentToken = "content";
    const QString tagsToken = "tags";
};

#endif // XLMSTORAGE_H
