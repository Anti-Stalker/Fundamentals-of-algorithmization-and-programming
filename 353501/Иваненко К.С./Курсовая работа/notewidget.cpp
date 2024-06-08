#include "notewidget.h"
#include "note.h"
#include "renamedialog.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QContextMenuEvent>
#include <QMenu>

NoteWidget::NoteWidget(const Note &note, QWidget *parent) : QWidget(parent)
{
    setupGui();

    id = note.id;
    title = note.title;
    lastModified = note.lastModified.toString(dateTimeFormat);
    content = note.content.left(10).replace("\n", " ") + "...";
    tags = note.tags;

    updateLabels();
    setToolTip(QString("%0\n%1\n%2").arg(title).arg(lastModified).arg(content));
}

int NoteWidget::noteId() const
{
    return id;
}

void NoteWidget::updateContent(const Note &note)
{
    title = note.title;
    lastModified = note.lastModified.toString(dateTimeFormat);
    content = note.content.left(10).replace("\n", " ") + "...";
    tags = note.tags;

    updateLabels();
    setToolTip(QString("%0\n%1\n%2").arg(title).arg(lastModified).arg(content));
}

void NoteWidget::resizeEvent(QResizeEvent *event)
{
    updateLabels();
    QWidget::resizeEvent(event);
}

void NoteWidget::contextMenuEvent(QContextMenuEvent *event)
{
    showContextMenu(event->globalPos());
}

void NoteWidget::setupGui()
{
    titleLable = new QLabel();
    lastModifiedLable = new QLabel();
    contentLable = new QLabel();

    auto layout = new QVBoxLayout(this);
    layout->addWidget(titleLable);
    layout->addWidget(lastModifiedLable);
    layout->addWidget(contentLable);
}

void NoteWidget::updateLabels()
{
    setElidedText(titleLable, title);
    setElidedText(lastModifiedLable, lastModified);
    setElidedText(contentLable, content);
}

void NoteWidget::setElidedText(QLabel *label, const QString &text)
{
    auto parentObj = parent();
    if (parentObj != nullptr)
    {
        auto parentWidget = qobject_cast<QWidget*>(parentObj);
        if (parentWidget != nullptr)
        {
            QFontMetrics fm(label->font());
            QString elitedText = fm.elidedText(text, Qt::ElideRight, parentWidget->width() - 20);
            label->setText(elitedText);
        }
    }
}

void NoteWidget::showContextMenu(const QPoint &pos)
{
    QMenu contextMenu(this);

    QAction *renameAction = contextMenu.addAction("Rename Note");
    renameAction->setIcon(QIcon("../sourse/edit.png"));
    connect(renameAction, &QAction::triggered, this, &NoteWidget::onRenameActionTriggered);
    QAction *removeAction = contextMenu.addAction("Remove Note");
    removeAction->setIcon(QIcon("../sourse/trash.png"));
    connect(removeAction, &QAction::triggered, this, &NoteWidget::onRemoveActionTriggered);

    contextMenu.exec(pos);
}

void NoteWidget::onRemoveActionTriggered()
{
    emit removeNote(id);
}

void NoteWidget::onRenameActionTriggered()
{
    RenameDialog renameDialog(title, this);
    if (renameDialog.exec() == QDialog::Accepted)
    {
        emit renameNote(id, renameDialog.newNane());
    } 
}

QString NoteWidget::getTitle()
{
    return title;
}

QString NoteWidget::getTags()
{
    return tags;
}
