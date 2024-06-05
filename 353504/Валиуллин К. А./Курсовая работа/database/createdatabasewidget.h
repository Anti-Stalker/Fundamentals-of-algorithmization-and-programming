#ifndef CREATEDATABASEWIDGET_H
#define CREATEDATABASEWIDGET_H

#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardPaths>

#include "structures/EnumWidgets.h"
#include "dbmanagement/databasecreator.h"
#include "database/hashingmanager.h"

namespace Ui {
class CreateDatabaseWidget;
}

class CreateDatabaseWidget : public QDialog
{
    Q_OBJECT

public:
     CreateDatabaseWidget(DatabaseCreator* databaseCreator, QWidget* parent = nullptr);
    ~CreateDatabaseWidget();

private slots:
    void on_buttonBox_accepted();
    void clear_all();
    void on_buttonBox_rejected();

private:
    Ui::CreateDatabaseWidget *ui;
    QString baseName, basePassword, queryRequest;
    DatabaseCreator *databaseCreator;

};

#endif //CREATEDATABASEWIDGET_H
