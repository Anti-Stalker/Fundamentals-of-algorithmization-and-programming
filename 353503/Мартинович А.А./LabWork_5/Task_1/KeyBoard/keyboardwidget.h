#ifndef KEYBOARDWIDGET_H
#define KEYBOARDWIDGET_H

#include "QWidget"
#include "QPainter"
#include "QKeyEvent"
#include "QDebug"
#include "QMap"

class KeyboardWidget : public QWidget
{
    Q_OBJECT

private:
    const int button_count = 55;
    int pressed_button_id = -1;
    bool shift_pressed = false;
    const int key_width = 50;
    const int key_height = 50;
    const int dist_height = 10;
    const int dist_width = 10;


    QMap<int, QRectF> button_id_rect;
    QMap<int, QPair<QString, QString>> button_id_symb;

public:
    explicit KeyboardWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event) override;

    void drawKey(int id, bool press = false);

    void drawPressedKey(int id);

    void setPressButton(QString str);

    void setLanguage(const QString lang);

protected:


signals:

};

#endif // KEYBOARDWIDGET_H
