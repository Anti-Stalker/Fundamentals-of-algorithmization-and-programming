#ifndef DATA_H
#define DATA_H

#include "product.h"
#include <QMap>
#include "stringprocessing.h"
#include <QDateTime>
#include <QRandomGenerator>
#include <QPair>
#include <QSqlDatabase>
#include <QSqlQuery>

class Data
{
public:
    Data();
    void setPopularProduct(QString _category, QString _subcategory);
    QVector<Product*> product;
    void setProduct(QString _category, QString _subcategory);
    void setProduct(QString _category, QString _subcategory, QString _substr);
    QRandomGenerator* randomGenerator;
    QVector<QVector<QString>> ArrSubcategory;
    int getNumberNameCategory(QString category);
    void deleteNoProduct();
    void doProductMultiples();
    QStringList getWordList(QString category, QString subcategory);
    QVector<QStringList> wordListCategory;
private:
    void setWordListCategory();
    Product* getProductFromData();
    const int RANGE = 20;
    const int NUMBER_CATEGORY = 7;
    const int NUMBER_SUBCATEGORY = 51;
    const int ARR_SIZE_CATEGORY[7] = {8, 10, 1, 3, 5, 2, 12};
    const QString ARR_CAREGORY[7] = {"Вода, напитки, соки, кофе и чай", "Бакалея", "Овощи и фрукты", "Мучные кондитерские изделия", "Сахарные кондитерские изделия", "Замороженные продукты", "Молочные продукты, яйца"};
    std::map<QString, QPair<int, int>> mapCategory = {{"Вода, напитки, соки, кофе и чай", QPair<int, int>(1, 360)},
        {"Бакалея", QPair<int, int>(360, 853)},
        {"Овощи и фрукты", QPair<int, int>(853, 858)},
        {"Мучные кондитерские изделия", QPair<int, int>(858, 992)},
        {"Сахарные кондитерские изделия", QPair<int, int>(992, 1217)},
        {"Замороженные продукты", QPair<int, int>(1217, 1307)},
        {"Молочные продукты, яйца", QPair<int, int>(1307, 1830)}
    };
    QSqlDatabase db;
    QSqlQuery* query;
};

#endif // DATA_H
