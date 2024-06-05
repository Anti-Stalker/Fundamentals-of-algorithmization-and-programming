#ifndef EDITDATABASEWIDGET_H
#define EDITDATABASEWIDGET_H

#include <QDialog>

#include "database/hashingmanager.h"
#include "dbmanagement/databaseeditor.h"
#include "other/checkifdatabaseexistwarning.h"

namespace Ui {
class EditDatabaseWidget;
}

class EditDatabaseWidget : public QDialog
{
    Q_OBJECT

public:
    explicit EditDatabaseWidget(QWidget *parent = nullptr);
    ~EditDatabaseWidget();

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
    void clear_all();
    void setDeleteAndRename();

private:
    Ui::EditDatabaseWidget *ui;
    QString newBaseName, newBasePassword;
    DatabaseEditor *databaseEditor;
    CheckIfDatabaseExistWarning *checkIfDatabaseExistWarning;
    bool deleteAndRename = false;
};

#endif // EDITDATABASEWIDGET_H
