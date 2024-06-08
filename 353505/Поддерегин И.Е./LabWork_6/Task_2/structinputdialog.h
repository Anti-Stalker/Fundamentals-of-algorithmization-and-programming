#ifndef STRUCTINPUTDIALOG_H
#define STRUCTINPUTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <cloth.h>

namespace Ui {
class StructInputDialog;
}

class StructInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StructInputDialog(QWidget*, Cloth*);
    ~StructInputDialog();

private slots:
    void on_buttonBox_accepted();

    void on_spinBox_valueChanged(int);

private:
    Ui::StructInputDialog *ui;
    Cloth* a;
    Cloth input;
};

#endif // STRUCTINPUTDIALOG_H
