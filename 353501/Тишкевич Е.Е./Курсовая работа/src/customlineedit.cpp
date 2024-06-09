#include "customlineedit.h"

CustomLineEdit::CustomLineEdit(QWidget *parent)
    : QLineEdit(parent), isFirstFocus(true)
{
    setText("Enter search text...");
}

void CustomLineEdit::focusInEvent(QFocusEvent *e)
{
    if (isFirstFocus) {
        clear();
        isFirstFocus = false;
    }
    QLineEdit::focusInEvent(e);
    emit focusIn();
}
