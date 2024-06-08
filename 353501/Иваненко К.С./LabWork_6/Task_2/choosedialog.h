#pragma once

#ifndef CHOOSEDIALOG_H
#define CHOOSEDIALOG_H

#include <QDialog>

namespace Ui {
class ChooseDialog;
}

class ChooseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseDialog(const QString &options, const int  number, QWidget *parent = nullptr);
    ~ChooseDialog();

    int getOption();

private:
    Ui::ChooseDialog *ui;
};

#endif // CHOOSEDIALOG_H
