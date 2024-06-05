#include "editdatabasewidget.h"
#include "ui_editdatabasewidget.h"

EditDatabaseWidget::EditDatabaseWidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditDatabaseWidget)
{
    ui->setupUi(this);
    checkIfDatabaseExistWarning = new CheckIfDatabaseExistWarning(this);
    connect(checkIfDatabaseExistWarning, &CheckIfDatabaseExistWarning::transmitCheckIfDbExistConfirmation,
            this, &EditDatabaseWidget::setDeleteAndRename);
}

EditDatabaseWidget::~EditDatabaseWidget()
{
    delete ui;
}

void EditDatabaseWidget::clear_all()
{
    newBaseName.clear();
    newBasePassword.clear();
    ui->baseName->clear();
    ui->basePassword->clear();
}

void EditDatabaseWidget::setDeleteAndRename()
{
    deleteAndRename = true;
}

void EditDatabaseWidget::on_buttonBox_rejected()
{
    clear_all();
}

void EditDatabaseWidget::on_buttonBox_accepted()
{
    QString oldBaseName = databaseEditor->getFilePath();
    newBaseName = ui->baseName->text();
    newBasePassword = ui->basePassword->text();
    newBasePassword = databaseEditor->padPassword(newBasePassword);
    if (!newBaseName.isEmpty() && !newBasePassword.isEmpty()) {
        databaseEditor->updateDatabasePassword(newBasePassword);
        databaseEditor->updateDatabaseName(checkIfDatabaseExistWarning, newBaseName, deleteAndRename);
        HashingManager::removeOldHashRecord(oldBaseName, newBaseName);
        HashingManager::savePasswordHash(newBaseName, newBasePassword);
    }
    else {
        QMessageBox::warning(this, "Ошибка", "Введите новое название и пароль базы данных");
    }
    clear_all();
    close();
}
