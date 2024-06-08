#pragma once

#ifndef NOTEWIDGET_H
#define NOTEWIDGET_H

#include <QWidget>

class QLabel;
class QPoint;

class Note;

class NoteWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NoteWidget(const Note &note, QWidget *parent = nullptr);

    int noteId() const;
    void updateContent(const Note &note);

signals:
    void removeNote(int id);
    void renameNote(int id, const QString &newTitle);

protected:
    void resizeEvent(QResizeEvent *event) override;
    void contextMenuEvent(QContextMenuEvent *event) override;

private:
    void setupGui();
    void updateLabels();

    void setElidedText(QLabel *label, const QString &text);

    void showContextMenu(const QPoint &pos);
    void onRemoveActionTriggered();
    void onRenameActionTriggered();

private:
    QLabel *titleLable;
    QLabel *lastModifiedLable;
    QLabel *contentLable;

    int id;
    QString title;
    QString lastModified;
    QString content = "";
    QString tags = "";

    const QString dateTimeFormat = "dd.MM.yyyy - hh:mm:ss";

public:
    QString getTitle();
    QString getTags();
};

#endif // NOTEWIDGET_H
