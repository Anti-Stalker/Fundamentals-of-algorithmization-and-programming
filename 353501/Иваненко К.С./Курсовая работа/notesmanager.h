#pragma once

#ifndef NOTESMANAGER_H
#define NOTESMANAGER_H

#include <QObject>
#include <unordered_map>
#include <utility>
#include <memory>

class Note;

class QTextDocument;
class QSignalMapper;

class NotesManager : public QObject
{
    Q_OBJECT
public:
    explicit NotesManager(QObject *parent = nullptr);
    ~NotesManager();

    void createNewNote();
    void removeNote(int id);
    void renameNote(int id, const QString &newTitle);

    const Note &note(int id) const;
    QTextDocument *noteDocument(int id) const;
    std::vector<std::reference_wrapper<Note>> noteCollection();
    size_t count() const;

signals:
    void newNoteCreated(int id);
    void noteContentChanged(int id);

private:
    void onNoteContentChanged(int id);
    std::unique_ptr<QTextDocument> createNewTextDocument(const Note &note);

public:
    void readNotes();
    void writeNotes();
    void getTagsFromContent(int id);

private:
    std::unordered_map<int, std::pair<Note, std::unique_ptr<QTextDocument>>> notes;

    QSignalMapper *mapChangedSignalToNoteId = nullptr;
};

#endif // NOTESMANAGER_H