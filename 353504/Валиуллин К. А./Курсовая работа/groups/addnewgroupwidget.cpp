#include "addnewgroupwidget.h"
#include "ui_addnewgroupwidget.h"

AddNewGroupWidget::AddNewGroupWidget(DatabaseGroupsCreator *databaseGroupCreator, QWidget *parent)
    : QDialog(parent), ui(new Ui::AddNewGroupWidget), databaseGroupCreator(databaseGroupCreator)
{
    ui->setupUi(this);
}

AddNewGroupWidget::~AddNewGroupWidget()
{
    delete ui;
}

void AddNewGroupWidget::on_buttonBox_accepted()
{
    clearStruct();
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

    databaseGroupCreator->createNewGroup(gd);
    emit transmitGroupId(gd.id);
    clearAll();
    emit transmitChangeToMainWindow(IndexMainWindow);
}

void AddNewGroupWidget::clearStruct()
{
    gd.groupName.clear();
    gd.otherNotes.clear();
}

void AddNewGroupWidget::clearUi() {
    ui->groupName->clear();
    ui->otherNotesForGroup->clear();
}

void AddNewGroupWidget::clearAll() {
    clearStruct();
    clearUi();
}

void AddNewGroupWidget::on_buttonBox_rejected()
{
    clearAll();
    emit transmitChangeToMainWindow(IndexMainWindow);
}

