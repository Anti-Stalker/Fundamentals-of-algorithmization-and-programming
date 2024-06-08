#include <QRandomGenerator>
#include <QContextMenuEvent>
#include <QMenu>

#include "graphwidget.h"
#include "ui_graphwidget.h"
#include "note.h"
#include "renamedialog.h"

static int randomBetween(int low, int high)
{
    return QRandomGenerator::global()->bounded(low, high + 1);
}

GraphWidget::GraphWidget(QWidget *parent) : QWidget(parent), ui(new Ui::GraphWidget)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    scene->setSceneRect(0, 0, 500, 500);

    connect(scene, &QGraphicsScene::changed, this, &GraphWidget::updateLines);
}

GraphWidget::~GraphWidget()
{
    delete ui;
}

void GraphWidget::addNote(const Note &note)
{
    MoveItem *item = new MoveItem(MoveItem::noteType);
    item->setPos(randomBetween(30, 470), randomBetween(30, 470));
    scene->addItem(item);
    item->setupMoveItemNote(note);
    if (note.tags != "")
    {
        for (const QString &tag : note.tags.split(' '))
        {
            if (!m_uniqueTags.contains(tag))
            {
                m_uniqueTags.append(tag);
            }
        }
    }

    drawTags();
    connect(item, &MoveItem::itemDoubleClicked, this, &GraphWidget::handleItemDoubleClicked);
}

void GraphWidget::drawTags()
{
    // 1. Удаляем теги, которых нет в списке
    QList<QGraphicsItem *> items = scene->items();
    for (QGraphicsItem *item : items)
    {
        MoveItem *tagItem = dynamic_cast<MoveItem *>(item);
        if (tagItem && tagItem->itemType == MoveItem::tagType && !m_uniqueTags.contains(tagItem->title))
        {
            scene->removeItem(tagItem);
            delete tagItem;
        }
    }

    // 2. Добавляем теги, которых нет на сцене
    for (const QString &tag : m_uniqueTags)
    {
        bool tagExists = false;
        for (QGraphicsItem *item : scene->items())
        {
            MoveItem *existingTagItem = dynamic_cast<MoveItem *>(item);
            if (existingTagItem && existingTagItem->itemType == MoveItem::tagType && existingTagItem->title == tag)
            {
                tagExists = true;
                break;
            }
        }

        if (!tagExists)
        {
            MoveItem *tagItem = new MoveItem(MoveItem::tagType);
            tagItem->setPos(randomBetween(30, 470), randomBetween(30, 470));
            scene->addItem(tagItem);
            tagItem->setupMoveItemTag(tag);
            connect(tagItem, &MoveItem::itemDoubleClicked, this, &GraphWidget::handleItemDoubleClicked);
        }
    }
}

void GraphWidget::updateLines()
{
    QList<QGraphicsItem *> lines = scene->items();
    for (QGraphicsItem *item : lines)
    {
        QGraphicsLineItem *line = dynamic_cast<QGraphicsLineItem *>(item);
        if (line)
        {
            scene->removeItem(line);
            delete line;
        }
    }
    QList<QGraphicsItem *> items = scene->items();
    for (QGraphicsItem *item : items)
    {
        MoveItem *noteItem = dynamic_cast<MoveItem *>(item);
        if (noteItem && noteItem->itemType == MoveItem::noteType)
        {
            connectItems(noteItem);
        }
    }
}

void GraphWidget::updateTags(const Note &note)
{
    QList<QGraphicsItem *> items = scene->items();
    for (QGraphicsItem *item : items)
    {
        MoveItem *noteItem = dynamic_cast<MoveItem *>(item);
        if (noteItem && noteItem->itemType == MoveItem::noteType && noteItem->id == note.id)
        {
            noteItem->tags = note.tags;
            break;
        }
    }
    if (note.tags != "")
    {
        for (const QString &tag : note.tags.split(' '))
        {
            if (!m_uniqueTags.contains(tag))
            {
                m_uniqueTags.append(tag);
            }
        }
    }

    QStringList temp;
    for (QGraphicsItem *item : items)
    {
        MoveItem *tagItem = dynamic_cast<MoveItem *>(item);
        if (tagItem && tagItem->itemType == MoveItem::noteType)
        {
            if (tagItem->tags != "")
            {
                for (const QString &tag : tagItem->tags.split(' '))
                {

                    if (!temp.contains(tag))
                    {
                        temp.append(tag);
                    }
                }
            }
        }
    }
    m_uniqueTags = temp;

    drawTags();
}

void GraphWidget::removeNote(int id)
{
    QList<QGraphicsItem *> items = scene->items();
    for (QGraphicsItem *item : items)
    {
        MoveItem *noteItem = dynamic_cast<MoveItem *>(item);
        if (noteItem && noteItem->id == id)
        {
            scene->removeItem(noteItem);
            delete noteItem;
            break;
        }
    }
}

void GraphWidget::renameNote(int id, const QString &newTitle)
{
    QList<QGraphicsItem *> items = scene->items();
    for (QGraphicsItem *item : items)
    {
        MoveItem *noteItem = dynamic_cast<MoveItem *>(item);
        if (noteItem && noteItem->id == id)
        {
            noteItem->titleText->setPlainText(newTitle);
            noteItem->title = newTitle;
            break;
        }
    }
}

void GraphWidget::drawLineBetweenItems(MoveItem *noteItem, MoveItem *tagItem)
{
    QGraphicsLineItem *line = new QGraphicsLineItem(noteItem->getPosition().x(), noteItem->getPosition().y(), tagItem->getPosition().x(), tagItem->getPosition().y());
    line->setPen(QPen(Qt::black));
    scene->addItem(line);
}

void GraphWidget::connectItems(MoveItem *noteItem)
{
    QStringList tagList = noteItem->tags.split(' ');

    for (const QString &tag : tagList)
    {
        QList<QGraphicsItem *> items = scene->items();
        for (QGraphicsItem *item : items)
        {
            MoveItem *tagItem = dynamic_cast<MoveItem *>(item);
            if (tagItem && tagItem->itemType == MoveItem::tagType && tagItem->title == tag)
            {
                drawLineBetweenItems(noteItem, tagItem);
                break;
            }
        }
    }
}

void GraphWidget::handleItemDoubleClicked(const int id, const QString &title)
{
    emit onMoveItemClicked(id, title);
}

void GraphWidget::contextMenuEvent(QContextMenuEvent *event)
{
    QGraphicsItem *item = scene->itemAt(ui->graphicsView->mapToScene(event->pos()), QTransform());
    MoveItem *moveItem = dynamic_cast<MoveItem *>(item);
    if (moveItem && moveItem->itemType == MoveItem::noteType)
    {
        selectedNoteId = moveItem->id;
        selectedNoteTitle = moveItem->title;
        showContextMenu(event->globalPos());
    }
}

void GraphWidget::showContextMenu(const QPoint &pos)
{
    QMenu contextMenu(this);

    QAction *renameAction = contextMenu.addAction("Rename Note");
    renameAction->setIcon(QIcon("../sourse/edit.png"));
    connect(renameAction, &QAction::triggered, this, &GraphWidget::onRenameActionTriggered);
    QAction *removeAction = contextMenu.addAction("Remove Note");
    removeAction->setIcon(QIcon("../sourse/trash.png"));
    connect(removeAction, &QAction::triggered, this, &GraphWidget::onRemoveActionTriggered);

    contextMenu.exec(pos);
}

void GraphWidget::onRemoveActionTriggered()
{
    emit removeNoteGraph(selectedNoteId);
}

void GraphWidget::onRenameActionTriggered()
{
    RenameDialog renameDialog(selectedNoteTitle, this);
    if (renameDialog.exec() == QDialog::Accepted)
    {
        emit renameNoteGraph(selectedNoteId, renameDialog.newNane());
    }
}