#include "keypressbutton.h"
#include <QKeyEvent>
KeyPressButton::KeyPressButton(const QString& text, const QString& keyShortcut, QWidget* parent)
    : QPushButton(text, parent)
{
    shortcut = new QShortcut(QKeySequence(keyShortcut), this);
    connect(shortcut, &QShortcut::activated, this, &KeyPressButton::keyPressed);
}
