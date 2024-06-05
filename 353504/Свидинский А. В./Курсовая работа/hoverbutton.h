#ifndef HOVERBUTTON_H
#define HOVERBUTTON_H

#include <QPushButton>
#include <QWidget>
#include <QEvent>

class HoverButton : public QPushButton {
    Q_OBJECT
public:
    explicit HoverButton(QWidget *parent = nullptr);

signals:
    void hovered();
    void unhovered();

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
};

#endif // HOVERBUTTON_H
