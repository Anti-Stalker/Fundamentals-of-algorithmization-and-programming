#include "editexistgroupwidget.h"
#include "ui_editexistgroupwidget.h"

EditExistGroupWidget::EditExistGroupWidget(DatabaseGroupsEditor *databaseGroupEditor, QWidget *parent)
    : QDialog(parent), ui(new Ui::EditExistGroupWidget), databaseGroupEditor(databaseGroupEditor)
{
    ui->setupUi(this);
}

EditExistGroupWidget::~EditExistGroupWidget()
{
    delete ui;
}

void EditExistGroupWidget::setGroupId(const int groupId)
{
    this->id = groupId;
}

void EditExistGroupWidget::on_buttonBox_accepted()
{
    clearAllExceptId();
    if (ui->groupName->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Ввод названия группы обязателен");
        return;
    }
    else {
        gd.groupName = ui->groupName->text();
    }

    if (!ui->otherNotesForGroup->toPlainText().isEmpty()) {
        gd.otherNotes = ui->otherNotesForGroup->toPlainText();
    } else {
        gd.otherNotes = "";
    }

    databaseGroupEditor->updateGroup(gd);
    emit transmitGroupId(id);
    clearAllExceptId();
    emit transmitChangeToMainWindow(IndexMainWindow);
}


void EditExistGroupWidget::on_buttonBox_rejected()
{
    clearAllExceptId();
    emit transmitChangeToMainWindow(IndexMainWindow);
}

void EditExistGroupWidget::clearAllExceptId()
{
    gd.groupName.clear();
    gd.otherNotes.clear();
}

void EditExistGroupWidget::toFillFields()
{
    databaseGroupEditor->selectGroupData(gd, id);
    ui->groupName->setText(gd.groupName);
    ui->otherNotesForGroup->setText(gd.otherNotes);
}
