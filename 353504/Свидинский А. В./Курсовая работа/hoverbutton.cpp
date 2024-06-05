    #include "hoverbutton.h"
    #include <QPropertyAnimation>

    HoverButton::HoverButton(QWidget *parent) : QPushButton(parent) {}

    void HoverButton::enterEvent(QEnterEvent *event) {
        emit hovered();
        QPushButton::enterEvent(event);
    }

    void HoverButton::leaveEvent(QEvent *event) {
        emit unhovered();
        QPushButton::leaveEvent(event);
    }


