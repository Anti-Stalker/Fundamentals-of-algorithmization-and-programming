#ifndef ADDNEWNOTEWIDGET_H
#define ADDNEWNOTEWIDGET_H

#include <QDialog>
#include <QString>
#include <QMessageBox>

#include "structures/EnumWidgets.h"
#include "structures/NodeData.h"
#include "dbmanagement/databasenotescreator.h"

namespace Ui {
class AddNewNoteWidget;
}

class AddNewNoteWidget : public QDialog
{
    Q_OBJECT

public:
    AddNewNoteWidget(DatabaseNotesCreator *databaseNotesCreator, QWidget *parent = nullptr);
    ~AddNewNoteWidget();

public slots:
    void populateGroupComboBox();

signals:
    void transmitGroupId(int group_id);
    void transmitChangeToMainWindow(int index);

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
    void on_chooseGroup_currentIndexChanged(int index);
    void clearUiText();
    void clearStruct();
    void clearAll();

void getND_Group_ID();

private:
    Ui::AddNewNoteWidget *ui;
    QString noteName;
    QString userName;
    QString url;
    QString passwordEntry;
    QString otherNotes;
    DatabaseNotesCreator *databaseNotesCreator;
    NoteData nd;

};

#endif // ADDNEWNOTEWIDGET_H
