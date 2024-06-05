#pragma once

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
signals:
    void textEntered(const int& runwayCount, const double& area, char inputChar, const bool& hasControlTower, std::string airportName, const QVector<int>& numbers);
};
