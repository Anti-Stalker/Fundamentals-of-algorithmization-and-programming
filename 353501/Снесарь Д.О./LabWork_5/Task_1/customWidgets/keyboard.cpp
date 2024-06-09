#include "keyboard.h"
#include "ui_keyboard.h"

keyboard::keyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::keyboard)
{
    ui->setupUi(this);

    buttonsMap = QMap<int, QPushButton*>{
        {49, ui->pushButton_49},
        {10, ui->pushButton_10},
        {11, ui->pushButton_11},
        {12, ui->pushButton_12},
        {13, ui->pushButton_13},
        {14, ui->pushButton_14},
        {15, ui->pushButton_15},
        {16, ui->pushButton_16},
        {17, ui->pushButton_17},
        {18, ui->pushButton_18},
        {19, ui->pushButton_19},
        {20, ui->pushButton_20},
        {21, ui->pushButton_21},
        {24, ui->pushButton_24},
        {25, ui->pushButton_25},
        {26, ui->pushButton_26},
        {27, ui->pushButton_27},
        {28, ui->pushButton_28},
        {29, ui->pushButton_29},
        {30, ui->pushButton_30},
        {31, ui->pushButton_31},
        {32, ui->pushButton_32},
        {33, ui->pushButton_33},
        {34, ui->pushButton_34},
        {35, ui->pushButton_35},
        {51, ui->pushButton_51},
        {38, ui->pushButton_38},
        {39, ui->pushButton_39},
        {40, ui->pushButton_40},
        {41, ui->pushButton_41},
        {42, ui->pushButton_42},
        {43, ui->pushButton_43},
        {44, ui->pushButton_44},
        {45, ui->pushButton_45},
        {46, ui->pushButton_46},
        {47, ui->pushButton_47},
        {48, ui->pushButton_48},
        {50, ui->pushButton_50},
        {52, ui->pushButton_52},
        {53, ui->pushButton_53},
        {54, ui->pushButton_54},
        {55, ui->pushButton_55},
        {56, ui->pushButton_56},
        {57, ui->pushButton_57},
        {58, ui->pushButton_58},
        {59, ui->pushButton_59},
        {60, ui->pushButton_60},
        {61, ui->pushButton_61},
        {62, ui->pushButton_62},
        {65, ui->pushButton_65},
        {66, ui->pushButton_66},
    };

    for (auto button : buttonsMap.values()) {
        connect(button, &QPushButton::clicked, this, &keyboard::handleButtonClicked);
      //  button->setEnabled(true);
    }
    initSymbols();
    setSymbols();
  //  setFocusPolicy(Qt::StrongFocus);
}

keyboard::~keyboard()
{
    delete ui;
}

void keyboard::handleButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    int buttonIndex = buttonsMap.key(button);
    qDebug() << buttonIndex;

    if (keyCodeNum.contains(buttonIndex))
    {
        int keyCode = keyCodeNum.value(buttonIndex);

        QKeyEvent *keyEvent = new QKeyEvent(QEvent::KeyPress, keyCode, Qt::NoModifier, QString());


        QCoreApplication::postEvent(parentWidget(), keyEvent);
    }
}
void keyboard::keyPressEventK(QKeyEvent *event)
{

    int key = event->nativeScanCode();

    if (key == 66)
    {
        isCaps = !isCaps;
        this->setLocale(curLocale);
    }

    if (buttonsMap.contains(key)) {
        QPushButton *button = buttonsMap[key];
        button->setStyleSheet("background-color: green");
        QTimer::singleShot(100, button, [button]() {
            button->setStyleSheet("");
        });

        return;
    }
    key = event->text().toInt();
    if (buttonsMap.contains(key)) {
        QPushButton *button = buttonsMap[key];
        button->setStyleSheet("background-color: green");
        QTimer::singleShot(100, button, [button]() {
            button->setStyleSheet("");
        });
    }
    if (key >= 1 && key <= 66) {
        QPushButton* button = buttonsMap[key];
        if (button != nullptr) {
            button->setStyleSheet("background-color: green");
            QTimer::singleShot(100, button, [button]() {
                button->setStyleSheet("");
            });

        }
    }

}

void keyboard::setSymbols()
{

    int id;
    if (!isCaps && !isShift) id = 0;
    if (!isCaps  && isShift) id = 1;
    if (isCaps  && !isShift) id = 2;
    if (isCaps  && isShift) id = 3;
    for (int key : buttonsMap.keys()) buttonsMap[key]->setText(keyText[curLocale][id][key]);
}

void keyboard::setLocale(int n)
{
    curLocale = n;
    setSymbols();
}
