#pragma once

#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QWidget>
#include <QGraphicsScene>

#include "moveitem.h"

namespace Ui
{
    class GraphWidget;
}

class Note;

class GraphWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GraphWidget(QWidget *parent = nullptr);
    ~GraphWidget();
    void addNote(const Note &note);
    void drawTags();
    void updateLines();
    void updateTags(const Note &note);
    void removeNote(int id);
    void renameNote(int id, const QString &newTitle);

private:
    void drawLineBetweenItems(MoveItem *noteItem, MoveItem *tagItem);
    void connectItems(MoveItem *noteItem);
    QStringList m_uniqueTags;

private slots:
    void handleItemDoubleClicked(const int id, const QString &title);

signals:
    void onMoveItemClicked(const int id, const QString &name);
    void selectedNoteChanged(int id);
    void removeNoteGraph(int id);
    void renameNoteGraph(int id, const QString &newTitle);

private:
    void contextMenuEvent(QContextMenuEvent *event);
    void showContextMenu(const QPoint &pos);
    void onRemoveActionTriggered();
    void onRenameActionTriggered();
    int selectedNoteId = -1;
    QString selectedNoteTitle = "";

private:
    Ui::GraphWidget *ui;
    QGraphicsScene *scene;
};

#endif // GRAPHWIDGET_H