#include "stringprocessing.h"

StringProcessing::StringProcessing() {

}

bool StringProcessing::searchKMP(QString line, QString subline) {
    line = line.toLower();
    subline = subline.toLower();
    QVector<int> arrFunctionPrefixSuffix;
    for(int i = 1; i < subline.size() + 1; i++) {
        QString sublineCheckPostfixSuffix = subline.mid(0, i);
        int setValue = 0;
        for(int t = 1; t < sublineCheckPostfixSuffix.size(); t++) {
            if(sublineCheckPostfixSuffix.mid(0, t) ==
                sublineCheckPostfixSuffix.mid(sublineCheckPostfixSuffix.size() - t, sublineCheckPostfixSuffix.size() + 1)) {
                setValue = t;
            }
        }
        arrFunctionPrefixSuffix.push_back(setValue);
    }
    int i = 0;
    int t = 0;
    while ((line.size() - i) >= (subline.size() - t)) {
        if (subline[t] == line[i]) {
            t++;
            i++;
        }
        if (t == subline.size()) {
            return 1;
        }
        else if (i < line.size() && subline[t] != line[i]) {
            if (t != 0)
                t = arrFunctionPrefixSuffix[t - 1];
            else
                i = i + 1;
        }
    }
    return false;
}

QString StringProcessing::additionPrice(QString price) {
    bool isDot = false;
    int i = 0;
    for(; i < price.size(); i++) {
        if(price[i] == '.'){
            isDot = true;
            break;
        }
    }
    if(isDot && price.size() - i <= 2) {
        return price + "0";
    }
    else if(!isDot){
        return price + ".00";
    }
    return price;
}

