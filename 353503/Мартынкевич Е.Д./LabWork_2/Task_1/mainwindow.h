#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "date.h"
#include "QGridLayout"
#include "QDebug"
#include "QDate"
#include "QTableWidget"
#include "QTextStream"
#include "QFile"
#include "QDir"
#include "QStandardItemModel"
#include "QLineEdit"
#include "QLabel"
#include "QPushButton"
#include "QSpacerItem"
#include "QFileDialog"
#include "QComboBox"
#include "QRegularExpression"
#include "QRegularExpressionValidator"
#include "QIntValidator"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void BearthdayUpdateTable(Date *bday);

    void OpenFile();
    void UpdateTable();
    void AddDate(Date *new_date);
    void ClearAddDateEdit();

    void BearthdayButtonClick();
    void AddDateButtonClick();
    void DelDateButtonClick();
    void CreateFileButtonClick();
    void CloseFileButtonClick();
    void ChangeDateButtonClick();

    void TextBdayChanged(const QString &text);
    void UpdateFile();

private:
    Ui::MainWindow *ui;

    QVector<Date> dates;
    QStringList headers;

    QString opened_file;
    Date *bearthday;

    QGridLayout *layout;
    QTableWidget *table;
    QWidget *central_widget;

    QLineEdit *bearthday_edit;
    QLineEdit *add_date_edit;
    QLineEdit *del_date_edit;
    QLineEdit *change_date_edit;
    QLineEdit *number_date_edit;

    QLabel *bearthday_label;
    QLabel *add_date_label;
    QLabel *del_date_label;
    QLabel *opened_file_name;
    QLabel *number_date_label;
    QLabel *change_date_label;

    QPushButton *bearthday_button;
    QPushButton *open_table_button;
    QPushButton *add_date_button;
    QPushButton *del_date_button;
    QPushButton *new_file_button;
    QPushButton *change_date_button;
    QPushButton *close_file_button;
};
#endif // MAINWINDOW_H
