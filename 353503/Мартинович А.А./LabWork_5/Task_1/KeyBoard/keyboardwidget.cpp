#include "keyboardwidget.h"
#include "keyboardlayouts.h"
#include "QRandomGenerator"
#include "iostream"
#include "QFileDialog"

KeyboardWidget::KeyboardWidget(QWidget *parent)
    : QWidget{parent}
{
    button_id_rect = KeyboardLayouts::getKeyRects();
    button_id_symb = KeyboardLayouts::getLayout("russian");

    setFixedSize(900, 310);
}


void KeyboardWidget::setPressButton(QString str)
{
    for (auto k: button_id_rect.keys()) {
        if (button_id_symb[k].first == str) {
            pressed_button_id = k;
            shift_pressed = false;
        }
        else if (button_id_symb[k].second == str) {
            pressed_button_id = k;
            shift_pressed = true;
        }
    }
    update();
}

void KeyboardWidget::setLanguage(const QString lang)
{
    button_id_symb = KeyboardLayouts::getLayout(lang);
    update();
}

void KeyboardWidget::paintEvent(QPaintEvent *event) {
    for (int i = 0; i < button_count; i++) {
        drawKey(i);
    }
    drawKey(pressed_button_id, true);
}

void KeyboardWidget::drawKey(int id, bool press)
{
    QPainter painter(this);
    if (press) {
        QBrush brush(Qt::red, Qt::SolidPattern);
        painter.setBrush(brush);
    }
    QRectF rect = button_id_rect[id];

    QPointF cp(rect.x() + rect.width() * 0.2, rect.y() + rect.height() * 0.4);
    QPointF lc(rect.x() + rect.width() * 0.5, rect.y() + rect.height() * 0.7);

    painter.drawRect(rect);
    painter.drawText(cp, button_id_symb[id].first);
    painter.drawText(lc, button_id_symb[id].second);

    if (shift_pressed) {
        QRectF rect = button_id_rect[41];
        QPointF cp(rect.x() + rect.width() * 0.2, rect.y() + rect.height() * 0.4);
        painter.drawRect(rect);
        painter.drawText(cp, button_id_symb[41].first);
    }
}


