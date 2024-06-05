#ifndef EDITEXISTGROUPWIDGET_H
#define EDITEXISTGROUPWIDGET_H

#include <QDialog>
#include <QString>
#include <QMessageBox>

#include "structures/EnumWidgets.h"
#include "structures/GroupData.h"
#include "dbmanagement/databasegroupseditor.h"

namespace Ui {
class EditExistGroupWidget;
}

class EditExistGroupWidget : public QDialog
{
    Q_OBJECT

public:
    explicit EditExistGroupWidget(DatabaseGroupsEditor *databaseGroupEditor, QWidget *parent = nullptr);
    ~EditExistGroupWidget();
    void setGroupId(const int groupId);
    void toFillFields();

signals:
    void transmitGroupId(int group_id);
    void transmitChangeToMainWindow(int index);

private slots:
    void clearAllExceptId();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::EditExistGroupWidget *ui;
    DatabaseGroupsEditor *databaseGroupEditor;
    GroupData gd;
    int id;

};

#endif // EDITEXISTGROUPWIDGET_H
