#ifndef PROJECTAPPEARANCE_H
#define PROJECTAPPEARANCE_H

#include <QFont>
#include <QLabel>
#include <QGroupBox>
#include <QPushButton>

class ProjectAppearance
{
public:
    ProjectAppearance();
    static void setSettingFontPrice(QVector<QLabel*> arrLabelPrice);
    static void setCorrectFontPrice(QFont* fontPrice);
    static void setSettingButtonsOpenProductWidget(QVector<QPushButton*> arrButtonOpenProductWidget);
    static void setSettingFontName(QVector<QGroupBox*> arrGroupBox);
    static void setCorrectFontName(QFont* fontPrice);
    static void setSettingFontPicture(QVector<QLabel*> arrLabelPicture);
};

#endif // PROJECTAPPEARANCE_H
