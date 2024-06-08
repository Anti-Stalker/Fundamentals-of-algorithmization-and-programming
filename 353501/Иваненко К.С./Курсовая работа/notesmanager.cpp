#include "notesmanager.h"
#include "note.h"
#include "xlmstorage.h"

#include <QTextDocument>
#include <QSignalMapper>

NotesManager::NotesManager(QObject *parent) : QObject(parent)
{
    mapChangedSignalToNoteId = new QSignalMapper(this);
    connect(mapChangedSignalToNoteId, &QSignalMapper::mappedInt, this, &NotesManager::onNoteContentChanged);

    readNotes();

    if (notes.size() == 0)
        createNewNote();
}

NotesManager::~NotesManager()
{
    writeNotes();
}

int nextNoteId();

void NotesManager::createNewNote()
{
    int id = nextNoteId();
    auto &[note, textDocument] = notes[id];
    note.id = id;
    note.title = "New note";
    note.lastModified = QDateTime::currentDateTime();
    textDocument = createNewTextDocument(note);

    emit newNoteCreated(id);
}

void NotesManager::removeNote(int id)
{
    notes.erase(id);

    if (notes.empty())
        createNewNote();
}

void NotesManager::renameNote(int id, const QString &newTitle)
{
    auto found = notes.find(id);
    if (found != notes.end())
    {
        auto &[note, textDocument] = found->second;
        note.title = newTitle;
        note.lastModified = QDateTime::currentDateTime();
    }
}

const Note &NotesManager::note(int id) const
{
    return notes.at(id).first;
}

QTextDocument *NotesManager::noteDocument(int id) const
{
    auto found = notes.find(id);
    if (found != notes.end())
    {
        return found->second.second.get();
    }
    return nullptr;
}

std::vector<std::reference_wrapper<Note>> NotesManager::noteCollection()
{
    std::vector<std::reference_wrapper<Note>> out;
    for (auto &i : notes)
    {
        auto &[note, textDocument] = i.second;
        note.content = textDocument->toPlainText();
        out.push_back(note);
    }
    return out;
}

size_t NotesManager::count() const
{
    return notes.size();
}

void NotesManager::onNoteContentChanged(int id)
{
    notes.at(id).first.lastModified = QDateTime::currentDateTime();

    emit noteContentChanged(id);
}

void NotesManager::readNotes()
{
    XlmStorage storage;

    auto savedNotes = storage.read();

    for (auto n : savedNotes)
    {
        n.id = nextNoteId();
        auto &[note, textDocumnet] = notes[n.id];
        note = n;
        textDocumnet = createNewTextDocument(note);
    }
}

void NotesManager::writeNotes()
{
    XlmStorage storage;
    storage.write(noteCollection());
}

void NotesManager::getTagsFromContent(int id)
{
    QString content = notes.at(id).first.content + " ";
    QString tags;
    QString word;
    bool withinWord = false;
    QStringList uniqueTags;

    for (int i = 0; i < content.length(); ++i)
    {
        QChar currentChar = content[i];

        if (currentChar.isSpace() || currentChar == '.' || currentChar == ',' || currentChar == '?' || currentChar == '!')
        {
            if (withinWord && word.startsWith('#') && word.length() > 1)
            {
                if (!uniqueTags.contains(word))
                    uniqueTags.append(word);
            }

            withinWord = false;
            word.clear();
        }
        else
        {
            if (!withinWord)
                withinWord = true;
            word += currentChar;
        }
    }

    if (withinWord && word.startsWith('#') && word.length() > 1)
    {
        if (!uniqueTags.contains(word))
            uniqueTags.append(word);
    }

    tags = uniqueTags.join(' ');
    notes.at(id).first.tags = tags;
}

std::unique_ptr<QTextDocument> NotesManager::createNewTextDocument(const Note &note)
{
    auto textDocument = std::make_unique<QTextDocument>(note.content);
    connect(textDocument.get(), &QTextDocument::contentsChange, mapChangedSignalToNoteId, qOverload<>(&QSignalMapper::map));
    mapChangedSignalToNoteId->setMapping(textDocument.get(), note.id);
    return textDocument;
}

int nextNoteId()
{
    static int id = 0;
    return ++id;
}