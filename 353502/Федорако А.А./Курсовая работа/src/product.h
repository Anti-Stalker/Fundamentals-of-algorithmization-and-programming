#ifndef PRODUCT_H
#define PRODUCT_H

#include <QPixmap>

class Product
{
public:
    Product();
    Product(QString name, double* arrCost, QString file, QString category, QString subcategory);
    double* getArrPrice();
    double getBestPrice();
    QString getName();
    QPixmap getPicture();
    QString getFileName();
    bool getIsProduct();
private:
    bool isProduct;
    QString file;
    QString name;
    QString category;
    double* arrCost;
    QPixmap picture;
};

#endif // PRODUCT_H
