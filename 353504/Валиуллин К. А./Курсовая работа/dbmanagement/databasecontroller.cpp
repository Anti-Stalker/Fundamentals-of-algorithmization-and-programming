    #include "databasecontroller.h"

DatabaseController::DatabaseController(QObject *parent)
    : QObject{parent}
{}

QString DatabaseController::filePath;

QString DatabaseController::password;

QString DatabaseController::tryPassword;

QMap<int, QString> DatabaseController::getGroupNames()
{
    openDatabase();
    QMap<int, QString> groupMap;

    QSqlQuery query;
    query.exec("SELECT id, group_name FROM groups");

    while (query.next())
    {
        int groupId = query.value("id").toInt();
        QString groupName = query.value("group_name").toString();
        groupMap.insert(groupId, groupName);
    }
    closeDatabase();
    return groupMap;
}

int DatabaseController::findGroupIDdByGroupName(QString comboText)
{
    openDatabase();
    QSqlQuery query;
    int groupId;
    query.prepare("SELECT id FROM groups WHERE group_name = :gr");
    query.bindValue(":gr", comboText);
    if (query.exec()) {
        if (query.next()) {
            closeDatabase();
            return groupId = query.value(0).toInt();
        }
    }
    closeDatabase();
    return -999;
}

QString DatabaseController::findGroupNameByGroupID(int id)
{
    openDatabase();
    QSqlQuery query;
    QString groupName = "ERROR";
    query.prepare("SELECT group_name FROM groups WHERE id = :id");
    query.bindValue(":id", id);
    if (query.exec()) {
        if (query.next()) {
            return groupName = query.value(0).toString();
        }
    }
    return groupName;
    closeDatabase();
}

void DatabaseController::setFilePath(const QString &filePath)
{
    DatabaseController::filePath = filePath;
}

bool DatabaseController::openDatabase() {
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection");
        if (db.isOpen()) {
            return true;
        } else {
            return db.open();
        }
    } else {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "qt_sql_default_connection");
        db.setDatabaseName(filePath);
        return db.open();
    }
}

void DatabaseController::closeDatabase()
{
    if (db.isOpen())
    {
        db.close();
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
    }
}

bool DatabaseController::isEmptyFilePath()
{
    if (filePath.isEmpty()) {
        return true;
    }
    else {
        return false;
    }
}

void DatabaseController::clearFilePath()
{
    filePath.clear();
}

QString DatabaseController::padPassword(const QString &password)
{
    QString paddedPassword = password;

    while (paddedPassword.size() < 32)
    {
        paddedPassword += '\0';
    }

    return paddedPassword;
}

QString DatabaseController::getPassword() const
{
    return password;
}

void DatabaseController::setPassword(const QString &newPassword)
{
    password = newPassword;
}

QString DatabaseController::getTryPassword() const
{
    return tryPassword;
}

void DatabaseController::setTryPassword(const QString &newTryPassword)
{
    tryPassword = newTryPassword;
}

QString DatabaseController::getFilePath()
{
    return filePath;
}

