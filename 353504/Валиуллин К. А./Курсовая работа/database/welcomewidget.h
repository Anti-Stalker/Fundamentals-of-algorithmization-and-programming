#ifndef WELCOMEWIDGET_H
#define WELCOMEWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QStandardPaths>

#include "database/recentdatabasemanager.h"
#include "structures/EnumWidgets.h"

namespace Ui {
class WelcomeWidget;
}

class WelcomeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeWidget(QWidget *parent = nullptr);
    ~WelcomeWidget();

public slots:
    void showRecentDatabases();

signals:
    void transmitFilePath(QString filePath);
    void transmitChangeToUnlockBase(int index);
    void transmitChangeToCreateBase(int index);

private slots:
    void on_openExistBaseButton_clicked();
    void on_createBaseButton_clicked();
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void changeRecentDatabasesStatusText();
    void on_deleteAllNonExistDb_clicked();

private:
    Ui::WelcomeWidget *ui;
    QString filePath;
    QStringList recentDatabases;

};

#endif // WELCOMEWIDGET_H
