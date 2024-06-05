#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QAbstractButton>
#include <QCloseEvent>
#include <QToolBar>

#include "database/welcomewidget.h"
#include "database/createdatabasewidget.h"
#include "database/unlockdatabasewidget.h"
#include "database/editdatabasewidget.h"
#include "database/hashingmanager.h"
#include "database/recentdatabasemanager.h"
#include "notes/addnewnotewidget.h"
#include "notes/editexistnotewidget.h"
#include "groups/addnewgroupwidget.h"
#include "groups/editexistgroupwidget.h"

#include "dbmanagement/databasecontroller.h"
#include "dbmanagement/databasecreator.h"
#include "dbmanagement/databasenotescreator.h"
#include "dbmanagement/databasenoteseditor.h"
#include "dbmanagement/databasegroupscreator.h"
#include "dbmanagement/databasegroupseditor.h"
#include "dbmanagement/databasedisplay.h"
#include "dbmanagement/databasenotesremover.h"
#include "dbmanagement/databasegroupsremover.h"
#include "dbmanagement/databaseencryptor.h"
#include "dbmanagement/databasedecryptor.h"
#include "dbmanagement/databaseshortcutsselecter.h"

#include "other/deletegroupwarning.h"
#include "other/aboutprogramwidget.h"

#include "structures/EnumWidgets.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void changeStackedWidgetIndex(int index);
    void activatePopUpWidget(int index);
    void actionCreateDatabase();
    void actionChooseUnlockingBase();
    void actionChangeDatabase();
    void actionQuit();
    void actionCreateNewNote();
    void actionChangeNote();
    void actionDeleteNote();
    void actionCreateGroup();
    void actionChangeGroup();
    void actionDeleteGroup();
    void actionCopyUsername();
    void actionCopyPassword();
    void actionAboutProgram();

    void receiveFilePath(const QString &fp);
    void receivePossibleFilePath(const QString &fp);
    void unlockBase();

    void setNewGroupItem();
    void setGroupId(int newGroupId);

private slots:
    void createBase();
    void saveNewFilePath();
    void showDatabasesGroups();
    void adjustTableWidget();
    void setDatabaseNameText();
    void ifMainWindowActivated();
    void firstStartOfMainWindow();
    void MWC_ConnectOfQActions();
    void MWC_InsertStackedWidgets();
    void MWC_CreationOfUiForms();
    void MWC_ConnectOfPushButtons();
    void MWC_ConnectsOther();
    void MWC_CreationOfToolBar();
    void MWC_Warnings();

    void on_groupListWidget_itemClicked(QListWidgetItem *item);
    void setDefaultGroupIdOnStart();

    int getIdOfSelectedNote();
    int getIdOfSelectedGroup();

    void MWC_CreationOfDatabaseControllers();
    void mustDeleteGroup();

    void keyPressEvent(QKeyEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

    void keyDeleteNote(const int noteId);
    bool whichGroupToShow();
    bool toShowGroupOfNewNote();

    void setRowByRealGroupId();

private:
    Ui::MainWindow *ui;
    WelcomeWidget *_welcomeWidget;
    CreateDatabaseWidget *_createDatabaseWidget;
    UnlockDatabaseWidget *_unlockDatabaseWidget;
    EditDatabaseWidget *_editDatabaseWidget;
    AddNewNoteWidget *_addNewNoteWidget;
    EditExistNoteWidget *_editExistNoteWidget;
    AddNewGroupWidget *_addNewGroupWidget;
    EditExistGroupWidget *_editExistGroupWidget;

    DatabaseController *_dbc;
    DatabaseCreator *_databaseCreator;
    DatabaseNotesCreator *_databaseNotesCreator;
    DatabaseNotesEditor *_databaseNotesEditor;
    DatabaseGroupsCreator *_databaseGroupsCreator;
    DatabaseGroupsEditor *_databaseGroupsEditor;
    DatabaseDisplay *_databaseDisplay;
    DatabaseNotesRemover *_databaseNotesRemover;
    DatabaseGroupsRemover *_databaseGroupsRemover;
    DatabaseEncryptor *_databaseEncryptor;
    DatabaseDecryptor *_databaseDecryptor;
    DatabaseShortcutsSelecter *_databaseShortcutsSelecter;

    DeleteGroupWarning *_deleteGroupWarning;

    QString possibleFilePath;
    QStringList recentDatabases;
    QToolBar *_toolbar;
    QStringList headerLabels
        = {"Название записи", "Имя пользователя", "URL-адрес", "Заметки", "Время изменения"};
    QString groupName = "PasswordManager";
    int counterOfMWActivations = 0;
    int counterOfNewNoteCreation = 0;
    int counterOfNewGroupCreation = 0;
    int noteId = -999;
    int groupId = -999;
    bool _mustDeleteGroup = false;

};
#endif // MAINWINDOW_H
