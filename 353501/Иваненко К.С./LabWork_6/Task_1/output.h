#pragma once

#ifndef OUTPUT
#define OUTPUT

#include <QDialog>

namespace Ui {
class Output;
}

class Output : public QDialog
{
    Q_OBJECT

public:
    explicit Output(const QString &output, QWidget *parent = nullptr);
    ~Output();

private:
    Ui::Output *ui;
};

#endif // OUTPUT
