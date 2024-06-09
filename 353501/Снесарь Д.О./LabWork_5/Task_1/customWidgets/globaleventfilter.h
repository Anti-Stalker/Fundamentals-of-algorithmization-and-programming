// GlobalEventFilter.h

#ifndef GLOBALEVENTFILTER_H
#define GLOBALEVENTFILTER_H

#include <QObject>
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>

class GlobalEventFilter : public QObject {
    Q_OBJECT
public:
    explicit GlobalEventFilter(QObject *parent = nullptr) : QObject(parent) {}

protected:
    bool eventFilter(QObject *obj, QEvent *event) override {
        if (event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            qDebug() << "Global Key Press Event:" << keyEvent->text()
                     << "Key code:" << keyEvent->key()
                     << "Native scan code:" << keyEvent->nativeScanCode();

            // Можно эмитировать сигнал или обрабатывать глобальные горячие клавиши
            // Не останавливаем событие, возвращаем false
        }
        return QObject::eventFilter(obj, event);
    }
};

#endif // GLOBALEVENTFILTER_H
