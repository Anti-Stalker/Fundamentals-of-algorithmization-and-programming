#include "database/unlockdatabasewidget.h"
#include "ui_unlockdatabasewidget.h"

UnlockDatabaseWidget::UnlockDatabaseWidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UnlockDatabaseWidget)
{
    ui->setupUi(this);
}

UnlockDatabaseWidget::~UnlockDatabaseWidget()
{
    delete ui;
}

void UnlockDatabaseWidget::clear_all()
{
    passwordEntry.clear();
    ui->passwordEntryField->clear();
}

void UnlockDatabaseWidget::closeEvent(QCloseEvent *event)
{
    clear_all();
    QWidget::closeEvent(event);
}

void UnlockDatabaseWidget::on_unlockBaseButton_clicked()
{
    passwordEntry = ui->passwordEntryField->text();
    passwordEntry = databaseDecryptor.padPassword(passwordEntry);
    databaseDecryptor.setTryPassword(passwordEntry);
    databaseDecryptor.setFilePath(filePath);
    isPasswordCorrect = HashingManager::comparePasswordHash(filePath, passwordEntry);
    if (!passwordEntry.isEmpty()) {
        if (isPasswordCorrect) {
            databaseDecryptor.decryptDatabase();
            databaseDecryptor.setPassword(passwordEntry);
            emit transmitDataBasePath(filePath);
            emit transmitChangeToMainWindow(IndexMainWindow);
            clear_all();
            close();
        } else {
            QMessageBox::warning(this, "Ошибка", "Неверный пароль!");
        }
    }
}

void UnlockDatabaseWidget::receiveFilePath(const QString &fp)
{
    filePath = fp;
    ui->baseName->setText(filePath);
}

