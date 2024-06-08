#pragma once

#ifndef NOTESLISTWIDGET_H
#define NOTESLISTWIDGET_H

#include <QWidget>

namespace Ui
{
    class NotesListWidget;
}

class Note;
class QListWidgetItem;

class NotesListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NotesListWidget(QWidget *parent = nullptr);
    ~NotesListWidget();

    void addNote(const Note &note);
    void removeCurrentNote();
    void updateCurrentNote(const Note &note);

    int currentNoteId();
    void setSearchText(const QString &text);
    void setCurrentNote(int id);

signals:
    void selectedNoteChanged(int id);
    void removeNote(int id);
    void renameNote(int id, const QString &newTitle);

private:
    void onItemSelectionChanged();

    void moveCurrentItemToTop(const Note &note);
    void setupNoteItem(const Note &note, QListWidgetItem *item);

    void filterNotes(const QString &searchText);

    bool contained(const QString& pattern, const QString& text);

private slots:
    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::NotesListWidget *ui;
};

#endif // NOTESLISTWIDGET_H
