#include "data.h"

Data::Data() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./product.db");

    if(!db.open()) {
        qDebug() << "Error QSQLite";
    }
    randomGenerator = new QRandomGenerator(QDateTime::currentMSecsSinceEpoch());
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Products (id INTEGER PRIMARY KEY, name TEXT NOT NULL, category TEXT NOT NULL, picture TEXT NOT NULL, url TEXT NOT NULL, first_price TEXT NOT NULL, second_price TEXT NOT NULL, third_price TEXT NOT NULL, fourth_price TEXT NOT NULL, fifth_price TEXT NOT NULL, sixth_price TEXT NOT NULL, seventh_price TEXT NOT NULL)");
    ArrSubcategory = {{"Вода минеральная, питьевая", "Чай, чайные напитки", "Напитки, напитки сокосодержащие", "Кофе в зернах", "Кофе молотый", "Кофе растворимый", "Соки, нектары, морсы, сиропы", "Энергетические напитки"},
                      {"Мука, мучные смеси", "Макаронные изделия","Крупы", "Консервация овощная, грибная", "Консервы мясные и мясорастительные", "Орехи, сухофрукты",  "Растительное масло, заправки, уксус", "Готовые завтраки, хлопья и каши быстрого приготовления", "Семечки", "Сахар и заменители, соль, крахмал, сода и прочие добавки", "Специи, приправы, пряности"},
                      {"Фрукты, ягоды"},
                      {"Вафли", "Мучные кондитерские изделия, в том числе без глютена", "Печенье, пряничные изделия"},
                      {"Жевательная резинка, освежающие конфеты", "Конфеты шоколадные в коробках", "Конфеты, карамель, драже, ирис", "Халва, зефир, мармелад, суфле, пастила", "Шоколад, шоколадные батончики"},
                      {"Блинчики, пиццы и основы, лазанья, тесто и прочее (замороженные)", "Пельмени, вареники, чебуреки, равиоли, клецки и прочее (замороженные)"},
                      {"Йогурты густые", "Йогурты питьевые, молочные коктейли и напитки (сладкие)", "Молоко",
                        "Молоко сгущенное и концентрированное", "Сыры твердые", "Творога зерненые (с наполнителем)",
                        "Масло сливочное", "Кефир", "Мороженое порционное", "Сырки глазированные, творожные торты",
                        "Творога зерненые (без наполнителей)", "Яйца куриные"}};
    setPopularProduct("Категории", "Подкатегории");
    setWordListCategory();
}

void Data::setProduct(QString _category, QString _subcategory) {
    product.clear();
    if(_category == "Категории") {
        query->exec("SELECT * FROM Products");
        while (query->next()) {
            QString name = query->value(1).toString();
            QString category = query->value(2).toString();
            QString subcategory = query->value(3).toString();
            QString file = query->value(4).toString();
            double* price = new double[7];
            for(int i = 0; i < 7; i++) {
                bool ok;
                QString number = query->value(6+i).toString();
                if(number == '-') {
                    price[i] = -1;
                }
                else {
                    price[i] = number.toDouble(&ok);
                }
            }
            product.push_back(new Product(name, price, file, category, subcategory));
        }
    }
    else if(_category != "Категории" && _subcategory == "Подкатегории") {
        auto it = mapCategory.find(_category);
        if (it != mapCategory.end()){
            int start = it->second.first;
            int i = 0;
            int end = it->second.second;
            while (start < end && i < 42) {
                i++;
                query->exec("SELECT * FROM Products WHERE id = " + QString::number(start));
                query->next();
                QString name = query->value(1).toString();
                QString category = query->value(2).toString();
                QString subcategory = query->value(3).toString();
                QString file = query->value(4).toString();
                double* price = new double[7];
                for(int i = 0; i < 7; i++) {
                    bool ok;
                    QString number = query->value(6+i).toString();
                    if(number == '-') {
                        price[i] = -1;
                    }
                    else {
                        price[i] = number.toDouble(&ok);
                    }
                }
                product.push_back(new Product(name, price, file, category, subcategory));
                start++;
            }
        }       
    }
    else if(_category != "Категории" && _subcategory != "Подкатегории") {
        query->exec("SELECT * FROM Products WHERE subcategory = '" + _subcategory + "'");
        while (query->next()) {
            QString name = query->value(1).toString();
            QString category = query->value(2).toString();
            QString subcategory = query->value(3).toString();
            QString file = query->value(4).toString();
            double* price = new double[7];
            for(int i = 0; i < 7; i++) {
                bool ok;
                QString number = query->value(6+i).toString();
                if(number == '-') {
                    price[i] = -1;
                }
                else {
                    price[i] = number.toDouble(&ok);
                }
            }
            product.push_back(new Product(name, price, file, category, subcategory));
        }
    }
    doProductMultiples();
}

void Data::setProduct(QString _category, QString _subcategory, QString _substr) {
    if(_substr == "") {
        setPopularProduct(_category, _subcategory);
    }
    else {
        product.clear();
        if(_category == "Категории") {
            query->exec("SELECT * FROM Products");
            while (query->next()) {
                QString name = query->value(1).toString();
                if(StringProcessing::searchKMP(name, _substr)){
                    QString category = query->value(2).toString();
                    QString subcategory = query->value(3).toString();
                    QString file = query->value(4).toString();
                    double* price = new double[7];
                    for(int i = 0; i < 7; i++) {
                        bool ok;
                        QString number = query->value(6+i).toString();
                        if(number == '-') {
                            price[i] = -1;
                        }
                        else {
                            price[i] = number.toDouble(&ok);
                        }
                    }
                    product.push_back(new Product(name, price, file, category, subcategory));
                }
            }
        }
        else if(_category != "Категории" && _subcategory == "Подкатегории") {
            auto it = mapCategory.find(_category);
            if (it != mapCategory.end()){
                int start = it->second.first;
                int end = it->second.second;
                while (start < end) {
                    query->exec("SELECT * FROM Products WHERE id = " + QString::number(start));
                    query->next();
                    QString name = query->value(1).toString();
                    if(StringProcessing::searchKMP(name, _substr))
                    {
                        QString category = query->value(2).toString();
                        QString subcategory = query->value(3).toString();
                        QString file = query->value(4).toString();
                        double* price = new double[7];
                        for(int i = 0; i < 7; i++) {
                            bool ok;
                            QString number = query->value(6+i).toString();
                            if(number == '-') {
                                price[i] = -1;
                            }
                            else {
                                price[i] = number.toDouble(&ok);
                            }
                        }
                        product.push_back(new Product(name, price, file, category, subcategory));
                    }
                    start++;
                }
            }
        }
        else if(_category != "Категории" && _subcategory != "Подкатегории") {
            query->exec("SELECT * FROM Products WHERE subcategory = '" + _subcategory + "'");
            while (query->next()) {
                QString name = query->value(1).toString();
                if(StringProcessing::searchKMP(name, _substr)) {

                    QString category = query->value(2).toString();
                    QString subcategory = query->value(3).toString();
                    QString file = query->value(4).toString();
                    double* price = new double[7];
                    for(int i = 0; i < 7; i++) {
                        bool ok;
                        QString number = query->value(6+i).toString();
                        if(number == '-') {
                            price[i] = -1;
                        }
                        else {
                            price[i] = number.toDouble(&ok);
                        }
                    }
                    product.push_back(new Product(name, price, file, category, subcategory));
                }
            }
        }
        doProductMultiples();
    }
}

void Data::setPopularProduct(QString _category, QString _subcategory) {
    QSet<int> set;
    product.clear();
    if(_category == "Категории") {
        while(set.size() < 42) {
            int numberCategory = randomGenerator->bounded(0, NUMBER_CATEGORY);
            int numberSubcategory = randomGenerator->bounded(0, ARR_SIZE_CATEGORY[numberCategory]);
            QString subcategory = ArrSubcategory[numberCategory][numberSubcategory];
            int numberRandom = randomGenerator->bounded(0, RANGE);
            query->exec("SELECT id FROM Products WHERE subcategory = '" + subcategory + "'");
            query->next();
            int numberFirstElement = query->value(0).toInt() + numberRandom;
            set.insert(numberFirstElement);
        }
        for (QSet<int>::iterator it = set.begin(); it != set.end(); ++it) {
            query->exec("SELECT * FROM Products WHERE id = " + QString::number(*it));
            product.push_back(getProductFromData());
        }
    }
    else if(_category != "Категории" && _subcategory == "Подкатегории") {
        auto it = mapCategory.find(_category);
        if (it != mapCategory.end()) {
            int start = it->second.first;
            int end = it->second.second;
            if(end - start < 2 * 40) {
                setProduct(_category, _subcategory);
            }
            else {
                while (set.size() < 40) {
                    int numberCategory = getNumberNameCategory(_category);
                    int numberSubcategory = randomGenerator->bounded(0, ARR_SIZE_CATEGORY[numberCategory]);
                    QString subcategory = ArrSubcategory[numberCategory][numberSubcategory];
                    int numberRandom = randomGenerator->bounded(0, RANGE);
                    query->exec("SELECT * FROM Products WHERE subcategory = '" + subcategory + "'");
                    query->next();
                    int numberFirstElement = query->value(0).toInt() + numberRandom;
                    set.insert(numberFirstElement);
                }
            }
        }
        for (QSet<int>::iterator it = set.begin(); it != set.end(); ++it) {
            query->exec("SELECT * FROM Products WHERE id = " + QString::number(*it));
            product.push_back(getProductFromData());
        }
    }
    else if(_category != "Категории" && _subcategory != "Подкатегории") {
        setProduct(_category, _subcategory);
    }
    doProductMultiples();
}

void Data::doProductMultiples() {
    while(product.size() % 6 != 0) {
        product.push_back(new Product());
    }
}

void Data::deleteNoProduct() {
    while(!product.isEmpty() && product.back()->getBestPrice() == -1) {
        product.pop_back();
    }
}

Product* Data::getProductFromData() {
    query->next();
    QString name = query->value(1).toString();
    QString category = query->value(2).toString();
    QString subcategory = query->value(3).toString();
    QString file = query->value(4).toString();
    double* price = new double[7];
    for(int i = 0; i < 7; i++) {
        bool ok;
        QString number = query->value(6+i).toString();
        if(number == '-') {
            price[i] = -1;
        }
        else {
            price[i] = number.toDouble(&ok);
        }
    }
    return new Product(name, price, file, category, subcategory);
}
int Data::getNumberNameCategory(QString category) {
    for(int i = 0; i < 7; i++) {
        if(ARR_CAREGORY[i] == category) {
            return i;
        }
    }
    return -1;
}

void Data::setWordListCategory() {
    QStringList list;
    query->exec("SELECT name FROM Products");
    while(query->next()) {
        list.push_back(query->value(0).toString());
    }
    wordListCategory.push_back(list);
    for(int i = 0; i < 7; i++) {
        QStringList list;
        query->exec("SELECT name FROM Products WHERE category = '" + ARR_CAREGORY[i] + "'");
        while(query->next()) {
            list.push_back(query->value(0).toString());
        }
        wordListCategory.push_back(list);
    }
}

QStringList Data::getWordList(QString category, QString subcategory) {
    if(subcategory == "Подкатегории") {
        if(category == "Категории") {
            return wordListCategory[0];
        }
        else {
            for(int i = 0; i < 7; i++) {
                if(ARR_CAREGORY[i] == category) {
                    return wordListCategory[i + 1];
                }
            }
        }
    }
    return QStringList();
}
