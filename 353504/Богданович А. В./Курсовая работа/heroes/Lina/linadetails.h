#ifndef LINADETAILS_H
#define LINADETAILS_H

#include <QWidget>
#include <QMovie>
#include <QMessageBox>

namespace Ui {
class LinaDetails;
}

class LinaDetails : public QDialog
{
    Q_OBJECT

public:
    explicit LinaDetails(QWidget *parent = nullptr);
    ~LinaDetails();

public slots:
    void on_Ab_1_clicked();

    void on_Ab_2_clicked();

    void on_Ab_3_clicked();

    void on_close_button_clicked();

private:
    Ui::LinaDetails *ui;
};

#endif // LINADETAILS_H
