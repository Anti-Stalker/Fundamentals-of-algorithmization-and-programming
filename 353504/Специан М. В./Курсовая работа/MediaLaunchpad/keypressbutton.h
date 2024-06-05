#ifndef KEYPRESSBUTTON_H
#define KEYPRESSBUTTON_H

#include <QPushButton>
#include <QShortcut>

class KeyPressButton : public QPushButton
{
    Q_OBJECT

public:
    explicit KeyPressButton(const QString& text,const QString& keyShortcut, QWidget* parent = nullptr);

signals:
    void keyPressed();

private:
    QShortcut* shortcut;
};

#endif // KEYPRESSBUTTON_H
