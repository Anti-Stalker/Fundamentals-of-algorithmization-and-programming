#include "customtextedit.h"

CustomTextEdit::CustomTextEdit(QWidget *parent)
    : QTextEdit(parent), isFirstFocus(true)
{
    setText("Enter possible artists (1 per line)...");
}

void CustomTextEdit::focusInEvent(QFocusEvent *e)
{
    if (isFirstFocus) {
        clear();
        isFirstFocus = false;
    }
    QTextEdit::focusInEvent(e);
}
