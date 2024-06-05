#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QWidget>
#include <QDir>
#include <QPalette>
#include <QRadioButton>
#include <QSignalMapper>
#include "basketwidget.h"
#include "productwidget.h"
#include "product.h"
#include "data.h"
#include <QCompleter>
#include "projectappearance.h"
#include "stringprocessing.h"
#include "productsort.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QStringList* wordList;
    void updateCompleter();
    QVector<QStringList*> wordListCategory;
    QWidget *mainWidget;
    ProductWidget *productWidget;
    BasketWidget *basketWidget;
    const QString DIRECTORY_IMAGE = "/image/";
    Data* data;
    Product* arrProductMainWindow[6];
    int numberPage;
    int numberAllPage;
    QString search;
    void updatePage();
    QString path;
    QCompleter *completer;
    QVector<QLabel*> arrLabelPrice;
    QVector<QLabel*> arrLabelPicture;
    QVector<QPushButton*> arrButtonOpenProductWidget;
    QVector<QPushButton*> arrButtonAddProductBasket;
    QVector<QGroupBox*> arrGroupBox;
    Ui::MainWindow *ui;
    QString category;
    QString subcategory;
    int numberSort;
private slots:
    void updateVisibleButton();
    void newCategory(int number);
    void newSubcategory(int number);
    void fillAllWidget();
    void fillArrLabelPrice();
    void fillArrLabelPicture();
    void fillArrButtonOpenProductWidget();
    void fillArrButtonAddProductBasket();
    void fillArrGroupBox();
    void fillComboBox();
    void nextPage();
    void previousPage();
    void setSettingAllWidget();
    void updateDataMainWindow();
    void updateProductsMainWindow();
    void setInformationSomeProduct(int number, Product* product);
    void on_buttonAddProduct_1_clicked();
    void on_buttonAddProduct_2_clicked();
    void on_buttonAddProduct_3_clicked();
    void on_buttonAddProduct_4_clicked();
    void on_buttonAddProduct_5_clicked();
    void on_buttonAddProduct_6_clicked();
    void on_buttonSearchProduct_clicked();
    void on_buttonOpenWidget_1_clicked();
    void on_buttonOpenWidget_2_clicked();
    void on_buttonOpenWidget_3_clicked();
    void on_buttonOpenWidget_4_clicked();
    void on_buttonOpenWidget_5_clicked();
    void on_buttonOpenWidget_6_clicked();
    void on_radioIncreasingName_clicked();
    void on_radioReductionName_clicked();
    void on_radioIncreasingPrice_clicked();
    void on_radioReductionPrice_clicked();
    void on_pushButton_clicked();
    void sortProduct();
    void on_radioPopularProduct_clicked();
protected:
    void keyPressEvent(QKeyEvent *event) override;
};
#endif // MAINWINDOW_H
