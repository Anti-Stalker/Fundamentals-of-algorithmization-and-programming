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

private:
    Ui::Dialog *ui;
    int eggsForSale = 0;
    int bearsForSale = 0;
private:
    void setDialogBackground();
    void createButtons();
    void setButtonStyle(QPushButton* button);
signals:
    void updateCollectedEggsLabelSignal();
    void selledEggs(QPushButton* sellEggsButton, int selledEggs);
    void selledBears(QPushButton* sellEggsButton, int selledBears);
private slots:
    void on_loadSingleEggButton_clicked();
    void on_loadAllEggsButton_clicked();
    void on_sellEggsButton_clicked();
    void on_loadBear_clicked();
    void on_sellBear_clicked();
};
