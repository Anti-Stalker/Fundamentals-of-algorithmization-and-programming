#ifndef UNLOCKDATABASEWIDGET_H
#define UNLOCKDATABASEWIDGET_H

#include <QDialog>
#include <QMessageBox>
#include <QCloseEvent>

#include "database/hashingmanager.h"
#include "dbmanagement/databasedecryptor.h"
#include "structures/EnumWidgets.h"

namespace Ui {
class UnlockDatabaseWidget;
}

class UnlockDatabaseWidget : public QDialog
{
    Q_OBJECT

public:
    explicit UnlockDatabaseWidget(QWidget *parent = nullptr);
    ~UnlockDatabaseWidget();

public slots:
    void receiveFilePath(const QString& filePath);

signals:
    void transmitChangeToMainWindow(int index);
    void transmitDataBasePath(QString filePath);

private slots:
    void on_unlockBaseButton_clicked();
    void clear_all();
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::UnlockDatabaseWidget *ui;
    QString filePath, passwordEntry;
    DatabaseDecryptor databaseDecryptor;
    bool isPasswordCorrect;
};

#endif // UNLOCKDATABASEWIDGET_H
