#include "database/createdatabasewidget.h"
#include "ui_createdatabasewidget.h"

CreateDatabaseWidget::CreateDatabaseWidget(DatabaseCreator *databaseCreator, QWidget* parent)
    : QDialog(parent), ui(new Ui::CreateDatabaseWidget), databaseCreator(databaseCreator)
{
    ui->setupUi(this);
}

CreateDatabaseWidget::~CreateDatabaseWidget()
{
    delete ui;
}

void CreateDatabaseWidget::clear_all()
{
    baseName.clear();
    basePassword.clear();
    ui->baseName->clear();
    ui->basePassword->clear();
}

void CreateDatabaseWidget::on_buttonBox_accepted()
{
    baseName = ui->baseName->text();
    basePassword = ui->basePassword->text();
    if (!baseName.isEmpty() && !basePassword.isEmpty()) {
        basePassword = databaseCreator->padPassword(basePassword);
        databaseCreator->setPassword(basePassword);
        QString filePath = QFileDialog::getSaveFileName(this, "Сохранить базу данных",
                                                        QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) +
                                                            QDir::separator() + baseName, "База данных (*.db)");
        if (!filePath.isEmpty()) {
            if (QFile::exists(filePath)) {
                QFile::remove(filePath);
            }
            databaseCreator->setFilePath(filePath);
            databaseCreator->createDatabase();
        } else {
            return;
        }
        HashingManager::savePasswordHash(baseName, basePassword);
        clear_all();
        close();
    }
    else {
        QMessageBox::warning(this, "Ошибка", "Введите название и пароль базы данных");
    }
}

void CreateDatabaseWidget::on_buttonBox_rejected()
{
    clear_all();
}
