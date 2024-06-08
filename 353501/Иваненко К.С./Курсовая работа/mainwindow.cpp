#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "notesmanager.h"
#include "note.h"
#include "noteslistwidget.h"

#include <QMessageBox>
#include <algorithm>

MainWindow::MainWindow(NotesManager &manager, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), notesManager(manager)
{
    ui->setupUi(this);

    init();

    connect(&notesManager, &NotesManager::newNoteCreated, this, &MainWindow::onNewNoteCreated);
    connect(&notesManager, &NotesManager::noteContentChanged, this, &MainWindow::onNoteContentChanged);

    connect(ui->notesListWidget, &NotesListWidget::selectedNoteChanged, this, &MainWindow::onSelectedNoteChanged);
    connect(ui->notesListWidget, &NotesListWidget::removeNote, this, &MainWindow::onRemoveNote);
    connect(ui->notesListWidget, &NotesListWidget::renameNote, this, &MainWindow::onRenameNote);

    connect(ui->graphWidget, &GraphWidget::onMoveItemClicked, this, &MainWindow::onMoveItemClicked);
    connect(ui->graphWidget, &GraphWidget::removeNoteGraph, this, &MainWindow::onRemoveNote);
    connect(ui->graphWidget, &GraphWidget::renameNoteGraph, this, &MainWindow::onRenameNote);
    for (int i = 0; i < notesManager.count() + 1; i++)
    {
        ui->notesListWidget->setCurrentNote(i);
    }
    ui->notesListWidget->setCurrentNote(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newNoteButton_clicked()
{
    notesManager.createNewNote();
}

void MainWindow::on_removeNoteButton_clicked()
{
    removeNote(ui->notesListWidget->currentNoteId());
}

void MainWindow::onNewNoteCreated(int id)
{
    addNoteToList(notesManager.note(id));
}

void MainWindow::onNoteContentChanged(int id)
{
    if (isWriting)
    {
        isWriting = false;
        notesManager.writeNotes();
        isWriting = true;
    }
    ui->notesListWidget->updateCurrentNote(notesManager.note(id));
    notesManager.getTagsFromContent(id);
    ui->graphWidget->updateTags(notesManager.note(id));
    ui->graphWidget->updateLines();
}

void MainWindow::onSelectedNoteChanged(int id)
{
    auto *document = notesManager.noteDocument(id);
    if (document != nullptr)
    {
        ui->textEdit->setDocument(document);
        auto cursor = ui->textEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->textEdit->setTextCursor(cursor);
    }
}

void MainWindow::onRemoveNote(int id)
{
    ui->notesListWidget->setCurrentNote(id);
    removeNote(id);
}

void MainWindow::onRenameNote(int id, const QString &newTitle)
{
    ui->notesListWidget->setCurrentNote(id);
    notesManager.renameNote(id, newTitle);
    ui->graphWidget->renameNote(id, newTitle);
    ui->notesListWidget->updateCurrentNote(notesManager.note(id));
}

void MainWindow::onMoveItemClicked(const int id, const QString &title)
{
    if (id != -1)
    {
        ui->notesListWidget->setCurrentNote(id);
        ui->notesListWidget->setSearchText("");
    }
    else
    {
        ui->notesListWidget->setSearchText(title);
    }
    ui->tabWidget->setCurrentIndex(0);
    ui->graphWidget->updateLines();
}

void MainWindow::addNoteToList(const Note &note)
{
    ui->notesListWidget->addNote(note);
    ui->graphWidget->addNote(note);
}

void MainWindow::removeNote(int id)
{
    QString noteTitle = notesManager.note(id).title;

    auto pressedButton = QMessageBox::information(this, "Remove note?",
                                                  QString("Are you sure you want to remove %0?").arg(noteTitle),
                                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (pressedButton == QMessageBox::Yes)
    {
        if (notesManager.count() == 1)
        {
            ui->textEdit->setDocument(nullptr);
        }

        ui->notesListWidget->removeCurrentNote();
        ui->graphWidget->removeNote(id);
        notesManager.removeNote(id);
    }
}

void MainWindow::init()
{
    auto notesList = notesManager.noteCollection();
    std::sort(notesList.begin(), notesList.end(), [](const Note &left, const Note &right)
              { return left.lastModified < right.lastModified; });
    for (auto &note : notesList)
    {
        addNoteToList(note);
    }
}
