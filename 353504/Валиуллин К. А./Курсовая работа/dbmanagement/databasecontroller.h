#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QFileDialog>
#include <QListWidget>
#include <QMessageBox>
#include <QTableWidget>
#include <QHeaderView>
#include <QComboBox>
#include <QWidget>

#include "structures/EnumWidgets.h"
#include "structures/NodeData.h"
#include "structures/GroupData.h"

class DatabaseController : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseController(QObject *parent = nullptr);

    QMap<int, QString> getGroupNames();
    int findGroupIDdByGroupName(QString comboText);
    QString findGroupNameByGroupID(int id);

    static void setFilePath(const QString &filePath);
    static QString getFilePath();

    bool openDatabase();
    void closeDatabase();
    bool isEmptyFilePath();
    void clearFilePath();

    QString padPassword(const QString& password);
    QString getPassword() const;
    void setPassword(const QString &newPassword);
    QString getTryPassword() const;
    void setTryPassword(const QString &newTryPassword);  

signals:
    void transmitFilePath(const QString &filePath);
    void transmitChangeToMainWindow(int index);

protected:
    static QString filePath;
    static QString password;
    static QString tryPassword;
    QWidget *parentWidget;
    QSqlDatabase db;

};

#endif // DATABASECONTROLLER_H
