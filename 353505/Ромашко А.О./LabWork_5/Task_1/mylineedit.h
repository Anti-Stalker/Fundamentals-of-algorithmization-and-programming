#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H


#include <QLineEdit>
#include <QPushButton>
#include <QObject>
#include <QKeyEvent>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    MyLineEdit(QWidget *parent = nullptr);

    void setHintText(QString hintText, int i);

    void keyPressEvent(QKeyEvent *event) override;

    void keyPressResult(int res);

signals:
    void resultSignal(int result);
    void pressResult(QString hintChar);

private:
    QString hintText;
    QString Buf;
    int i = 0;
};
#endif // MYLINEEDIT_H
