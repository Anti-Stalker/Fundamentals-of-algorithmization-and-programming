#ifndef EDITEXISTNOTEWIDGET_H
#define EDITEXISTNOTEWIDGET_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include <QTableWidgetItem>

#include "structures/EnumWidgets.h"
#include "structures/NodeData.h"
#include "dbmanagement/databasenoteseditor.h"

namespace Ui {
class EditExistNoteWidget;
}

class EditExistNoteWidget : public QDialog
{
    Q_OBJECT

public:
    explicit EditExistNoteWidget(DatabaseNotesEditor *DatabaseNotesEditor, QWidget *parent = nullptr);
    ~EditExistNoteWidget();
    void setNoteId(const int noteId);
    void populateGroupComboBox();
    void toFillFields();

signals:
    void transmitGroupId(int group_id);
    void transmitChangeToMainWindow(int index);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void clearAllExceptId();
    void setRowByRealGroupId();
    void getND_Group_ID();

private:
    Ui::EditExistNoteWidget *ui;
    QString noteName;
    QString groupName;
    QString userName;
    QString url;
    QString passwordEntry;
    QString otherNotes;
    QString realNameOfGroup;
    DatabaseNotesEditor *databaseNotesEditor;
    NoteData nd;
    QTableWidgetItem *selectedNote;
    int id;
};

#endif // EDITEXISTNOTEWIDGET_H
