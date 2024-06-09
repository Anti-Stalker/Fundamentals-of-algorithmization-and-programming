#ifndef DYNAMICTEXT_H
#define DYNAMICTEXT_H
#include "QWidget"
#include "QLineEdit"
#include "QLabel"

class DynamicText : public QWidget
{
    Q_OBJECT
public:
    explicit DynamicText(QWidget *parent = nullptr);
    void showText();
    void setTemplate(QString txt);
    void delSymb(QString symb);
    void keyPress(QKeyEvent *event);
    int getWordCount();
    int getSymbCount();
    int getAccuracy();
    bool isEnd();

signals:
    void TextChangedSignal(QString str);

protected:
    QLabel *text_label;

private:
    QString temp_text;
    QString entered_text{};
    int line_size = 30;

};

#endif // DYNAMICTEXT_H
