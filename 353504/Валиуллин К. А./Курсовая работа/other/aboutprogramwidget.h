#ifndef ABOUTPROGRAMWIDGET_H
#define ABOUTPROGRAMWIDGET_H

#include <QDialog>
#include <QLabel>
#include <QDesktopServices>
#include <QUrl>

namespace Ui {
class AboutProgramWidget;
}

class AboutProgramWidget : public QDialog
{
    Q_OBJECT

public:
    explicit AboutProgramWidget(QWidget *parent = nullptr);
    ~AboutProgramWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AboutProgramWidget *ui;
};

#endif // ABOUTPROGRAMWIDGET_H
