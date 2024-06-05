#ifndef DROWRANGERDIALOG_H
#define DROWRANGERDIALOG_H

#include <QDialog>
#include <QMovie>
#include <QMessageBox>

namespace Ui {
class DrowRangerDialog;
}

class DrowRangerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DrowRangerDialog(QWidget *parent = nullptr);
    ~DrowRangerDialog();

public slots:
    void on_Ab_1_clicked();

    void on_Ab_2_clicked();

    void on_Ab_3_clicked();

    void on_close_button_clicked();

private:
    Ui::DrowRangerDialog *ui;
};

#endif // DROWRANGERDIALOG_H
