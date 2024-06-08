#include "keyboardvisualizer.h"
#include "ui_keyboard.h"

KeyboardVisualizer::KeyboardVisualizer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KeyboardVisualizer)
{
    ui->setupUi(this);
    _scene = new QGraphicsScene();
    ui->graphicsView->setScene(_scene);
    painter = new QPainter();
    drawKeys();
    addText();
}

KeyboardVisualizer::~KeyboardVisualizer()
{
    delete ui;
}

void KeyboardVisualizer::setLanguage(language nlang)
{
    _currentLang = nlang;
    switch(nlang)
    {
    case angl:
        languageLayout = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
        break;
    case bel:
        languageLayout = "ё1234567890-=йцукенгшўзх'\\фывапролджэячсмітьбю.";
        break;
    case rus:
        languageLayout = "ё1234567890-=йцукенгшщзхъ\\фывапролджэячсмитьбю.";
        break;
    case ara:
        languageLayout = "ذ1234567890-=ضصثقفغعهخحجد\\شسيبلاتنمكطئءؤرلاىةوزظ";
        break;
    case ger:
        languageLayout = "^1234567890ß´qwertyuiopü+#asdfghjklöäzxcvbnm,.-";
        break;
    case heb:
        languageLayout = ";1234567890-=/'קראטוןםפ][\\שדגכעיחלךף,זסבהנמצתץ.";
        break;
    case chi:
        languageLayout = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
        break;
    case fre:
        languageLayout = "<&é”’(§è!çà)-azertyuiop^$`qsdfghjklmùwxcvbn,;:=";
        break;
    default:
        languageLayout = "Unsupported language";
        break;
    }
    addText();
}

void KeyboardVisualizer::drawKeys()
{

    const double KEY_SPOT_HALF = KEY_SPOT * 0.5;
    const double KEY_SPOT_1_5 = KEY_SPOT * 1.5;
    const double KEY_SIZE_1_5 = KEY_SIZE * 1.5;
    const double KEY_SIZE_2 = KEY_SIZE * 2.0;
    const double KEY_SPOT_2_5 = KEY_SPOT * 2.5;
    const double KEY_SIZE_2_5 = KEY_SIZE * 2.5;
    const double KEY_SIZE_3 = KEY_SIZE * 3.0;
    const double KEY_SPOT_3_5 = KEY_SPOT * 3.5;
    const double KEY_SIZE_4 = KEY_SIZE * 4.0;
    const double KEY_SPOT_4_5 = KEY_SPOT * 4.5;
    const double KEY_SIZE_4_5 = KEY_SIZE * 4.5;
    const double KEY_SIZE_7 = KEY_SIZE * 7.0;
    const double KEY_SIZE_11_5 = KEY_SIZE * 11.5;
    const double KEY_SIZE_13_5 = KEY_SIZE * 13.5;

    const double ROW_1_Y = KEY_SPOT_HALF;
    const double ROW_2_Y = KEY_SPOT_1_5 + KEY_SIZE;
    const double ROW_3_Y = KEY_SPOT * 2.5 + KEY_SIZE_2;
    const double ROW_4_Y = KEY_SPOT * 3.5 + KEY_SIZE_3;
    const double ROW_5_Y = KEY_SPOT * 4.5 + KEY_SIZE_4;

    std::array<QGraphicsRectItem *, 11> keys = {
        tab = new QGraphicsRectItem(KEY_SPOT_HALF, ROW_2_Y, KEY_SIZE_1_5, KEY_SIZE),
        caps = new QGraphicsRectItem(KEY_SPOT_HALF, ROW_3_Y, KEY_SIZE_2, KEY_SIZE),
        lShift = new QGraphicsRectItem(KEY_SPOT_HALF, ROW_4_Y, KEY_SIZE_2_5, KEY_SIZE),
        lOption = new QGraphicsRectItem(KEY_SPOT_HALF, ROW_5_Y, KEY_SIZE_2_5, KEY_SIZE),
        lCommand = new QGraphicsRectItem(KEY_SPOT_1_5 + KEY_SIZE_2_5, ROW_5_Y, KEY_SIZE_2, KEY_SIZE),
        space = new QGraphicsRectItem(KEY_SPOT_2_5 + KEY_SIZE_4_5, ROW_5_Y, KEY_SIZE_7, KEY_SIZE),
        rCommand = new QGraphicsRectItem(KEY_SPOT_3_5 + KEY_SIZE_11_5, ROW_5_Y, KEY_SIZE_2, KEY_SIZE),
        rOption = new QGraphicsRectItem(KEY_SPOT_4_5 + KEY_SIZE_13_5,
                                        ROW_5_Y,
                                        KEY_SIZE_2_5,
                                        KEY_SIZE),
        back = new QGraphicsRectItem(KEY_SPOT_HALF + TOP_ROW_KEYS * (KEY_SIZE + KEY_SPOT),
                                     ROW_1_Y,
                                     KEY_SIZE_1_5,
                                     KEY_SIZE),
        enter = new QGraphicsRectItem(KEY_SPOT_1_5 + KEY_SIZE_2
                                          + MID_ROW_KEYS * (KEY_SIZE + KEY_SPOT),
                                      ROW_3_Y,
                                      KEY_SIZE_1_5 + KEY_SPOT,
                                      KEY_SIZE),
        rShift = new QGraphicsRectItem(KEY_SPOT_1_5 + KEY_SIZE_2_5
                                           + BOT_ROW_KEYS * (KEY_SIZE + KEY_SPOT),
                                       ROW_4_Y,
                                       KEY_SIZE_2_5 - KEY_SPOT,
                                       KEY_SIZE)};
    for (auto key : keys)
    {
        _scene->addItem(key);
    }

    for (int i = 0; i < TOP_ROW_KEYS; ++i)
    {
        _highestRowBtn.at(i) = new QGraphicsRectItem(KEY_SPOT_HALF + i * (KEY_SIZE + KEY_SPOT), ROW_1_Y, KEY_SIZE, KEY_SIZE);
        _scene->addItem(_highestRowBtn.at(i));
    }

    for (int i = 0; i < TOP_ROW_KEYS; ++i)
    {
        _topRowBtn.at(i) = new QGraphicsRectItem(KEY_SPOT_1_5 + KEY_SIZE_1_5 + i * (KEY_SIZE + KEY_SPOT), ROW_2_Y, KEY_SIZE, KEY_SIZE);
        _scene->addItem(_topRowBtn.at(i));
    }

    for (int i = 0; i < MID_ROW_KEYS; ++i)
    {
        _midRowBtn.at(i) = new QGraphicsRectItem(KEY_SPOT_1_5 + KEY_SIZE_2 + i * (KEY_SIZE + KEY_SPOT), ROW_3_Y, KEY_SIZE, KEY_SIZE);
        _scene->addItem(_midRowBtn.at(i));
    }

    for (int i = 0; i < BOT_ROW_KEYS; ++i)
    {
        _botRowBtn.at(i) = new QGraphicsRectItem(KEY_SPOT_1_5 + KEY_SIZE_2_5 + i * (KEY_SIZE + KEY_SPOT), ROW_4_Y, KEY_SIZE, KEY_SIZE);
        _scene->addItem(_botRowBtn.at(i));
    }

    _lastItem = tab;
}

void KeyboardVisualizer::addTextToButton(QGraphicsRectItem* button, const QString& text)
{
    QPointF point = button->rect().center();
    QGraphicsItem* item = _scene->itemAt(point,QTransform());
    QList<QGraphicsItem*> collidingItems = button->collidingItems();
    for(QGraphicsItem* item : collidingItems)
    {
        QGraphicsTextItem* t = dynamic_cast<QGraphicsTextItem*>(item);
        if(t)
        {
            _scene->removeItem(t);
        }
    }
    QGraphicsTextItem* textItem = _scene->addText(text, QFont("AppleSystemUIFont", 12, 20));
    textItem->setPos(button->boundingRect().x() + KEY_SPOT,
                     button->boundingRect().y() + KEY_SIZE / 3.0f);
    Q_UNUSED(item);
}

void KeyboardVisualizer::addText()
{
    addTextToButton(tab, "tab");
    addTextToButton(caps, "caps lock");
    addTextToButton(lShift, "shift");
    addTextToButton(rShift, "shift");
    addTextToButton(lOption, "option");
    addTextToButton(rOption, "option");
    addTextToButton(lCommand, "command");
    addTextToButton(rCommand, "command");
    addTextToButton(enter, "return");
    addTextToButton(back, "delete");
    addTextToButton(space, "space");

    for (int i = 0; i < TOP_ROW_KEYS; ++i)
    {
        addTextToButton(_highestRowBtn.at(i), languageLayout.at(i));
        addTextToButton(_topRowBtn.at(i), languageLayout.at(TOP_ROW_KEYS + i));
        if (i >= MID_ROW_KEYS)
        {
            continue;
        }
        addTextToButton(_midRowBtn.at(i), languageLayout.at(TOP_ROW_KEYS * 2 + i));
        if (i >= BOT_ROW_KEYS)
        {
            continue;
        }
        addTextToButton(_botRowBtn.at(i), languageLayout.at(TOP_ROW_KEYS * 2 + MID_ROW_KEYS + i));
    }
}

QGraphicsRectItem *KeyboardVisualizer::atIndex(int index)
{
    if (index < 0)
    {
        return nullptr;
    }
    if (index >= TOP_ROW_KEYS * 2 + MID_ROW_KEYS + BOT_ROW_KEYS)
    {
        index -= TOP_ROW_KEYS * 2 + MID_ROW_KEYS + BOT_ROW_KEYS;
        switch (index)
        {
        case 0:
            return space;
        case 1:
            return enter;
        }
        return nullptr;
    }
    else if (index >= TOP_ROW_KEYS * 2 + MID_ROW_KEYS)
    {
        return _botRowBtn.at(index - TOP_ROW_KEYS * 2 - MID_ROW_KEYS);
    }
    else if (index >= TOP_ROW_KEYS * 2)
    {
        return _midRowBtn.at(index - TOP_ROW_KEYS * 2);
    }
    else if (index >= TOP_ROW_KEYS)
    {
        return _topRowBtn.at(index - TOP_ROW_KEYS);
    }
    return _highestRowBtn.at(index);
}

void KeyboardVisualizer::makeButtonGreen(int index)
{
    if (_lastItem != nullptr) {
        _lastItem->setBrush(Qt::white);
    }
    if (index > 0) {
        atIndex(index)->setBrush(Qt::green);
        _lastItem = atIndex(index);
    }
}

void KeyboardVisualizer::makeButtonRed(int index)
{
    if (_lastItem != nullptr) {
        _lastItem->setBrush(Qt::white);
    }
    if (index > 0) {
        atIndex(index)->setBrush(Qt::red);
        _lastItem = atIndex(index);
    }
}

int KeyboardVisualizer::getLanguage()
{
    return static_cast<int>(_currentLang);
}

