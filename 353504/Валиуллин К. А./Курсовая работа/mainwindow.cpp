#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::MWC_ConnectOfQActions()
{
    connect(ui->actionCreateDatabase, &QAction::triggered,
            this, &MainWindow::actionCreateDatabase);
    connect(ui->actionChooseUnlockingBase, &QAction::triggered,
            this, &MainWindow::actionChooseUnlockingBase);
    connect(ui->actionChangeDatabase, &QAction::triggered,
            this, &MainWindow::actionChangeDatabase);
    connect(ui->actionCreateNewNote, &QAction::triggered,
            this, &MainWindow::actionCreateNewNote);
    connect(ui->actionChangeNote, &QAction::triggered,
            this, &MainWindow::actionChangeNote);
    connect(ui->actionDeleteNote, &QAction::triggered,
            this, &MainWindow::actionDeleteNote);
    connect(ui->actionCreateGroup, &QAction::triggered,
            this, &MainWindow::actionCreateGroup);
    connect(ui->actionChangeGroup, &QAction::triggered,
            this, &MainWindow::actionChangeGroup);
    connect(ui->actionDeleteGroup, &QAction::triggered,
            this, &MainWindow::actionDeleteGroup);
    connect(ui->actionCopyUsername, &QAction::triggered,
            this, &MainWindow::actionCopyUsername);
    connect(ui->actionCopyPassword, &QAction::triggered,
            this, &MainWindow::actionCopyPassword);
    connect(ui->actionAboutProgram, &QAction::triggered,
            this, &MainWindow::actionAboutProgram);
    connect(ui->actionQuit, &QAction::triggered,
            this, &MainWindow::actionQuit);
}

void MainWindow::MWC_InsertStackedWidgets()
{
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(1, _welcomeWidget);
    ui->stackedWidget->insertWidget(2, _addNewNoteWidget);
    ui->stackedWidget->insertWidget(3, _editExistNoteWidget);
    ui->stackedWidget->insertWidget(4, _addNewGroupWidget);
    ui->stackedWidget->insertWidget(5, _editExistGroupWidget);
    ui->stackedWidget->setCurrentIndex(IndexWelcomeWidget);
}

void MainWindow::MWC_CreationOfDatabaseControllers()
{
    _dbc = new DatabaseController(this);
    _databaseNotesCreator = new DatabaseNotesCreator(this);
    _databaseNotesEditor = new DatabaseNotesEditor(this);
    _databaseGroupsCreator = new DatabaseGroupsCreator(this);
    _databaseGroupsEditor = new DatabaseGroupsEditor(this);
    _databaseCreator = new DatabaseCreator(_databaseGroupsCreator, this);
    _databaseDisplay = new DatabaseDisplay(this);
    _databaseNotesRemover = new DatabaseNotesRemover(this);
    _databaseGroupsRemover = new DatabaseGroupsRemover(this);
    _databaseEncryptor = new DatabaseEncryptor(this);
    _databaseDecryptor = new DatabaseDecryptor(this);
    _databaseShortcutsSelecter = new DatabaseShortcutsSelecter(this);
}

void MainWindow::MWC_CreationOfUiForms()
{
    _welcomeWidget = new WelcomeWidget(this);
    _welcomeWidget->showRecentDatabases();
    _unlockDatabaseWidget = new UnlockDatabaseWidget(this);
    _createDatabaseWidget = new CreateDatabaseWidget(_databaseCreator, this);
    _editDatabaseWidget = new EditDatabaseWidget(this);
    _addNewNoteWidget = new AddNewNoteWidget(_databaseNotesCreator, this);
    _editExistNoteWidget = new EditExistNoteWidget(_databaseNotesEditor, this);
    _addNewGroupWidget = new AddNewGroupWidget(_databaseGroupsCreator, this);
    _editExistGroupWidget = new EditExistGroupWidget(_databaseGroupsEditor, this);
}

void MainWindow::MWC_ConnectOfPushButtons()
{
    connect(_welcomeWidget, &WelcomeWidget::transmitChangeToUnlockBase,
            this, &MainWindow::changeStackedWidgetIndex);
    connect(_welcomeWidget, &WelcomeWidget::transmitChangeToCreateBase,
            this, &MainWindow::activatePopUpWidget);
    connect(_welcomeWidget, &WelcomeWidget::transmitChangeToUnlockBase,
            this, &MainWindow::activatePopUpWidget);
    connect(_databaseCreator, &DatabaseCreator::transmitChangeToMainWindow,
            this, &MainWindow::changeStackedWidgetIndex);
    connect(_unlockDatabaseWidget, &UnlockDatabaseWidget::transmitChangeToMainWindow,
            this, &MainWindow::changeStackedWidgetIndex);
}

void MainWindow::MWC_ConnectsOther()
{
    connect(_welcomeWidget, &WelcomeWidget::transmitFilePath,
            this, &MainWindow::receivePossibleFilePath);
    connect(_unlockDatabaseWidget, &UnlockDatabaseWidget::transmitDataBasePath,
            this, &MainWindow::receiveFilePath);
    connect(_databaseCreator, &DatabaseCreator::transmitFilePath,
            this, &MainWindow::receiveFilePath);
    connect(_addNewNoteWidget, &AddNewNoteWidget::transmitChangeToMainWindow,
            this, &MainWindow::changeStackedWidgetIndex);
    connect(_addNewNoteWidget, &AddNewNoteWidget::transmitGroupId,
            this, &MainWindow::setGroupId);
    connect(_editExistNoteWidget, &EditExistNoteWidget::transmitGroupId,
            this, &MainWindow::setGroupId);
    connect(_addNewGroupWidget, &AddNewGroupWidget::transmitGroupId,
            this, &MainWindow::setGroupId);
    connect(_editExistGroupWidget, &EditExistGroupWidget::transmitGroupId,
            this, &MainWindow::setGroupId);
    connect(_editExistNoteWidget, &EditExistNoteWidget::transmitChangeToMainWindow,
            this, &MainWindow::changeStackedWidgetIndex);
    connect(_addNewGroupWidget, &AddNewGroupWidget::transmitChangeToMainWindow,
            this, &MainWindow::changeStackedWidgetIndex);
    connect(_editExistGroupWidget, &EditExistGroupWidget::transmitChangeToMainWindow,
            this, &MainWindow::changeStackedWidgetIndex);
}

void MainWindow::MWC_CreationOfToolBar()
{
    _toolbar = new QToolBar(this);
    QSize iconSize(48, 48);

    QFrame* separator1 = new QFrame();
    separator1->setFrameShape(QFrame::VLine);
    separator1->setFrameShadow(QFrame::Sunken);
    separator1->setLineWidth(2);
    separator1->setMidLineWidth(0);
    separator1->setStyleSheet("background-color: gray;");

    QFrame* separator2 = new QFrame();
    separator2->setFrameShape(QFrame::VLine);
    separator2->setFrameShadow(QFrame::Sunken);
    separator2->setLineWidth(2);
    separator2->setMidLineWidth(0);
    separator2->setStyleSheet("background-color: gray;");

    QFrame* separator3 = new QFrame();
    separator3->setFrameShape(QFrame::VLine);
    separator3->setFrameShadow(QFrame::Sunken);
    separator3->setLineWidth(2);
    separator3->setMidLineWidth(0);
    separator3->setStyleSheet("background-color: gray;");

    QWidget* spacer1 = new QWidget();
    spacer1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    QWidget* spacer2 = new QWidget();
    spacer2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    addToolBar(_toolbar);
    _toolbar->setIconSize(iconSize);
    _toolbar->setMovable(false);

    _toolbar->addAction(ui->actionCreateDatabase);
    ui->actionCreateDatabase->setIcon(QIcon("://Images/CreateDatabase.png"));
    _toolbar->addAction(ui->actionChooseUnlockingBase);
    ui->actionChooseUnlockingBase->setIcon(QIcon("://Images/LockDatabase.png"));
    _toolbar->addAction(ui->actionChangeDatabase);
    ui->actionChangeDatabase->setIcon(QIcon("://Images/ChangeDatabase.png"));

    _toolbar->addWidget(spacer1);
    _toolbar->addWidget(separator1);

    _toolbar->addAction(ui->actionCreateNewNote);
    ui->actionCreateNewNote->setIcon(QIcon("://Images/CreateNewNote.png"));
    _toolbar->addAction(ui->actionChangeNote);
    ui->actionChangeNote->setIcon(QIcon("://Images/ChangeExistNote.png"));
    _toolbar->addAction(ui->actionDeleteNote);
    ui->actionDeleteNote->setIcon(QIcon("://Images/DeleteNote.png"));

    _toolbar->addWidget(spacer2);
    _toolbar->addWidget(separator2);
    _toolbar->addWidget(spacer2);

    _toolbar->addAction(ui->actionCreateGroup);
    ui->actionCreateGroup->setIcon(QIcon("://Images/CreateGroup.png"));
    _toolbar->addAction(ui->actionChangeGroup);
    ui->actionChangeGroup->setIcon(QIcon("://Images/ChangeGroup.png"));
    _toolbar->addAction(ui->actionDeleteGroup);
    ui->actionDeleteGroup->setIcon(QIcon("://Images/DeleteGroup.png"));

    ui->actionCopyPassword->setShortcut(QKeySequence("Ctrl+C"));
    ui->actionCopyPassword->setIcon(QIcon("://Images/copyToClipboard.png"));
    ui->actionCopyUsername->setShortcut(QKeySequence("Ctrl+B"));
    ui->actionCopyUsername->setIcon(QIcon("://Images/copyToClipboard.png"));


    _toolbar->addWidget(spacer1);
    _toolbar->addWidget(separator3);
    _toolbar->addWidget(spacer1);

    _toolbar->addAction(ui->actionAboutProgram);
    ui->actionAboutProgram->setIcon(QIcon("://Images/About.png"));
    _toolbar->addAction(ui->actionQuit);
    ui->actionQuit->setIcon(QIcon("://Images/Quit.png"));
}

void MainWindow::MWC_Warnings()
{
    _deleteGroupWarning = new DeleteGroupWarning(this);
    connect(_deleteGroupWarning, &DeleteGroupWarning::transmitDeletingConfirmation,
            this, &MainWindow::mustDeleteGroup);
}

void MainWindow::mustDeleteGroup()
{
    _mustDeleteGroup = true;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    MWC_CreationOfDatabaseControllers();
    MWC_CreationOfUiForms();
    MWC_InsertStackedWidgets();
    MWC_ConnectOfQActions();
    MWC_ConnectOfPushButtons();
    MWC_ConnectsOther();
    MWC_CreationOfToolBar();
    MWC_Warnings();
}

MainWindow::~MainWindow()
{
    delete ui;
}




//НЕ КОНСТРУКТОР




void MainWindow::closeEvent(QCloseEvent *event)  {
    if (ui->stackedWidget->currentIndex() == IndexMainWindow) {
        _databaseEncryptor->encryptDatabase();
        QMainWindow::closeEvent(event);
    }
    else {
        QMainWindow::closeEvent(event);
    }
}

void MainWindow::changeStackedWidgetIndex(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
    if (counterOfMWActivations == 0 && ui->stackedWidget->currentIndex() == IndexMainWindow) {
        firstStartOfMainWindow();
        counterOfMWActivations++;
    }
    else {
        ifMainWindowActivated();
    }
}

void MainWindow::activatePopUpWidget(int index)
{
    switch (index) {
    case IndexСreateBaseWidget:
        createBase();
        break;
    case IndexUnlockBaseWidget:
        unlockBase();
        break;
    default:
        break;
    }
}

bool MainWindow::whichGroupToShow()
{
    if (counterOfNewGroupCreation != 0) {
        setNewGroupItem();
        counterOfNewGroupCreation--;
        return true;
    }
    return false;
}

void MainWindow::setRowByRealGroupId()
{
    QString realNameOfGroup = _dbc->findGroupNameByGroupID(groupId);
    int rowIndex = -1;
    for (int i = 0; i < ui->groupListWidget->count(); i++) {
        if (ui->groupListWidget->item(i)->text() == realNameOfGroup) {
            rowIndex = i;
            break;
        }
    }
    if (rowIndex != -1) {
        ui->groupListWidget->setCurrentRow(rowIndex);
    }
    counterOfNewNoteCreation--;
}

bool MainWindow::toShowGroupOfNewNote()
{
    if (counterOfNewNoteCreation != 0) {
        _databaseDisplay->showNotesByGroupId(ui->notesTableWidget, groupId);
        setRowByRealGroupId();
        return true;
    }
    return false;
}

void MainWindow::firstStartOfMainWindow()
{
    if (ui->stackedWidget->currentIndex() == IndexMainWindow) {
        showDatabasesGroups();
        adjustTableWidget();
        setDefaultGroupIdOnStart();
        ui->groupListWidget->setCurrentRow(0);
        _databaseDisplay->showNotesByGroupId(ui->notesTableWidget, groupId);
        _addNewNoteWidget->populateGroupComboBox();
        _editExistNoteWidget->populateGroupComboBox();
    }
}

void MainWindow::ifMainWindowActivated()
{
    if (ui->stackedWidget->currentIndex() == IndexMainWindow) {
        showDatabasesGroups();
        adjustTableWidget();
        if (!whichGroupToShow()) {
            if (!toShowGroupOfNewNote()) {
                _databaseDisplay->showNotesByGroupId(ui->notesTableWidget, groupId);
                setRowByRealGroupId();
            }
        }
        _addNewNoteWidget->populateGroupComboBox();
        _editExistNoteWidget->populateGroupComboBox();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    noteId = getIdOfSelectedNote();
    groupId = getIdOfSelectedGroup();
    if (event->key() == Qt::Key_Delete) {
        if (noteId != 0) {
            keyDeleteNote(noteId);
        }
        else if (groupId != 0) {
            actionDeleteGroup();
        }
    } else {
        QMainWindow::keyPressEvent(event);
    }
}

void MainWindow::unlockBase()
{
    _unlockDatabaseWidget->receiveFilePath(possibleFilePath);
    _unlockDatabaseWidget->show();
}

void MainWindow::createBase()
{
    _createDatabaseWidget->show();
}

void MainWindow::showDatabasesGroups()
{
    ui->groupListWidget->clear();
    _databaseDisplay->showDatabasesGroups(ui->groupListWidget);
}

void MainWindow::adjustTableWidget()
{
    ui->notesTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->notesTableWidget->setHorizontalHeaderLabels(headerLabels);
    ui->notesTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->notesTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->notesTableWidget->verticalHeader()->setVisible(false);
}

void MainWindow::receivePossibleFilePath(const QString &fp)
{
    possibleFilePath = fp;
}

void MainWindow::saveNewFilePath()
{
    recentDatabases = RecentDatabaseManager::loadRecentDatabases();
    if (!DatabaseController::getFilePath().isEmpty() && !recentDatabases.contains(DatabaseController::getFilePath()))
    {
        recentDatabases.prepend(DatabaseController::getFilePath());;
        RecentDatabaseManager::saveRecentDatabases(recentDatabases);
        _welcomeWidget->showRecentDatabases();
    }
}

void MainWindow::setDatabaseNameText()
{
    ui->baseName->setText(DatabaseController::getFilePath());
    QFont font;
    font.setPointSize(12);
    ui->baseName->setFont(font);
}

void MainWindow::setDefaultGroupIdOnStart()
{
    QMap<int, QString> groupNames = _dbc->getGroupNames();
    if (!groupNames.isEmpty()) {
        groupId = groupNames.firstKey();
    }
}



void MainWindow::receiveFilePath(const QString &fp)
{
    DatabaseController::setFilePath(fp);
    setDatabaseNameText();
    saveNewFilePath();
}




//НАСТРОЙКИ БАЗЫ ДАННЫХ




void MainWindow::actionCreateDatabase()
{
    if (ui->stackedWidget->currentIndex() == IndexWelcomeWidget) {
        _createDatabaseWidget->show();
    }
    else {
        _databaseEncryptor->encryptDatabase();
        _dbc->clearFilePath();
        changeStackedWidgetIndex(IndexWelcomeWidget);
        _welcomeWidget->showRecentDatabases();
        _createDatabaseWidget->show();
    }
}

void MainWindow::actionChooseUnlockingBase()
{
    if (ui->stackedWidget->currentIndex() == IndexWelcomeWidget) {
        _welcomeWidget->showRecentDatabases();
    }
    else {
        _databaseEncryptor->encryptDatabase();
        _dbc->clearFilePath();
        changeStackedWidgetIndex(IndexWelcomeWidget);
        _welcomeWidget->showRecentDatabases();
    }
}

void MainWindow::actionChangeDatabase()
{
    if (ui->stackedWidget->currentIndex() == IndexMainWindow && !_dbc->isEmptyFilePath()) {
        _editDatabaseWidget->exec();
        setDatabaseNameText();
        saveNewFilePath();
    }
    else {
        QMessageBox::warning(this, "Ошибка", "Cначала войдите в базу данных!");
    }
}




//НАСТРОЙКИ ЗАПИСЕЙ




void MainWindow::actionCreateNewNote()
{
    if (_dbc->isEmptyFilePath()) {
        QMessageBox::warning(this, "Ошибка", "Cначала войдите в базу данных!");
    }
    else {
        groupId = getIdOfSelectedGroup();
        counterOfNewNoteCreation++;
        changeStackedWidgetIndex(IndexAddNewNoteWidget);
    }
}

int MainWindow::getIdOfSelectedNote()
{
    QList<QTableWidgetItem*> selectedItems = ui->notesTableWidget->selectedItems();
    int idItem, row;
    if (!selectedItems.isEmpty()) {
        QTableWidgetItem* selectedItem = selectedItems.first();
        row = selectedItem->row();
        return idItem = ui->notesTableWidget->item(row, 0)->data(Qt::UserRole).toInt();
    }
    return -999;
}

void MainWindow::actionChangeNote()
{
    noteId = getIdOfSelectedNote();
    if (_dbc->isEmptyFilePath()) {
        QMessageBox::warning(this, "Ошибка", "Cначала войдите в базу данных!");
    }
    else if (noteId != -999  && noteId != 0) {
        _editExistNoteWidget->setNoteId(noteId);
        _editExistNoteWidget->toFillFields();
        changeStackedWidgetIndex(IndexEditExistNoteWidget);
    }
    else {
        QMessageBox::warning(this, "Ошибка", "Выберите запись для изменения!");
    }
}

void MainWindow::actionDeleteNote()
{
    noteId = getIdOfSelectedNote();
    if (_dbc->isEmptyFilePath()) {
        QMessageBox::warning(this, "Ошибка", "Cначала войдите в базу данных!");
    }
    else if (noteId != -999 && noteId != 0) {
        _databaseNotesRemover->deleteNote(noteId);
        _databaseDisplay->showNotesByGroupId(ui->notesTableWidget, groupId);
    }
    else {
        QMessageBox::warning(this, "Ошибка", "Cначала выберите запись для удаления!");
    }
}

void MainWindow::keyDeleteNote(const int noteId) {
    _databaseNotesRemover->deleteNote(noteId);
    _databaseDisplay->showNotesByGroupId(ui->notesTableWidget, groupId);
}



//НАСТРОЙКИ ГРУППЫ



void MainWindow::setNewGroupItem()
{
    int indexOfLastElement = ui->groupListWidget->count() - 1;
    QListWidgetItem* newGroupItem = ui->groupListWidget->item(indexOfLastElement);
    on_groupListWidget_itemClicked(newGroupItem);
    ui->groupListWidget->setCurrentRow(indexOfLastElement);
}

void MainWindow::setGroupId(int newGroupId)
{
    groupId = newGroupId;
}

void MainWindow::actionCreateGroup()
{
    if (_dbc->isEmptyFilePath()) {
        QMessageBox::warning(this, "Ошибка", "Cначала войдите в базу данных!");
    }
    else {
        counterOfNewGroupCreation++;
        changeStackedWidgetIndex(IndexAddNewGroupWidget);
    }
}

int MainWindow::getIdOfSelectedGroup()
{
    QList<QListWidgetItem*> selectedItems = ui->groupListWidget->selectedItems();
    int idItem, row;
    if (!selectedItems.isEmpty()) {
        QListWidgetItem* selectedItem = selectedItems.first();
        row = ui->groupListWidget->row(selectedItem);
        return idItem = ui->groupListWidget->item(row)->data(Qt::UserRole).toInt();
    }
    return -999;
}

void MainWindow::actionChangeGroup()
{
    groupId = getIdOfSelectedGroup();
    if (_dbc->isEmptyFilePath()) {
        QMessageBox::warning(this, "Ошибка", "Cначала войдите в базу данных!");
    }
    else if (groupId != -999 && groupId != 0) {
        _editExistGroupWidget->setGroupId(groupId);
        _editExistGroupWidget->toFillFields();
        changeStackedWidgetIndex(IndexEditExistGroupWidget);
    } else {
        QMessageBox::warning(this, "Ошибка", "Выберите группу для изменения!");
    }
}

void MainWindow::actionDeleteGroup()
{
    groupId = getIdOfSelectedGroup();
    if (_dbc->isEmptyFilePath()) {
        QMessageBox::warning(this, "Ошибка", "Cначала войдите в базу данных!");
    }
    else if (groupId != -999 && groupId != 0) {
        _deleteGroupWarning->exec();
        if (_mustDeleteGroup) {
            groupId = getIdOfSelectedGroup();
            _databaseGroupsRemover->deleteGroup(groupId);
            _databaseGroupsRemover->deleteNotesByGroupId(groupId);
            setDefaultGroupIdOnStart();
            _databaseDisplay->showDatabasesGroups(ui->groupListWidget);
            _databaseDisplay->showNotesByGroupId(ui->notesTableWidget, groupId);
            ui->groupListWidget->setCurrentRow(0);
            _mustDeleteGroup = false;
            ifMainWindowActivated();
        }
    }
    else {
        QMessageBox::warning(this, "Ошибка", "Выберите группу для удаления!");
    }
}

void MainWindow::actionCopyUsername()
{
    if (ui->stackedWidget->currentIndex() == IndexMainWindow) {
        noteId = getIdOfSelectedNote();
        _databaseShortcutsSelecter->copyUsernameToClipboard(noteId);
    }
}

void MainWindow::actionCopyPassword()
{
    if (ui->stackedWidget->currentIndex() == IndexMainWindow) {
        noteId = getIdOfSelectedNote();
        _databaseShortcutsSelecter->copyPasswordToClipboard(noteId);
    }
}

void MainWindow::on_groupListWidget_itemClicked(QListWidgetItem *item)
{
    if (!_databaseGroupsCreator->isGroupTableEmpty()) {
        int row = ui->groupListWidget->row(item);
        groupId = ui->groupListWidget->item(row)->data(Qt::UserRole).toInt();
        _databaseDisplay->showNotesByGroupId(ui->notesTableWidget, groupId);
    }
}



//ДРУГИЕ НАСТРОЙКИ




void MainWindow::actionAboutProgram()
{
    AboutProgramWidget *aboutProgramWidget;
    aboutProgramWidget = new AboutProgramWidget(this);
    aboutProgramWidget->show();
}

void MainWindow::actionQuit()
{
    if (ui->stackedWidget->currentIndex() == IndexWelcomeWidget) {
        close();
    }
    else {
        _databaseEncryptor->encryptDatabase();
        close();
    }

}
