#ifndef CUSTOMLINEEDIT_H
#define CUSTOMLINEEDIT_H

#include <QLineEdit>

class CustomLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    explicit CustomLineEdit(QWidget *parent = nullptr);

public:
    void focusInEvent(QFocusEvent *e) override;
signals:
    void focusIn();

private:
    bool isFirstFocus;
};

#endif // CUSTOMLINEEDIT_H
