#include "product.h"

Product::Product() {
    this->name = "";
    this->arrCost = new double[8] {-1,-1,-1,-1,-1,-1,-1,-1};
    this->category = "";
    this->file = "";
    isProduct = false;
    picture = QPixmap();
}

Product::Product(QString name, double* arrCost, QString file, QString category, QString subcategory) {
    this->name = name;
    this->arrCost = arrCost;
    this->category = category;
    this->file = file;
    picture = QPixmap("./image/" + file);
    isProduct = !(name == "");
}

QPixmap Product::getPicture() {
    return picture;
}

QString Product::getFileName() {
    return file;
}
double* Product::getArrPrice() {
    return arrCost;
}

QString Product::getName() {
    return name;
}

bool Product::getIsProduct() {
    return isProduct;
}
double Product::getBestPrice() {
    double result = 1e20;
    bool isProduct = false;
    for(int i = 0; i < 7; i++) {
        if(arrCost[i] >= 0) {
            isProduct = true;
            result = qMin(result, arrCost[i]);
        }
    }
    return (isProduct ? result : -1);
}
