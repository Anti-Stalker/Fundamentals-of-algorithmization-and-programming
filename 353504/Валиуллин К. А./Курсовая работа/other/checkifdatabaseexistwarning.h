#ifndef CHECKIFDATABASEEXISTWARNING_H
#define CHECKIFDATABASEEXISTWARNING_H

#include <QDialog>

namespace Ui {
class CheckIfDatabaseExistWarning;
}

class CheckIfDatabaseExistWarning : public QDialog
{
    Q_OBJECT

public:
    explicit CheckIfDatabaseExistWarning(QWidget *parent = nullptr);
    ~CheckIfDatabaseExistWarning();

signals:
    void transmitCheckIfDbExistConfirmation();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::CheckIfDatabaseExistWarning *ui;
};

#endif // CHECKIFDATABASEEXISTWARNING_H
