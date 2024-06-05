#pragma once

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class RulesDialog;
}

class RulesDialog : public QDialog
{
    Q_OBJECT
private:
    Ui::RulesDialog *ui;
public:
    explicit RulesDialog(QWidget *parent = nullptr);
    ~RulesDialog();
};
