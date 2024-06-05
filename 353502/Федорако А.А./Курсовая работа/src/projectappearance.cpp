#include "projectappearance.h"

ProjectAppearance::ProjectAppearance() {
}

void ProjectAppearance::setSettingFontPrice(QVector<QLabel*> arrLabelPrice) {
    QFont* fontPrice = new QFont();
    setCorrectFontPrice(fontPrice);
    for(int i = 0; i < 6; i++) {
        arrLabelPrice[i]->setFont(*fontPrice);
    }
}

void ProjectAppearance::setCorrectFontPrice(QFont* fontPrice) {
    fontPrice->setPointSize(14);
    fontPrice->setWeight(QFont::Bold);
}

void ProjectAppearance::setSettingButtonsOpenProductWidget(QVector<QPushButton*> arrButtonOpenProductWidget) {
    for(int i = 0; i < 6; i++) {
        arrButtonOpenProductWidget[i]->setStyleSheet("QPushButton{background: transparent;}");
    }
}



void ProjectAppearance::setSettingFontName(QVector<QGroupBox*> arrGroupBox) {
    QFont* fontName = new QFont();
    setCorrectFontName(fontName);
    for(int i = 0; i < 6; i++) {
        arrGroupBox[i]->setFont(*fontName);
    }
}

void ProjectAppearance::setCorrectFontName(QFont* fontName) {
    fontName->setPointSize(8);
    fontName->setWeight(QFont::Bold);
}

void ProjectAppearance::setSettingFontPicture(QVector<QLabel*> arrLabelPicture) {
    for(int i = 0; i < 6; i++) {
        arrLabelPicture[i]->setAlignment(Qt::AlignCenter);
    }
}
