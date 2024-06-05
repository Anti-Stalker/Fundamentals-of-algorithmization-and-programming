#ifndef DELETEGROUPWARNING_H
#define DELETEGROUPWARNING_H

#include <QDialog>

namespace Ui {
class DeleteGroupWarning;
}

class DeleteGroupWarning : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteGroupWarning(QWidget *parent = nullptr);
    ~DeleteGroupWarning();

signals:
    void transmitDeletingConfirmation();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::DeleteGroupWarning *ui;
};

#endif // DELETEGROUPWARNING_H
