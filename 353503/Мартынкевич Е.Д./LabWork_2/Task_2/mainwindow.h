#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "сourier.h"
#include "zakaz.h"
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
#include <QRadioButton>

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

    void UpdateZakazTable();
    void UpdateCourierTable();
    void UpdateBadZakazTable();
    void UpdateZakazFile();
    void UpdateCourierFile();

    void OpenZakazFile();
    void OpenCourierFile();
    void CloseZakazFile();
    void CloseCourierFile();
    void NewZakazFile();
    void NewCourierFile();
    void AddZakazButtonClick();
    void AddCourierButtonClick();
    void ChangeZakazButtonClick();
    void ChangeCourierButtonClick();
    void DeleteZakazButtonClick();
    void DeleteCourierButtonClick();
    void UpdateTable();

private:
    Ui::MainWindow *ui;

    QVector<Zakaz> zakazes;
    QVector<Courier> courieres;
    QVector<Zakaz> bad_zakazes;

    QStringList headers;

    QString opened_zakaz_file_string;
    QString opened_courier_file_string;

    QGridLayout *layout;
    QTableWidget *zakaz_table;
    QTableWidget *bad_zakaz_table;
    QTableWidget *courier_table;
    QWidget *central_widget;

    QLabel *constructor_zakaz_label;
    QLabel *constructor_courier_label;

    QLineEdit *number_zakaz_edit;
    QLineEdit *adress_zakaz_edit;
    QLineEdit *data_zakaz_edit;
    QLineEdit *time_zakaz_edit;
    QLineEdit *massa_zakaz_edit;

    QLineEdit *number_courier_edit;
    QLineEdit *fio_courier_edit;
    QLineEdit *begin_time_courier_edit;
    QLineEdit *end_time_courier_edit;
    QLineEdit *min_mass_courier_edit;

    QPushButton *add_zakaz_button;
    QPushButton *add_courier_button;

    QLabel *change_label;

    QLineEdit *change_zakaz_edit;
    QLineEdit *change_courier_edit;

    QPushButton *change_zakaz_button;
    QPushButton *change_courier_button;

    QLabel *delete_label;

    QPushButton *delete_zakaz_button;
    QPushButton *delete_courier_button;

    QPushButton *new_file_zakaz_button;
    QPushButton *close_file_zakaz_button;
    QPushButton *open_table_zakaz_button;

    QPushButton *new_file_courier_button;
    QPushButton *close_file_courier_button;
    QPushButton *open_table_courier_button;

    QLabel *opened_zakaz_file_label;
    QLabel *opened_courier_file_label;
};
#endif // MAINWINDOW_H
