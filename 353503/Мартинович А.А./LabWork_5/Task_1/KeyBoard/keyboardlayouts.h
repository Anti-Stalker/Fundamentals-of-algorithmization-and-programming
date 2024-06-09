#ifndef KEYBOARDLAYOUTS_H
#define KEYBOARDLAYOUTS_H
#include "QMap"
#include "QString"
#include "QRectF"

class KeyboardLayouts
{
public:
    static QMap<int, QRectF> getKeyRects();
    static QMap<int, QPair<QString, QString>> getLayout(QString lang);
    static QMap<int, QPair<int, int>> getButtonId(QString lang);
};

#endif // KEYBOARDLAYOUTS_H
