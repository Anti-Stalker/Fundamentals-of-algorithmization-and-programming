#ifndef CUSTOMTEXTEDIT_H
#define CUSTOMTEXTEDIT_H

#include <QTextEdit>

class CustomTextEdit : public QTextEdit
{
    Q_OBJECT

public:
    explicit CustomTextEdit(QWidget *parent = nullptr);

protected:
    void focusInEvent(QFocusEvent *e) override;

private:
    bool isFirstFocus;
};

#endif // CUSTOMTEXTEDIT_H
