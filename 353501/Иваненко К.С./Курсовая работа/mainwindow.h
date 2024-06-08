#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class NotesManager;
class Note;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(NotesManager &manager, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Handle signal from ui
    void on_newNoteButton_clicked();
    void on_removeNoteButton_clicked();

    // Handle NotesManager signals
    void onNewNoteCreated(int id);
    void onNoteContentChanged(int id);

    // Handle listWidget signals
    void onSelectedNoteChanged(int id);
    void onRemoveNote(int id);
    void onRenameNote(int id, const QString &newTitle);

    // Handle graphWidget signals
    void onMoveItemClicked(const int id, const QString &title);

private:
    void addNoteToList(const Note &note);
    void removeNote(int id);

    void init();

    bool isWriting = true;

    Ui::MainWindow *ui;
    NotesManager &notesManager;
};
#endif // MAINWINDOW_H
