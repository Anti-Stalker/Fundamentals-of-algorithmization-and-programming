#include "dynamictext.h"
#include "QKeyEvent"
#include "QVBoxLayout"
#include "QRegularExpression"
#include "QFileDialog"

DynamicText::DynamicText(QWidget *parent)
    : QWidget{parent},
      text_label(new QLabel(this))
{
    text_label->setStyleSheet("border: 1px solid black;"
                              "letter-spacing: 0px;"
                              "font-family: monospace;");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(text_label, 0, Qt::AlignCenter);

    text_label->setFixedWidth(875);

    QFont font = text_label->font();
    font.setPointSize(40);
    text_label->setFont(font);
}

void DynamicText::showText()
{

    QString txt = "";
    int hz = line_size / 2;
    int ez = entered_text.size();
    int tz = temp_text.size();

    for (int i = 0; i < hz-ez; ++i) {
        txt += QString("<span style='color: gray;'>&nbsp;</span>");
    }

    int s = (ez < hz)?0:ez- hz;
    int m = (ez < hz)?ez:ez;
    int e = (ez + hz < tz)?ez + hz:tz;

    for (int i = s; i < m; i++) {

        if (entered_text[i] == temp_text[i]) {
            if (entered_text[i] == ' ') {
                txt += QString("<span style='background-color: LightGreen;'>&nbsp;</span>");
            }
            else {
                txt += QString("<span style='background-color: LightGreen;'>%1</span>").arg(temp_text[i]);
            }
        }
        else {
            txt += QString("<span style='background-color: LightCoral;'>%1</span>").arg(temp_text[i]);
        }
    }
    for (int i = m; i < e; i++) {
        if (temp_text[i] == ' ') {
            txt += QString("<span style='color: gray;'>&nbsp;</span>");
        }
        else {
            txt += QString("<span style='color: gray;'>%1</span>").arg(temp_text[i]);
        }
    }

    text_label->setText(txt);
}

void DynamicText::setTemplate(QString txt)
{
    txt.replace("\n", " ");
    txt.replace("\t", " ");
    entered_text = "";
    temp_text = txt;
    emit TextChangedSignal(temp_text[entered_text.size()]);
}

void DynamicText::keyPress(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Backspace && entered_text.size() >= 0) {
        entered_text.remove(entered_text.size()-1, 1);
    }
    else if (entered_text.size() < temp_text.size()){
        entered_text += event->text();
    }

    if (entered_text.size() < temp_text.size()) {
        emit TextChangedSignal(temp_text[entered_text.size()]);
    }

    showText();
}

int DynamicText::getWordCount() {
    int sz = entered_text.size();
    QString txt = temp_text.left(sz);
    QStringList words = txt.split(QRegularExpression("\\s+"));
    int c = 0;
    for (auto w: words) {
        if (w != "") {
            c++;
        }
    }
    return c;
}

int DynamicText::getSymbCount()
{
    return entered_text.size();
}

int DynamicText::getAccuracy()
{
    double ac = 0;
    for (int i = 0; i < entered_text.size(); i++) {
        if (temp_text[i] == entered_text[i]) {
            ac++;
        }
    }
    return (ac)?ac/entered_text.size() * 100:0;
}

bool DynamicText::isEnd()
{
    return temp_text.size() == entered_text.size();
}
