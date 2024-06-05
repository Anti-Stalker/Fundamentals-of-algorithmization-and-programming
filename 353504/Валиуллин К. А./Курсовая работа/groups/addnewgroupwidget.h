#ifndef ADDNEWGROUPWIDGET_H
#define ADDNEWGROUPWIDGET_H

#include <QDialog>
#include <QString>
#include <QMessageBox>

#include "structures/EnumWidgets.h"
#include "structures/GroupData.h"
#include "dbmanagement/databasegroupscreator.h"

namespace Ui {
class AddNewGroupWidget;
}

class AddNewGroupWidget : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewGroupWidget(DatabaseGroupsCreator *databaseGroupCreator, QWidget *parent = nullptr);
    ~AddNewGroupWidget();

signals:
    void transmitGroupId(int group_id);
    void transmitChangeToMainWindow(int index);

private slots:
    void on_buttonBox_accepted();
    void clearUi();
    void clearStruct();
    void clearAll();
    void on_buttonBox_rejected();

private:
    Ui::AddNewGroupWidget *ui;
    DatabaseGroupsCreator *databaseGroupCreator;
    GroupData gd;
};

#endif // ADDNEWGROUPWIDGET_H
