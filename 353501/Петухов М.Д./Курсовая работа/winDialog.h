#pragma once

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class WinDialog;
}

class WinDialog : public QDialog
{
    Q_OBJECT
private:
    Ui::WinDialog *ui;
public:
    explicit WinDialog(QWidget *parent = nullptr);
    ~WinDialog();
private slots:
    void on_pushButton_clicked();
signals:
    void closedEvent();
protected:
    void closeEvent(QCloseEvent *event) override;
};
