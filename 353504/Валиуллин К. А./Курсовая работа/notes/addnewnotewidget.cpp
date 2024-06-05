#include "notes/addnewnotewidget.h"
#include "ui_addnewnotewidget.h"

AddNewNoteWidget::AddNewNoteWidget(DatabaseNotesCreator *databaseNotesCreator, QWidget *parent)
    : QDialog(parent), ui(new Ui::AddNewNoteWidget), databaseNotesCreator(databaseNotesCreator)
{
    ui->setupUi(this);
}

AddNewNoteWidget::~AddNewNoteWidget()
{
    delete ui;
}

void AddNewNoteWidget::getND_Group_ID()
{
    QString comboText = ui->chooseGroup->currentText();
    nd.group_id = databaseNotesCreator->findGroupIDdByGroupName(comboText);
}

void AddNewNoteWidget::on_buttonBox_accepted()
{
    clearStruct();

    if (ui->passwordEntry->text().isEmpty() && ui->noteName->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Ввод названия записи и пароля обязателен!");
        return;
    }

    if (!ui->noteName->text().isEmpty()) {
        nd.noteName = ui->noteName->text();
    }
    else {
        QMessageBox::warning(this, "Ошибка", "Ввод названия записи обязателен!");
        return;
    }
    if (!ui->passwordEntry->text().isEmpty()) {
        nd.passwordEntry = ui->passwordEntry->text();
    }
    else {
        QMessageBox::warning(this, "Ошибка", "Ввод пароля обязателен!");
        return;
    }
    if (!ui->userName->text().isEmpty()) {
        nd.userName = ui->userName->text();
    } else {
        nd.userName = "";
    }

    if (!ui->url->text().isEmpty()) {
        nd.url = ui->url->text();
    } else {
        nd.url = "";
    }

    if (!ui->otherNotes->toPlainText().isEmpty()) {
        nd.otherNotes = ui->otherNotes->toPlainText();
    } else {
        nd.otherNotes = "";
    }

    getND_Group_ID();

    if (nd.group_id == -999) {
        QMessageBox::warning(this, "Ошибка", "Выберите группу!");
        return;
    }

    databaseNotesCreator->createNewNote(nd);

    emit transmitGroupId(nd.group_id);
    clearAll();
    emit transmitChangeToMainWindow(IndexMainWindow);
}

void AddNewNoteWidget::on_buttonBox_rejected()
{
    clearAll();
    emit transmitChangeToMainWindow(IndexMainWindow);
}

void AddNewNoteWidget::populateGroupComboBox()
{
    ui->chooseGroup->clear();
    QMap<int, QString> groupNames = databaseNotesCreator->getGroupNames();
    for (auto it = groupNames.begin(); it != groupNames.end(); ++it) {
        int groupId = it.key();
        QString groupName = it.value();
        ui->chooseGroup->insertItem(groupId, groupName);
    }
}

void AddNewNoteWidget::clearUiText()
{
    ui->noteName->clear();
    ui->passwordEntry->clear();
    ui->url->clear();
    ui->userName->clear();
    ui->otherNotes->clear();
}

void AddNewNoteWidget::clearStruct()
{
    nd.noteName.clear();
    nd.userName.clear();
    nd.url.clear();
    nd.passwordEntry.clear();
    nd.otherNotes.clear();
    nd.group_id = 1;
}

void AddNewNoteWidget::clearAll()
{
    clearStruct();
    clearUiText();
}


void AddNewNoteWidget::on_chooseGroup_currentIndexChanged(int index)
{
    nd.group_id = index;
}
